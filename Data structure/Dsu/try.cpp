#include <bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
set <PII> keep;
int parent [100005];
int sz[100005];
int findset (int a)
{
	if(parent[a]==0)return a;return parent[a]=findset(parent[a]);
}
void merge (int a,int b)
{
	int k = findset(a), kk = findset(b);
	if(k==kk)return;
	parent[k]=kk;
	keep.erase(PII(sz[kk], kk));
	keep.erase(PII(sz[k], k));
	sz[kk]+=sz[k];
	keep.insert(PII(sz[kk],kk));
}
int main()
{
	ios_base::sync_with_stdio(0);
	int N, Q; cin >> N >> Q;
	for (int g=1;g<=N;g++)keep.insert(PII(1, g)),sz[g]=1;
	for (int g=0; g<Q; g++)
	{
		int a, b; cin >> a >> b;
		merge(a, b);
		set <PII> :: iterator ending = keep.end(); ending--;
		set <PII> :: iterator beginning = keep.begin();
		cout << (*ending).first-(*beginning).first << '\n';
	}
	return 0;
}
