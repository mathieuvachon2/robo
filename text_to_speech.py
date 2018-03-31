#!/usr/env python
# -*- coding : utf-8 -*-
#
# text_to_speech.py
#
'''
Text to speech part that reads from 'test.txt'
'''

# import pywin
from time import sleep

try:
    import pyttsx3 as pyttsx
except ImportError:
    import pyttsx
#from pytesseract import image_to_string
from PIL import Image
import os, sys, subprocess
from cv2 import *
import image_to_text as itt
import serial
#establishing connection with the arduino
######## If you're using Mac, uncomment the first line. If you're using Windows, uncomment the second line
#and dont forget to type the correct post #######
#ser = serial.Serial('/dev/cu.usbmodem1461',9600)
ser = serial.Serial('COM6', 9600)

# Initialize the camera
#redundant as itt initialize the camera already
#cam = VideoCapture(0)   # 1 -> index of camera
#s, img = cam.read()
# print(img)
while(True):
    itt.func()

    # Initialize TTS engine
    engine = pyttsx.init()
    MODIF = 1.0
    SPEED = engine.getProperty('rate') * MODIF
    engine.setProperty('rate', SPEED)
    # print(engine.getProperty('voice'))
    engine.say("You entered carry on. I will now read the text for you")

    file1 = "out1.txt"
    file2 = "out2.txt"

    # Reading text file
    with open(file1, "r+") as testFile:
        for line in testFile.readlines():
            engine.say(line)
        engine.runAndWait()

    # Reading text file 2
    #with open(file2, "r+") as testFile:
     #   for line in testFile.readlines():
      #      engine.say(line)
       # engine.runAndWait()

    #send 1 to arduino to start the flipping process
    engine.say("I will now flip the page")
    engine.runAndWait()
    ser.write(b'1')
    sleep(12)
    #executing the flipping in python
    #for line in ser.readlines():
     #   if (line == 'turn = 0\n'): break
      #  print(line)
