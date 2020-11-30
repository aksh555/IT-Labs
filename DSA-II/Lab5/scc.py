adj=[[] for i in range(20)]
rev_adj=[[] for i in range(20)]
vis1=[0 for i in range(20)]
vis2=[0 for i in range(20)]
ct=[0] #this denotes current time 
time=[ -1 for i in range(20)]
cn=0
def dfs(node):
	vis2[node]=1
	
	for i in rev_adj[node]:
		if vis2[i]==0:
			dfs(i)
	ct[0]+=1
	print('***',ct[0])
	time[ct[0]]=node
	

def scc(node):
	vis1[node]=1
	print(node,end=',')
	for i in adj[node]:
		if vis1[i]==0:
			scc(i)
			
def main():
	global cn
	file=open('input1.txt','r')
	for line in file:
		line=line.strip()
		line=line.split()
		n=int(line[0])
		cn+=1
		for i in range(1,len(line)):
			adj[n].append(int(line[i]))
			rev_adj[int(line[i])].append(n)
	file.close()
	print(adj)
	print(rev_adj)
	for i in range(cn):
		if(vis2[i]==0):
			dfs(i)

	#print('Time: ',time)
	
	for i in range(len(time)-1,-1,-1):
		if time[i]!=-1 and vis1[time[i]]==0:
			print()	
			scc(time[i])
		

if __name__ == '__main__':
	main()


 