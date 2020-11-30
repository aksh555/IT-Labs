from collections import deque
adj=[]
dist=[0 for i in range(100)]
vis=[0 for i in range(100)]

def bfs(node):
	q=deque([node])
	vis[node]=1
	while q:
		top=q.popleft()
		#print(top,end=' ')
		for i in adj[top]:
			if vis[i]==0:
				dist[i]=dist[top]+1
				q.append(i)
				vis[i]=1
			else:
				if dist[i]==dist[top]:
					return 1
					
def main():
	file=open('input.txt','r')
	for line in file:
		line=line.strip()
		temp=[]
		flag=1
		for node in line.split():
			if flag==1:
				flag=0
				continue
			temp.append(int(node))
		adj.append(temp)

	for i in range(0,len(adj)):
		if(vis[i]==0):
			if(bfs(i)==1):
				print('not bipartite')
			else:
				print('yes bipartite')
		
	
if __name__ == '__main__':
	main()