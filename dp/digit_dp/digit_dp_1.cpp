//How many integers within the range A to B having digit sum equals to X?
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
int dp[11][2][92];
string s="",s2="",A,B;
int x;

void ini(string tmp,bool chk)
{
    for(int i=0;i<10-tmp.size();i++) s+="0";
    s+=tmp;
    for(int i=9;i>=0;i--)
    {
        if(s[i]-'0'>0 and chk)
        {
            s[i]--;
            break;
        }
        else if(chk)
        {
            s[i]+=9;

        }
    }
}
int f(int pos,bool isSmall,int dgtSum)
{
    if(pos==s.size()) return (dgtSum==x);
    if(dp[pos][isSmall][dgtSum]!=-1) return dp[pos][isSmall][dgtSum];

    int v=s[pos]-'0';
    if(isSmall) v=9;
    int ret=0;

    for(int i=0;i<=v;i++)
    {
        bool isSmall2=isSmall | (i<v);
        int val=f(pos+1,isSmall2,dgtSum+i);
        ret+=val;
    }
    return dp[pos][isSmall][dgtSum]=ret;

}
int main()
{


    cin>>A>>B;
    cin>>x;
    ini(A,1);
    memset(dp,-1,sizeof dp);
    int lef=f(0,0,0);
    debug(s,lef);

    memset(dp,-1,sizeof dp);
    s="";
    ini(B,0);
    int rght=f(0,0,0);
    debug(s,rght);
    cout<<rght-lef<<endl;




}
