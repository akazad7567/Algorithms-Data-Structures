#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>adj[10001];

void BFS(int s,int n)
{
    vector<bool>used(n);
    vector<int>p(n),d(n);
    queue<int>q;

    used[s]=true;
    p[s]=-1;

    q.push(s);
    while(!q.empty())
    {
        int v=q.front();
        q.pop();
        cout<<v<<' ';

        for(int u:adj[v])
        {
          if(!used[u])
          {
              used[u]=true;
              q.push(u);
              d[u]=d[v]+1;
              p[u]=v;

          }

        }
    }
    cout<<endl;

    for(int i=0;i<n;i++)
    {
       cout<<"To reached "<<i;
       if(!used[i]) cout<<" there are No Path\n";
       else
       {
           vector<int>path;
           for(int v=i;v!=-1;v=p[v])
           {
             path.push_back(v);
           }
           cout<<" Path is ";
           for(int u:path)
           {
              cout<<u<<' ';
           }
           cout<<endl;
       }
    }

}

int main()
{
    int node,edge;
    scanf("%d %d",&node,&edge);

    for(int i=0;i<edge;i++)
    {
        int n1,n2;
        scanf("%d %d",&n1,&n2);
        adj[n1].push_back(n2);
    }

    BFS(2,node);
}

/*
4 5
2 0
2 3
0 2
0 1
1 2
*/

