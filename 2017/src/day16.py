moves = [i for i in open("inputs/day16-inputs.txt", "r").read().split("\n")[0].split(",")]

dancers = list("abcdefghijklmnop")

def dance():
    global dancers
    for i in moves:
        if i[0] == "s":
            x = int(i[1:])
            dancers = dancers[-x:] + dancers[:-x]
        elif i[0] == "x":
            i = i[1:].split("/")
            x, y = int(i[0]), int(i[1])
            x1, y1 = dancers[x], dancers[y]
            dancers[x], dancers[y] = y1, x1
        elif i[0] == "p":
            i = i[1:].split("/")
            x, y = dancers.index(i[0]), dancers.index(i[1])
            x1, y1 = dancers[x], dancers[y]
            dancers[x], dancers[y] = y1, x1

# Part 2 -> Final arrangement of dancers after 1000000000 dances? Answer: bpcekomfgjdlinha
pattern = {}
for i in range(48):
    pattern[i] = ''.join(dancers)
    dance()

i = 1000000000 % 48
print(pattern[i])

# Part 1 -> Final arrangement of dancers? Answer: ehdpincaogkblmfj
#print(''.join(dancers))
