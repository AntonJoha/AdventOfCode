


def dupe(low1, high1, low2, high2):

    l1 = [i for i in range(low1, high1 + 1)]
    l2 = [i for i in range(low2, high2 + 1)]
    
    l = l1 + l2
    l.sort()

    current = 0
    for i in l:
        if i == current:
            return True
        current = i
    return False

def part1(lines):
    total = 0

    for l in lines:
        a = l.split(',')
        low1 = int(a[0].split('-')[0])
        high1 = int(a[0].split('-')[1])
        low2 = int(a[1].split('-')[0])
        high2 = int(a[1].split('-')[1])

        if low1 <= low2 and high1 >= high2: 
            total += 1
        elif low2 <= low1 and high2 >= high1:
            total += 1
    print("First: ", total)


def part2(lines):
    total = 0
    for l in lines:
        a = l.split(',')
        low1 = int(a[0].split('-')[0])
        high1 = int(a[0].split('-')[1])
        low2 = int(a[1].split('-')[0])
        high2 = int(a[1].split('-')[1])
        
        if dupe(low1, high1, low2, high2):
            total += 1
    
    print("Second: ", total)

f = open("input","r")

lines = [line.strip('\n') for line in f.readlines()]

f.close()

part1(lines)
part2(lines)


