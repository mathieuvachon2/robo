import pywin
import pyttsx
from pytesseract import image_to_string
from PIL import Image
import os
from cv2 import *
import image_to_text as iit

engine = pyttsx .init()
# Opening text file
# initialize the camera
cam = VideoCapture(1)   # 1 -> index of camera
s, img = cam.read()

iit.func()

testFile = open("out.txt", "r+")
for line in testFile.readlines():
    engine.say(line)
    engine.runAndWait()

testFile.close()


