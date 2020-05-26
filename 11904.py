from sys import stdin

class SmartMap:
    def __init__(self, graph, mijidPos):
        self.graph = graph
        self.mijidPos = mijidPos
        self.visited = {}
        for i in graph.keys():
            self.visited[i] = False
    
    def get_non_visited_node(self):
        for i in self.visited:
            if self.visited[i] == False: return i
        return None

    def __dfs__(self, s):
        sPath = 1
        queue = []

        queue.append(s)
        self.visited[s] = True
        if s[0] == self.mijidPos[0] and s[1] == self.mijidPos[1]: return 0
        while queue:
            node = queue.pop()
            for i in self.graph[node]:
                if self.visited[i] == False:
                    self.visited[i] = True
                    queue.append(i)
                    sPath += 1
                    if i[0] == self.mijidPos[0] and i[1] == self.mijidPos[1]: return 0
        return sPath
    
    def get_biggest_continent(self):
        n = self.get_non_visited_node()
        largest = 0
        while n != None:
            nPath = self.__dfs__(n)
            if largest < nPath: largest = nPath
            n = self.get_non_visited_node()
        return largest

if __name__ == "__main__":
    line = stdin.readline()
    while line:
        m, n = map(int, line.split())
        grid = [""] * m
        for i in range(m):
            grid[i] = input()
        mijidPos = [int(i) for i in stdin.readline().split()]
        land = grid[mijidPos[0]][mijidPos[1]]
        graph = {}
        for i in range(m):
            for j in range(n):
                if grid[i][j] == land:
                    graph[(i, j)] = []
                    if i-1 >= 0:
                        if grid[i-1][j] == land:
                                graph[(i, j)].append((i-1, j))
                    if i+1 < m:
                        if grid[i+1][j] == land:
                                graph[(i, j)].append((i+1, j))
                    if j-1 >= 0:
                        if grid[i][j-1] == land:
                                graph[(i, j)].append((i, j-1))
                    if j+1 < n:
                        if grid[i][j+1] == land:
                                graph[(i, j)].append((i, j+1))
        smartMap = SmartMap(graph, mijidPos)
        ans = smartMap.get_biggest_continent()
        print(ans)
        stdin.readline()
        line = stdin.readline()