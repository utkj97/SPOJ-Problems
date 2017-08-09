#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000000
#define ll long long
int n,m;
int *parent,*len;
vector <pair<int,pair<int,int>>> edges;
bool compare(const pair<int,pair<int,int>> l,const pair<int,pair<int,int>> r)
{
 	return l.first > r.first;
}
void initialize()
{
	for(int i=1;i<=n;i++)
	{
		parent[i]=i;
		len[i]=1;
	}

}
int root(int x)
{
	while(x!=parent[x])
	{
		parent[x]=parent[parent[x]];
		x=parent[x];
	}
	return x;
}
int join(int i,int j)
{
	int x=root(i);
	int y=root(j);
	if(x==y)
	return 0;
    ll prod=1;
    prod=len[x] * len[y];
    if(len[x]>len[y])
    {
    	parent[y]=parent[x];
    	len[x]=len[x] + len[y];
    }
    else
    {
    	parent[x]=parent[y];
    	len[y]=len[y] + len[x];
    }
    return prod%MOD;
}
ll find_sum()
{
    initialize();
	int s=0;
	ll sum=0;
	for(int i=0;i<edges.size();i++)
	{
         s=s+join(edges[i].second.first,edges[i].second.second);
         sum=(sum+(s* edges[i].first))%MOD;
	}
	return sum;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	parent=new int[n+1];
	len=new int[n+1];
	int x,y,w;
	for(int i=0;i<m;i++)
	{
		cin>>x>>y>>w;
        edges.push_back(make_pair(w,pair<int,int>(x,y)));
	}
	sort(edges.begin(),edges.end(),compare);
    ll ans=find_sum();
    cout<<ans%MOD<<"\n";
    return 0;
}
