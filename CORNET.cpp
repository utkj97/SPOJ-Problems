#include <bits/stdc++.h>
using namespace std;
#define MAXZ 20005
int n;
int center[MAXZ];
int dist[MAXZ];
void initialize()
{
	int i;
	for(i=1;i<=n;i++)
	{
		center[i]=i;
		dist[i]=0;
	}
}
void find_dist(int x)
{
   if(center[x]!=x)
   {
      find_dist(center[x]);
      dist[x]=dist[x]+dist[center[x]];
      center[x]=center[center[x]];
   }
}

void make_center(int i,int j)
{
    center[i]=center[j];
    dist[i]=abs(i-j)%1000 + dist[j];
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%d",&n);
		char ch;
		initialize();
		int i,j;
		while(scanf("%c",&ch)&&ch!='O')
		{
			switch(ch)
			{
				case 'I': scanf("%d %d",&i,&j);
				          make_center(i,j);
				          break;

				case 'E': scanf("%d",&i);
				          find_dist(i);
				          printf("%d \n",dist[i]);
				          break;
			}

		}
	}
	return 0;

}
