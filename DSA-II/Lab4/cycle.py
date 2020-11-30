import sys
adj=[]
time=0
flag = 1
def dfs(node,vis,times):
    global time, flag
    vis[node]=1
    print(node,end=" ")
    times[node].append(time)
    for i in adj[node]:
        if vis[i]==0:
            time+=1
            dfs(i,vis,times)
        else:
            if times[node][0]>times[i][0] and vis[i]!=2:
                #print(i,node)
                flag=0
                print("Cyclic")
                sys.exit()
    time+=1
    times[node].append(time)
    vis[node]=2

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

    
    source=0
    vis=[0 for i in range(len(adj))]
    times=[]
    for  i in range(len(adj)):
        times.append([])
    dfs(source,vis,times)
    print(times)

    if flag:
        print("Acyclic")

if __name__ == "__main__":
    main()