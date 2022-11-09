directions = [i for i in open("inputs/day11-inputs.txt", "r").read().split("\n")[0].split(",")]

steps = {(0, 0):0}
x, y = 0, 0
for i in directions:
    if i == "n":
        y -= 1
    elif i == "s":
        y += 1
    elif i == "nw":
        x -= 1
        y -= 1
    elif i == "ne":
        x += 1
    elif i == "sw":
        x -= 1
    elif i == "se":
        x += 1
        y += 1

    steps[(x, y)] = (abs(x) + abs(y) + abs(x - y)) / 2

print(steps[max(steps, key=steps.get)]) # Part 2 -> How many steps was the furthest it ever got? Answer: 1406
distance = (abs(x) + abs(y) + abs(x - y)) / 2 # Part 1 -> How many stpes? Answer: 682
print(distance)
