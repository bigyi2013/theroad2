import glob
import cv2
images = glob.glob('tupian/*.bmp')
fn=1
for image in images:
    print(image)
    img = cv2.imread(image,0)
    fn=fn+1
    name='%d.bmp'% (fn)
    cv2.imwrite(image, img)

