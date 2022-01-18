import os
from pprint import pprint
from PIL import Image
import argparse

args = argparse.ArgumentParser()
args.add_argument("-i", "--input", help="Input sprite file", required=True)
args.add_argument("-o", "--output", help="Output image file", required=True)
args = args.parse_args()

if "sprites/proto" not in os.getcwd():
    os.chdir("sprites/proto")
SPRITE_PATH = args.input

colors = []
print("Reading palette -> ", end="")
with open(SPRITE_PATH, "rb") as f:
    num_colors = f.read(1)[0]
    bytes_to_read = num_colors * 3
    r = g = b = 0
    for i in range(bytes_to_read):
        if i % 3 == 0:
            r = f.read(1)[0]
        elif i % 3 == 1:
            g = f.read(1)[0]
        elif i % 3 == 2:
            b = f.read(1)[0]
            colors.append((r, g, b))

    print("✅")
    print("Found {} colors".format(len(colors)))
    pprint(colors)


    OUTPUT_PATH = args.output
    # get pixel count by reading 2 bytes
    print("Reading sprite size -> ", end="")
    x, y = f.read(2)
    print("✅")
    print("Reading pixel count -> ", end="")
    pixel_count = int.from_bytes(f.read(2), "big")
    print("✅")
    print("Pixel count: {}".format(pixel_count))
    written_pixels = 0
    with Image.new("RGBA", (x, y)) as pixel_image:
        i, j = 0, 0
        print("Size : {}, {}".format(pixel_image.size[0], pixel_image.size[1]))
        for k in range(pixel_count):
            print("Writing at {}, {} -- Progress : {:.2f}%  ".format(i, j, written_pixels/pixel_count*100), end='\n')
            # print("Reading sprite pixels -> {}/{}".format(i+1, pixel_count), end="\r")
            pixel = f.read(1)[0]
            if pixel == 0xFF:
                pixel_image.putpixel((i, j), (0, 0, 0, 0))
                written_pixels += 1
                continue
            try:
                color = colors[pixel]
            except:
                print("\nError :")
                print("Tried to access color {} but exceed palette".format(pixel, len(colors)))
                print("Pixel : {}".format(pixel))
                pprint(colors)
                exit(1)
            try:
                pixel_image.putpixel((j, i), color)
            except:
                print("\nError :")
                print("Tried to access {},{} but exceed image".format(i, j, (x, y)))
                pprint(colors)
                exit(1)
            written_pixels += 1
            i += 1
            if i >= pixel_image.size[0]:
                i = 0
                j += 1
        print()
        pixel_image.save(OUTPUT_PATH, "PNG", optimize=True)
