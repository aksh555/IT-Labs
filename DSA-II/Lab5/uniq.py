from collections import deque
dis=[10e7 for i in range(10)]
ko=[0 for i in range(10)]
def bfs(s):
    l=deque()
    l.append(s)
    dis[s]=0
    ko[s]=1
    while(l):
        x=l.popleft()
        for i in adj[x]:
            if(dis[i]==10e7):
                l.append(i)
                ko[i]=ko[x]
                dis[i]=dis[x]+1
            elif(dis[i]>dis[x]+1):
                dis[i]=dis[x]+1
                ko[i]=ko[x]
            elif(dis[i]==dis[x]+1):
                ko[i]+=ko[x]
    print(ko)
adj=[[1,4],[0,2],[1,4,3],[2],[0,2]]
bfs(0)