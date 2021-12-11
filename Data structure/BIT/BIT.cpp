#include <bits/stdc++.h>
using namespace std;

int ar[100010];
int tree[100010];

int query(int idx){
    int sum=0;
    while(idx>0){
        sum+=tree[idx];
        idx-=(idx&-idx);
    }
    return sum;
}

void update(int idx,int val,int n){
    while(idx<=n){
        tree[idx]+=val;
        idx+=(idx&-idx);
    }
}

void print(int *ar,int n){
    for(int i=1;i<=n;++i){
        cout<<ar[i]<<" ";
    }
    puts("");
}

int main(){
    int n,a,b;
    cin >> n;
    for(int i=1;i<=n;++i){
        cin>>ar[i];
        update(i,ar[i],n);
    }

    cout<<"input array - ";
    print(ar,n);

    cout<<"tree array - ";
    print(tree,n);
    cin>>a>>b;
    cout<<query(b)-query(a-1);

    return 0;
}

/*
5
4 3 5 6 1
input array - 4 3 5 6 1
tree array - 4 7 5 18 1
2 5
15
*/
