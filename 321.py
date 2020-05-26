paths = []
lights = []

#M n -> move to room n
#Su n -> turn on light n
#So n -> turn off light n

def travel(rooms, doors, r, acum):
    print(acum)
    global paths
    global lights
    global bedroom
    for s in lights[r]:
        if s == 0:
            if r == bedroom:
                good = True
                for i in rooms:
                    good &= not i
                if good: paths.append(acum)
                return 0
            for d in range(len(doors[r])):
                if doors[r][d][1] == False and rooms[doors[r][d][0]] == True:
                    tmp_doors = doors
                    tmp_doors[r][d][1] = True
                    tmp_acum = acum
                    tmp_acum.append("M "+str(tmp_doors[r][d][0]))
                    travel(rooms, tmp_doors, tmp_doors[r][d][0], tmp_acum)
        else:
            tmp_rooms = rooms
            tmp_acum = acum
            if tmp_rooms[s]:
                tmp_acum.append("So "+str(s))
            else:
                tmp_acum.append("Su "+str(s))
            tmp_rooms[s] = not tmp_rooms[s]
            travel(tmp_rooms, doors, r, tmp_acum)
    return 0


if __name__ == '__main__':
    case = 1
    r, d, s = input().split()
    r = int(r)
    bedroom = r
    d = int(d)
    s = int(s)
    while(r or d or s):
        paths = []
        rooms = [False]*(r+1)
        rooms[1] = True
        doors = [[]]*(r+1)
        lights = [[0]]*(r+1)

        for _ in range(d):
            i, j = input().split()
            i = int(i)
            j = int(j)
            doors[i].append([j, False])
            doors[j].append([i, False])

        for _ in range(s):
            k, l = input().split()
            k = int(k)
            l = int(l)
            lights[k].append(l)

        travel(rooms, doors, 1, [])
        print(paths)
        r, d, s = input().split()
        r = int(r)
        d = int(d)
        s = int(s) 
