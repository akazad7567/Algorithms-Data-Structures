#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
#include <iostream>
using namespace __gnu_pbds;
using namespace std;

// a new data structure defined. Please refer below
// GNU link : https://goo.gl/WVDL6g
typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> order_set;

int prnt[200000];
int sz[200000];
order_set st;
void ini(int n)
{
    for(int i=1;i<=n;i++) prnt[i]=i,sz[i]=1;
}

int fndRoot(int i)
{
    if(prnt[i]!=i) prnt[i]=fndRoot(prnt[i]);
    return prnt[i];
}
void Union(int u,int v)
{
    int rootU=fndRoot(u);
    int rootV=fndRoot(v);

    if(rootU==rootV) return;
//    int ans=abs(sz[rootU]-sz[rootV]);

    st.erase({sz[rootU],rootU});
    st.erase({sz[rootV],rootV});
    prnt[rootU]=prnt[rootV];
    sz[rootV]+=sz[rootU];
    st.insert({sz[rootV],rootV});


//    return ans;

}


int main()
{
    int n;
    cin>>n;
    ini(n);

    int k;
    cin>>k;
    for(int i=1;i<=n;i++) st.insert({1,i});
    for(int i=0;i<k;i++)
    {
        int a,b;
        cin>>a>>b;
        Union(a,b);
//        auto fst=st.begin();
//        auto lst=st.end();
//        lst--;
//        cout<<st.find_by_order(1)->first<<endl;
        cout<<st.rbegin()->first-st.begin()->first<<endl;
    }
//    cout<<endl<<endl;



}

