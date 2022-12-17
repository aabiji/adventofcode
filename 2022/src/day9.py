directions = open("../inputs/day9.txt", "r").read().split("\n")
part = 2
rope_size = 2 if part == 1 else 10
rope = [[0, 0] for i in range(rope_size)]
has_stepped = []

movements = {
    "R": lambda x, y: [x + 1, y],
    "L": lambda x, y: [x - 1, y],
    "D": lambda x, y: [x, y + 1],
    "U": lambda x, y: [x, y - 1]
}

def move_rope(head, tail, knot_index):
    global rope
    diff_x = abs(head[0] - tail[0])
    diff_y = abs(head[1] - tail[1])
    diff = diff_x + diff_y
    
    if diff > 2:
        rope[knot_index][0] += 1 if tail[0] < head[0] else -1
        rope[knot_index][1] += 1 if tail[1] < head[1] else -1

    elif diff_x == 2:
        rope[knot_index][0] += 1 if tail[0] < head[0] else -1

    elif diff_y == 2:
        rope[knot_index][1] += 1 if tail[1] < head[1] else -1
    
    has_stepped.append((rope[-1][0], rope[-1][1]))

for d in directions:
    d = d.split(" ")    

    for i in range(int(d[1])):
        rope[0] = movements[d[0]](rope[0][0], rope[0][1])
        for x in range(1, len(rope)):
            head, tail = rope[x - 1], rope[x]
            move_rope(head, tail, x)


print(len(set(has_stepped)))
