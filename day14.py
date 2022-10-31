from day10 import knot_hash

hex_digits = {"0":"0000", "1":"0001", "2":"0010", "3":"0011", "4":"0100",
              "5":"0101", "6":"0110", "7":"0111", "8":"1000", "9":"1001",
              "A":"1010", "B":"1011", "C":"1100", "D":"1101", "E":"1110",
              "F":"1111" }

used_count = 0
seed = "uugsqrei"
grid = []
for i in range(128):
    string_hash = seed + "-" + str(i)
    row_hash = knot_hash(string_hash)

    bin_row_hash = ""
    for x in row_hash:
        bin_row_hash += hex_digits[x]
    
    row = ['.' if i == "0" else "#" for i in bin_row_hash]
    grid.append(row)

    used_count += bin_row_hash.count("1")

def defragment(x, y):
    global grid
    if grid[y][x] != "#": return
    grid[y][x] = '.'
    if y + 1 < len(grid): defragment(x, y + 1)
    if y - 1 >= 0: defragment(x, y - 1)
    if x + 1 < len(grid[0]): defragment(x + 1, y)
    if x - 1 >= 0: defragment(x - 1, y)

groups = 0
for y in range(128):
    for x in range(128):
        if grid[y][x] == "#":
            groups += 1
            defragment(x, y)
print(groups)
# Part 1 -> How many squares are used? Answer: 8194
# Part 2 -> How many regions are there? Answer: 1141
