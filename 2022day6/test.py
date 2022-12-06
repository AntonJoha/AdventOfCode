
def unique(l):
    i = l.copy()
    i.sort()
    curr = i.pop(0)
    for c in i:
        if curr == c:
            return False
        curr = c
    return True

def part1(lines):
    for l in lines:
        
        initial= []
        for i in range(0,4):
            initial.append(l[i])
        if unique(initial):
            print("4")
            return
        for i in range(4, len(l)):
            initial.pop(0)
            initial.append(l[i])
            if unique(initial):
                print(1+i)
                return


def part2(lines):
    for l in lines:
        
        initial= []
        for i in range(0,14):
            initial.append(l[i])
        if unique(initial):
            print("14")
            return
        for i in range(14, len(l)):
            initial.pop(0)
            initial.append(l[i])
            if unique(initial):
                print(1+i)
                return

    

f = open("input","r")

lines = [line.strip('\n') for line in f.readlines()]

f.close()



part1(lines)


part2(lines)



