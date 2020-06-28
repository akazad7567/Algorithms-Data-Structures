#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//vector<ll>adj[10000000];
map<string,vector<string>>adj;
map<string,bool>visited;
map<string,ll>p,d;
ll a,b;
int cnt=0;
bool create(ll x)
{
   // cout<<x<<' ';
    cnt++;
    if(cnt>1 and x%2==0 and x<=b)
    {
        //cout<<"mara\n";
        string s1=to_string(x);
        string s2=to_string(x/2);
        adj[s1].push_back(s2);
        adj[s2].push_back(s1);
    }
    if(cnt>1 and x%2==1 and x<=b)
    {
        string s1=to_string(x);
        string s2=to_string(x/10);
        adj[s1].push_back(s2);
        adj[s2].push_back(s1);
        //cout<<"mara2\n";
    }

    if(x<b) return create(x*2)+create(x*10+1);
    else if(x==b) return true;
    else return false;
//    if(create(x*2))
//    {
//        cout<<x<<' '<<x*2<<endl;
//        adj[x].push_back(x*2);
//        adj[x*2].push_back(x);
//    }
//    if(create(x*10+1))
//    {
//        cout<<x<<' '<<x*10+1<<endl;
//        adj[x].push_back(x*10+1);
//        adj[x*10+1].push_back(x);
//    }
}

void DFS(string x)
{
    visited[x]=true;
    //cout<<x<<' ';
    for(string u:adj[x])
    {
        if(visited[u]==false)
        {
            //visited[u]=true;
            stringstream ss(x);
            ll tmp;
            ss>>tmp;

            p[u]=tmp;
            d[u]=d[x]+1;
            DFS(u);
        }
    }
}
int main()
{
    vector<string>ans;

    scanf("%lld %lld",&a,&b);
    if(create(a)){
    DFS(to_string(a));
    cout<<"YES\n";
    ll re=d[to_string(b)]+1;
    cout<<re<<endl;
    string tmp=to_string(b);
    for(ll i=0;i<re;i++)
    {
        ans.push_back(tmp);
        //cout<<tmp<<' ';
        tmp=to_string(p[tmp]);

    }
    reverse(ans.begin(),ans.end());
    for(ll i=0;i<re;i++) cout<<ans[i]<<' ';

    }
    else cout<<"NO";
    cout<<endl;




}
