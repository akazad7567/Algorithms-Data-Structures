#include<bits/stdc++.h>
using namespace std;
int ar[10000];
int output[10000];
int n;

void radix(int exp)
{
    int cnt[10]={0};
    for(int i=0;i<n;i++) cnt[ar[i]/exp%10]++;

    for(int i=1;i<10;i++) cnt[i]+=cnt[i-1];

    for(int i=n-1;i>=0;i--) output[cnt[ar[i]/exp%10]-1]=ar[i],cnt[ar[i]/exp%10]--;

    for(int i=0;i<n;i++) ar[i]=output[i];
}
int main()
{
    int mx=-1e9;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&ar[i]),mx=max(mx,ar[i]);

    for(int exp=1;mx/exp>0;exp*=10) radix(exp);

    for(int i=0;i<n;i++) printf("%d ",ar[i]);
    printf("\n");
}
