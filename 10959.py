from collections import defaultdict

class Graph:
    def __init__(self, nNodes):
        self.nNodes = nNodes
        self.edges = defaultdict(list)

    def addEdge(self, nX, nY):
        self.edges[nX].append(nY)
        self.edges[nY].append(nX)
    
    def giovanniGrade(self):
        grades = [-1] * self.nNodes
        grade = 0

        visited = [False] * self.nNodes
        queue = []
        queueAux = []
        queue.append(0)
        visited[0] = True

        grades[0] = grade
        grade += 1
        while queue:
            s = queue.pop(0)
            for i in self.edges[s]:
                if visited[i] == False:
                    queueAux.append(i)
                    visited[i] = True
                    grades[i] = grade
            if queue == []:
                grade += 1
                queue = queueAux
                queueAux = []
        return grades

if __name__ == "__main__":
    cases = int(input())
    while cases:
        input()
        aux = input().split()
        p = int(aux[0])
        d = int(aux[1])
        g = Graph(p)
        while d:
            aux = input().split()
            nX = int(aux[0])
            nY = int(aux[1])
            g.addEdge(nX, nY)
            d -= 1
        giovanniGrades = g.giovanniGrade()
        for i in range(1,g.nNodes):
            print(giovanniGrades[i])
        cases -= 1
        if cases: print()