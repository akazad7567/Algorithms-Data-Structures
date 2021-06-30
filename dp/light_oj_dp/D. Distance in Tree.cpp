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
typedef long long ll;
ll dp[50005][505];
ll n,k;
vector<ll>graph[50005];
ll ans=0;
//void ini(int pos)
//{
//
//        for(ll j=0;j<=k;j++)
//        {
//            dp[pos][j]=0;
//
//        }
//
//}
void dfs(ll pos,ll prnt)
{
//    ini(pos);
    dp[pos][0]=1;
//    debug(pos,prnt);
    for(ll child:graph[pos])
    {
        if(child==prnt) continue;
//        if(child==pos) debug("wrong");
        dfs(child,pos);

        for(ll i=0;i<k;i++)
        {
            ans+=dp[child][i]*dp[pos][k-(i+1)];
        }
        for(ll i=0;i<k;i++) dp[pos][i+1]+=dp[child][i];
    }
//    debug(pos,ans);
}
int main()
{
    cin>>n>>k;
    for(ll i=0;i<n-1;i++)
    {
        ll x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    dfs(1,-1);
    cout<<ans<<endl;
}
