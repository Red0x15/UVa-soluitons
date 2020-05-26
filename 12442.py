from sys import stdin
from collections import defaultdict

class Graph:
    def __init__(self, nNodes):
        self.nNodes = nNodes
        self.edges = defaultdict(list)

    def addEdge(self, s, d):
        self.edges[s].append(d)

    def dfs(self, s):
        jumps = 0
        visited = [False] * self.nNodes; visited[0] = True
        stack = []
        stack.append(s)
        visited[s] = True
        while stack:
            node = stack.pop()
            for i in self.edges[node]:
                if visited[i] == False:
                    stack.append(i)
                    visited[i] = True
                    jumps += 1
        return jumps
    
def main():
    cases = int(input()) + 1
    for i in range(1, cases):
        martians = int(input())
        g = Graph(martians+1)
        for _ in range(martians):
            s, d = map(int, stdin.readline().split())
            g.addEdge(s, d)
        travels = [g.dfs(j) for j in range(1, martians+1)]
        chismoso = 0
        maxSpread = 0
        for j in range(len(travels)):
            if travels[j] > maxSpread:
                maxSpread = travels[j]
                chismoso = j+1
        print("Case " + str(i) + ": " + str(chismoso))

main()