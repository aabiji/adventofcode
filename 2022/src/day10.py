instructions = open("../inputs/day10.txt", "r").read().split("\n")
cycle = 0
X = 1
signal = 0
checks = [20, 60, 100, 140, 180, 220]

crt = [[0] * 40 for i in range(6)]
pos = [0, 0]

def cycle_through():
    global signal, crt, pos
    if cycle in checks: 
        signal += (X * cycle)
    
    if pos[0] >= 40:
        pos[1] += 1
        pos[0] = 0

    if pos[0] in range(X - 1, X + 2):
        crt[pos[1]][pos[0]] = 1

    pos[0] += 1

for i in instructions:
    if i[0:4] == "noop":
        cycle += 1
        cycle_through()
    else:
        cycle += 1
        cycle_through()
        cycle += 1
        cycle_through()
        X += int(i.split(" ")[1])

for i in crt:
    for x in i:
        if x == 0: print(" ", end="")
        else: print("#", end="")
    print()

# X  -> X position of the sprite
#   | _ _ _ |
#       ^ -> X
# if sprite horizantal position is where the sanner is, the sprites are drawn
