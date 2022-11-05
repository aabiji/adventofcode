
def par1():
    # Part 1 -> Manhattan distance from position to center? Answer: 438
    n = 265149
    i = 1
    while i * i < n:
        i += 2

    pivots = [i * i - k*(i - 1) for k in range(4)]
    for p in pivots:
        dist = abs(p - n)
        if dist <= (i - 1) // 2:
            print(i - 1 - dist)
            break

# First value added to spiral that bigger than input? Answer: 266330 
def part2():
    inp = 265149
    def next_coords(x, y):
        if x == y == 0: return (1, 0)
        if y > -x and x > y: return (x, y+1)
        if y > -x and y >= x: return (x-1, y)
        if y <= -x and x < y: return (x, y-1)
        if y <= -x and x >= y: return (x+1, y)

    x, y = 0, 0
    vals = { (0, 0): 1 }
    while vals[(x, y)] <= inp:
        x, y = next_coords(x, y)
        vals[(x, y)] = sum(vals.get((x+i, y+j), 0) for i in [-1, 0, 1] for j in [0, 1, -1])
    print(vals[(x, y)])

part2()
