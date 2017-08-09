#include <bits/stdc++.h>
using namespace std;
int *par;
int n;
int m;
int compo;
vector<pair<int,int>> edges;
void initialize()
{
	for(int i=1;i<=n;i++)
	{
		par[i]=i;
	}
}
int root(int x)
{
	while(x!=par[x])
	{
		par[x]=par[par[x]];
		x=par[x];
	}
	return x;
}
void join(int i,int j)
{
	int x=root(i);
    int y=root(j);
    if(x==y)
    return;
   	par[x]=par[y];
    compo--;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	par=new int[n+1];
	initialize();
	int x,y;
	compo=n;
	for(int i=0;i<m;i++)
	{
		cin>>x>>y;
		edges.push_back(pair<int,int>(x,y));
	}
	for(int i=0;i<edges.size();i++)
	{
		join(edges[i].first,edges[i].second);
	}
    cout<<compo<<"\n";
    return 0;
}
