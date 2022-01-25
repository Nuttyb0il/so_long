import os
from pprint import pprint
import traceback
from PIL import Image
import argparse

args = argparse.ArgumentParser()
args.add_argument("-i", "--input", help="Input sprite file", required=True)
args.add_argument("-o", "--output", help="Output image file", required=True)
args = args.parse_args()

if "sprites/proto" not in os.getcwd():
    os.chdir("sprites/proto")
def decode(sprite_path, output):
    colors = []
    print("Reading palette -> ", end="")
    with open(sprite_path, "rb") as f:
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
        compressed = bool(f.read(1)[0])
        print("Compressed: {}".format(compressed))
        x, y = f.read(2)
        print("Dimensions: {}x{}".format(x, y))
        pixels = []
        # read until end of file
        while True:
            if compressed:
                try:
                    repeat_count, palette_index = f.read(2)
                    for _ in range(repeat_count + 1):
                        pixels.append(palette_index)
                except:
                    break
            else:
                try:
                    pixels.append(f.read(1)[0])
                except:
                    break
        print("Pixel count", len(pixels))
        with Image.new("RGBA", (x, y)) as image:
            print("Decoding image -> ", end="")
            for i in range(y):
                for j in range(x):
                    try:
                        if pixels[i * x + j] == 255:
                            image.putpixel((j, i), (0, 0, 0, 0))
                        else:
                            image.putpixel((j, i), colors[pixels[i * x + j]])
                    except:
                        print("❌\nCRASH :")
                        print("Tried to access: {}, {}".format(j, i))
                        print("Image size : {}x{}".format(x, y))
                        try:
                            print("Pixels index : {}".format(pixels[i * x + j]))
                        except:
                            print("Pixels index : Out of range ({} >= {})".format(i * x + j, len(pixels)))
                        print("Color count : {}".format(len(colors)))
                        print("Color list :")
                        pprint(colors)
                        exit()
            print("✅")
            image.save(output)
            print("Saved to {}".format(output))
decode(args.input, args.output)