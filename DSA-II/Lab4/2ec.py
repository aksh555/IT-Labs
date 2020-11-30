import sys
adj=[]
time=0
mint=1000000   # dynamic time counter
flag=0
start=0  # source of dfs

def dfs(node,vis,times,parent):
    global time, mint, flag, start
    mint=time
    vis[node]=1
    #print(node,end=" ")
    times[node]=time
    
    for i in adj[node]:
        if vis[i]==0:
            time+=1
            parent[i]=node
            mint=min(mint,dfs(i,vis,times,parent))  
        else:
            mint=min(mint,times[i])
    '''
    if deepest back edge from the node is its parent itself and node's parent is not the source 
    then that edge (from node to its parent itself is bridge edge) so not 2ec
    '''

    if mint==times[parent[node]] and parent[node]!=start:  
        flag=1
        print("Not 2ec")
        sys.exit()
    time+=1
    return mint

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
    file.close()

    vis=[0 for i in range(len(adj))]
    times=[0 for i in range(len(adj))]
    tbe=[0 for i in range(len(adj))]
    parent=[0 for i in range(len(adj))]  # keeping track of node's parent
    
    dfs(start,vis,times,parent)

    if not(flag):
        print("2ec")
    #print(times)

if __name__ == "__main__":
    main()
