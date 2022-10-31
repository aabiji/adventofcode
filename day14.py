from day10 import knot_hash

hex_digits = {"0":"0000", "1":"0001", "2":"0010", "3":"0011", "4":"0100",
              "5":"0101", "6":"0110", "7":"0111", "8":"1000", "9":"1001",
              "A":"1010", "B":"1011", "C":"1100", "D":"1101", "E":"1110",
              "F":"1111" }

used_count = 0
seed = "uugsqrei"
for i in range(128):
    string_hash = seed + "-" + str(i)
    row_hash = knot_hash(string_hash)

    bin_row_hash = ""
    for x in row_hash:
        bin_row_hash += hex_digits[x]

    used_count += bin_row_hash.count("1")
print(used_count)

# Part 1 -> How many squares are used? Answer: 8194
