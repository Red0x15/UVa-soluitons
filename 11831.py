from sys import stdin



def main():
    n ,m , s = map(int, stdin.readline().split())
    while(n and m and s):
        robot = {'dir' : [1, 0], 'i' : 0, 'j' : 0, 'stickers' : 0}
        arena = [""]*n
        for i in range(n):
            aux = input()
            for j in range(m):
                if not aux[j] in ".*#":
                    if aux[j] == "N":
                        robot['dir'] = [-1, 0]
                    elif aux[j] == "S":
                        robot['dir'] = [1, 0]
                    elif aux[j] == "L":
                        robot['dir'] = [0, 1]
                    elif aux[j] == "O":
                        robot['dir'] = [0, -1]
                    robot['i'], robot['j'] = i, j
                arena[i] += aux[j]
        inst = input()
        for i in inst:
            if i == 'D':
                if robot['dir'] == [-1, 0]:
                    robot['dir'] = [0, 1]
                elif robot['dir'] == [1, 0]:
                    robot['dir'] = [0, -1]
                elif robot['dir'] == [0, 1]:
                    robot['dir'] = [1, 0]
                elif robot['dir'] == [0, -1]:
                    robot['dir'] = [-1, 0]
            elif i == 'E':
                if robot['dir'] == [-1, 0]:
                    robot['dir'] = [0, -1]
                elif robot['dir'] == [1, 0]:
                    robot['dir'] = [0, 1]
                elif robot['dir'] == [0, 1]:
                    robot['dir'] = [-1, 0]
                elif robot['dir'] == [0, -1]:
                    robot['dir'] = [1, 0]
            else:
                if ((robot['i'] + robot['dir'][0]) >= 0) and ((robot['i'] + robot['dir'][0]) < n):
                    if ((robot['j'] + robot['dir'][1]) >= 0) and ((robot['j'] + robot['dir'][1]) < m):
                        if arena[robot['i'] + robot['dir'][0]][robot['j'] + robot['dir'][1]] != "#":
                            robot['i'] += robot['dir'][0]
                            robot['j'] += robot['dir'][1]
                if arena[robot['i']][robot['j']] == "*":
                    robot['stickers'] += 1
                    arena[robot['i']] = arena[robot['i']][:robot['j']] + "." + arena[robot['i']][robot['j']+1:]
        
        print(robot['stickers'])
        n ,m , s = map(int, stdin.readline().split())

if __name__ == '__main__':
    main()