#lengths = [int(i) for i in open("day10-inputs.txt", "r").read().split("\n")[0].split(",")]

# Part 2
suffix = [17, 31, 73, 47, 23]
lengths = [ord(i) for i in open("day10-inputs.txt", "r").read().split("\n")[0]]
lengths += suffix

arr = [i for i in range(256)]

def reverse(position, length, arr):
    to_reverse = []
    temp_position = position
    for i in range(length):
        to_reverse.append(arr[temp_position])
        temp_position += 1
        temp_position %= len(arr)
    to_reverse = to_reverse[::-1]
    for i in to_reverse:
        arr[position] = i
        position += 1
        position %= len(arr)

    return arr

skip_size = 0
reverse_length = 0
current_position = 0
rounds = 64
i = 0

while i < rounds:
    for length in lengths:
        arr = reverse(current_position, length, arr)
        current_position += length + skip_size
        current_position %= len(arr)
        skip_size += 1
    i += 1


dense_hash = []
for i in range(0, 256, 16):
    xor_val = 0
    for i in arr[i : i + 16]:
        xor_val ^= i
    dense_hash.append(xor_val)

hex_str = ""
for i in dense_hash:
    hex_str += ''.join('{:02X}'.format(i))
print(hex_str)

# Product of multiplying first two elements after knot hash? Answer: 5577
# Knot hash? 44F4BEFB0F303C0BAFD085F97741D51D
