/*
approach->
1.Pick any vertex as source vertex.
2.Find the most distant vertex from the source. Make this vertex new source.
3.Repeat step 2 two times.
4.Distance between the source and the the most distant vertex from the source is diameter
*/




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

vector<int>g[100050];
int n,m;
int dp[100050];


int dfs(int node)
{
//    debug(node);
    if(g[node].size()==0) return 0;
    if(dp[node]!=-1) return dp[node];

    int dis=0;
    for(int it:g[node])
    {

            dis=max(dis,1+dfs(it));

    }
    return dp[node]=dis;

}
int main()
{
    memset(dp,-1,sizeof dp);
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
    }
    int ans=0;

    for(int i=1;i<=n;i++)
    {
        ans=max(ans,dfs(i));
    }
    cout<<ans<<endl;
}
