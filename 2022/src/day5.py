
inputs = open("../inputs/day5.txt", "r").read().split("\n")

split_index = inputs.index('')
instructions = inputs[split_index + 1: ]
drawing = inputs[0 :split_index]

stack = []
nums = drawing[-1]
stack_indices = [i for i in range(len(nums)) if nums[i].isdigit()]
drawing = drawing[0:len(drawing) - 1]
index = 0

for i in stack_indices:
    stack.append([])
    for line in drawing:
        if line[i] != " ":
            stack[index].append(line[i])
    
    stack[index] = stack[index][::-1]
    index += 1

for i in instructions:
    i = i.replace("move ", "")
    i = i.replace("from", "")
    i = i.replace("to", "")
    i = [x for x in i.split(" ") if x != ""]

    move_count  =  int(i[0])
    source_index = int(i[1]) - 1
    target_index = int(i[2]) - 1

    to_move = []
    for x in range(move_count):
        crate = stack[source_index].pop()
        to_move.append(crate)
    to_move = to_move[::-1]

    for crate in to_move:
        stack[target_index].append(crate)

top = ""
for i in stack:
    top += i[-1]
print(top)
