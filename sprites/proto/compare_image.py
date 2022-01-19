import sys
from PIL import Image

if len(sys.argv) != 3:
    exit(1)

image_a = Image.open(sys.argv[1])
image_b = Image.open(sys.argv[2])

if image_a.size != image_b.size:
    print("Image sizes do not match")
    exit(1)

pixels_a = pixels_b = []

# Get all pixels colors of all images
for i in range(image_a.size[0]):
    for j in range(image_a.size[1]):
        pixels_a.append(image_a.getpixel((i, j)))
        pixels_b.append(image_b.getpixel((i, j)))

# compare both lists
for i in range(len(pixels_a)):
    if pixels_a[i] != pixels_b[i]:
        print("Pixel {} differs".format(i))
        print("A: {}".format(pixels_a[i]))
        print("B: {}".format(pixels_b[i]))
        exit(1)

print("Images are identical")