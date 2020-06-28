#include<bits/stdc++.h>
using namespace std;
vector<int>adj[200510];
vector<bool>visited(200510);
vector<int>d1(200510),d2(200510);
int x=0,a_to_b=0,mx_b=0,nxt=0,mx_ln=0,last=0;
void clean()
{
    for(int i=0;i<200010;i++)
    {
        visited[i]=false;
    }
}

void clean2()
{
    for(int i=0;i<200510;i++) {adj[i].clear();
    visited[i]=false;
    d1[i]=0,d2[i]=0;

    }
}

void DFS1(int node)
{
   visited[node]=true;

   for(int u:adj[node])
   {
       if(visited[u]==false)
       {
           d1[u]=d1[node]+1;

           DFS1(u);
       }
   }
}
void DFS2(int node)
{
   visited[node]=true;

   for(int u:adj[node])
   {
       if(visited[u]==false)
       {
           d2[u]=d2[node]+1;

           DFS2(u);
       }
   }
}



int main()
{
    int n;
    while(scanf("%d  %d",&n,&x)!=EOF)
    {
        int same=0;
        clean();
        clean2();
        int n1,n2;
        for(int i=0;i<n-1;i++)
        {
            scanf("%d %d",&n1,&n2);
            adj[n1].push_back(n2);
            adj[n2].push_back(n1);
        }

        DFS1(1);
        clean();
        DFS2(x);
        int ans=0;
        for(int i=0;i<200005;i++)
        {
            if(d2[i]<d1[i]) ans=max(ans,d1[i]);
        }
        cout<<ans*2<<endl;
        clean2();

    }
}

/*
15 4
1 2
2 3
3 4
4 6
6 8
6 7
7 9
4 5
5 10
10 11
10 12
12 13
13 14
14 15
ans =18
*/
