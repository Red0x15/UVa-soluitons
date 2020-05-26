from collections import defaultdict

if __name__ == '__main__':
    nW = int(input())
    while nW:
        adj = defaultdict(list)
        adjT = defaultdict(list)
        topo = defaultdict(list)
        visitados = defaultdict(bool)
        scc = defaultdict(int)

        for i in range(nW):
            line = input().split()
            word = line[0]
            desc = line[1:]
            
            visitados[word] = False
            scc[word] = -1
            signif = set()
            for j in desc:
                if not(j in signif):
                    signif.add(j)
                    adj[word].append(j)
                    adjT[j].append(word)
                    visitados[j] = False
                    scc[j] = -1
 
        nW = int(input())
