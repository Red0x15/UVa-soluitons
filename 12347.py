from sys import stdin

class Tree:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

    def __addLeft__(self, left_val):
        self.left = Tree(left_val)

    def __addRight__(self, right_val):
        self.right = Tree(right_val)

    def binAdd(self, val):
        if val < self.val:
            if not (self.left is None):
                self.left.binAdd(val)
            else:
                self.__addLeft__(val)
        else:
            if not (self.right is None):
                self.right.binAdd(val)
            else:
                self.__addRight__(val)


    def printPosOrder(self):
        if not (self.left is None):
            self.left.printPosOrder()
        if not (self.right is None):
            self.right.printPosOrder()
        print(self.val)

if __name__ == '__main__':
    i = stdin.readline()
    t = None
    while i != '':
        i = int(i) 
        if t is None: t = Tree(i)
        else: t.binAdd(i)
        i = stdin.readline()
    t.printPosOrder()
