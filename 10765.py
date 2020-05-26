import sys
from sys import stdin
from collections import defaultdict

def doubleSort(l):
    attack = defaultdict(list)
    i = 0
    while(i < len(l)):
        attack[l[i]].append(i)
        i += 1
    return attack

class Graph:
    def __init__(self, vertices):
        self.V = vertices
        self.graph = defaultdict(list)
        self.Time = 0

    def addEdge(self, u, v):
        self.graph[u].append(v)
        self.graph[v].append(u)

    def APUtil(self, u, visited, ap, parent, low, disc, pigeons):
        children = 0
        visited[u] = True
        disc[u] = self.Time
        low[u] = self.Time
        self.Time += 1
        for v in self.graph[u]:
            if visited[v] == False:
                parent[v] = u
                children += 1
                self.APUtil(v, visited, ap, parent, low, disc, pigeons)
                low[u] = min(low[u], low[v])
                if parent[u] == -1 and children > 1:
                    ap[u] = True
                    pigeons[u] = children + 1
                if parent[u] != -1 and low[v] >= disc[u]:
                    ap[u] = True
                    pigeons[u] = children + 1
            elif v != parent[u]:
                low[u] = min(low[u], disc[v])

    def AP(self, m):
        visited = [False]*self.V
        ap = [False]*self.V
        parent = [-1] *self.V
        low = [float("Inf")]*self.V
        disc = [float("Inf")]*self.V
        pigeons = [1]*self.V

        for i in range(self.V):
            if visited[i] == False:
                self.APUtil(i, visited, ap, parent, low, disc, pigeons)

        attack = doubleSort(pigeons)
        maxP = max(pigeons)
        s = 0
        i = maxP
        while(i > 0):
            if i in attack:
                for j in attack[i]:
                    if s < m:
                        print(str(j) + ' ' + str(i))
                        s += 1
                    else: break
            i -= 1

if __name__ == '__main__':
    sys.setrecursionlimit(1000000)
    n, m = map(int, stdin.readline().split())
    while(n != 0 or m != 0):
        vim = Graph(n)
        u, v = map(int, stdin.readline().split())
        vim.addEdge(u, v)
        while(u != -1 or v != -1):
            u, v = map(int, stdin.readline().split())
            vim.addEdge(u, v)
        vim.AP(m)
        print()
        n, m = map(int, stdin.readline().split())
