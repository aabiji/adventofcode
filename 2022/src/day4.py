
assignments = [x.split(",") for x in open("../inputs/day4.txt", "r").read().split("\n")]
inrange = lambda x, y: set(x) <= set(y)
def any_overlap(x: int, y: list):
    for i in y:
        if x == i:
            return True
    return False

part1_subset_count = 0
part2_subset_count = 0

for i in assignments:

    first = i[0].split("-")
    second = i[1].split("-")

    range1 = list(range(int(first[0]), int(first[1]) + 1))
    range2 = list(range(int(second[0]), int(second[1]) + 1))

    if first[0] == first[1]:
        range1 = [int(first[0])]
    elif second[0] == second[1]:
        range2 = [int(second[0])]

    if inrange(range1, range2) or inrange(range2, range1):
        part1_subset_count += 1

    for i in range1:
        if any_overlap(i, range2):
            part2_subset_count += 1
            break

print("Part 1:", part1_subset_count)
print("Part 2:", part2_subset_count)

