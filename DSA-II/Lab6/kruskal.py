import disjointsets as d
import heapq
mst=[]
def krus(adj,pq):
	ds=d.DisjointSets()
	nodes=[]
	for i in range(len(adj)):
		node=ds.makeset(i)
		nodes.append(node)
	#print(nodes)
	while pq:
		ls=heapq.heappop(pq)[1]
		if ds.findset(nodes[ls[0]])!=ds.findset(nodes[ls[1]]):
			mst.append(ls)
			ds.union(nodes[ls[0]],nodes[ls[1]])

	print(mst)

def main():

	adj=[]
	pq=[]
	adm=[ [0 for i in range(100)] for i in range(100) ]
	file=open('input.txt','r')

	for line in file:
		line=line.strip()
		temp=[]
		flg=0

		for node in line.split():
			if flg==0:
				first=int(node)
				flg=1
				continue
			else:
				v,weight=node.split(',')
				v=int(v)
				weight=int(weight)
				temp.append(v)
				if adm[first][v]==0 and adm[v][first]==0:
					pq.append([weight,[first,v]])
					adm[first][v]=weight
		adj.append(temp)

	heapq.heapify(pq)
	krus(adj,pq)

if __name__ == '__main__':
	main()

