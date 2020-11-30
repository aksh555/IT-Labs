start=[0 for i in range(1000)]
vis=[0 for i in range(1000)]
time=[0]
sst=[0]
source=0
adj=[[] for i in range(1000)]
def dfs(node,p):
	vis[node]=1
	#print('node: ',node)
	start[node]=time[0]
	time[0]+=1
	sst[0]=start[node]

	for i in adj[node]:
		if vis[i]==0:
			sst[0]=min(sst[0],dfs(i,node))
		else:
			if i!=p and start[i]<start[node]:
				sst[0]=min(start[i],sst[0])
	#print('sst[0]: ',sst[0],' and start[node]: ',start[node])
	if node!=source and sst[0]==start[node]:
		print('nope','   and it broke at :',node)
		exit()
	return sst[0]

def main():
	n=int(input('enter the number of nodes'))
	e=int(input('enter the number of edges'))
	print('enter the edges:')
	for i in range(e):
		a,b=map(int,input().split())
		adj[a].append(b)
		adj[b].append(a)

	dfs(0,-1)
	print('yes, it is 2 edge connected')

if __name__ == '__main__':
	main()


