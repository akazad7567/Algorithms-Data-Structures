#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <math.h>
#include <unordered_map>
#include <tr1/unordered_map>

using namespace std;
#define me(x,y) memset(x,y,sizeof x)
#define MIN(x,y) x < y ? x : y
#define MAX(x,y) x > y ? x : y

typedef long long ll;
typedef unsigned long long ull;

const int maxn = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
const double eps = 1e-06;
const double PI = acos(-1);

int main(){
    int t;
    int ca = 1;
    cin>>t;
    while(t--){
        int p,l;
        set<int>s;
        scanf("%d%d",&p,&l);
        int n = p-l;
        for(ll i = 1; i*i <= n; ++i){
            if(n%i==0){
                if(i > l) s.insert((int)i);
                if(i*i != n && n/i > l) s.insert((int)n/i);
            }
        }
        printf("Case %d:",ca++);
        if(s.empty()){
            printf(" impossible\n");
            continue;
        }
        set<int>::iterator it;
        for(it = s.begin(); it != s.end(); it++){
            printf(" %d",*it);
        }
        printf("\n");
    }
    return 0;
}

/*

*/
