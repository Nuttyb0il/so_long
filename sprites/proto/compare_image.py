import sys
from PIL import Image

if len(sys.argv) != 3:
    exit(1)

image_a = Image.open(sys.argv[1])
image_b = Image.open(sys.argv[2])

# convert both image to RGBA
image_a = image_a.convert("RGBA")
image_b = image_b.convert("RGBA")

if image_a.size != image_b.size:
    print("Image sizes do not match")
    exit(1)

# Get all pixels colors of all images
for i in range(image_a.size[0]):
    for j in range(image_a.size[1]):
        if image_a.getpixel((i, j)) != image_b.getpixel((i, j)):
            print("Pixel {}x{} differs".format(i, j))
            # print colors
            r, g, b, a = image_a.getpixel((i, j))
            print("Image A: {} {} {}".format(r, g, b))
            r, g, b, a = image_b.getpixel((i, j))
            print("Image B: {} {} {}".format(r, g, b))
            exit(1)

print("Images are identical")