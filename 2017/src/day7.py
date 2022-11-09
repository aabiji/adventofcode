listing = [i for i in open("inputs/day7-inputs.txt", "r").read().split("\n")]

prev = {}
weights = {}
tower = {}
for i in listing:
    i = i.split(" ")
    weight = int(i[1].replace(")", "").replace("(", ""))
    weights[i[0]] = weight
    if "->" in i:
        tower[i[0]] = [x.replace(",", "") for x in i[3:]]
    else:
        tower[i[0]] = weight
listing = tower

def build(node):
    global prev
    if type(listing[node]) == int:
        return listing[node]

    children = {}
    for i in listing[node]:
        children[i] = listing[i]
        prev[i] = node

    return children

def part1():
    tower = {}
    for i in listing:
        tower[i] = build(i)

    # Part 1 : What is the base of the tower? Answer: aapssr 
    n = list(prev.keys())[0]
    while n in prev:
        n = prev[n]
    return tower, n

# Part 2 -> What should actual weight of a faulty weight be? Answer: 1458
tower, root = part1()
def get_weight(node):
    base_weight = weights[node]
    if type(tower[node]) == int:
        return base_weight
    for child in tower[node]:
        base_weight += get_weight(child)

    return base_weight

import collections
def get_offset(node, val, shouldbe):
    subtowers = {}
    for i in tower[node]:
        subtowers[i] = get_weight(i)

    ordering = collections.Counter(subtowers.values()).most_common()
    at_fault = ""
    for i in subtowers:
        if subtowers[i] == ordering[-1][0]:
            at_fault = i
    val, shouldbe = ordering[-1][0], ordering[0][0]
    
    get_offset(at_fault, val, shouldbe)

print(get_offset(root, 0, 0))
# node at fault -> tlskukk
# should be 1486 | 1486 - get_weight("tlskukk") = 1458
