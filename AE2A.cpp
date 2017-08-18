#include <bits/stdc++.h>
using namespace std;
#define ll long long
/*int find_sum(int n,int k)
{
	if(n==0&&k==0)
		return 1;
	if(n<=0||k<=0)
		return 0;
	else
		return find_sum(n-1,k-1)+find_sum(n-1,k-2)+find_sum(n-1,k-3)+find_sum(n-1,k-4)+find_sum(n-1,k-5)+find_sum(n-1,k-6);
}*/
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	float dp[550][3300];
	    for(int i=0;i<550;i++)
	    	for(int j=0;j<3300;j++)
	    		dp[i][j]=0.0f;
        
        for(int i=1;i<=6;i++)
        	dp[1][i]=1.0/6.0;
        for(int i=1;i<=545;i++)
        {
        	for(int j=1;j<=3270;j++)
        	{
        		for(int k=1;k<=6;k++)
        		{
        			if(j-k<0)
        				break;
        			dp[i][j]=dp[i][j]+(dp[i-1][j-k])/6.0f;
        		}
        	}
        }

	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		
        if(n>545||k>3270)
        	cout<<"0\n";
        else
        	cout<<(int)(100*dp[n][k])<<"\n";
	}
	return 0;
}