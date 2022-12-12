import math

def get_monkies(lines):

    monkies = []

    while len(lines) > 0:
        monkey = {}
        lines.pop(0)
        items = lines.pop(0).split(" ")
        
        monkey["items"] = [int(items[i].strip(',')) for i in range(4, len(items))]

        print(monkey["items"])
        
        val = lines.pop(0).split(" ")

        monkey["mult"] = val[-1]
        monkey["sign"] = val[-2]
        monkey["test"] = int(lines.pop(0).split(" ")[-1])
        monkey["true"] = int(lines.pop(0).split(" ")[-1])
        monkey["false"] = int(lines.pop(0).split(" ")[-1])
        monkey["count"] = 0
        try:
            lines.pop(0)
        except:
            print("")
        monkies.append(monkey)

    return monkies

def part1(lines):
    

    monkies = get_monkies(lines)

    for i in range(0, 20):
        print("ROUND NUMBER %d" % i)
        for j in range(0, len(monkies)):
            while len(monkies[j]["items"]) > 0:
                value = monkies[j]["items"].pop(0)
                mult = 0
                if monkies[j]["mult"] == "old":
                    mult = value
                else:
                    mult = int(monkies[j]["mult"])

                if monkies[j]["sign"] == "*":
                    value *= mult
                else:
                    value += mult

                value = math.floor(value/3)
                if value % monkies[j]["test"] == 0:
                    monkies[int(monkies[j]["true"])]["items"].append(value)
                else:
                    monkies[int(monkies[j]["false"])]["items"].append(value)
                monkies[j]["count"] += 1
        for j in range(0, len(monkies)):
                print("Monkey %d: " % j, monkies[j]["items"])

    l = [monkies[i]["count"] for i in range(0, len(monkies))]
    l.sort()
    

    print(l)
    print(l[-1]*l[-2])


def part2(lines):


    monkies = get_monkies(lines)

    for i in range(0, 10000):
        print("ROUND NUMBER %d" % i)
        for j in range(0, len(monkies)):
            while len(monkies[j]["items"]) > 0:
                value = monkies[j]["items"].pop(0)
                mult = 0
                if monkies[j]["mult"] == "old":
                    mult = value
                else:
                    mult = int(monkies[j]["mult"])

                if monkies[j]["sign"] == "*":
                    value *= mult
                else:
                    value += mult

                if value % monkies[j]["test"] == 0:
                    monkies[int(monkies[j]["true"])]["items"].append()
                else:
                    monkies[int(monkies[j]["false"])]["items"].append(value)
                monkies[j]["count"] += 1
        for j in range(0, len(monkies)):
                print("Monkey %d: " % j, monkies[j]["items"])

    l = [monkies[i]["count"] for i in range(0, len(monkies))]
    l.sort()
    

    print(l)
    print(l[-1]*l[-2])





f = open("example","r")

lines = [line.strip('\n') for line in f.readlines()]

f.close()




part1(lines.copy())


part2(lines.copy())



