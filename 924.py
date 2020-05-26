from collections import defaultdict

class Graph:
    def __init__(self, nNodes):
        self.nNodes = nNodes
        self.edges = defaultdict(list)

    def addEdge(self, s, d):
        self.edges[s].append(d)

    def spreadingBFS(self, s):
        day = 1
        boom = [0, 0]

        visited = [False] * self.nNodes
        queue = []
        queueAux = []
        queue.append(s)
        visited[s] = True
        while queue:
            node = queue.pop(0)
            for i in self.edges[node]:
                if visited[i] == False:
                    queueAux.append(i)
                    visited[i] = True
            if queue == []:
                actBoom = len(queueAux)
                if boom[0] < actBoom:
                    boom = [actBoom, day]
                queue = queueAux
                queueAux = []
                day += 1
        return boom

if __name__ == "__main__":
    e = int(input())
    empG = Graph(e)
    i = 0
    while i < e:
        friends = input().split()
        for j in range(1, len(friends)):
            empG.addEdge(i, int(friends[j]))
        i += 1
    
    t = int(input())
    i = 0
    while i < t:
        source = int(input())
        boom = empG.spreadingBFS(source)
        if boom[0]:
            print(str(boom[0]) + " " + str(boom[1]))
        else:
            print(0)
        i += 1