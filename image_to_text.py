#from pytesseract import image_to_string
from PIL import Image
import os, sys, subprocess
import numpy as np
from cv2 import *

image1jpg = "Image1.jpg"
image2jpg = "Image2.jpg"
file1 = "out1"
file2 = "out2"

def func():
    # initialize the camera
    cam = VideoCapture(0)   # 1 -> index of camera
    s, img = cam.read()

    if s:    # frame captured without any errors
        namedWindow("cam-test",WINDOW_NORMAL)
        imshow("cam-test",img)
        waitKey(0)
        destroyWindow("cam-test")
        imwrite(image1jpg,img) #save image
        gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

    img = cv2.imread(image1jpg)
    h = np.size(img, 0)
    w = np.size(img, 1)

    x = input('Do you want to carry on? ("n" to exit): ')
    if (x == "n"):
        exit()

    # Cropping the left and right halves of the picture
    image = Image.open(image1jpg)
    cnt = 0
    while(True):

        if (cnt == 2) : break # Both pages have been cropped

        if (cnt == 0) : # Crop the left half
            image2 = image.crop((0, 0, w/2, h))
            image2.save(image2jpg)
            # os.system("tesseract "+image2jpg+" "+file1)
            subprocess.run(["tesseract", image2jpg, file1])
            cnt += 1

        if (cnt == 1) : # Crop the right half
            image2 = image.crop((w/2, 0, w, h))
            image2.save(image2jpg)
            # os.system("tesseract "+image2jpg+" "+file2)
            subprocess.run(["tesseract", image2jpg, file2])
            cnt += 1
func()
