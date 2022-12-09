

def make_matrix(lines):
    to_return = []

    for l in lines:
        curr = []
        for c in range(0, len(l)):
            curr.append(int(l[c]))
        to_return.append(curr)
    return to_return


def in_bounds(i, j,heigth, width, offset, mult):
    new_i = offset[0] * mult + i
    new_j = offset[1] * mult + j
    if new_i < 0 or new_j < 0 or new_j >= width or new_i >= heigth:
        return False
    return True

def check_direction(matrix, i, j, offset):
    heigth = len(matrix)
    width = len(matrix[0])

    mult = 1
    val = matrix[i][j]

    while in_bounds(i, j, heigth, width, offset, mult):
        if matrix[i + offset[0]*mult][j + offset[1]*mult] >= val:
            return False
        mult += 1
    return True

def safe(matrix, i, j):
    offset= [
        #(-1, -1),
        (0, -1),
        #(1, -1),
        (-1, 0),
        (1, 0),
        #(-1, 1),
        (0, 1),
        #(1, 1)
    ]
    
    val = matrix[i][j] 

    if val == 10:
        return True

    for o in offset:
        if check_direction(matrix, i, j, o):
            return True
    return False


def part1(matrix):
    
    

    heigth = len(matrix)
    width = len(matrix[0])

    total = heigth * 2 + width * 2 - 4
    not_done = True
    while not_done:
        not_done = False
        for i in range(1, heigth- 1):
            for j in range(1, width - 1):
                if safe(matrix, i, j) == True:
                    total += 1

    
    #total = 0
        #for j in i:
        #    if j != 10:
        #        total += 1

    print(total)



def calc_direction(matrix, i, j, offset):
    heigth = len(matrix)
    width = len(matrix[0])

    mult = 1
    val = matrix[i][j]

    while in_bounds(i, j, heigth, width, offset, mult):
        if matrix[i + offset[0]*mult][j + offset[1]*mult] >= val:
            return mult
        mult += 1
    return mult -1



def score(matrix, i, j):
    offset= [
        #(-1, -1),
        (0, -1),
        #(1, -1),
        (-1, 0),
        (1, 0),
        #(-1, 1),
        (0, 1),
        #(1, 1)
    ]
    
    toReturn = 1

    for o in offset:
        point = calc_direction(matrix, i,j,o)
        toReturn *= point
        
    return toReturn

def part2(matrix):


    heigth = len(matrix)
    width = len(matrix[0])

    total = 0

    not_done = True
    while not_done:
        not_done = False
        for i in range(1, heigth- 1):
            for j in range(1, width - 1):
                curr = score(matrix,i,j)
                if curr > total:
                    total = curr

    
    #total = 0
        #for j in i:
        #    if j != 10:
        #        total += 1

    print(total)




f = open("input","r")

lines = [line.strip('\n') for line in f.readlines()]

f.close()


matrix = make_matrix(lines)


part1(matrix)


part2(matrix)



