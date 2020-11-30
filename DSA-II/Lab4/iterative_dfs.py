adj=[]
source=0


def dfs(source,times):
    time=0
    print(source,end=" ")
    st=[]
    vis=[0 for i in range(len(adj))]
    st.append(source)
    vis[source]=1
    while len(st)!=0:
        x=st[len(st)-1]
        for i in adj[x]:
            if not(vis[i]):
                time+=1
                print(i,end=" ")
                vis[i]=1
                times[i].append(time)
                st.append(i)
                break
        else:
            time+=1
            del st[len(st)-1]
            times[i].append(time)



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
    print(adj)
    times=[]
    for i in range(len(adj)):
        times.append([])
    dfs(source,times)
    print(times)

if __name__ == "__main__":
    main()