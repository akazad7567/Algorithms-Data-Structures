#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans=0;
vector<ll>adj[100010];
//map<ll,bool>visited;
vector<bool>visited(100010);
ll ttl=0;
void BFS(ll s)
{

    vector<ll>p(100010,0LL),d(100010,0LL);
    queue<ll>Q;
    //cout<<Q.size()<<endl;
    visited[s]=true;
    //cout<<s<<' ';
    Q.push(s);
    p[s]=-1;

    while(!Q.empty())
    {
        ll v=Q.front();

        Q.pop();
        //cout<<"ok\n";
       // iterator it;
        for(ll u:adj[v])
        {

            if(d[v]>=ttl) break;
            if(!visited[u])
            {
                ans++;
              // cout<<u<<' ';
                visited[u]=true;
                Q.push(u);
                d[u]=d[v]+1;
                p[u]=v;
               // if(d[u]>=ttl) return;
            }


        }
    }

}

int main()
{
   //freopen("out.txt","w",stdout);
    ll E,tks=0;
    while(scanf("%lld",&E)==1LL)
    {

        if(E==0LL)
            break;
        // scanf("%d",&E);
        set<ll>se;
        se.clear();
        ll node1,node2,tmp=0;
        for(ll i=0; i<E; i++)
        {
            scanf("%lld %lld",&node1,&node2);
            adj[node1].push_back(node2);
            adj[node2].push_back(node1);
            se.insert(node1);
            se.insert(node2);
            if(node1==0LL or node2==0LL) tmp=1;

        }

        while(true)
        {
            ans=0;
            ll start,cnt=0;
            scanf("%lld %lld",&start,&ttl);
            if(start==0LL and ttl==0LL)
                break;
            BFS(start);
            tks++;

            for(ll i=0; i<100010; i++)
            {
               // if(se.count(i)) cout<<"ok\n";
                if(visited[i]==true and se.count(i))
                {
                    cnt++;
                }
                visited[i]=false;
            }

           cout<<"Case "<<tks<<": "<<se.size()-cnt<<" nodes not reachable from node "<<start<<" with TTL = "<<ttl<<".\n";

        }


        for(ll i=0; i<100010; i++)
        {
            adj[i].clear();
        }

    }
}
