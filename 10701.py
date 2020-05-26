preOr = []
class Tree:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

    def dock_left(self, t):
        self.left = t

    def dock_right(self, t):
        self.right = t
    
    def printPosOrder(self):
        posOr = ""
        if not (self.left is None):
            posOr += self.left.printPosOrder()
        if not (self.right is None):
            posOr += self.right.printPosOrder()
        posOr += self.val
        return posOr

def scratch_tree(inOr):
    global preOr
    if len(inOr) == 0: return None
    t = Tree(preOr[0])
    wi = str_whereis(preOr[0], inOr)
    preOr.pop(0)
    left_inOr = inOr[:wi]
    right_inOr = inOr[1+wi:]
    t.dock_left(scratch_tree(left_inOr))
    t.dock_right(scratch_tree(right_inOr))
    return t

def str_whereis(c, s):
    i = 0
    while i < len(s):
        if s[i] == c:
            return i
        i+=1
    return -1

if __name__ == '__main__':
    c = int(input())
    for _ in range(c):
        line = input().split()
        preOr = list(line[1])
        inOr = list(line[2])
        t = scratch_tree(inOr)
        print(t.printPosOrder())
