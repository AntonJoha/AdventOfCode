

def calc_score2(l, curr):

    score = 100000000000000000
    total = 0

    for key in l:
        if type(l[key]) is dict:
            (s, t) = calc_score2(l[key], curr)
            if score > s:
                score = s
            total += t
        else:
            total += l[key]
    if total >= (30000000 - curr ) and total <= score:
        score = total
    return (score, total)


def calc_score(l):

    score = 0
    total = 0

    for key in l:
        if type(l[key]) is dict:
            (s, t) = calc_score(l[key])
            score += s
            total += t
        else:
            total += l[key]
    if total <= 100000:
        score += total
    return (score, total)

def rec_handle(lineList):

    toReturn = {}

    while len(lineList) > 0:
        curr = lineList.pop(0).split(" ")

        if curr[0] == '$':
            if curr[1] == "cd":
                if curr[2] == "..":
                    return toReturn
                else:
                    toReturn[curr[2]] = rec_handle(lineList)
        elif curr[0] != "dir":
            toReturn[curr[1]] = int(curr[0])
    return toReturn

def part1(lines):
    l = {} #Dictionary

    lineList = [i for i in lines]

    l = rec_handle(lineList)
    

    print(calc_score(l))

def part2(lines):
    
    l = {} #Dictionary

    lineList = [i for i in lines]

    l = rec_handle(lineList)
    

    space = 70000000 - calc_score(l)[1]
    print(calc_score2(l, space))

f = open("input","r")

lines = [line.strip('\n') for line in f.readlines()]

f.close()



part1(lines)


part2(lines)



