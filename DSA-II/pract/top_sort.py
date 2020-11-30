adj=[[],[],[3],[1],[0,1],[2,0]]
source=0
time=0

def dfs(source,vis,top):
    global time
    vis[source]=1
    for i in adj[source]:
        if vis[i]==0:
            time+=1
            dfs(i,vis,top)
    time+=1
    print(time,end=" ")
    top[time]=source

def main():
    '''file=open('input.txt','r')
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
    file.close()'''

    
    vis=[0 for i in range(len(adj))]
    top=["-" for i in range(0,2*len(adj)+1)]
    dfs(5,vis,top)
    print(top)

if __name__=="__main__":
    main()