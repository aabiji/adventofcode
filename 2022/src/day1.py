inputs = open("inputs/day1.txt", "r").read().split("\n")

num_sum = 0
nums = []

for i in inputs:
    if i == '':
        nums.append(num_sum)
        num_sum = 0
        continue

    num_sum += int(i)
nums.append(num_sum)

nums.sort()
print(sum([nums[-1], nums[-2], nums[-3]]))
