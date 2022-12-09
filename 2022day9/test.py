

def calc_moves(lines):
    
    offset = {}
    offset["R"] = [0,1]
    offset["U"] = [-1, 0]
    offset["L"] = [0, -1]
    offset["D"] = [1,0]

    start = [0,0]

    to_return = []
    to_return.append(start.copy())
    

    for l in lines:
        values = l.split(" ")
        o = offset[values[0]]
        for i in range(0, int(values[1])):
            start[0] = start[0] + o[0]
            start[1] = start[1] + o[1]
            to_return.append(start.copy())


    return to_return

def touching(tail, move):
    x = tail[0] - move[0]
    y = tail[1] - move[1]
    z = x*x + y*y
    if z > 2:
        return False
    return True

def new_pos(tail, move):
    x = 0
    y = 0
    if tail[0] < move[0]:
        x = 1
    if tail[0] > move[0]:
        x = -1
    if tail[1] < move[1]:
        y = 1
    if tail[1] > move[1]:
        y = -1

    return [tail[0] + x, tail[1] + y]


def calc_tail(moves):
    
    tail = [0,0]
    to_return = {}
    pos = []
    to_return["%d,%d" % (tail[0],tail[1])] = 1

    for move in moves:
        if touching(tail, move) == False:
            tail = new_pos(tail, move)
            to_return["%d,%d" % (tail[0],tail[1])] = 1
        pos.append(tail.copy())

    return to_return, pos

def part1(lines):

    moves = calc_moves(lines)


    tail_pos = calc_tail(moves)

    print(len(tail_pos))


def part2(lines):

    moves = calc_moves(lines)

    tail_pos = {}
    for i in range(0,9):
        tail_pos, moves = calc_tail(moves)

    print(len(tail_pos))






f = open("input","r")

lines = [line.strip('\n') for line in f.readlines()]

f.close()



part1(lines)


part2(lines)



