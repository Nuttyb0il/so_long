import random
import os
import subprocess
import time

def generate_map(output: str, height: int, width: int, collectibles: int,
                spawn_points: int, exit_points: int, valid_borders: bool):
    if os.path.exists(output):
        os.remove(output)
    with open(output, 'a+') as f:
        for i in range(height):
            for j in range(width):
                if (i == 0 or i == height - 1 or j == 0 or j == width - 1):
                    if not valid_borders:
                        f.write(random.choice(['1', '0', 'E', 'P', 'S']))
                    else:
                        f.write('1')
                else:
                    placed_something = False
                    if collectibles > 0 and not placed_something:
                        # 1 chance out of size // 16 to spawn a collectible
                        if random.randint(1, width * height // 16) == 1:
                            f.write('C')
                            collectibles -= 1
                            placed_something = True
                    if spawn_points > 0 and not placed_something:
                        # 1 chance out of size // 16 to spawn a spawn point
                        if random.randint(1, width * height // 16) == 1:
                            f.write('P')
                            spawn_points -= 1
                            placed_something = True
                    if exit_points > 0 and not placed_something:
                        # 1 chance out of size // 16 to spawn an exit point
                        if random.randint(1, width * height // 16) == 1:
                            f.write('E')
                            exit_points -= 1
                            placed_something = True
                    if not placed_something:
                        f.write('0')
            if i != height - 1:
                f.write('\n')

def run_tests(input: str) -> bool:
    try:
        subprocess.check_output(['./checker', input])
        return 0
    except: # Non-zero = error
        return 1

# Generate 200 random sized maps with invalid borders
print("Border parsing : ⏳", end="\r")
times = []
for i in range(200):
    generate_map("test_map_%d.ber" % i,
                random.randint(10, 100),
                random.randint(10, 100),
                1,
                1,
                1,
                False)
    start = time.time()
    if run_tests("test_map_%d.ber" % i) == 0:
        print("Border parsing : 💥")
        print(f"test_map_{i}.ber was wrongly judged as valid")
        exit(1)
    else:
        os.remove("test_map_%d.ber" % i)
    times.append(time.time() - start)
print("Border parsing : ✅")
print("{:.5f} seconds per map".format(sum(times) / len(times)))
print("Max : {:.5f} seconds".format(max(times)))
print("---------------------------")

# Generate 200 squared map
print("Shape parsing : ⏳", end="\r")
times = []
for i in range(200):
    a = random.randint(8, 40)
    generate_map("test_map_%d.ber" % i,
                a,
                a,
                1,
                1,
                1,
                True)
    start = time.time()
    if run_tests("test_map_%d.ber" % i) == 0:
        print("Shape parsing : 💥")
        print(f"test_map_{i}.ber was wrongly judged as valid")
        exit(1)
    else:
        os.remove("test_map_%d.ber" % i)
    times.append(time.time() - start)
print("Shape parsing : ✅")
print("{:.5f} seconds per map".format(sum(times) / len(times)))
print("Max : {:.5f} seconds".format(max(times)))
print("Min : {:.5f} seconds".format(min(times)))
print("---------------------------")

# Generate 500 valid maps
print("False positive : ⏳", end="\r")
times = []
for i in range(500):
    a = random.randint(8, 40)
    generate_map("test_map_%d.ber" % i,
                a,
                a + random.randint(1, 30),
                random.randint(1, 3),
                1,
                1,
                True)
    start = time.time()
    if run_tests("test_map_%d.ber" % i) == 1:
        print("False positive : 💥")
        print(f"test_map_{i}.ber was wrongly judged as invalid")
        exit(1)
    else:
        os.remove("test_map_%d.ber" % i)
    times.append(time.time() - start)
print("False positive : ✅")
print("{:.5f} seconds per map".format(sum(times) / len(times)))
print("Max : {:.5f} seconds".format(max(times)))
print("Min : {:.5f} seconds".format(min(times)))
print("---------------------------")

# Generate 500 maps with missing requirements
print("False positive (alt) : ⏳", end="\r")
times = []
for i in range(500):
    a = random.randint(8, 40)
    collectibles, spawn_points, exit_points = 1, 1, 1
    r = random.randint(1, 3)
    if r == 1:
        collectibles = 0
    elif r == 2:
        spawn_points = 0
    elif r == 3:
        exit_points = 0
    generate_map("test_map_%d.ber" % i,
                a,
                a + random.randint(1, 30),
                collectibles,
                spawn_points,
                exit_points,
                True)
    start = time.time()
    if run_tests("test_map_%d.ber" % i) == 0:
        print("False positive (alt) : 💥")
        print(f"test_map_{i}.ber was wrongly judged as invalid")
        exit(1)
    else:
        os.remove("test_map_%d.ber" % i)
    times.append(time.time() - start)
print("False positive (alt) : ✅")
print("{:.5f} seconds per map".format(sum(times) / len(times)))
print("Max : {:.5f} seconds".format(max(times)))
print("Min : {:.5f} seconds".format(min(times)))
print("---------------------------")