import sys
from PIL import Image
if len(sys.argv) != 2:
    exit(1)

colors = []
with open(sys.argv[1], "rb") as f:
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

for i, c in enumerate(colors):
    print("#{} : {},{},{}".format(i, c[0], c[1], c[2]))

# new image of size (len(colors), 1)
with Image.new("RGBA", (len(colors), 1)) as image:
    for i in range(len(colors)):
        image.putpixel((i, 0), colors[i])
    image.show()