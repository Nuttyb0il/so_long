import sys
import random
from PIL import Image
if len(sys.argv) != 2:
    exit(1)

OUTPUT_PATH = sys.argv[1]

def random_color() -> tuple:
    return (random.randint(0, 255), random.randint(0, 255), random.randint(0, 255))

size = (1024, 1024)
COLORS = [random_color() for i in range(64)]

with Image.new("RGBA", size) as pixel_image:
    for i in range(size[0]):
        for j in range(size[1]):
            pixel_image.putpixel((i, j), random.choice(COLORS))
    pixel_image.save(OUTPUT_PATH)
    print("Writing image to {}".format(OUTPUT_PATH))
