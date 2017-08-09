#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	int n;
	scanf("%d",&n);
	int *arr=new int[n];
	i=0;
	while(i<n)
	{
		scanf("%d",&arr[i]);
		i++;
	}
    int j,k;
    vector <ll> lhs;
    vector <ll> rhs;
    for(i=0;i<n;i++)
    {
    	for(j=0;j<n;j++)
    	{
    		for(k=0;k<n;k++)
    		{
    			lhs.push_back(arr[i]*arr[j]+arr[k]);
    		}
    	}
    }
    for(i=0;i<n;i++)
    {
         if(arr[i]==0)
         	continue;
         for(j=0;j<n;j++)
         {
         	for(k=0;k<n;k++)
         	{
         		rhs.push_back(arr[i]*(arr[j]+arr[k]));
         	}
         }

    }
    ll ans=0;
    sort(lhs.begin(),lhs.end());
    sort(rhs.begin(),rhs.end());
    for(i=0;i<lhs.size();i++)
        {  
           ans+= upper_bound(rhs.begin(),rhs.end(),lhs[i])-lower_bound(rhs.begin(),rhs.end(),lhs[i]);
        }

    printf("%lld\n",ans);    

}