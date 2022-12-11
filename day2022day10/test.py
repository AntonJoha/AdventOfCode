


def part1(lines):
    

    options = [20, 60, 100, 140, 180, 220]

    step = 1
    value = 1
    result = 0
    for l in lines:

        args = l.split(" ")
        if args[0] == "noop":
            step += 1
            if step in options:
                print("Added %d * %d" % (step , value))
                result += value*step
        else:
            if step + 1 in options:
                print("Added %d * %d" % (step + 1, value))
                result += value*(1+step)
            step += 2
            value += int(args[1])
            if step in options:
                result += value*step
    print(result)


def handle_step(value, step):
    loop = step -1
    
    draw = False

    for a in range(loop, loop + 3):
        if a % 40 == value:
            draw = True

    if (loop % 40 == 0):
        print("")
    if draw:
        print("#", end='')
    else:
        print(" ", end='')

def part2(lines):


    step = 0
    value = 1
    for l in lines:

        args = l.split(" ")
        if args[0] == "noop":
            step += 1
            handle_step(value, step)
        else:
            step +=1
            handle_step(value, step)
            step += 1
            value += int(args[1])
            handle_step(value, step)





f = open("input","r")

lines = [line.strip('\n') for line in f.readlines()]

f.close()




part1(lines)


part2(lines)



