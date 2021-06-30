#include<bits/stdc++.h>
using namespace std;
#define XOX (-D XOX
typedef long long ll;
//debug for single line start from here
template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl //debug for single line ending here

//debug for multiple line start from here
vector<string> vec_splitter(string s) {
	s += ',';
	vector<string> res;
	while(!s.empty()) {
		res.push_back(s.substr(0, s.find(',')));
		s = s.substr(s.find(',') + 1);
	}
	return res;
}
void debug_out(
vector<string> __attribute__ ((unused)) args,
__attribute__ ((unused)) int idx,
__attribute__ ((unused)) int LINE_NUM) { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
	if(idx > 0) cerr << ", "; else cerr << "Line(" << LINE_NUM << ") ";
	stringstream ss; ss << H;
	cerr << args[idx] << " = " << ss.str();
	debug_out(args, idx + 1, LINE_NUM, T...);
}
#ifdef XOX
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#else
#define debug(...) 42
#endif

#define M 1010
ll dp[M],cnt[M];
vector<ll>graph[M],graph2[M];
ll const mod=1e9+7;
ll fac[M],inv[M];
bool vis[M];
ll notroot[M];

void ini()
{
    for(ll i=0;i<M;i++) graph[i].clear(),notroot[i]=0;

}
ll bmod(ll a,ll b)
{
    if(b==0) return 1;
    ll r=bmod(a,b/2);
    r=(r*r)%mod;
    if(b&1) r*=a;
    return r%mod;
}
void cal()
{
    fac[0]=inv[0]=1;
    for(ll i=1;i<M;i++)
    {
        fac[i]=(fac[i-1]*i)%mod;
//        debug(i,fac[i]);
    }
    inv[M-1]=bmod(fac[M-1],mod-2);
//    debug(inv[M-1]);

    for(ll i=M-2;i>=1;i--)
    {
        inv[i]=(inv[i+1]*(i+1))%mod;
//        debug(i,inv[i]);
    }


}
void dfs(ll pos,ll prnt)
{
    cnt[pos]=0,dp[pos]=1;
//    debug(pos);
    for(ll to:graph[pos])
    {
        if(to==prnt) continue;
        dfs(to,pos);
        dp[pos]=(dp[pos]*dp[to])%mod;
        dp[pos]=(dp[pos]*inv[cnt[to]])%mod;
//        debug(dp[pos],inv[cnt[to]]);
        cnt[pos]+=cnt[to];

    }
    dp[pos]=(dp[pos]*fac[cnt[pos]])%mod;
    cnt[pos]++;
    debug(pos,cnt[pos]);
}
int main()
{
//    freopen("out.txt","w",stdout);

    cal();
    ll t,tks=0;
    cin>>t;
    while(t--)
    {
        ini();
        ll n;
        cin>>n;
        ll st=0;
        for(ll i=0;i<n-1;i++)
        {
            ll u,v;
            cin>>u>>v;
            graph[u].push_back(v);
            notroot[v]=1;
        }
        for(int i=1;i<=n;i++)
        {
            if(notroot[i]) continue;
            st=i;
            dfs(i,-1);
            break;
        }
//        if(n==1) dp[st]=1;
        cout<<"Case "<<++tks<<": "<<dp[st]<<endl;


    }

}
/*
10
5
2 1
2 3
3 4
3 5
....

11
1 2
1 3
2 4
2 5
5 8
8 10
3 7
3 6
6 9
9 11


*/
