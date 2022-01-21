import os
from sys import stderr
import unittest
import random
import subprocess
import string
import random

def random_string(length=12):
    return ''.join(random.choice(string.ascii_letters + string.digits) for i in range(length))

def generate_image(palette_size: int, width: int, height: int) -> str:
    output_path = random_string() + ".png"
    try:
        subprocess.check_call(["python3", "create_debug.py", "-p", str(palette_size), "-x", str(width), "-y", str(height), "-o", output_path], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except:
        return None
    return output_path

def encode(image_path: str, compressed: bool) -> str:
    output_path = random_string() + ".sprite"
    try:
        args = ["python3", "encode.py", "-i", image_path, "-o", output_path]
        if compressed:
            args.append("-c")
        subprocess.check_call(args, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except:
        return None
    return output_path
def decode(sprite_path: str) -> str:
    output_path = random_string() + ".png"
    try:
        subprocess.check_call(["python3", "decode.py", "-i", sprite_path, "-o", output_path], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except:
        return None
    return output_path

def compare_images(image_path: str, original_path: str) -> bool:
    try:
        subprocess.check_call(["python3", "compare_image.py", image_path, original_path], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    except:
        return False
    return True

class TestSprite(unittest.TestCase):
    # def test_sprite_uncompressed(self):  
        # print("Testing uncompressed sprites", file=stderr)
        # for i in range(35+1):
        #     palette_size = random.randint(1, 200)
        #     height = random.randint(1, 200)
        #     width = random.randint(1, 200)
        #     file_path = generate_image(palette_size, width, height)
        #     if file_path is None:
        #         self.fail("Failed to generate image :\n\t-> Palette size : {}\n\t-> Width : {}\n\t-> Height : {}".format(palette_size, width, height))
        #     sprite_path = encode(file_path, False)
        #     if sprite_path is None:
        #         self.fail("Failed to encode image :\n\t-> Image path : {}".format(file_path))
        #     decoded = decode(sprite_path)
        #     if decoded is None:
        #         self.fail("Failed to decode image :\n\t-> Sprite path : {}".format(sprite_path))
        #     os.remove(sprite_path)
        #     if not compare_images(decoded, file_path):
        #         self.fail("Failed to compare images :\n\t-> Decoded path : {}\n\t-> Original path : {}".format(decoded, file_path))
        #     os.remove(decoded)
        #     os.remove(file_path)
        #     print("Test {}/35 passed".format(i), file=stderr)
    def test_sprite_compressed(self):
        for i in range(35+1):
            palette_size = random.randint(1, 200)
            height = random.randint(1, 200)
            width = random.randint(1, 200)
            file_path = generate_image(palette_size, width, height)
            if file_path is None:
                self.fail("Failed to generate image :\n\t-> Palette size : {}\n\t-> Width : {}\n\t-> Height : {}".format(palette_size, width, height))
            sprite_path = encode(file_path, True)
            if sprite_path is None:
                self.fail("Failed to encode image :\n\t-> Image path : {}".format(file_path))
            decoded = decode(sprite_path)
            if decoded is None:
                self.fail("Failed to decode image :\n\t-> Sprite path : {}".format(sprite_path))
            os.remove(sprite_path)
            if not compare_images(decoded, file_path):
                self.fail("Failed to compare images :\n\t-> Decoded path : {}\n\t-> Original path : {}".format(decoded, file_path))
            os.remove(decoded)
            os.remove(file_path)
            print("Test {}/35 passed".format(i), file=stderr)
if __name__ == '__main__':
    unittest.main()