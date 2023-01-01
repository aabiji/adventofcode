puzzle_inputs = open("../inputs/day1.txt", "r").read().split(", ")

x, y = 0, 0
rotate = [0, 1]
visited = {(0, 0)}
done = False

for d in puzzle_inputs:
    amount = int(d[1:])

    if d[0] == "L":
        rotate = [rotate[1], -rotate[0]]
    else:
        rotate = [-rotate[1], rotate[0]]

    for i in range(amount):
        x += rotate[0]
        y += rotate[1]

        # Part 2
        if (x, y) in visited:
            print(abs(x) + abs(y))
            done = True
            break

        visited.add((x, y))
    
    if done:
        break

# Part 1
# print(abs(x) + abs(y))
