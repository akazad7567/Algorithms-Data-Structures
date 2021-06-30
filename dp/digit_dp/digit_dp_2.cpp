//If we write integers from A to B(A,B<=10^9), how many zeros will be write?
//(Leading zero Not allowed)

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
int dp1[11][2][2];
int dp2[11][2];
string str,A,B;

void ini(string s,bool chk)
{
    string tmp1="";
    for(int i=0;i<10-s.size();i++) tmp1+="0";
    if(chk)
    {
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]-'0'>0)
            {
                s[i]--;
                break;
            }
            else s[i]+=9;
        }
    }

    str=tmp1+s;
}
int f2(int pos,bool isSmall)
{
    if(pos==str.size()) return 1;
    if(dp2[pos][isSmall]!=-1) return dp2[pos][isSmall];

    int v=str[pos]-'0';
    if(isSmall) v=9;
    int ret=0;

    for(int i=0;i<=v;i++)
    {
        int val=f2(pos+1,isSmall|(i<v));
        ret+=val;
    }
    return dp2[pos][isSmall]=ret;
}
int f(int pos,bool isSmall,bool hasStart)
{
    if(pos==str.size()) return 0;
    if(dp1[pos][isSmall][hasStart]!=-1) return dp1[pos][isSmall][hasStart];

    int ret=0;
    int v=str[pos]-'0';
    if(isSmall) v=9;

    for(int i=0;i<=v;i++)
    {
        int val=f(pos+1,isSmall|(i<v),hasStart|(i!=0));
        if(hasStart and i==0) val+=f2(pos+1,isSmall|(i<v));
        ret+=val;
    }
    return dp1[pos][isSmall][hasStart]=ret;
}

int main()
{
    cin>>A>>B;
    ini(A,1);
    memset(dp1,-1,sizeof dp1);
    memset(dp2,-1,sizeof dp2);
    int lef=f(0,0,0);
    debug(str,lef);

    ini(B,0);
    memset(dp1,-1,sizeof dp1);
    memset(dp2,-1,sizeof dp2);
    int rght=f(0,0,0);
    debug(str,rght);
    cout<<rght-lef<<endl;


}
