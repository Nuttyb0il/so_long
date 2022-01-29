from PIL import Image
import argparse

args = argparse.ArgumentParser()
args.add_argument("-i", "--input", help="Path to the input image", required=True)
args.add_argument("-s", "--scale", help="Scale factor", required=True)
args = args.parse_args()

image = Image.open(args.input)
image = image.resize((int(image.width * float(args.scale)), int(image.height * float(args.scale))), Image.BOX)

filename, ext = args.input.split(".")
image.save(filename + "_upscaled." + ext)
image.close()