#include <bits/stdc++.h>
using namespace std;
#define pf printf
 
int sf()
{
	int n=0;
	char c=getchar_unlocked();
	while(c<33)c=getchar_unlocked();
	while(c>33)
	{
		n=(n<<1)+(n<<3)+(c-'0');
		c=getchar_unlocked();
	}
	return n;
}
int max(int a,int b)
{
	if(a>b)
		return a;
	return b;
}
int main()
{
	int n,i,j,k;
	k=sf();n=sf();
	int wt[n+1]={0},val[n+1]={0},ksk[2][k+1]={0};
	memset(ksk,0,sizeof ksk);
	for(i=1;i<=n;i++)
	{
		val[i]=sf(),wt[i]=sf();
	}
	for(i=1;i<=n;i++)
	{
		if(i%2!=0)
		{
			for(j=1;j<=k;j++)
			{
				if(wt[i]>j)	
					ksk[1][j]=ksk[0][j];
				else
					ksk[1][j]=max(val[i]+ksk[0][j-wt[i]],ksk[0][j]);
			}
		}
		else
		{
			for(j=1;j<=k;j++)
			{
				if(wt[i]>j)
					ksk[0][j]=ksk[1][j];
				else
					ksk[0][j]=max(val[i]+ksk[1][j-wt[i]],ksk[1][j]);
			}
		}
	}
	if(n%2==0)
		pf("%d",ksk[0][k]);
	else
		pf("%d",ksk[1][k]);
	return 0;
} 
