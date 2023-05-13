import numpy as np
from PIL import Image
import matplotlib.pyplot as plt
import cv2

images = [
    'coyote_cayendo_bw_escalado_final',
    'coyote_final'
]

def convert_to_oled_format(image_name):
    im = np.array(Image.open(image_name + '.png'))
    print(im.shape)
    column_count = im.shape[1]
    row_count = im.shape[0]
    output = ""
    for i in range(0, row_count):
        output += ""
        for j in range(0, column_count):
            pixel = im[i,j]
            #print(pixel)
            if pixel[0] == 255:
                output += "_"
            else:
                output += "X"
            if (j+1) % 8 == 0 and j > 0:
                output += ","
        output += "\n"

    print(output)
    return output


for img_name in images:
    output = convert_to_oled_format(img_name)
    text_file = open("OLED_" + img_name + ".txt", "w")
    n = text_file.write(output)
    text_file.close()