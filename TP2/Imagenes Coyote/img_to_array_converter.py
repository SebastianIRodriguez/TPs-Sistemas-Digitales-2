import numpy as np
from PIL import Image
import matplotlib.pyplot as plt
import cv2

im = np.array(Image.open('coyote_cayendo_bw_escalado_final.png'))
print(im.shape)
output = ""
for i in range(0,64):
    for j in range(0,64):
        pixel = im[i,j]
        #print(pixel)
        if pixel[0] == 255:
            output += "_"
        else:
            output += "X"
    output += ",\n"

print(output)
