#include<bits/stdc++.h>
using namespace std;

int n;
vector <int> g[500];
vector<int>color(500,0);
int chk=0;
void dfs(int v, int p){
  color[v] = 1; // GREY
  for(int w : g[v]){
    if(color[w] == 1){
    chk=1;
      // you found a cycle, it's easy to recover it now.
    }
    if(color[w] == 0) dfs(w, v);
  }
  color[v] = 2; // BLACK
}

int main()
{
    int edge;
    scanf("%d %d",&n,&edge);
    for(int i=0;i<edge;i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
    }
    for(int i = 0; i < n; i++)
    if(color[i] == 0) dfs(i, -1); // IF NODE IS WHITE, START NEW DFS
    if(chk==1) printf("found\n");
    else printf("Not found\n");

}

/*
6 7
1 2
2 3
1 3
4 1
4 5
5 6
6 4
*/
