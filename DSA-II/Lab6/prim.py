import heapq
adjl=[]
adjm=[]
pq=[]
for i in range(6):
    adjm.append([0 for i in range(6)])
    
s=[0 for i in range(6)]
dis=[10e7 for i in range(6)]
pos=[0 for i in range(6)]
mst=[]
def update(dis,node):
    pq[pos[node]][0] = dis
    while True:
        par=int((pos[node]-1)/2)
        child=pos[node]
        if pq[child][0]<pq[par][0]:
            pq[child],pq[par]=pq[par],pq[child]
            pos[child]=par
            pos[par]=child
        else:
            break


def prims():
    #print(adjm)
    s[0]=1
    dis[0]=0
    for i in range(len(adjl)):
        pq.append([dis[i],i])
        heapq.heapify(pq)
    #print(pq)
    while(pq):
        
        u=heapq.heappop(pq)[1]
        for i in range(len(pq)):
            pos[pq[i][1]]=i
        for j in adjl[u]:
            if(s[j]==0):
                if dis[j]>adjm[u][j]:
                    dis[j]=adjm[u][j]
                    update(dis[j],j)
        s[u]=1
        mst.append(u)
    print(mst)

def main():
    with open('input.txt','r') as f:
        for line in f:
            l = []
            line = line.strip()
            line = line.split()
            no = int(line[0])
            for i in range(1,len(line)):
                n,w = line[i].split(',')
                l.append(int(n))
                adjm[no][int(n)]=int(w)
            adjl.append(l)
   
    prims()
    
if __name__=="__main__":
    main()