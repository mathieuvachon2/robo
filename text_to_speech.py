#!/usr/env python
# -*- coding : utf-8 -*-
#
# text_to_speech.py
#
'''
Text to speech part that reads from 'test.txt'
'''

# import pywin
try:
    import pyttsx3 as pyttsx
except ImportError:
    import pyttsx
from pytesseract import image_to_string
from PIL import Image
import os, sys, subprocess
from cv2 import *
import image_to_text as itt
import serial

# ser = serial.Serial()

# Initialize the camera
cam = VideoCapture(0)   # 1 -> index of camera
s, img = cam.read()
# print(img)

itt.func()

# Initialize TTS engine
engine = pyttsx.init()
MODIF = 1.0
SPEED = engine.getProperty('rate') * MODIF
engine.setProperty('rate', SPEED)
# print(engine.getProperty('voice'))

file1 = "out1.txt"
file2 = "out2.txt"

# Reading text file
with open(file1, "r+") as testFile:
    for line in testFile.readlines():
        engine.say(line)
    engine.runAndWait()

# Reading text file 2
with open(file2, "r+") as testFile:
    for line in testFile.readlines():
        engine.say(line)
    engine.runAndWait()
