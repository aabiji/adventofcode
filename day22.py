
infection_map = open("inputs/day22-inputs.txt", "r").read().split("\n")
middle_x, middle_y = len(infection_map[0]) // 2, len(infection_map) // 2
infections, current_node = {}, (0, 0)
for y in range(len(infection_map)):
    for x in range(len(infection_map[0])):
        if infection_map[y][x] == "#":
            infections[(x - middle_x, y - middle_y)] = "infected"

rotate_index = 0
directions = [[0, 1], [-1, 0], [0, -1], [1, 0]]
def turn(direction):
    global rotate_index, directions
    rotate_index += 1 if direction == "left" else -1
    rotate_index %= len(directions)

def work():
    global current_node, infections, directions
    if current_node in infections:
        turn("right")
        del infections[current_node]
        i = 0
    else:
        turn("left")
        infections[current_node] = 1
        i = 1
    r = directions[rotate_index]
    current_node = (current_node[0] + r[0], current_node[1] - r[1])
    
    return i


def evolved():
    global current_node, infections, rotate_index
    if current_node not in infections:
        infections[current_node] = "clean"

    state = infections[current_node]
    i = 0

    if state == "clean":
        turn("left")
        infections[current_node] = "weak"
    elif state == "weak":
        infections[current_node] = "infected"
        i = 1
    elif state == "infected":
        turn("right")
        infections[current_node] = "flag"
    elif state == "flag":
        rotate_index += 2 if rotate_index < 2 else -2
        rotate_index %= len(directions)

        infections[current_node] = "clean"

    r = directions[rotate_index]
    current_node = (current_node[0] + r[0], current_node[1] - r[1])

    return i

caused_infection, spurts = 0, 10000000
for i in range(spurts):
    caused_infection += evolved()

print(caused_infection)

# Part 1: Given 10000 spurts, how many spurts result in nodes being infected? 5259 
# Part 2: Same idea, 10000000 spurts, different rules. Answer: 2511722
