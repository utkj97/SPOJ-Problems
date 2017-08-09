#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
bool *inc;
int *milk;
vector <pair<int,int>> *nodes;
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		nodes=new vector <pair<int,int>> [n+2];
		milk=new int[n+1];
		inc=new bool[n+2];
		for(int i=1;i<=n;i++)
		{
			cin>>milk[i];
		}
		int x,y,w;
		for(int i=0;i<m;i++)
		{
			cin>>x>>y>>w;
            nodes[x].push_back(pair<int,int>(w,y));
            nodes[y].push_back(pair<int,int>(w,x));
		}
		int l=0;
		for(int i=1;i<=n;i++)
		{
			if(milk[i])
			{
				l=1;
				nodes[n+1].push_back(pair<int,int>(0,i));
                nodes[i].push_back(pair<int,int>(0,n+1));

			}
		}
		if(l==0)
		{
			cout<<"impossible\n";
			continue;
		}
		for(int i=1;i<=n+1;i++)
		{
			inc[i]=false;
		}
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> Q;
		ll mincost=0;
		Q.push(pair<int,int>(0,1));
		while(!Q.empty())
		{
			pair<int,int> p=Q.top();
			Q.pop();
			x=p.second;
			w=p.first;
			if(inc[x])
              continue;
            inc[x]=true;
            mincost=mincost+w;
			for(int i=0;i<nodes[x].size();i++)
			{
				if(!inc[nodes[x][i].second])
                   Q.push(nodes[x][i]);
			}
		}
		int f=0;
		for(int i=1;i<=n;i++)
		{
			if(!inc[i])
			{
				f=1;break;
			}
		}
		if(f==0)
		cout<<mincost<<"\n";
        else
        cout<<"impossible\n";

	}
    return 0;
}
