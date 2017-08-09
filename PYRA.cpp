#include <bits/stdc++.h>
using namespace std;
#define  MAX 10005
vector <int> *graph;
bool visited[MAX];
int length[MAX];
int n;
void initialize()
{
   for(int i=0;i<n;i++)
   {
   	visited[i]=false;
   	length[i]=0;
   }
}
void find_vol(int node)
{
	visited[node]=true;
	int c=0;
	int s=0;
	for(int i=0;i<graph[node].size();i++)
	{
		if(!visited[graph[node][i]])
		{
			c++;
            find_vol(graph[node][i]);
            s=s+length[graph[node][i]];
		}
	}
	length[node]=s+c+1;
}
int main()
{
	int  t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int x,y;
		graph= new vector<int>[n];
		for(int i=1;i<n;i++)
		{
			scanf("%d %d",&x,&y);
			graph[x].push_back(y);
			graph[y].push_back(x);
		}

		initialize();
		find_vol(0);
		int sum=0;
		for(int i=0;i<n;i++)
        {
            sum=sum+length[i];
        }
        printf("%d\n",sum);
	}
     return 0;
}
