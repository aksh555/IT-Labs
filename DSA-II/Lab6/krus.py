from disjointsets import Node,DisjointSets
ds = DisjointSets()
nodes = []
mst=[]

def krus(vert, weight):
    for i in vert:
        node = ds.makeset(i)
        nodes.append(node)
    print(vert)
    print(weight)
    for i in weight:
        if(ds.union(nodes[i[0]],nodes[i[1]])):
            mst.append((i[0],i[1]))
    print(mst)

def main():
    weight={}
    vert=[]
    file =  open("input.txt",'r') 
    for line in file:
        line = line.strip()
        line  = line.split()
        n = int(line[0])
        vert.append(n)
        for i in range(1,len(line)):
            v,w = line[i].split(',')
            if(not (int(v),n) in weight.keys()):
                weight[(n,int(v))] = int(w)
    file.close()
    
    weight={k: v for k, v in sorted(weight.items(), key=lambda item: item[1])}
    krus(vert,weight)


if __name__ == "__main__":
    main()