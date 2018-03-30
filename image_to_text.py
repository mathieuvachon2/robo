from pytesseract import image_to_string
from PIL import Image
import os
from cv2 import *

def func():
    # initialize the camera
    cam = VideoCapture(1)   # 1 -> index of camera
    s, img = cam.read()

    if s:    # frame captured without any errors
        namedWindow("cam-test",WINDOW_NORMAL)
        imshow("cam-test",img)
        waitKey(0)
        destroyWindow("cam-test")
        imwrite("Image.jpg",img) #save image
        gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

    x = raw_input('Do you want to carry on ?')
    if (x == "n"): exit()

    os.system("tesseract Image.jpg out") # Tesseract needs to be installed
