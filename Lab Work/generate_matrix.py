import random

sizes = [2, 4, 8, 16, 32]

with open("input.txt", "w") as f:
    f.write(f"{len(sizes)}\n")
    for size in sizes:
        f.write(f"{size}\n")
        for _ in range(size):
            row = [str(random.randint(1, 10)) for _ in range(size)]
            f.write(" ".join(row) + "\n")
        for _ in range(size):
            row = [str(random.randint(1, 10)) for _ in range(size)]
            f.write(" ".join(row) + "\n")