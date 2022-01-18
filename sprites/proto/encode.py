from PIL import Image
from pprint import pprint
import os
import PIL
import argparse

args = argparse.ArgumentParser()
args.add_argument("-i", "--input", help="Input sprite file", required=True)
args.add_argument("-o", "--output", help="Output image file", required=True)
args = args.parse_args()

print(PIL.__version__)
if "sprites/proto" not in os.getcwd():
    os.chdir("sprites/proto")
IMAGE_PATH = args.input
if os.path.exists(args.output):
    os.remove(args.output)
colors = []


def convert_rgb_to_index(r: int, g: int, b: int, palette: list) -> int:
    for p in palette:
        if p[0] == r and p[1] == g and p[2] == b:
            return palette.index(p)
    return -1
strawberry = Image.open(IMAGE_PATH)
strawberry = strawberry.convert("RGBA")
x, y = strawberry.size
assert x <= 0xFF and y <= 0xFF
print("Image size:", strawberry.size)
print("Extracting colors -> ", end="")
for i in range(x):
    for j in range(y):
        if IMAGE_PATH.endswith(".png"):
            r, g, b, a = strawberry.getpixel((i, j))
            if a == 255:
                colors.append((r, g, b))
print("✅")
print("Removing duplicates -> ", end="")

colors = list(dict.fromkeys(colors))
print("✅")
print("Found {} colors".format(len(colors)))
pprint(colors)
with open(args.output, "ab+") as f:
    f.write(bytes([len(colors)]))
    for i, c in enumerate(colors):
        print("Writing sprite palette -> {}/{} -- {}".format(i+1, len(colors), c), end="\r")
        f.write(bytes(c))
    print()

    print("Encoding image -> ", end="")
    pixels = []
    for i in range(x):
        for j in range(y):
            r, g, b, a = strawberry.getpixel((i, j))
            if a != 255:
                pixels.append(0xFF)
            index = convert_rgb_to_index(r, g, b, colors)
            assert index >= 0
            pixels.append(index)
    print("✅")
    # Write height and width
    print("Writing sprite size -> ", end="")
    f.write(bytes([x]))
    f.write(bytes([y]))
    print("✅")
    # Write pixel count to file
    print("{} pixels to encode".format(len(pixels)))
    f.write(len(pixels).to_bytes(2, "big"))
    # Write pixels
    for i, p in enumerate(pixels):
        print("Writing sprite pixels -> {}/{}".format(i+1, len(pixels)), end="\r")
        f.write(bytes([p]))
    print()
strawberry.close()
print("Output : {}".format(args.output))