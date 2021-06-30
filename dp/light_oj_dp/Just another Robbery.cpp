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


#define M1 102
#define M2 10020
double dp[M1][M2];
int vis[M1][M2];
int n;
int money[M1];
double caught[M1];
double p,eps=1e-7;

double f(int pos,int taka)
{
    if(pos==n) return (taka==0)?1.0:0.0;
    if(vis[pos][taka]!=-1) return dp[pos][taka];
    vis[pos][taka]=1;
    double ret=0;

    ret=f(pos+1,taka);
    if(taka-money[pos]>=0) ret=max(ret,(1.0-caught[pos])*f(pos+1,taka-money[pos]));


    return dp[pos][taka]=ret;
}
int main()
{
//    freopen("out.txt","w",stdout);
    int t,tks=0;
    cin>>t;
    while(t--)
    {
        int tot=0;
        cin>>p>>n;
        for(int i=0;i<n;i++) cin>>money[i]>>caught[i],tot+=money[i];
        memset(vis,-1,sizeof vis);
        int ans=0;

        for(int i=1;i<=tot;i++)
        {
            if((1.0-p)<=f(0,i)+eps) ans=max(ans,i);
//              if(p>=(1.0-f(0,i))) ans=max(ans,i);
        }
        cout<<"Case "<<++tks<<": "<<ans<<endl;


    }


}
/*
3
0.04 3
1 0.02
2 0.03
3 0.05
0.06 3
2 0.03
2 0.03
3 0.05
0.10 3
1 0.03
2 0.02
3 0.05
*/

