# Part 1 : What's the value of the first sound recoverd? Answer: 3423
# Part 2: Instructions now run in parallel, how many times does program 1 send? Answer: 7493

instructions = open("day18-inputs.txt", "r").read().split("\n")

def return_registers():
    registers = {}
    for i in range(97, 122 + 1):
        registers[chr(i)] = 0
    return registers
registers = {0 : return_registers(), 1 : return_registers()}
registers[1]['p'] = 1
recv_queue = [[], []]

def value_of(program_id, s):
    if s not in registers[program_id]:
        return int(s)
    else:
        return registers[program_id][s]

send_count = 0
def execute(index, p_id):
    global send_count
    no_deadlock = True
    while index < len(instructions):
        i = instructions[index].split(" ")
        x = i[1]
        y = i[2] if len(i) == 3 else 0

        if i[0] == "set": registers[p_id][x] = value_of(p_id, y)
        if i[0] == "add": registers[p_id][x] += value_of(p_id, y)
        if i[0] == "mul": registers[p_id][x] *= value_of(p_id, y)
        if i[0] == "mod": registers[p_id][x] %= value_of(p_id, y)
        if i[0] == "jgz" and value_of(p_id, x) > 0:
            index += value_of(p_id, y)
            continue
        if i[0] == "snd":
            recv_queue[~p_id].append(value_of(p_id, x))
            send_count += 1 if p_id == 1 else 0
        if i[0] == "rcv":
            if len(recv_queue[p_id]) > 0:
                val = recv_queue[p_id][0]
                recv_queue[p_id] = recv_queue[p_id][1:]
                registers[p_id][x] = val
            else:
                no_deadlock = False
                break
        index += 1
    return index, no_deadlock

program0_index, program1_index = 0, 0
program0_deadlock, program1_deadlock = True, True
while True:
    program0_index, program0_deadlock = execute(program0_index, 0)
    program1_index, program1_deadlock = execute(program1_index, 1)

    if len(recv_queue[0]) == 0 and len(recv_queue[1]) == 0:
        break

for i in registers:
    print(registers[i])
for i in recv_queue:
    print(i)
print(send_count)