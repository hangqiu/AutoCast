#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <time.h>
#include <unistd.h>
#include <v2x_api.h>

#define LOG_CONFIG_PATH "/usr/local/mocar_log.conf"
#define MOUDLE_NAME "custom"

typedef void (*timer_func)(union sigval sig);

/* UDP config */
const char *udpAddress = "0.0.0.0";
int udpPort = 9999;
int udpFD;
struct sockaddr clientSocketAddress;
struct sockaddr replySocketAddress;
socklen_t addressSize;
struct sockaddr_in serverAddress;

/* "Last client IP that sent a message to the radio" is who we'll reply to */
int returnFD;
bool hasReplyAddress = false;

/* Buffers */
uint8_t recvbuf[4096];

void printIP(struct in_addr address) {
  char buf[INET_ADDRSTRLEN];
  if (inet_ntop(AF_INET, &address, buf, 100) == NULL) {
    // fprintf(stderr, "inet_ntop error on address conversion\n");
  } else {
    fprintf(stderr, "%s", buf);
  }
}

void v2x_custom_recv_handle(char *custom_buffer, int len) {
  if (hasReplyAddress) {

    /* Who sent us the last packet? */
    struct sockaddr_in *sin = (struct sockaddr_in *)&clientSocketAddress;
    struct in_addr addr =
        sin->sin_addr;             // original IP address that sent this to us
    uint16_t port = sin->sin_port; // to send, might need htons();

    /* RETURN TO SENDER */
    struct sockaddr_in returnToSender;
    returnToSender.sin_family = AF_INET;
    returnToSender.sin_port = htons(udpPort);
    returnToSender.sin_addr = addr;

    sendto(returnFD, custom_buffer, len, 0, (struct sockaddr *)&returnToSender,
           addressSize);
    fprintf(stderr, "[DSRC RX][%d] sending to: ", len);
    printIP(returnToSender.sin_addr);
    fprintf(stderr, ":%d\n", udpPort);

    // fprintf(stderr, "%.*s", len, custom_buffer);
    // fprintf(stderr, "\n");
  } else {
    fprintf(stderr,
            "Got RX packet, but I don't know where to send to. Dropping!\n");
  }
}

int main(int argc, char *argv[]) {
  int ret = -1;

  /* Port to use must be specified on startup */
  if (argc != 2 || atoi(argv[1]) <= 0 || atoi(argv[1]) > 65535) {
    fprintf(stderr, "Usage: ./dsrcSendMessage_UDP <port number (1-65535)>\n");
    return -2;
  }
  udpPort = atoi(argv[1]);
  fprintf(stderr, "Listening on port %d\n", udpPort);

  ret = mde_v2x_init(LOG_CONFIG_PATH, MOUDLE_NAME);
  if (0 != ret) {
    fprintf(stderr, "v2x init faild\n");
    return -1;
  }
  fprintf(stderr, "v2x init success\n");

  ret = mde_v2x_register_custom(v2x_custom_recv_handle);
  if (0 != ret) {
    fprintf(stderr, "custom register failed\n");
    return -1;
  }
  fprintf(stderr, "custom register success\n");

  /* Open and configure UDP socket for receiving data */
  udpFD = socket(PF_INET, SOCK_DGRAM, 0);
  serverAddress.sin_family = AF_INET;
  serverAddress.sin_port = htons(udpPort);
  serverAddress.sin_addr.s_addr = inet_addr(udpAddress);
  memset(serverAddress.sin_zero, '\0', sizeof(serverAddress.sin_zero));
  bind(udpFD, (struct sockaddr *)&serverAddress, sizeof(serverAddress));

  if (udpFD == -1) {
    fprintf(stderr, "Unable to open UDP receiver socket\n");
    return -2;
  }

  /* UDP reply "return-to-sender" port */
  returnFD = socket(PF_INET, SOCK_DGRAM, 0);
  if (returnFD == -1) {
    fprintf(stderr, "Unable to open UDP return socket\n");
    return -3;
  }

  /* Keep running forever */
  int nBytes;
  addressSize = sizeof(clientSocketAddress);

  while (1) {
    nBytes = recvfrom(udpFD, recvbuf, 4096, 0,
                      (struct sockaddr *)&clientSocketAddress, &addressSize);

    /* We should know the client's IP now */
    hasReplyAddress = true;

    /* Now we have something on UDP... */
    int ret = mde_v2x_send_custom(recvbuf, nBytes);
    if (0 != ret) {
      fprintf(stderr, "[ERR] DSRC transmit failed!\n");
    } else {
      fprintf(stderr, "[DSRC TX]\n");
    }
  }
}
