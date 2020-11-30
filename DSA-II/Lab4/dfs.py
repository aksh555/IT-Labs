adj=[]
time=0

def dfs(node,vis,times):
    global time
    vis[node]=1
    print(node,end=" ")
    times[node].append(time)
    for i in adj[node]:
        if vis[i]==0:
            time+=1
            dfs(i,vis,times)
    time+=1
    times[node].append(time)

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

    print("Enter the source vertex")
    source=int(input())
    vis=[0 for i in range(len(adj))]
    times=[]
    for  i in range(len(adj)):
        times.append([])
    dfs(source,vis,times)
    print(times)

if __name__ == "__main__":
    main()