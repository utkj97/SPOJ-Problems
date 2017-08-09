#include <bits/stdc++.h>
using namespace std;
int level[1005];
int P[1005][11];
int parent[1005];
int n;
vector <int> v[1005];
bool visited[1005];
void find_levels(int node,int l)
{
     visited[node]=true;
     level[node]=l;
     for(int i=0;i<v[node].size();i++)
     {
     	if(!visited[v[node][i]])
     	{
     		parent[v[node][i]]=node;
     		find_levels(v[node][i],l+1);
     	}
     }
}

int low_com_anc(int u,int v)
{
	if(level[u]<level[v])
		swap(u,v);
	int log;
	for(log=1;log<=level[u];log++);
	--log;
    for(int i=log;i>=0;i--)
    {
    	if(level[u]-(1<<i)>=level[v])
    	{
    		u=P[u][i];
    	}
    }
    if(u==v)
    	return v;
    for(int i=log;i>=0;i--)
    {
    	if(P[u][i]!=-1&&P[u][i]!=P[v][i])
    	{
    		u=P[u][i];
    		v=P[v][i];
    	}
    }
    return parent[u];
}
int main()
{
	int m;
	int x;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&m);
			v[i].clear();
			for(int j=0;j<m;j++)
			{
				scanf("%d",&x);
				v[i].push_back(x);
			}
		}//Input

		for(int i=0;i<n;i++)
		{
			visited[i]=false;
		}

		int root=0;
		parent[0]=-1;
		find_levels(root,0);

		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<11;j++)
			{
				P[i][j]=-1;
			}
		}

		for(int i=0;i<n;i++)
		{
             P[i][0]=parent[i];
		}

		for(int j=1;(1<<j)<=n;j++)
		{
			for(int i=0;i<n;i++)
			{
				if(P[i][j-1]!=-1)
				{
					P[i][j]=P[P[i][j-1]][j-1];
				}
			}
		}
		int q;
		scanf("%d",&q);
		int u,v;
		vector <pair<int,int>> query;
		while(q--)
		{
			scanf("%d %d",&u,&v);
			query.push_back(make_pair(u,v));
		}


		int lca;
		for(int i=0;i<query.size();i++)
        {
            lca=low_com_anc(query[i].first,query[i].second);
            printf("%d\n",lca);
        }


	return 0;
}
