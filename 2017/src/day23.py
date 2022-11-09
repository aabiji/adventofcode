inputs = open("inputs/day23-inputs.txt", "r").read().split("\n")

# Part 1 -> How many times is the mul instruction called? Answer: 3969
registers = {"a":0, "b":0, "c":0, "d":0, "e":0, "f":0, "g":0, "h":0}
mul_count, i = 0, 0
while i < len(inputs):
    instruction = inputs[i].split(" ")

    x, y = instruction[1], instruction[2]
    if y not in registers: y = int(y)
    else: y = registers[y]

    if instruction[0] == "set":
        registers[x] = y
    elif instruction[0] == "sub":
        registers[x] = registers[x] - y
    elif instruction[0] == "mul":
        registers[x] = registers[x] * y
        mul_count += 1
    elif instruction[0] == "jnz":
        condition = registers[x] if x in registers else int(x)
        if condition != 0:
            i += y
            continue
    i += 1
print(mul_count)

# Part 2 -> Running the program to completion and changing a to 1, what's the value left in register h?
def is_prime(n):
    if n <= 3: return n > 1
    if not n % 2 or not n % 3: return False
    i, stop = 5, int(n ** 0.5)
    while i <= stop:
        if not n % i or not n % (i + 2):
            return False
        i += 6
    return True

h, a, b = 0, 106500, 123500
jmp_offset = 17
for i in range(a, b + 1, jmp_offset):
    if not is_prime(i): h += 1
print(h)