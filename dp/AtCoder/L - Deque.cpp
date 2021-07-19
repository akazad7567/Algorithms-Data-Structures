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
#define M 3005
ll  dp[M][M][2];
int ar[M];
int n;

ll cal(int b,int e,bool chk)
{
    debug(b,e,chk);
    if(e<b) return 0;
    if(dp[b][e][chk]!=-1) return dp[b][e][chk];

    ll r1=0,r2=0,r3=0,r4=0;
    ll mx_taro=0,mx_jaro=0;
    ll mn_taro=0,mn_jaro=0;

    if(chk){
    r1=(ar[b]+cal(b+1,e,!chk));
    r2=(ar[e]+cal(b,e-1,!chk));
    mx_taro=max(r1,r2),mn_taro=min(r1,r2);
    }
    else
    {
        r3=(ar[b]+cal(b+1,e,!chk));
        r4=(ar[e]+cal(b,e-1,!chk));
        mx_jaro=max(r3,r4);
        mn_jaro=min(r3,r4);
    }
    if(mx_taro>=mx_jaro)
    {
        mx_taro=mx_taro-mx_jaro;
    }
    else
    {
        mn_taro-=mn_jaro;
    }
    debug(b,e,mx_taro,mn_taro);
    if(mx_taro>=mn_taro) return dp[b][e][chk]=mx_taro;
    else return dp[b][e][chk]=mn_taro;

}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    memset(dp,-1,sizeof dp);

    cout<<cal(0,n-1,1)<<endl;
}
