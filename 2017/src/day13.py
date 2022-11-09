recordings = open("inputs/day13-inputs.txt", "r").read().split("\n")

# Part 1 : Severity of getting caught.
# Part 2: Number of delays that the packet won't get caught? Answer: 3849742

#total = 0
delay = 0
ok = False

while not ok:
    ok = True
    for i in recordings:
        i = i.split(": ")
        layer, depth = int(i[0]), int(i[1])
    
        #if layer % ((depth - 1) * 2) == 0:
            #total += layer * depth
        if (layer + delay) % (2 * depth - 2) == 0:
            ok = False
            delay += 1
            break

print(delay)
