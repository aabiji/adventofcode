inputs = open("../inputs/day3.txt", "r").read().split("\n")
triangles = []

for i in inputs:
    if len(i) > 0:
        i = [x for x in i.split("  ") if x != '']
        triangles.append((int(i[0]), int(i[1]), int(i[2])))

possible = lambda a, b, c: (a + b) > c and (a + c) > b and (b + c) > a

'''
part1_count = 0
for i in triangles:
    if possible(i[0], i[1], i[2]):
        part1_count += 1
'''

part2_count = 0
for i in range(0, len(triangles), 3):
    row1, row2, row3 = triangles[i], triangles[i + 1], triangles[i + 2]

    if possible(row1[0], row2[0], row3[0]):
        part2_count += 1
    if possible(row1[1], row2[1], row3[1]):
        part2_count += 1
    if possible(row1[2], row2[2], row3[2]):
        part2_count += 1

print(part2_count)
