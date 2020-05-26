from sys import stdin
from collections import defaultdict

graph = defaultdict(list)
weights = defaultdict(list)
visited = [False]*10001
largest = 0

def dfs(n, acum):
    global largest
    global visited
    maxp = 0
    i = 0
    while i < len(graph[n]):
        v = graph[n][i]
        if not visited[v]:
            visited[v] = True
            aux = dfs(v, weights[n][i])
            largest = max(largest, maxp+aux)
            maxp = max(maxp, aux)
        i += 1
    return maxp+acum


if __name__ == '__main__':
    line = stdin.readline()
    while line != '':
        graph = defaultdict(list)
        weights = defaultdict(list)
        visited = [False]*10001
        largest = 0
        if line == '\n': line = stdin.readline()
        while line != '\n' and line != '':
            sv, dv, w = map(int, line.split())
            graph[sv].append(dv)
            graph[dv].append(sv)
            weights[sv].append(w)
            weights[dv].append(w)
            line = stdin.readline()
        visited[1] = True
        dfs(1,0)
        print(largest)
