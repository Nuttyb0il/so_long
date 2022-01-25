from PIL import Image
from pprint import pprint
import os
import PIL
import argparse

args = argparse.ArgumentParser()
args.add_argument("-i", "--input", help="Input sprite file", required=True)
args.add_argument("-o", "--output", help="Output image file", required=False)
args.add_argument("-c", "--compressed", help="Compress sprite", action="store_true")
args = args.parse_args()

print(PIL.__version__)
if "sprites/proto" not in os.getcwd():
    os.chdir("sprites/proto")
IMAGE_PATH = args.input
neighbors_total = 0
def convert_rgb_to_index(r: int, g: int, b: int, palette: list) -> int:
    for p in palette:
        if p[0] == r and p[1] == g and p[2] == b:
            return palette.index(p)
    return -1

def count_neighbors(haystack: list, offset: int) -> int:
    """
    Counts the number of identical neighbors in a list.
    :param haystack: The list to search.
    :param offset: The offset to start searching from.
    :return: The number of identical neighbors.
    """
    count = 0
    for i in range(offset + 1, len(haystack)):
        if haystack[i] == haystack[offset]:
            count += 1
        else:
            break
    return count

def bytes_to_human(bytes: int) -> str:
    if bytes < 1024:
        return "{:.2f} B".format(bytes)
    elif bytes < 1024 * 1024:
        return "{:.2f} KB".format(bytes / 1024)
    elif bytes < 1024 * 1024 * 1024:
        return "{:.2f} MB".format(bytes / 1024 / 1024)
    else:
        return "{:.2f} GB".format(bytes / 1024 / 1024 / 1024)
def encode(image, output=None, compressed=False):
    global neighbors_total
    if output is None:
        output = args.input.replace(".png", ".sprite")
    if os.path.exists(output):
        os.remove(output)
    x, y = image.size
    colors = []
    print("Image size:", image.size)
    print("Extracting colors -> ", end="")
    # read through image line by line
    for i in range(y):
        for j in range(x):
            r, g, b, a = image.getpixel((j, i))
            if a == 255:
                colors.append((r, g, b))
    print("✅")
    print("Removing duplicates -> ", end="")

    colors = list(dict.fromkeys(colors))
    print("✅")
    print("Found {} colors".format(len(colors)))
    pprint(colors)
    with open(output, "ab+") as f:
        f.write(bytes([len(colors)]))
        for i, c in enumerate(colors):
            print("Writing sprite palette -> {}/{} -- {}".format(i+1, len(colors), c), end="\r")
            f.write(bytes(c))
        print()
        f.write(bytes([int(compressed)]))
        print("Encoding image -> ", end="")
        pixels = []
        # read through image line by line
        for i in range(y):
            for j in range(x):
                r, g, b, a = image.getpixel((j, i))
                if a != 255:
                    pixels.append(0xFF)
                    continue
                index = convert_rgb_to_index(r, g, b, colors)
                if index < 0:
                    pixels.append(0xFF)
                else:
                    pixels.append(index)
        print("✅")
        # Write height and width
        print("Writing sprite size -> ", end="")
        f.write(bytes([x]))
        f.write(bytes([y]))
        print("✅")
        # Write pixel count to file
        print("{} pixels to encode".format(len(pixels)))
        # Write pixels
        
        skip = 0
        for i, p in enumerate(pixels):
            if skip != 0:
                skip -= 1
                continue
            # print("Writing sprite pixels -> {}/{}".format(i+1, len(pixels)), end="\r")
            if compressed:
                neighbors = count_neighbors(pixels, i)
                neighbors_total += neighbors - 1
                skip = neighbors
                f.write(bytes([neighbors]))
            f.write(bytes([p]))
        print()
    image.close()
    print("Output : {}".format(args.output))
    print("Size : {} -- {}".format(bytes_to_human(os.path.getsize(output)), "compressed" if compressed else "uncompressed"))
    if compressed:
        print("Saved {} using pattern repeat.".format(bytes_to_human(neighbors_total)))
strawberry = Image.open(IMAGE_PATH)
strawberry = strawberry.convert("RGBA")
encode(strawberry, args.output, args.compressed)