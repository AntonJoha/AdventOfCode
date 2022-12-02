

def winner(a,b):
    if a == b:
        return 0
    if a == "A" and b == "C":
        return -1
    if a == "B" and b == "A":
        return -1
    if a == "C" and b == "B":
        return -1
    return 1
def convert(a):
    if a == "Y":
        return "B"
    if a == "X":
        return "A"
    return "C"

def score_add(a):
    if a == "A":
        return 1
    if a == "B":
        return 2
    if a == "C":
        return 3


def calc(elf, you):
    opt = ord(you[0]) - ord('Y')

    options = ["X", "Y", "Z"]

    for o in options:
        a = convert(o)
        if winner(elf, a) == opt:
            return a

f = open("input","r")

lines = [line for line in f.readlines()]

f.close()

total = 0

for l in lines:
    options = l.split(" ")
    elf = options[0]
    you = options[1].strip("\n")

    you = calc(elf, you)

    total += 3*(winner(elf,you) + 1)
    total += score_add(you)

print(total)

