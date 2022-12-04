

def find_common_l(first, second):
    l1 = first
    l2 = second
    if len(first) < len(second):
        l1 = second
        l2 = first

    pos = 0
    results = []
    for c in l2:
        while ord(c) > ord(l1[pos]):
            pos += 1
            if pos >= len(l1):
                return results 
        if ord(c) == ord(l1[pos]):
            results.append(c)
    return results




def part1(lines):
    total = 0

    for l in lines:
        first = sorted(l[slice(0,len(l)//2)])
        second = sorted(l[slice(len(l)//2, len(l))])
    
        c = find_common(first, second)
    
        total += calc_score(c)

    print(total)

def part2(lines):

    total = 0

    while len(lines) > 0:
        first = sorted(lines.pop())
        second = sorted(lines.pop())
        third = sorted(lines.pop())

        list1 = find_common_l(first, second)
        list2 = find_common_l(second, third)
        

        res = find_common(list1, list2)
        total +=  calc_score(res)

    print(total)

def find_common(first, second):
    pos = 0
    for c in second:
        while ord(c) > ord(first[pos]):
            pos += 1
        if ord(c) == ord(first[pos]):
            return c
 
def calc_score(c):
    if c.islower():
        return ord(c) - ord('a') + 1
    else:
        return ord(c) - ord('A') + 1 + 26

f = open("input","r")

lines = [line.strip('\n') for line in f.readlines()]

f.close()

part1(lines)
part2(lines)


