import pywin
import pyttsx

engine = pyttsx .init()
# Opening text file
testFile = open("test.txt", "r+")
for line in testFile.readlines():
    engine.say(line)
    engine.runAndWait()

testFile.close()


