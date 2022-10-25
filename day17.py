
step = 363
cbuffer = [0]
current_position = 0
index = 1
part = 2
spins = 2017 

# What's the value after 2017 in the circular buffer? Answer: 136
for inserted_value in range(1, spins + 1):
    index += step
    if index > len(cbuffer) - 1:
        index = index % len(cbuffer)

    cbuffer = cbuffer[0 : index + 1] + [inserted_value] + cbuffer[index + 1: ]

    current_position = index + 1
    index += 1
print(cbuffer[cbuffer.index(2017) + 1])

# What's the value after 0 after 50000000 iterations? Answer: 1080289
second, current_position, second = -1, 0, 0
for i in range(1, 50000000 + 1):
    current_position = (current_position + step) % i + 1
    if current_position == 1:
        second = i
print(second)
