#
# DSRC radio layer for integration into other stuff (like AutoCast in CARLA)
# Namo <namo@usc.edu>, Jan 2022
#
import socket, threading

class DSRCRadio:

    def __init__(self, address, callback, port = 9999, trimOutput = True):
        """
        Initializer function. Required parameters to initialize:

        - address:      the IP address for the target radio we want to
                        send frames to
        - callback:     the function that will be called (as callback(message)) when
                        a message is received over the DSRC/UDP interface
        - port:         UDP port that is used for communications between this
                        class and the radio. MUST BE UNIQUE for each instance of DSRCRadio!

        Optional parameters
        - trimOutput:   if "True", enables .trim() on data when it is sent/received
        """
        self.radioAddress = address
        self.callback = callback
        self.port = int(port)
        self.trimOutput = trimOutput

        # INTERNAL: RX buffer size
        self.rxBufferSize = 4096

        # Here, we establish the incoming and outgoing data sockets...
        self.initOutgoingSocket()
        self.initIncomingSocket()

        # And then start a thread for the incoming socket...
        self.rxThread = threading.Thread(target = self.rxThreadLoop)
        self.rxThread.start()

    def initOutgoingSocket(self):
        """
        Establishes outgoing UDP socket so we can send data to the radio
        """
        self.txSocket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.txRadioServer = (self.radioAddress, self.port)
        self.txSocket.bind(('', 0))
        self.txSocketPort = self.txSocket.getsockname()[1]

    def initIncomingSocket(self):
        """
        Establishes a listen (incoming) UDP socket so we can get data from
        the radio.
        """
        self.rxSocket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.rxSocket.bind(('', self.port))

    def rxThreadLoop(self):
        """
        Perpetual loop for the receive (RX) thread
        """
        while True:
            try:
                d = self.rxSocket.recvfrom(self.rxBufferSize)
                data = d[0]
                address = d[1] # not used yet but is here just in case
                incomingData = data.decode()

                # If trimming enabled...
                if(self.trimOutput):
                    incomingData = incomingData.strip()

                self.callback(incomingData)
            except Exception as e:
                print(f"RX loop exception: {e}")

# ================================================================================================= #

    def send(self, payload):
        """
        Send packet 'payload' (must be byte-encodable, typically we expect a string)
        to the radio for transmission (TX)
        """

        # If trimming enabled...
        if(self.trimOutput):
            payload = payload.strip()

        self.txSocket.sendto(bytes(payload, "utf-8"), self.txRadioServer)
