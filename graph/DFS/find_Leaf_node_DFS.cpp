// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;
vector<int>t[1000];
// Function to perform DFS on the tree
void dfs( int node, int parent)
{
    int flag = 1;

    // Iterating the children of current node
    for (int ir : t[node])
    {

        // There is at least a child
        // of the current node
        if (ir != parent)
        {
            flag = 0;
            dfs(ir, node);
        }
    }

    // Current node is connected to only
    // its parent i.e. it is a leaf node
    if (flag == 1)
        cout << node << " ";
}

// Driver code
int main()
{
    // Adjacency list
    int N;
    scanf("%d",&N);
    for(int i=0; i<N-1; i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        t[x].push_back(y);
        t[y].push_back(x);

    }

    // Function call
    dfs(1, 0);

    return 0;
}

