from sys import stdin
from collections import defaultdict

letters = []
cons = defaultdict(list)
visited = {}

def orderBFS(order):
    if len(order) == len(letters):
        ans = ""
        for i in order:
            ans += " " + i
        print(ans[1:])
        return True
    isOrder = False
    for i in letters:
        if visited[i] == False:
            isValid = True
            for j in cons[i]:
                if visited[j] == True: isValid = False
            if isValid:
                visited[i] = True
                isOrder = orderBFS(order +  i) or isOrder
                visited[i] = False
    return isOrder

if __name__ == '__main__':
    cases = int(stdin.readline())
    for t in range(cases):
        stdin.readline()
        letters = stdin.readline().split()
        letters.sort()
        visited.clear() 
        for i in letters: visited[i] = False
        aux = stdin.readline().split()
        cons.clear()
        for c in aux:
            cons[c[0]].append(c[2])
        if not orderBFS(""): print("NO")
        if t != cases-1: print()
