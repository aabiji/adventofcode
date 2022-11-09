# Part 1 -> Total score of group? Answer: 10616
# Part 2 -> Count of all the garbage? Answer: 5101

stream = open("day9-inputs.txt", "r").read().rstrip()

i = 0
depth, score, garbage_count = 0, 0, 0
while i < len(stream):
    c = stream[i]
    
    if c == "<":
        while c != ">":
            i += 1
            c = stream[i]
            if c == "!": 
                i += 1
            if c != ">" and c != "!":
                garbage_count += 1

    if c == "{":
        depth += 1
        score += depth
    elif c == "}":
        depth -= 1

    i += 1

print(garbage_count)
print(score)
