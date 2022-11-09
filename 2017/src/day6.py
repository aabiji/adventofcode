blocks = [int(i) for i in open("inputs/day6-inputs.txt", "r").read().split("\n")[0].split("\t")]
seen_before = []
cycle_count = 0
first_duplicate_cycle_count = 0
first_duplicate = ""

while True:
    cycle_count += 1

    highest_index = blocks.index(max(blocks))
    highest = blocks[highest_index]
    blocks[highest_index] = 0
    for i in range(highest):
        highest_index = (highest_index + 1) % len(blocks)
        blocks[highest_index] += 1
    
    if str(blocks) not in seen_before:
        seen_before.append(str(blocks))
    elif str(blocks) == first_duplicate and str(blocks) in seen_before:
        break
    elif str(blocks) in seen_before and first_duplicate == "":
        first_duplicate = str(blocks)
        first_duplicate_cycle_count = cycle_count

print(cycle_count - first_duplicate_cycle_count)

# Part 1 -> Cycle where block is already seen before: Answer: 5042
# Part 2 -> Same thing, but block is already seen twice. Answer: 1086
