from pytesseract import image_to_string
from PIL import Image
from cv2 import *
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

# load the image as a PIL/Pillow image, apply OCR, and then delete
# the temporary file
imag = Image.open("Image.jpg")
text = image_to_string(imag)
print(text)