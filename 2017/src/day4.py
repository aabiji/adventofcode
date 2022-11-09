phrases = [i.split(" ") for i in open("inputs/day4-inputs.txt", "r").read().split("\n")]

valid_count = 0
for phrase in phrases:
    is_valid = True
    words = []
    for i in phrase:
        freq = {}
        for x in i:
            freq[x] = 1 if x not in freq else freq[x] + 1
        freq = {key : value for key, value in sorted(freq.items())}
        
        if str(freq) in words:
            is_valid = False
            break
        else:
            words.append(str(freq))

        '''
        if phrase.count(i) > 1:
            is_valid = False
            break
        '''
    if is_valid:
        valid_count += 1
print(valid_count)

# Part 1 -> Valid phrases? Answer: 337
# Part 2 -> Same thing as part 1, different rules? Answer: 231
