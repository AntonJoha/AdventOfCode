
def part1(lines, towers):

    for l in lines:
        i = l.split(" ")
        amount = int(i[1])
        src = int(i[3]) - 1
        dest = int(i[5]) -1 

        for _ in range(0, amount):
            move = towers[src].pop(0)
            towers[dest].insert(0, move)
    
    print("First: ")
    for i in towers:
        print(i[0], end='')
    print()

def part2(lines, towers):

    for l in lines:
        i = l.split(" ")
        amount = int(i[1])
        src = int(i[3]) - 1
        dest = int(i[5]) -1 

        temp = []

        for _ in range(0, amount):
            temp.append(towers[src].pop(0))

        towers[dest] = temp + towers[dest]

    print("Second: ")
    for i in towers:
        print(i[0], end='')
    print()


def get_tower():
    
    return  [ [ 'F', 'R', 'W'],
        ['P', 'W', 'V', 'D', 'C', 'M', 'H', 'T' ],
        ['L', 'N', 'Z', 'M', 'P'],
        ['R', 'H', 'C', 'J'],
        ['B', 'T', 'Q', 'H', 'G', 'P', 'C'],
        ['Z', 'F', 'L', 'W', 'C', 'G'],
        ['C', 'G', 'J', 'Z', 'Q', 'L', 'V', 'W'],
        ['C', 'V', 'T', 'W', 'F', 'R', 'N', 'P'],
        ['V', 'S', 'R', 'G', 'H', 'W', 'J']]
    '''
    return [ ['N', 'Z'],
        ['D', 'C', 'M'],
        ['P']]
    '''

f = open("input","r")

lines = [line.strip('\n') for line in f.readlines()]

f.close()


towers = get_tower()

part1(lines, towers.copy())

towers = get_tower()

part2(lines, towers.copy())



