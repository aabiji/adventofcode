# Part 1 -> How many cells were one on the tape? Answer: 3578
tape = {}
cursor = 0
state = "A"
steps = 12861455

def get(cursor):
    if cursor not in tape:
        tape[cursor] = 0
    return tape[cursor]

def step():
    global cursor, tape, state
    
    if state == "A":
        if get(cursor) == 0:
            tape[cursor] = 1
            cursor += 1
            state = "B"
        else:
            tape[cursor] = 0
            cursor -= 1
            state = "B"
    elif state == "B":
        if get(cursor) == 0:
            tape[cursor] = 1
            cursor -= 1
            state = "C"
        else:
            tape[cursor] = 0
            cursor += 1
            state = "E"
    elif state == "C":
        if get(cursor) == 0:
            tape[cursor] = 1
            cursor += 1
            state = "E"
        else:
            tape[cursor] = 0
            cursor -= 1
            state = "D"
    elif state == "D":
        tape[cursor] = 1
        cursor -= 1
        state = "A"
    elif state == "E":
        if get(cursor) == 0:
            tape[cursor] = 0
            cursor += 1
            state = "A"
        else:
            tape[cursor] = 0
            cursor += 1
            state = "F"
    elif state == "F":
        if get(cursor) == 0:
            tape[cursor] = 1
            cursor += 1
            state = "E"
        else:
            tape[cursor] = 1
            cursor += 1
            state = "A"


checksum = 0
for i in range(steps):
    step()
for i in tape:
    if tape[i] == 1: checksum += 1
print(checksum)
