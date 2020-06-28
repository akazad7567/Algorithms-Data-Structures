#include<bits/stdc++.h>
using namespace std;
vector<int>graph[200010];
vector<int>adj[200010];
vector<int>chk[200010];
vector<bool>visited(200010);
vector<int>p(200010),p2(200010),parent(200010);
int ans=0,val=0;
//int flag=1;
void dfs(int node,int prnt)
{
    int flag=1;
    visited[node]=true;
   for(int ir:graph[node])
   {
       if(ir!=prnt and visited[ir]==false)
       {
           if(p[node]==1 or p2[node]>val)
           p2[ir]+=p2[node];
           flag=0;
           dfs(ir,node);
       }
   }
   //if(flag==1) cout<<node<<"-> "<<p2[node]<<' ';

    if(p2[node]<=val and flag==1) ans++;
}

void clean()
{
    for(int i=0;i<200000;i++)
    {
        graph[i].clear();
        chk[i].clear();
        p[i]=0,p2[i]=0;
        visited[i]=false;
        parent[i]=0;
    }

    ans=0;
}

int main()
{
    int N,M;
    while(scanf("%d %d ",&N,&val)!=EOF)
    {
        clean();
        int n;
        for(int i=1;i<=N;i++)
        {
            scanf("%d",&p[i]);
            p2[i]=p[i];

        }
        int x,y;
        for(int i=0;i<N-1;i++)
        {
            scanf("%d %d",&x,&y);
            graph[x].push_back(y);
            graph[y].push_back(x);
           // parent[y]=x;//amr ki kono child ace?? hmmm x amr child
            //parent[x]=-1;
        }
        dfs(1,0);
        //cout<<endl;
        cout<<ans<<endl;
    }
}

/*
12 3

1 0 1 0 1 1 1 1 0 0 0 0

6 7

12 1

9 7

1 4

10 7

7 1

11 8

5 1

3 7

5 8

4 2
*/
