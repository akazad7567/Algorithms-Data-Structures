#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int>adj[1000];
int n; // number of vertices
vector<int> color(1000);
vector<int> time_in(1000), time_out(1000);

int dfs_timer = 0;
void dfs(int v)
{
    cout<<v<<' ';
    time_in[v] = dfs_timer++;
    color[v] = 1;
    for (int u : adj[v])
        if (color[u] == 0)
            dfs(u);
    color[v] = 2;
    time_out[v] = dfs_timer++;

}

int main()
{
    int E;
    scanf("%d %d",&n,&E);
    int node1,node2;

    for(int i=0;i<E;i++)
    {
        scanf("%d %d",&node1,&node2);
        adj[node1].push_back(node2);
    }


        dfs(2);
        cout<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<i<<"-> "<<time_in[i]<<' '<<time_out[i]<<endl;
            cout<<i<<"-> "<<color[i]<<endl;
        }


}
