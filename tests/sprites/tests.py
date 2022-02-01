import random
import os
import subprocess
import time

class DecodedSprite:
    def __init__(self, width: int, height: int, palette_size: int):
        self.width = width
        self.height = height
        self.palette_size = palette_size
    def correctly_decoded(self, width: int, height: int, palette_size: int):
        return (self.width == width and self.height == height and self.palette_size == palette_size)

def generate_sprites(output: str, palette_size: int, width: int, height: int, compressed: bool):
    assert palette_size > 0 and width > 0 and height > 0 and width <= 0xFF and height <= 0xFF
    try:
        subprocess.check_call(["python3", "../../sprites/proto/create_debug.py", "-p", str(palette_size), "-x", str(width), "-y", str(height), "-o", output.replace(".cnv", ".png")], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except:
        print("\nFailed to create sprite :\n{} depth\n{}x{}".format(palette_size, width, height))
        exit(1)
    args = ["python3", "../../sprites/proto/encode.py", "-i", output.replace(".cnv", ".png"), "-o", output, "-c"]
    if not compressed:
        args.remove("-c")
    try:
        subprocess.check_call(args, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except:
        print("\nFailed to encode sprite :\n{} depth\n{}x{}".format(palette_size, width, height))
        exit(1)
    os.remove(output.replace(".cnv", ".png"))
def parse_sprite_stdout(content: str) -> DecodedSprite:
    lines = content.split("\n")
    return DecodedSprite(int(lines[0]), int(lines[1]), int(lines[2]))

def run_tests(input: str, palette_size: int, width: int, height: int) -> tuple:
    try:
        output = subprocess.check_output(['./checker', input]).decode("utf-8")
        sprite = parse_sprite_stdout(output)
        return (sprite.correctly_decoded(width, height, palette_size), sprite)
    except: # Non-zero = error
        return 1

for i in range(1, 24):
    compressed = i % 2 == 0
    width, height = 8 * i, 8 * i
    palette = random.randint(2, 8 * (i//2) + 2)

    desc = "(compressed)" if compressed else "(uncompressed)"
    desc += " {}x{} palette ({} depth) : ".format(width, height, palette)
    print(desc + "⏳", end="\r")
    times = []
    for i in range(200):
        palette_size, width, height = 16, 8, 8
        generate_sprites("test_sprite_%d.cnv" % i,
                    palette_size,
                    width,
                    height,
                    False)
        
        start = time.time()
        sprite, status = run_tests("test_sprite_%d.cnv" % i, palette_size, width, height)
        if status == 0:
            print(desc + "💥")
            print(f"test_sprite{i}.cnv was improperly decoded")
            exit(1)
        else:
            os.remove("test_sprite_%d.cnv" % i)
        times.append(time.time() - start)
    print(desc + "✅")
    print("{:.5f} seconds per sprites".format(sum(times) / len(times)))
    print("Max : {:.5f} seconds".format(max(times)))
    print("---------------------------")
