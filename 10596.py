from sys import stdin
from collections import defaultdict

class Graph:

    def __init__(self,vertices):
        self.V = vertices
        self.graph = defaultdict(list)

    def addEdge(self,u,v):
        self.graph[u].append(v)
        self.graph[v].append(u)

    def DFSUtil(self,v,visited):
        visited[v] = True
        for i in self.graph[v]:
            if visited[i]==False:
                self.DFSUtil(i,visited)

    def isConnected(self):
        visited = [False]*(self.V)
        for i in range(self.V):
            if len(self.graph[i]) > 1:
                break
        if i == self.V-1:
            return False
        self.DFSUtil(i,visited)
        for i in range(self.V):
            if visited[i]==False and len(self.graph[i]) > 0:
                return False
        return True

if __name__ == '__main__':
    line = stdin.readline()
    while line != '':
        n, r = map(int, line.split())
        chittagong = Graph(n)
        grades = [0]*n
        for _ in range(r):
            c1, c2 = map(int, stdin.readline().split())
            chittagong.addEdge(c1, c2)
            grades[c1] += 1
            grades[c2] += 1
        eulerian = True
        eulerian &= chittagong.isConnected()
        i = 0
        while eulerian and i < n:
            if grades[i] % 2: eulerian = False
            i += 1
        if eulerian: print("Possible")
        else: print("Not Possible")
        line = stdin.readline()
