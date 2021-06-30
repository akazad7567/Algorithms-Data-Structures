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

#define M 105
int dp[M][M];
int n,w;
vector<pair<int,int>>vec;

int bs(int pos)
{
    int val=vec[pos].first+w;
    int lef=pos,rght=n-1;
    int b=false;
    while(lef<=rght)
    {
        int mid=(lef+rght)/2;
        if(vec[mid].first<=val)
        {
            lef=mid+1;
            b=true;
        }
        else rght=mid-1;
    }
    return lef;
}


int f(int pos,int k)
{
    if(pos>=n or k<=0) return 0;
    if(dp[pos][k]!=-1) return dp[pos][k];

    int ret=0,nxt=0;
    nxt=bs(pos);
    ret=(nxt-pos)+f(nxt,k-1);
    ret=max(ret,f(pos+1,k));

    dp[pos][k]=ret;
    return ret;
}
int main()
{
//    freopen("out.txt","w",stdout);
    int t,tks=0;
    cin>>t;
    while(t--)
    {
        int k;
        cin>>n>>w>>k;
        memset(dp,-1,sizeof dp);
        vec.clear();
        for(int i=0;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            vec.push_back({y,x});
        }
        sort(vec.begin(),vec.end());
        int r1=f(0,k);
        cout<<"Case "<<++tks<<": "<<r1<<endl;
    }
}
