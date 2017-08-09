#include <bits/stdc++.h>
using namespace std;
#define MAX 1005
int n,c;
int *wt;
vector <int> *graph;
bool *visited;
int dp[MAX][MAX];
int compowt[MAX];
int composz[MAX];
pair<int,int> dfs(int node)
{
	visited[node]=true;
	int s=0;
	int c=0;
	pair<int,int> pp;
	for(int i=0;i<graph[node].size();i++)
	{
		if(!visited[graph[node][i]])
		{
			pp=dfs(graph[node][i]);
			s+=pp.first;
			c+=pp.second;
		}

	}
	pair<int,int> sp(s+wt[node],c+1);
	return sp;
}
int main()
{
    ios_base::sync_with_stdio(false);

	while(true)
	{
	    cin>>n>>c;
        if(n==0&&c==0)
            break;
		wt=new int[n+1];
		graph=new vector<int> [n+1];
		visited=new bool[n+1];
		int x;
		for(int i=1;i<=n;i++)
		{
			cin>>x;
            wt[i]=x;
		}
		int k;
		for(int i=1;i<=n;i++)
		{
			cin>>k;
            for(int j=0;j<k;j++)
            {
            	cin>>x;
            	graph[i].push_back(x);
            	graph[x].push_back(i);
            }
		}
		int p=0;
		for(int i=1;i<=n;i++)
			visited[i]=false;

		for(int i=1;i<=n;i++)
		{
			if(!visited[i])
			{
				pair <int,int> pp=dfs(i);
				compowt[p]=pp.first;
				composz[p]=pp.second;
				p++;
			}
		}
		for(int i=0;i<=p;i++)
		{
			for(int j=0;j<=c;j++)
			{
				if(i==0||j==0)
				{
					dp[i][j]=0;
				}
				else if(compowt[i-1]<=j)
				{
					dp[i][j]=max(composz[i-1] + dp[i-1][j-compowt[i-1]],dp[i-1][j]);
				}
				else
					dp[i][j]=dp[i-1][j];
			}
		}
		cout<<dp[p][c]<<"\n";
	}
	return 0;
}
