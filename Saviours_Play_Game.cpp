#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

typedef long long ll;
const int N=1e3+5;

int n, m;
ll a[N][N];
ll dp1[N][N]; //Going from 1,1 to i,j
ll dp2[N][N]; //Going from i,j to n,m
ll dp3[N][N]; //Going from n,1 to i,j
ll dp4[N][N]; //Going from i,j to 1,m


int main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			dp1[i][j]=a[i][j] + max(dp1[i-1][j], dp1[i][j-1]);
		}
	}
	for(int i=n;i>=1;i--)
	{
		for(int j=m;j>=1;j--)
		{
			dp2[i][j]=a[i][j] + max(dp2[i+1][j], dp2[i][j+1]);
		}
	}
	for(int i=n;i>=1;i--)
	{
		for(int j=1;j<=m;j++)
		{
			dp3[i][j]=a[i][j] + max(dp3[i+1][j], dp3[i][j-1]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=1;j--)
		{
			dp4[i][j]=a[i][j] + max(dp4[i-1][j], dp4[i][j+1]);
		}
	}
	ll ans=0;
	for(int i=2;i<n;i++)
	{
		for(int j=2;j<m;j++)
		{
			ans=max(ans, dp1[i][j-1] + dp2[i][j+1] + dp3[i+1][j] + dp4[i-1][j]);
			ans=max(ans, dp1[i-1][j] + dp2[i+1][j] + dp3[i][j-1] + dp4[i][j+1]);
		}
	}
	cout<<ans;
	return 0;
}
