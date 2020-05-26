class Node:
    def __init__(self, val, step):
        self.val = val
        self.step = step

if __name__ == "__main__":
    case_n = 1
    inData = input().split()
    while inData != ['0','0','0']:
        l = int(inData[0])
        u = int(inData[1])
        b = int(inData[2])
        inData = input().split()
        buttons = [0] * b
        for i in range(len(inData)):
            buttons[i] = int(inData[i])

        fisrtN = Node(l, 0)
        found = False
        visited = [False] * 10000
        visited[l] = True
        queue = []
        queue.append(fisrtN)
        while(queue and not found):
            node = queue.pop(0)
            if node.val == u:
                found = True
                print("Case " + str(case_n) + ": " + str(node.step))
            for i in buttons:
                next_node = Node((node.val + i)%10000, node.step + 1)
                if visited[next_node.val] == False:
                    visited[next_node.val] = True
                    queue.append(next_node)
        if not found:
            print("Case " + str(case_n) + ": Permanently Locked")

        case_n += 1
        inData = input().split()