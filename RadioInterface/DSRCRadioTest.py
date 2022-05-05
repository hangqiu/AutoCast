#!/usr/bin/python3
#
# Example code for the DSRCRadio module
# Namo <namo@usc.edu>, Jan 2022
#
from RadioInterface.DSRCRadio import DSRCRadio
import time

# This callback function is called when a message is received through
# the radio interface
def onMessage(message):
    print(f"\t -> RX on radio 1: {message}")
def onMessage_radio2(message):
    print(f"\t -> RX on radio 2: {message}")

# This is how we initialize the radio class/object
radio1 = DSRCRadio(address = "192.168.253.15", callback = onMessage, port = 9999)
radio2 = DSRCRadio(address = "192.168.253.16", callback = onMessage_radio2, port = 10000)

# Infinite loop to send a message once per second
while True:
    tick = f"Time is {time.time()}"
    radio1.send(f"TX from radio 1: {tick}")
    radio2.send(f"TX from radio 2: {tick}")
    print(tick)
    time.sleep(1)
