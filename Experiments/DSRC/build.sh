#!/bin/bash
rm -f dsrcSendMessage_UDP

# For paho-mqtt (not working yet tho)
# -lpaho-embed-mqtt3c -lMQTTPacketClient -lMQTTPacketServer

arm-linux-gnueabihf-gcc dsrc_send_message.c -I libs/includes/ -L libs/ -lmocarv2x -L libs/base/ -lasnhl -lLLC -losstoed -lsmartway -lstack -lrt -lpthread -o dsrcSendMessage_UDP
