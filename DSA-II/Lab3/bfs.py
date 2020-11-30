from collections import deque
adj=[]

vis=[0 for i in range(100)]
dist=[0 for i in range(100)]
def bfs(node):
	q=deque([node])
	vis[node]=1
	while q:
		node=q.popleft()
		print(node,"-", dist[node],end=",")
		for i in adj[node]:
			if vis[i]==0:
				dist[i]=dist[node]+1
				q.append(i)
				vis[i]=1

def main():
	file=open('input.txt','r')
	for line in file:
		line=line.strip()
		temp=[]
		flg=1
		for node in line.split():
			if flg==1:
				flg=0
				continue
			temp.append(int(node))
		adj.append(temp)

	
	print("Enter the source vertex")
	source=int(input())
	bfs(source)
	for i in range(len(adj)):
		if vis[i]==0:
			print()
			dist[i]="INF"
			bfs(i)


if __name__ == '__main__':
	main()