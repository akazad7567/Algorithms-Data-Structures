    #include<bits/stdc++.h>
    using namespace std;
    vector<pair<int,int>>adj[1000];
    const int INF=0x3f3f3f3f;
    int cas=0;

    void add(int u,int v,int w)
    {
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    void prims(int N)
    {
        vector<int>key(N,INF);
        vector<int>prnt(N,-1);
        vector<bool>isMST(N,false);
        int src;
        scanf("%d",&src);
        key[src]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,src});
        int cost=0;
        vector<int>wght(1000,0);
    //    cout<<"ok1\n";
        while(!pq.empty())
        {

            int u=pq.top().second;

            if(isMST[u]==false)
            {
                cost+=pq.top().first;
                int wg=wght[prnt[u]];
                if(u==src) wg=0;
                wght[u]=max(wg,pq.top().first);
    //            cout<<wght[u]<<' ';
            }
            pq.pop();
            isMST[u]=true;

            for(auto it:adj[u])
            {
                int v=it.first;
                int w=it.second;
                if(isMST[v]==false and key[v]>w)
                {
                    key[v]=w;
                    pq.push({w,v});
                    prnt[v]=u;
    //                wght[v]=
                }
            }
        }
    //    cout<<"ok\n";
    //    printf("%d\n",cost);
        printf("Case %d:\n",cas);
        for(int i=0;i<N;i++)
        {
            if(isMST[i]==false) printf("Impossible\n");
            else
            printf("%d\n",wght[i]);
        }
    }

    void clean(int N)
    {
        for(int i=0;i<=N;i++)
        {
            adj[i].clear();
        }
    }
    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--){
        cas++;
        int N,E;
        scanf("%d %d",&N,&E);
        for(int i=0;i<E;i++)
        {
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            add(u,v,w);
        }
    //    cout<<"inner\n";

        prims(N);
        clean(N);
        }


    }


