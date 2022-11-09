instructions = open("inputs/day8-inputs.txt", "r").read().split("\n")

registers = {}
highest_value_after, values = 0, []
for i in instructions:
    if len(registers) > 0:
        values.append(registers[ max(registers, key=registers.get) ])

    i = i.split(" ")

    x, y = int(i[2]), int(i[6])
    result_var, comp_var = i[0], i[4]

    if comp_var not in registers:
        registers[comp_var] = 0
    if result_var not in registers:
        registers[result_var] = 0

    n = -1 if i[1] == "dec" else 1
    op = i[5]

    if op == ">" and registers[comp_var] > y:
        registers[result_var] += (x * n)
    elif op == "<" and registers[comp_var] < y:
        registers[result_var] += (x * n) 
    elif op == ">=" and registers[comp_var] >= y:
        registers[result_var] += (x * n) 
    elif op == "<=" and registers[comp_var] <= y:
        registers[result_var] += (x * n) 
    elif op == "==" and registers[comp_var] == y: 
        registers[result_var] += (x * n)
    elif op == "!=" and registers[comp_var] != y:
        registers[result_var] += (x * n)

highest_value_after = registers[ max(registers, key=registers.get) ]
print(highest_value_after)
print(max(values))

# Part 1 : What's the highest value in any of the registers? Answer: 4448
# Part 2: Same thing, but during execution. Answer: 6582