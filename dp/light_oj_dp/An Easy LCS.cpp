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
string s1,s2;
int dp[102][102];
string ans[102][102];
int ln;

int f(int i,int j)
{
    if(i<0 or j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ret=0;

    if(s1[i]==s2[j])
    {
        ret=1+f(i-1,j-1);
        if(i>0 and j>0)
        ans[i][j]=ans[i-1][j-1]+s1[i];
        else ans[i][j]=s1[i];

    }
    else
    {
        int r1=f(i,j-1);
        int r2=f(i-1,j);
        if(r1>r2)
        {
            if(j>0)
            ans[i][j]=ans[i][j-1];

        }
        else if(r2>r1)
        {
            if(i>0)ans[i][j]=ans[i-1][j];
        }
        else
        {
            if(i>0 and j>0) ans[i][j]=min(ans[i-1][j],ans[i][j-1]);
        }
        ret=max(r1,r2);
    }
    return dp[i][j]=ret;
}

int main()
{
//    freopen("out.txt","w",stdout);
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
    int t,tks=0;
    cin>>t;
    while(t--)
    {

        memset(dp,-1,sizeof dp);
        cin>>s1>>s2;
        int n=s1.size(),m=s2.size();
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                ans[i][j]="";
            }
        }
        ln=f(n-1,m-1);

        string str=ans[n-1][m-1];
        if(ln==0) cout<<"Case "<<++tks<<": :(\n";
        else cout<<"Case "<<++tks<<": "<<str<<endl;

    }
}
