#include<bits/stdc++.h>
using namespace std;
double dp[3005][1505];
bool vis[3005][1505];
int n;
double p[3005];
double const eps=0.00000000001;
int mx_tail;
double cal(int  pos,int cnt)
{
    if(pos==n) return 1.0;
    if(vis[pos][cnt]!=false) return dp[pos][cnt];

    double ret1=0,ret2=0;
    if(cnt<mx_tail) ret1=(1-p[pos])*cal(pos+1,cnt+1);
    ret2=p[pos]*cal(pos+1,cnt);
    vis[pos][cnt]=true;
    return dp[pos][cnt]=ret1+ret2;
}
int main()
{
//    memset(vis,false,sizeof vis);
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%lf",&p[i]);
    mx_tail=n/2;
    if(n==1) printf("%.10f\n",p[0]);
    else
    printf("%.10f\n",(cal(0,0)+eps));
    return 0;
}
