#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define sf scanf
#define pf printf
ll *stree,*lazy;
 
void update(ll s,ll e,ll pos,ll l,ll r,ll val)
{
	if(lazy[pos]!=0)
	{
		stree[pos]+=(e-s+1)*lazy[pos];
		if(s!=e)
		{
			lazy[2*pos+1]+=lazy[pos];
			lazy[2*pos+2]+=lazy[pos];
		}
		lazy[pos]=0;
	}
	if(s>e||s>r||e<l)
		return;
	if(s>=l&&e<=r)
	{
		stree[pos]+=(e-s+1)*val;
		if(s!=e)
		{
			lazy[2*pos+1]+=val;
			lazy[2*pos+2]+=val;
		}
		return;
	}
	ll mid=(s+e)/2;
	update(s,mid,2*pos+1,l,r,val);
	update(mid+1,e,2*pos+2,l,r,val);
	stree[pos]=stree[2*pos+1]+stree[2*pos+2];
}
ll query(ll s,ll e,ll pos,ll l,ll r)
{
	if(s>e||s>r||e<l)
		return 0;
	if(lazy[pos]!=0)
	{
		stree[pos]+=(e-s+1)*lazy[pos];
		if(s!=e)
		{
			lazy[2*pos+1]+=lazy[pos];
			lazy[2*pos+2]+=lazy[pos];
		}
		lazy[pos]=0;
	}
	if(s>=l&&e<=r)
		return stree[pos];
	ll mid=(s+e)/2;
	return query(s,mid,2*pos+1,l,r)+query(mid+1,e,2*pos+2,l,r);	
}
int main()
{
	ll t;
	sf("%lld",&t);
	while(t--)
	{
		ll n,c,p,q,v,type;
		sf("%lld %lld",&n,&c);
		stree=new ll[4*n];
		lazy=new ll[4*n];
		memset(stree,0,sizeof stree);
		memset(lazy,0,sizeof lazy);
		while(c--)
		{
			sf("%lld",&type);
			if(type==0)
			{
				sf("%lld %lld %lld",&p,&q,&v);
				p--;q--;
				update(0,n-1,0,p,q,v);
			}
			else
			{
				sf("%lld %lld",&p,&q);
				p--;q--;
				pf("%lld\n",query(0,n-1,0,p,q));
			}
		}
	}
	return 0;
} 
