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

ll dp[65][65];
string s;

ll cal(ll b,ll e)
{
    if(b==e) return 1LL;
    if(e<b) return 0LL;
    if(dp[b][e]!=-1) return dp[b][e];
    ll ret=0;
    if(s[b]==s[e]) ret=1+cal(b,e-1)+cal(b+1,e);
    else ret=cal(b,e-1)+cal(b+1,e)-cal(b+1,e-1);
//    debug(b,e,ret);
    return dp[b][e]=ret;
}
int main()
{
    int t,tks=0;
    cin>>t;
    while(t--)
    {
        memset(dp,-1,sizeof dp);
        cin>>s;
        ll n=s.size();
        cout<<"Case "<<++tks<<": "<<cal(0,n-1)<<endl;
    }
}
