from pytesseract import image_to_string
from PIL import Image
import os
import numpy as np
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

    img = cv2.imread('Image.jpg')
    h = np.size(img, 0)
    w = np.size(img, 1)

    x = raw_input('Do you want to carry on ?')
    if (x == "n"): exit()

    # Cropping the left and right halves of the picture
    image = Image.open("Image.jpg")
    cnt = 0
    while(True) :

        if (cnt == 2) : break # Both pages have been cropped

        if (cnt == 0) : # Crop the left half
            image2 = image.crop((0, 0, w/2, h))
            image2.save("Image2.jpg")
            os.system("tesseract Image2.jpg out1")
            cnt = cnt + 1

        if (cnt == 1) : # Crop the right half
            image2 = image.crop((w/2, 0, w, h))
            image2.save("Image2.jpg")
            os.system("tesseract Image2.jpg out2")
            cnt = cnt + 1
