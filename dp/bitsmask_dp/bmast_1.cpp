// count the N length numbers without leading zeros that used all digits (0-9)

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
#define M 1000
int dp[M][1<<10+2];
int n;

bool chk(int msk)
{
    return (bool)(msk&((1<<10)-1));// maybe it's always return true

}
int f(int pos,int msk)
{
    if(pos>=n)
    {
        return chk(msk);
    }
    if(dp[pos][msk]!=-1) return dp[pos][msk];
    int ret=0;
    int low=0;
    if(pos==0) low=1;
    for(int i=low;i<10;i++)
    {
        int val=f(pos+1,msk|(1<<i));
        ret+=val;
    }

    return dp[pos][msk]=ret;
}
int main()
{

    cin>>n;
    memset(dp,-1,sizeof dp);
    cout<<f(0,0)<<endl;

}
