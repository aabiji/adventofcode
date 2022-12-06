
puzzle_input = open("../inputs/day6.txt", "r").read().split("\n")[0]
start = 0
selection = 14

while start < len(puzzle_input):
    
    four_range = puzzle_input[start:start + selection]
    if len(four_range) == len(set(four_range)):
        break

    start += 1

print(start + selection)
