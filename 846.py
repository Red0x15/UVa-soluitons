def step(p, src):
    if src == 0:
        return 0

    izq = p
    if src < p:
        izq = src

    der = p
    if src - izq < p:
        der = src - izq
    
    if der == 0:
        return 1
    else:
        return 2 + step(p +  1, src - izq - der)


def stepS(d):
    p = 1
    src = d
    steps = 0
    while(src):
        izq = p
        if src < p:
            izq = src
        der = p
        if src - izq < p:
            der = src - izq
        
        if der == 0:
            steps += 1
            src -= izq
        else:
            steps += 2
            src -= der + izq
        p += 1
    return steps

if __name__ == "__main__":
    cases = int(input())
    while cases:
        t = input().split()
        d = int(t[1]) - int(t[0])
        print(stepS(d))
        # try:
            # print(step(1, d))
        # except:
        #     print(t[1] + ' ' + t[0] + ' ' + str(d))
        cases -= 1