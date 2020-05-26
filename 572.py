class CheckedList(object):
    def __init__(self, graph):
        self.nodes = {}
        for i in graph.keys():
            self.nodes[i] = 0

    def isfully_visited(self):
        for i in self.nodes:
                if self.nodes[i] == 0: return False
        return True

    def get_nonVisited_node(self):
        for i in self.nodes:
            if self.nodes[i] == 0: return i
        return (-1, -1)

def bfs(node, graph, checked):
    checked.nodes[node] = 1
    neighbours = graph[node]
    visitList = []
    for i in neighbours:
        if checked.nodes[i] == 0:
            checked.nodes[i] = 1
            visitList.append(i)
    for i in visitList:
        bfs(i, graph, checked)


if __name__ == "__main__":
    aux = input().split()
    n, m = int(aux[0]), int(aux[1])
    
    while(n and m):
        grid = [""]*n
        for i in range(n):
            grid[i] = input()

        graph = {} # {(y, x): [(y0, x0), (y0, x0)]}
        for i in range(n):
            for j in range(m):
                if grid[i][j] == "@":
                    graph[(i, j)] = []
                    if i-1 >= 0:
                        if j-1 >= 0:
                            if grid[i-1][j-1] == "@":
                                graph[(i, j)].append((i-1, j-1))
                        if grid[i-1][j] == "@":
                            graph[(i, j)].append((i-1, j))
                        if j+1 < m:
                            if grid[i-1][j+1] == "@":
                                graph[(i, j)].append((i-1, j+1))

                    if j-1 >= 0:
                        if grid[i][j-1] == "@":
                                graph[(i, j)].append((i, j-1))
                    if j+1 < m:
                        if grid[i][j+1] == "@":
                                graph[(i, j)].append((i, j+1))

                    if i+1 < n:
                        if j-1 >= 0:
                            if grid[i+1][j-1] == "@":
                                graph[(i, j)].append((i+1, j-1))
                        if grid[i+1][j] == "@":
                            graph[(i, j)].append((i+1, j))
                        if j+1 < m:
                            if grid[i+1][j+1] == "@":
                                graph[(i, j)].append((i+1, j+1))

        checked = CheckedList(graph)
        nonConnected = 0
        if checked.nodes != {}:
            while not checked.isfully_visited():
                bfs(checked.get_nonVisited_node(), graph, checked)
                nonConnected += 1
        print(nonConnected)

        aux = input().split()
        n, m = int(aux[0]), int(aux[1])