class Node:
    def __init__(self,x):
        self.val = x
        self.parent = self
        self.rank = 0

    def __str__(self):
        return str(self.val)

class DisjointSets: 

   def makeset(self,i):
    return Node(i)
   
   def findset(self,node):
    if node.parent==node:
        return node
    else:
        node.parent=self.findset(node.parent)
        return node.parent

   def union(self,a,b):
    x=self.findset(a)
    y=self.findset(b)
    if(x!=y):
        if x.rank>y.rank:
            y.parent=x
            return (b.val,a.val)
        else:
            if x.rank==y.rank:
                y.rank+=1
            x.parent=y
            return (a.val,b.val)

    


# def main():
#     ds = DisjointSets()
    
#     nodes = []
#     for i in range(10):
#         node = ds.makeset(i)
#         nodes.append(node)
    

#     # ds.union(nodes[0],nodes[1])
#     # print(ds.findset(nodes[0]))    # Should print 1
#     # ds.union(nodes[0],nodes[2])
#     # print(ds.findset(nodes[2]))    # Should print 1
#     ''' Add more tests!'''

# if __name__ == '__main__':
#     main()