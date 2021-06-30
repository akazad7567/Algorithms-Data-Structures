//find the maximum length of palindromic subsequence
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
int dp[M][M];
string str;
pair<int,int>nxt[M][M];

int f(int l,int r)
{

    if(l==r) return 1;
    if(l>r) return 0;
    if(dp[l][r]!=-1) return dp[l][r];

    if(str[l]==str[r]) nxt[l][r]={l+1,r-1}, dp[l][r]=f(l+1,r-1)+2;
    else
    {
        int r1=f(l,r-1);
        int r2=f(l+1,r);
        if(r1>r2) nxt[l][r]={l,r-1};
        else nxt[l][r]={l+1,r};
        dp[l][r]=max(r1,r2);
    }
//    debug(l,r,dp[l][r],nxt[l][r].first,nxt[l][r].second);
    return dp[l][r];

}
int main()
{

    cin>>str;

    int n=str.size();
    memset(dp,-1,sizeof dp);
    memset(nxt,-1,sizeof nxt);

    cout<<f(0,n-1)<<endl;
    int l=0,r=n-1;

    string b="",e="";
    while(l<=r)
    {
        if(str[l]==str[r])
        {
            if(l!=r) b+=str[l],e+=str[r];
            else
            {
                b+=str[l];
                break;
            }
        }
        int tmpL;
        tmpL=nxt[l][r].first;
        r=nxt[l][r].second;
        l=tmpL;
        if(l<0 or r<0) break;

    }
    reverse(e.begin(),e.end());
    cout<<b+e<<endl;
}
//xyzxzy
