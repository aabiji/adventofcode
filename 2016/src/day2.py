inputs = open("../inputs/day2.txt", "r").read().split("\n")
inputs = [i for i in inputs if len(i) > 0]

x, y = 0, 2
grid = [
    [0,  0,  1,   0,  0],
    [0,  2,  3,   4,  0],
    [5,  6,  7,   8,  9],
    [0, "A", "B","C", 0],
    [0,  0,  "D", 0,  0]
]

code = ""

for line in inputs:
    for i in line:
        if i == "L":
            x = x - 1 if (x - 1 )>= 0 and grid[y][x - 1] != 0 else x
        elif i == "R":
            x = x + 1 if (x + 1) <= 4 and grid[y][x + 1] != 0 else x
        elif i == "U":
            y = y - 1 if (y - 1) >= 0 and grid[y - 1][x] != 0 else y
        else:
            y = y + 1 if (y + 1) <= 4 and grid[y + 1][x] != 0 else y
    
    code += str(grid[y][x])

print(code)
