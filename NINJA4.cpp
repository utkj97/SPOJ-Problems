#include <bits/stdc++.h>
using namespace std; 
#define ll long long
ll find_x(ll n)
{
	ll x,y;
	ll sum;
	if(n%2==0)
	{
		x=n/2;
		y=n/2; 
	}	
	else
	{
		x=n/2+1;
		y=n/2; 
	}

	sum = x*( 2 + (x-1)*4 )/2 - y*( 6 + (y-1)*4)/2; 
	return sum;
}
ll find_y(ll n)
{
	ll x,y;
	ll sum;
	if(n%2==0)
	{
		x=n/2;
		y=n/2; 
	}	
	else
	{
		x=n/2+1;
		y=n/2; 
	}

	sum = x*( 4 + (x-1)*4 )/2 - y*( 8 + (y-1)*4 )/2; 
	return sum;
}
pair<ll,ll> find_pos(ll n)
{
	pair<ll,ll> pp;
	ll x,y;
	if( n%2==0 )
	{
		x=find_x(n/2);
		y=find_y(n/2);
	}	
	else
	{
		x=find_x(n/2+1);
		y=find_y(n/2);
	}

	pp.first=x;
	pp.second=y;
	return pp;
}
int main()
{
	ll t;
	ll n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		pair <ll,ll> pp=find_pos(n);
		cout<<pp.first<<" "<<pp.second<<"\n";
	}

	return 0;
}