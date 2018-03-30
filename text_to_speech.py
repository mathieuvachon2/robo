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

engine = pyttsx.init()

# Opening text file
with open("test.txt", "r+") as testFile:
    for line in testFile.readlines():
        engine.say(line)

engine.runAndWait()
