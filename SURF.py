import cv2 
import matplotlib as plt
img=cv2.imread("data_0.jpg",0)
surf = cv2.xfeatures2d.SURF_create(400)
kp, des = surf.detectAndCompute(img,None)
surf.setUpright(True)
print( surf.getUpright() )
kp = surf.detect(img,None)
img2 = cv2.drawKeypoints(img,kp,None,(255,0,0),4)
cv2.imshow("danh",img2)
cv2.waitKey(0)