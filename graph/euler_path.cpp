    //you are given an undirected and unweighted graph

    #include<bits/stdc++.h>
    using namespace std;
    vector<int> g[1000];
    void add_edge(int from, int to)
    {
        g[from].push_back(to);
        g[to].push_back(from);
    }
    void dfs(int cur, bool visited[])
    {
        visited[cur] = true;
        for(auto adj: g[cur])
            if(!visited[adj])
                dfs(adj, visited);
    }
    bool isConnected(int n, bool visited[])
    {
        int start=-1;
        for(int i=0 ; i<n ; ++i)
        {
//            cout<<i<<' ';
            if(!visited[i] && g[i].size() > 0)
            {
//                cout<<"inner= "<<i<<endl;
                if(start == -1)             // First component
                {
                    dfs(i, visited);
                    start = i;
                }
                else                        // Second component
                {
                    cout<<"The graph is not Eulerian"<<endl;
                    return false;
                }
            }
            visited[i] = true;
        }


        return true;                        // 0 or 1 Component
    }
    void checkGraph(int n)
    {
        bool visited[n];
        fill(visited, visited+n, false);
        if(isConnected(n, visited))
        {
            int oddV = 0;                   // Count odd degree vertices
            for(int i=0 ; i<n ; ++i)
                if(g[i].size()%2 == 1)
                    oddV++;

            if(oddV == 0)
                cout<<"The graph has Euler Circuit"<<endl;
            else if(oddV == 2)
                cout<<"The graph has Euler Path"<<endl;
            else
                cout<<"The graph is not Eulerian"<<endl;
        }
    }
    int main()
    {
        for(int i=0 ; i<5 ; ++i) g[i].clear();  // Clears all the edges
        add_edge(3, 4);
        add_edge(4, 2);
        add_edge(2, 3);
        add_edge(4, 1);
        add_edge(1, 0);
        checkGraph(5);

        for(int i=0 ; i<5 ; ++i) g[i].clear();  // Clears all the edges
        add_edge(3, 4);
        add_edge(4, 2);
        add_edge(2, 3);
        add_edge(4, 1);
        add_edge(1, 0);
        add_edge(3, 1);
        checkGraph(5);
//        for(int i=0 ; i<3 ; ++i) g[i].clear();  // Clears all the edges
//        add_edge(2, 1);
//        add_edge(1, 0);
//        add_edge(0, 2);
//        checkGraph(3);
//        for(int i=0 ; i<3 ; ++i) g[i].clear();  // Clears all the edges
//        checkGraph(3);
        return 0;
    }
