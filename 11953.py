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

def bfs(node, graph, checked, grid):
    up = False
    if grid[node[0]][node[1]] == "x":
        up = True
    queue = []
    queue.append(node)
    checked.nodes[node] = 1
    while queue:
        n = queue.pop()
        for i in graph[n]:
            if checked.nodes[i] == 0:
                if grid[i[0]][i[1]] == "x":
                    up = True
                checked.nodes[i] = 1
                queue.append(i)
    return up


if __name__ == "__main__":
    cases = int(input())
    
    for c in range(1, cases+1):
        n = int(input())
        grid = [""]*n
        for i in range(n):
            grid[i] = input()

        graph = {}
        for i in range(n):
            for j in range(n):
                if grid[i][j] != ".":
                    graph[(i, j)] = []
                    if i-1 >= 0:
                        if grid[i-1][j] != ".":
                                graph[(i, j)].append((i-1, j))
                    if i+1 < n:
                        if grid[i+1][j] != ".":
                                graph[(i, j)].append((i+1, j))

                    if j-1 >= 0:
                        if grid[i][j-1] != ".":
                                graph[(i, j)].append((i, j-1))
                    if j+1 < n:
                        if grid[i][j+1] != ".":
                                graph[(i, j)].append((i, j+1))
        checked = CheckedList(graph)
        nonConnected = 0
        if checked.nodes != {}:
            while not checked.isfully_visited():
                ship_up = bfs(checked.get_nonVisited_node(), graph, checked, grid)
                if ship_up: nonConnected += 1
        print("Case " + str(c) + ": " + str(nonConnected))