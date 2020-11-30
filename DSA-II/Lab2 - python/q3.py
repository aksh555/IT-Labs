class graph:
    def __init__(self,v):
        self.v = v
        self.adjmat = []
        self.adjlist = []
        for i in range(v):
            self.adjmat.append([0 for j in range(v)])
            self.adjlist.append([])
    def add_edge(self,v1,v2):
        self.adjmat[v1][v2] = 1
        self.adjmat[v2][v1] = 1
        self.adjlist[v1].append(v2)
        self.adjlist[v2].append(v1)
    def display(self):
        print("Adjacency Matrix:")
        for i in range(self.v):
            for j in range(self.v):
                print(self.adjmat[i][j], end=" ")
            print()
        print("Adjacency List:")
        for i in range(self.v):
            print("vertex " +str(i)+":", self.adjlist[i])

def main():
    print("Enter no of vertices:")
    v=int(input())
    g = graph(v)
    print("Enter edges:")
    while(True):
        s=input()
        if (s!=""):
            s=[int(i) for i in s.split()]
            v1,v2=s
            g.add_edge(v1,v2)
        else:
            break
    g.display()

if __name__ == '__main__':
    main()
