

gen_a_factor, gen_b_factor = 16807, 48271
divider = 2147483647
gen_a, gen_b = 591, 393
match_count = 0
part = 2
iterations = 40000000 if part == 1 else 5000000

for i in range(iterations):
    while True:
        gen_a = (gen_a * gen_a_factor) % divider
        if (gen_a % 4) == 0:
            break
    while True:
        gen_b = (gen_b * gen_b_factor) % divider
        if (gen_b % 8) == 0:
            break

    if (gen_a & 0xFFFF) == (gen_b & 0xFFFF):
        match_count += 1
print(match_count)

# How many times do the 2 generator outputs lower 16 bits match? Answer: 619
