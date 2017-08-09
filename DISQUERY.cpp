#include <bits/stdc++.h>
using namespace std;
#define MAX 100005
int maxi[MAX][18];
int mini[MAX][18];
int P[MAX][18];
int parent[MAX];
int level[MAX];
vector <pair<int,int>> v[MAX];
bool visited[MAX];
int n;
void find_levels(int node,int l,int dist)
{
	visited[node]=true;
	level[node]=l;
	if(dist!=-1)
	{
		maxi[node][0]=dist,mini[node][0]=dist;
	}
	for(int i=0;i<v[node].size();i++)
	{
		if(!visited[v[node][i].first])
		{
			parent[v[node][i].first]=node;
			find_levels(v[node][i].first,l+1,v[node][i].second);
		}
	}

}
int lowest_com_anc(int p,int q)
{
	if(level[p]<level[q])
	{
		swap(p,q);
	}
	int log;
	for(log=1;(1<<log)<=level[p];log++);
	--log;
	for(int i=log;i>=0;i--)
	{
		if(level[p]-(1<<i)>=level[q])
			p=P[p][i];
	}
	if(p==q)
		return p;
	for(int i=log;i>=0;i--)
	{
		if(P[p][i]!=-1&&P[p][i]!=P[q][i])
		{
			p=P[p][i];
			q=P[q][i];
		}
	}
	return parent[p];

}
pair<int,int> find_dist(int u,int v)
{
	pair<int,int> pp;
	pp.first=INT_MIN;
	pp.second=INT_MAX;
	int log;
	for(log=1;(1<<log)<=level[u];log++);
	--log;

	for(int i=log;i>=0;i--)
	{
		if(level[u]-(1<<i)>=level[v])
		{
			pp.first=max(pp.first,maxi[u][i]);
			pp.second=min(pp.second,mini[u][i]);
			u=P[u][i];
		}
	}
    return pp;

}
int main()
{
	scanf("%d",&n);
	int x,y,w;
	for(int i=1;i<=n-1;i++)
	{
		scanf("%d %d %d",&x,&y,&w);
		v[x].push_back(make_pair(y,w));
		v[y].push_back(make_pair(x,w));
	}
	for(int i=1;i<=n;i++)
	{
		visited[n]=false;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<18;j++)
		{
			P[i][j]=-1;
			maxi[i][j]=INT_MIN;
			mini[i][j]=INT_MAX;
		}
	}
	int root=1;
	parent[1]=-1;
	find_levels(root,0,-1);
	for(int i=1;i<=n;i++)
	{
		P[i][0]=parent[i];
	}
	for(int j=1;(1<<j)<=n;j++)
	{
		for(int i=1;i<=n;i++)
		{
			if(P[i][j-1]!=-1)
			{
				P[i][j]=P[P[i][j-1]][j-1];
				maxi[i][j]=max(maxi[i][j-1],maxi[P[i][j-1]][j-1]);
				mini[i][j]=min(mini[i][j-1],mini[P[i][j-1]][j-1]);
			}
		}
	}
	//DP to find the LCA
    int q;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d %d",&x,&y);
		pair<int,int> pp;
		int anc=lowest_com_anc(x,y);
		int maxedge,minedge;
		if(x==anc)
		{
			pp=find_dist(y,anc);
			maxedge=pp.first;
            minedge=pp.second;
		}
		else if(y==anc)
		{
			pp=find_dist(x,anc);
			maxedge=pp.first;
			minedge=pp.second;
		}
		else
		{
			pp=find_dist(x,anc);
			maxedge=pp.first;
			minedge=pp.second;
			pp=find_dist(y,anc);
			maxedge=max(maxedge,pp.first);
			minedge=min(minedge,pp.second);
		}
		printf("%d %d\n",minedge,maxedge);
	}
	return 0;
}
