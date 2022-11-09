inputs = open("inputs/day19-inputs.txt", "r").read().split("\n")

x, y = inputs[0].index("|"), 0
direction = "d"
visited = ""

# Part 1 -> Letters it visits? Answer: EPYDUXANIT
# Part 2 -> Number of steps it takes to visit? Answer: 17544

i = 0
while i < 17544:
    if inputs[y][x].isalpha():
        visited += inputs[y][x]

    if direction == "d":
        y += 1
    elif direction == "u":
        y -= 1
    if direction == "l":
        x -= 1
    elif direction == "r":
        x += 1 

    if inputs[y][x] == "+" and (direction == "u" or direction == "d"):
        possible_directions = ["l", "r"]
        for d in possible_directions:
            if d == "l" and (x - 1) >= 0:
                if inputs[y][x - 1] != " ":
                    direction = d
            elif d == "r" and (x + 1) < len(inputs[0]):
                if inputs[y][x + 1] != " ":
                    direction = d

    elif inputs[y][x] == "+" and (direction == "l" or direction == "r"):
        possible_directions = ["d", "u"]
        for d in possible_directions:
            if d == "u" and (y - 1) >= 1:
                if inputs[y - 1][x] != " ":
                    direction = d
            elif d == "d" and (y + 1) < len(inputs):
                if inputs[y + 1][x] != " ":
                    direction = d
    
    i += 1
print(visited, i)
