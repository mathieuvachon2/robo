import cv2
from PIL import Image
import numpy as np
try:
    import pyttsx3 as pyttsx
except ImportError:
    import pyttsx
import os
import pytesseract

src_path = 'C:\\Users\\Simon\\Desktop\\CompSci\\SharedFolder1\\robo'
img_path = 'C:\\Users\\Simon\\Desktop\\CompSci\\SharedFolder1\\robo\\hard.jpg'
def main():
   # Read image with opencv
   img = cv2.imread(img_path)

   # Convert to gray
   img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

   # Apply dilation and erosion to remove some noise
   kernel = np.ones((1, 1), np.uint8)
   img = cv2.dilate(img, kernel, iterations=1)
   img = cv2.erode(img, kernel, iterations=1)

   # Write image after removed noise
   cv2.imwrite(src_path + '\\removed_noise.png', img)

   #  Apply threshold to get image with only black and white
   #img = cv2.adaptiveThreshold(img, 255, cv2.ADAPTIVE_THRESH_GAUSSIAN_C, cv2.THRESH_BINARY, 31, 2)

   # Write the image after apply opencv to do some ...
   cv2.imwrite(src_path + '\\thres.png', img)
   engine = pyttsx.init()
   MODIF = 1.0
   SPEED = engine.getProperty('rate') * MODIF
   engine.setProperty('rate', SPEED)
   # print(engine.getProperty('voice'))
   engine.say("You entered carry on. I will now read the text for you")
   file1 = src_path+"\\out1.txt"
   image1jpg = src_path+"\\thres.png"

   result = pytesseract.image_to_string(Image.open(src_path +'\\thres.png'))
   engine.say(result)
   engine.runAndWait()




if __name__ == '__main__': main()
