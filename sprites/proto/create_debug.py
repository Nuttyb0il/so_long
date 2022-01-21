import sys
import random
import argparse
from PIL import Image
from tqdm import tqdm

args = argparse.ArgumentParser()
args.add_argument("-p", "--palette_size", help="Palette size", required=True, type=int)
args.add_argument("-x", "--image_width", help="Image width", required=True, type=int)
args.add_argument("-y", "--image_height", help="Image height", required=True, type=int)
args.add_argument("-o", "--output", help="Output file", required=True, type=str)
args = args.parse_args()

OUTPUT_PATH = args.output

def random_color() -> tuple:
    return (random.randint(0, 255), random.randint(0, 255), random.randint(0, 255))

size = (args.image_width, args.image_height)
COLORS = [random_color() for i in range(args.palette_size)]

with Image.new("RGBA", size) as pixel_image:
    for i in tqdm(range(size[0])):
        for j in range(size[1]):
            pixel_image.putpixel((i, j), random.choice(COLORS))
    pixel_image.save(OUTPUT_PATH)
    print("Writing image to {}".format(OUTPUT_PATH))
