#include <bits/stdc++.h>
using namespace std;
#define ll long long
int *price;
int *weight;
int n;
ll m=1000000001;
ll knapsack(int w)
{
	ll dp[w+1];
	int i=1;
	int j=0;
	dp[0]=0;
	while(i<=w)
	{   dp[i]=m;
		j=0;
		while(j<n)
			 { 
			 	if(weight[j]<=i)
			 	{
			 		dp[i]=min(dp[i],price[j]+dp[i-weight[j]]);
			 	}
			 	j++;
			 }
        i++;
      
	}

	return dp[w];
}
int main()
{
    int t;
    scanf("%d",&t);
    int e,f;
    while(t--)
    {

    	scanf("%d %d",&e,&f);
    	scanf("%d",&n);
    	int i=0;
    	price=new int[n];
    	weight=new int [n];
    	while(i<n)
    	{
           scanf("%d %d",&price[i],&weight[i]);
           i++;
    	}
    	ll res=knapsack(f-e);
    	if(res>=m)
    	   printf("This is impossible.\n");
    	   
    	else
    	   printf("The minimum amount of money in the piggy-bank is %lld.\n",res);   	

    }
    return 0;

}