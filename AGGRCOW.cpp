#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,c;
ll *arr;
bool possibleToFit(ll x)
{ 
	ll prev=arr[0]+x;
	int k=1;
	int i;
	for(i=1;i<n;i++)
	{
		if(prev>arr[i])
			continue;
		prev=arr[i]+x;
		k++;
		if(k==c)
			return true;
	}
    return false;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&c);
		arr=new ll[n];
		int i;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&arr[i]);
		}
		sort(arr,arr+n);
		ll l,h;
		l=1;
		h=arr[n-1];
		ll mid;
		ll ans;
		bool p,q;
		while(l<=h)
		{
           mid=l+(h-l)/2;
           p=possibleToFit(mid);
           q=possibleToFit(mid+1);
           if(p&&!q)
              {
                ans=mid;
                break;
              }
           else if(p&&q)
                   l=mid+1;   
           else
           	    h=mid-1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

