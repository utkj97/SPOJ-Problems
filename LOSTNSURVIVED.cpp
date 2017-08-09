#include <bits/stdc++.h>
using namespace std;
int *arr,*size;
int n;
multiset <int> ms;
void initialize()
{
    int i;
    for(i=1;i<=n;i++)
    {
    	arr[i]=i;
    	size[i]=1;
    	ms.insert(1);
    }

}
int root(int x)
{
    while(x!=arr[x])
    {

    	arr[x]=arr[arr[x]];
    	x=arr[x];
    }
    return x;
}

void dounion(int x,int y)
{
	if(root(x)==root(y))
		return ;
	else
    {   

		int root_x=root(x);
	    int root_y=root(y);
	    ms.erase(ms.find(size[root_x]));
	    ms.erase(ms.find(size[root_y]));
	    if(size[root_x]<size[root_y])
	    {
		  swap(root_x,root_y);
     	}
	    arr[root_y]=arr[root_x];
	    size[root_x]+=size[root_y];
	    ms.insert(size[root_x]);
    }
}
int main()
{
	int q;
	scanf("%d %d",&n,&q);
	int u,v;
	arr=new int[n+1];
	size=new int[n+1];
    initialize();
	while(q--)
	{
        scanf("%d %d",&u,&v);
        dounion(u,v);
        
        printf("%d\n",*(ms.end()-1)-*ms.begin()); 

	}
	return 0;
}