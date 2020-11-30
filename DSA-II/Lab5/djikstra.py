import heapq
adj=[]
adm=[[0 for i in range(10)]for i in range(10)]
pq=[]
pred=[-1 for i in range(10)]
dist=[10e9 for i in range(10)]
pos=[-1 for i in range(10)]
unique=[True for i in range(10)]
def update(prio,node):
	print(pos[node])
	pq[pos[node]][0]=prio
	while True:
		par=int((pos[node]-1)/2)
		child=pos[node]
		if pq[child][0]<pq[par][0]:
			pq[child],pq[par]=pq[par],pq[child]
			pos[child]=par
			pos[par]=child
		else:
			break

def dij(s):
	dist[s]=0
	for i in range(len(adj)):	
		entry=[dist[i],i]
		pq.append(entry)
	heapq.heapify(pq)
	for i in range(len(pq)):
		pos[pq[i][1]]=i

	while pq:
		u=heapq.heappop(pq)[1]
		for i in range(len(pq)):
			pos[pq[i][1]]=i
		for i in adj[u]:
			if dist[i]>dist[u]+adm[u][i]:
				dist[i]=dist[u]+adm[u][i]
				update(dist[i],i)
				pred[i]=u
				unique[i]=True
			elif dist[i]==dist[u]+adm[u][i]:
				unique[i]=False

def main():

    file=open('input.txt','r')
    for line in file:
        line=line.strip()
        adjacentVertices = []
        line = line.split()
        first=int(line[0])
        for i in range(1,len(line)):
            node,weight = line[i].split(',')
            adm[first][int(node)]=int(weight)
            adjacentVertices.append(int(node))

        adj.append(adjacentVertices)
    print(adj)
    print(adm)

    file.close()
    dij(0)
    print('distane :',dist)
    print("Parent  array:",pred)
    print("unique: ",unique)    

if __name__ == '__main__':
    main()

