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
int dp[102][102];
string str;

int f(int b,int e,bool isMax)
{
//    if(b>e) return 0;
    if(b==e) return (str[b]-'0');
    if(dp[b][e]!=-1) return dp[b][e];
    int ret=0;
    if(isMax) ret=0;
    else ret=INT_MAX;
//    debug(b,e);
    for(int i=b;i<=e;i++)
    {
        if(str[i]-'0'>=0 and str[i]-'0'<=9) continue;
        int v1=f(b,i-1,isMax);
        int v2=f(i+1,e,isMax);
        if(isMax)
        {
            if(str[i]=='+')
            ret=max(ret,v1+v2);
            else ret=max(ret,v1*v2);
        }
        else
        {
            if(str[i]=='+')
            ret=min(ret,v1+v2);
            else ret=min(ret,v1*v2);
        }
    }
//    debug(b,e,ret);
    return dp[b][e]=ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int k;
    cin>>k;
    while(k--){
    cin>>str;
//    debug(str);
    memset(dp,-1,sizeof dp);
    int sz=str.size()-1;
    cout<<f(0,sz,1)<<' ';
    memset(dp,-1,sizeof dp);
    cout<<f(0,sz,0)<<endl;
    }
}
