import random
import unittest
import subprocess
import shutil
import string
import os

CHARSET = string.ascii_letters + string.digits

def generate_invalid_walls(n: int) -> str:
	"""
	Generate a string representing invalid walls for so_long map
	:param n: Number of walls
	"""
	output = ""
	payload = random.randint(1, 3)
	if payload == 1:
		# Generate walls with invalid characters
		possibilites = ["0", "Y", "E"]
		for _ in range(n):
			output += random.choice(possibilites)
	elif payload == 2:
		# Generate a (n-x) wall where X is a random number between 1 and n
		x = random.randint(1, n)
		output += "1" * x + "0" * (n - x)
	elif payload == 3:
		# Generate a (n+x) wall where X is a random number between 1 and n
		x = random.randint(1, n)
		output += "0" * x + "1" * (n + x)
	return output

def get_random_index(s: str) -> int:
	"""
	Returns the index of a random 0 in the map
	Pick first one if n < 3
	:param s: Map to search in
	"""
	if s.count("0") < 3:
		return s.find("0")
	while True:
		i = random.randint(0, len(s) - 1)
		if s[i] == "0":
			return i

def generate_map(height: int = 10, width: int = 10,
			collectibles: int = 1, spawns: int = 1, exits: int = 1,
			valid_walls: bool = True) -> str:
	"""
	Generate a so_long map with passed parameters
	:param height: Height of the map
	:param width: Width of the map
	:param collectibles: Collectibles to place (>= 0)
	:param spawns: Spawn points to place (>= 0)
	:param exits: Exit points to place (>= 0)
	:param valid_walls: Surround properly (or not) the generated map by walls
	"""
	output = ""
	if valid_walls:
		output += "1" * width + "\n"
	else:
		output += generate_invalid_walls(width) + "\n"
	for _ in range(width):
		output += "1" + "0" * (width - 2) + "1" + "\n"
	if valid_walls:
		output += "1" * width + "\n"
	else:
		output += generate_invalid_walls(width) + "\n"
	# Place collectibles, spawns and exits randomly
	for _ in range(collectibles):
		pos = get_random_index(output)
		output = output[:pos] + "C" + output[pos + 1:]
	for _ in range(spawns):
		pos = get_random_index(output)
		output = output[:pos] + "P" + output[pos + 1:]
	for _ in range(exits):
		pos = get_random_index(output)
		output = output[:pos] + "E" + output[pos + 1:]
	return output

def random_string(length=12):
	return ''.join(random.choice(CHARSET) for _ in range(length))

def save_map(s: str) -> str:
	"""
	Save the map to a temporary file
	:param s: Map to save
	:return: Path to the file
	"""
	path = f"tmp/{random_string()}.ber"
	with open(path, "w+") as f:
		f.write(s)
	return path
	

class TestSmallValidMaps(unittest.TestCase):
	def test_3x3_valid_maps(self):
		"""
		Test small valid maps
		"""
		for _ in range(20):
			path = save_map(generate_map(3, 3))
			try:
				subprocess.check_output(["../so_long", path],
					stderr=subprocess.STDOUT)
				os.remove(path)
			except subprocess.CalledProcessError:
				os.remove(path)
				self.fail("Map was parsed as invalid, but it should be valid")
	def test_5x5_valid_maps(self):
		"""
		Test small valid maps
		"""
		for _ in range(20):
			path = save_map(generate_map(5, 5))
			try:
				subprocess.check_output(["../so_long", path],
					stderr=subprocess.STDOUT)
				os.remove(path)
			except subprocess.CalledProcessError:
				os.remove(path)
				self.fail("Map was parsed as invalid, but it should be valid")
	def test_10x10_valid_maps(self):
		"""
		Test small valid maps
		"""
		for _ in range(20):
			path = save_map(generate_map(10, 10))
			try:
				subprocess.check_output(["../so_long", path],
					stderr=subprocess.STDOUT)
				os.remove(path)
			except subprocess.CalledProcessError:
				os.remove(path)
				self.fail("Map was parsed as invalid, but it should be valid")
class TestSmallInvalidMaps(unittest.TestCase):
	def test_3x3_invalid_maps_0(self):
		"""
		Test small invalid maps
		Batch 0 : Tests with invalid walls
		"""
		for _ in range(20):
			path = save_map(generate_map(3, 3, valid_walls=False))
			try:
				subprocess.check_output(["../so_long", path],
					stderr=subprocess.STDOUT)
				os.remove(path)
				self.fail("Map was parsed as valid, but it should be invalid")
			except subprocess.CalledProcessError:
				os.remove(path)
	def test_3x3_invalid_maps_1(self):
		"""
		Test small invalid maps
		Batch 1 : Tests with invalid exit points
		"""
		for _ in range(20):
			path = save_map(generate_map(3, 3, exits=0))
			try:
				subprocess.check_output(["../so_long", path],
					stderr=subprocess.STDOUT)
				os.remove(path)
				self.fail("Map was parsed as valid, but it should be invalid")
			except subprocess.CalledProcessError:
				os.remove(path)
	def test_3x3_invalid_maps_2(self):
		"""
		Test small invalid maps
		Batch 2 : Tests with invalid collectibles
		"""
		for _ in range(20):
			path = save_map(generate_map(3, 3, collectibles=0))
			try:
				subprocess.check_output(["../so_long", path],
					stderr=subprocess.STDOUT)
				os.remove(path)
				self.fail("Map was parsed as valid, but it should be invalid")
			except subprocess.CalledProcessError:
				os.remove(path)
	def test_3x3_invalid_maps_3(self):
		"""
		Test small invalid maps
		Batch 3 : Tests with spawn points
		"""
		for _ in range(20):
			path = save_map(generate_map(3, 3, spawns=0))
			try:
				subprocess.check_output(["../so_long", path],
					stderr=subprocess.STDOUT)
				os.remove(path)
				self.fail("Map was parsed as valid, but it should be invalid")
			except subprocess.CalledProcessError:
				os.remove(path)
	def test_10x10_invalid_maps_0(self):
		"""
		Test small invalid maps
		Batch 0 : Tests with invalid walls
		"""
		for _ in range(20):
			path = save_map(generate_map(10, 10, valid_walls=False))
			try:
				subprocess.check_output(["../so_long", path],
					stderr=subprocess.STDOUT)
				os.remove(path)
				self.fail("Map was parsed as valid, but it should be invalid")
			except subprocess.CalledProcessError:
				os.remove(path)
	def test_10x10_invalid_maps_1(self):
		"""
		Test small invalid maps
		Batch 1 : Tests with invalid exit points
		"""
		for _ in range(20):
			path = save_map(generate_map(10, 10, exits=0))
			try:
				subprocess.check_output(["../so_long", path],
					stderr=subprocess.STDOUT)
				os.remove(path)
				self.fail("Map was parsed as valid, but it should be invalid")
			except subprocess.CalledProcessError:
				os.remove(path)
	def test_10x10_invalid_maps_2(self):
		"""
		Test small invalid maps
		Batch 2 : Tests with invalid collectibles
		"""
		for _ in range(20):
			path = save_map(generate_map(10, 10, collectibles=0))
			try:
				subprocess.check_output(["../so_long", path],
					stderr=subprocess.STDOUT)
				os.remove(path)
				self.fail("Map was parsed as valid, but it should be invalid")
			except subprocess.CalledProcessError:
				os.remove(path)
	def test_10x10_invalid_maps_3(self):
		"""
		Test small invalid maps
		Batch 3 : Tests with spawn points
		"""
		for _ in range(20):
			path = save_map(generate_map(10, 10, spawns=0))
			try:
				subprocess.check_output(["../so_long", path],
					stderr=subprocess.STDOUT)
				os.remove(path)
				self.fail("Map was parsed as valid, but it should be invalid")
			except subprocess.CalledProcessError:
				os.remove(path)
	
class TestBigValidMaps(unittest.TestCase):
	def test_30x30_valid_maps(self):
		"""
		Test big valid maps
		"""
		for _ in range(20):
			path = save_map(generate_map(30, 30))
			try:
				subprocess.check_output(["../so_long", path],
					stderr=subprocess.STDOUT)
				os.remove(path)
			except subprocess.CalledProcessError:
				os.remove(path)
				self.fail("Map was parsed as invalid, but it should be valid")
	def test_20x50_valid_maps(self):
		"""
		Test big valid maps
		"""
		for _ in range(20):
			path = save_map(generate_map(20, 50))
			try:
				subprocess.check_output(["../so_long", path],
					stderr=subprocess.STDOUT)
				os.remove(path)
			except subprocess.CalledProcessError:
				os.remove(path)
				self.fail("Map was parsed as invalid, but it should be valid")
	def test_nxn_valid_maps(self):
		"""
		Test big valid maps
		"""
		for _ in range(20):
			path = save_map(generate_map(random.randint(10, 35), random.randint(10, 35)))
			try:
				subprocess.check_output(["../so_long", path],
					stderr=subprocess.STDOUT)
				os.remove(path)
			except subprocess.CalledProcessError:
				os.remove(path)
				self.fail("Map was parsed as invalid, but it should be valid")

class TestBigInvalidMaps(unittest.TestCase):
	def test_30x30_invalid_maps_0(self):
		"""
		Test small invalid maps
		Batch 0 : Tests with invalid walls
		"""
		for _ in range(20):
			path = save_map(generate_map(30, 30, valid_walls=False))
			try:
				subprocess.check_output(["../so_long", path],
					stderr=subprocess.STDOUT)
				os.remove(path)
				self.fail("Map was parsed as valid, but it should be invalid")
			except subprocess.CalledProcessError:
				os.remove(path)
	def test_30x30_invalid_maps_1(self):
		"""
		Test small invalid maps
		Batch 1 : Tests with invalid exit points
		"""
		for _ in range(20):
			path = save_map(generate_map(30, 30, exits=0))
			try:
				subprocess.check_output(["../so_long", path],
					stderr=subprocess.STDOUT)
				os.remove(path)
				self.fail("Map was parsed as valid, but it should be invalid")
			except subprocess.CalledProcessError:
				os.remove(path)
	def test_30x30_invalid_maps_2(self):
		"""
		Test small invalid maps
		Batch 2 : Tests with invalid collectibles
		"""
		for _ in range(20):
			path = save_map(generate_map(30, 30, collectibles=0))
			try:
				subprocess.check_output(["../so_long", path],
					stderr=subprocess.STDOUT)
				os.remove(path)
				self.fail("Map was parsed as valid, but it should be invalid")
			except subprocess.CalledProcessError:
				os.remove(path)
	def test_30x30_invalid_maps_3(self):
		"""
		Test small invalid maps
		Batch 3 : Tests with spawn points
		"""
		for _ in range(20):
			path = save_map(generate_map(30, 30, spawns=0))
			try:
				subprocess.check_output(["../so_long", path],
					stderr=subprocess.STDOUT)
				os.remove(path)
				self.fail("Map was parsed as valid, but it should be invalid")
			except subprocess.CalledProcessError:
				os.remove(path)
	def test_20x50_invalid_maps_0(self):
		"""
		Test small invalid maps
		Batch 0 : Tests with invalid walls
		"""
		for _ in range(20):
			path = save_map(generate_map(20, 50, valid_walls=False))
			try:
				subprocess.check_output(["../so_long", path],
					stderr=subprocess.STDOUT)
				os.remove(path)
				self.fail("Map was parsed as valid, but it should be invalid")
			except subprocess.CalledProcessError:
				os.remove(path)
	def test_20x50_invalid_maps_1(self):
		"""
		Test small invalid maps
		Batch 1 : Tests with invalid exit points
		"""
		for _ in range(20):
			path = save_map(generate_map(20, 50, exits=0))
			try:
				subprocess.check_output(["../so_long", path],
					stderr=subprocess.STDOUT)
				os.remove(path)
				self.fail("Map was parsed as valid, but it should be invalid")
			except subprocess.CalledProcessError:
				os.remove(path)
	def test_20x50_invalid_maps_2(self):
		"""
		Test small invalid maps
		Batch 2 : Tests with invalid collectibles
		"""
		for _ in range(20):
			path = save_map(generate_map(20, 50, collectibles=0))
			try:
				subprocess.check_output(["../so_long", path],
					stderr=subprocess.STDOUT)
				os.remove(path)
				self.fail("Map was parsed as valid, but it should be invalid")
			except subprocess.CalledProcessError:
				os.remove(path)
	def test_20x50_invalid_maps_3(self):
		"""
		Test small invalid maps
		Batch 3 : Tests with spawn points
		"""
		for _ in range(20):
			path = save_map(generate_map(20, 50, spawns=0))
			try:
				subprocess.check_output(["../so_long", path],
					stderr=subprocess.STDOUT)
				os.remove(path)
				self.fail("Map was parsed as valid, but it should be invalid")
			except subprocess.CalledProcessError:
				os.remove(path)

if __name__ == "__main__":
	unittest.main()