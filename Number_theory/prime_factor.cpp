// Program to print all prime factors
# include <bits/stdc++.h>
using namespace std;
#define MAX 100000
bool b[MAX];
int cnt=0;

void primeFactors(int n)
{
    int flag=0;
	while (n%2 == 0)
	{
	     cnt=1;
		n = n/2;
	}


	for (int i = 3; i <= sqrt(n); i = i+2)
	{

		flag=0;
		while (n%i == 0)
		{
			//printf("%d ", i);
			flag=1;
			n = n/i;
		}
		if(flag) cnt++;

	}


	if (n > 2)
		cnt++;
}

//void prime_check(int n)
//{
//
//    memset(b,true,sizeof b);
//    b[0]=false;
//    b[1]=false;
//    for(int i=2;i*i<=n;i++)
//    {
//        if(b[i])
//        {
//            for(int j=i*i;j<=n;j+=i)
//            {
//                b[j]=false;
//            }
//
//        }
//    }
//}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cnt2=0;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
            cnt=0;
	primeFactors(i);
	if(cnt==2) cnt2++;

	}
	cout<<cnt2<<endl;
	return 0;
}

