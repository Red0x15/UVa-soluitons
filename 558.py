from sys import stdin

class Graph:
    
    def __init__(self, v, e):
        self.v = v
        self.e = e
        self.edges = [0]*self.e

    def possible_big_bang(self, source):
        infinito = float("inf")
        dist = [infinito]*self.v
        dist[source] = 0

        for _ in range(self.v):
            for i in range(self.e):
                u = self.edges[i][0]
                v = self.edges[i][1]
                w = self.edges[i][2]
                if dist[u] != infinito and dist[v] > dist[u]+w:
                    dist[v] = dist[u]+w
                    
        for i in range(self.e):
            u = self.edges[i][0]
            v = self.edges[i][1]
            w = self.edges[i][2]
            if dist[u] != infinito and dist[v] > dist[u]+w:
                return True
        return False

if __name__ == '__main__':
    c = int(stdin.readline())
    for _ in range(c):
        n, m = map(int, stdin.readline().split())
        space = Graph(n, m)
        for i in range(m):
            x, y, t = map(int, stdin.readline().split())
            space.edges[i] = [x,y,t]
        if space.possible_big_bang(0): print("possible")
        else: print("not possible")
