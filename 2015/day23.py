
part = 2
a, b, i = 0, 1, 0
registers = [0, 0]
registers[a] = 0 if part != 2 else 1
inputs = [i.split(" ") for i in open("day23-inputs.txt", "r").read().split("\n")][:-1]

while i < len(inputs):
    ins = inputs[i]

    op = ins[0]
    reg = ins[1].replace(",", "") == "b"
    if op == "tpl": registers[reg] *= 3
    if op == "inc": registers[reg] += 1
    if op == "hlf": registers[reg] //= 2

    if op[0] == "j":
        sign = 1 if ins[-1][0] == "+" else -1
        offset = int(ins[-1][1:]) * sign
        if op == "jmp":
            i += offset
            continue
        if op == "jio" and registers[reg] == 1:
            i += offset
            continue
        if op == "jie" and (registers[reg] % 2) == 0:
            i += offset
            continue

    i += 1

print(f"A:{registers[a]}, B:{registers[b]}")
