#include <bits/stdc++.h>
using namespace std;
int dp[1001];
void knapsack()
{
    int p=sqrt(1000);
    int sq[p+1];
    int k=0;
    while(k<=p)
    {
        sq[k]=k*k;
        k++;
    }
    dp[0]=0;
    dp[1]=1;
    int i=1;
    int j=1;
    while(i<=1000)
    {   dp[i]=i;
            j=1;
        while(j<=p&&sq[j]<=i)
        {
            dp[i]=min(dp[i],1+dp[i-sq[j]]);
            j++;
        }
        i++;
    }

}
int main()
{
    int t;
    knapsack();
    cin>>t;
    int x;
    while(t--)
    {
    	cin>>x;
    	cout<<dp[x]<<"\n";
    }
 
    return 0;
}
