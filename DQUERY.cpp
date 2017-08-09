#include <bits/stdc++.h>
using namespace std;
int n;
int *inp;
vector <int> *segment;
void build_Segtree(int low,int high,int pos)
{
	if(low==high)
	{
		segment[pos].push_back(inp[low]);
		return ;
	}
	int mid=low+(high-low)/2;
	build_Segtree(low,mid,2*pos+1);
	build_Segtree(mid+1,high,2*pos+2);
	int x= 2*pos + 1;
	int y= 2*pos + 2;
	int i=0,j=0;
	while((i<segment[x].size())&&(j<segment[y].size()))
	{
		if(segment[x][i]<segment[y][j])
		{
			segment[pos].push_back(segment[x][i]);
			i++;
		}
		else if(segment[x][i]>segment[y][j])
		{
			segment[pos].push_back(segment[y][j]);
			j++;
		}
		else
		{
			segment[pos].push_back(segment[y][j]);
			i++;
			j++;
		}
	}
	while(i<segment[x].size())
	{
		segment[pos].push_back(segment[x][i]);
		i++;
	}
	while(j<segment[y].size())
	{
		segment[pos].push_back(segment[y][j]);
		j++;
	}

}
vector<int> different_Int(int qlow,int qhigh,int low,int high,int pos)
{
	if(qlow<=low&&qhigh>=high)
	{
		return segment[pos];
	}
	else if(qlow>high||qhigh<low)
	{   vector <int> vec(0);
		return vec;
	}
	else
	{
		int mid=low+(high-low)/2;
		int i=0,j=0;
		vector<int> v1=different_Int(qlow,qhigh,low,mid,2*pos+1);
		vector<int> v2=different_Int(qlow,qhigh,mid+1,high,2*pos+2);
		vector <int> res;
		while((i<v1.size())&&(j<v2.size()))
	    {
		if(v1[i]<v2[j])
		{
			res.push_back(v1[i]);
			i++;
		}
		else if(v1[i]>v2[j])
		{
			res.push_back(v2[j]);
			j++;
		}
		else
		{
			res.push_back(v2[j]);
			i++;
			j++;
		}
	    }
	    while(i<v1.size())
	    {
		res.push_back(v1[i]);
		i++;
	    }
	    while(j<v2.size())
	    {
		res.push_back(v2[j]);
		j++;
     	}
        return res;
	}
}
int main()
{
    scanf("%d",&n);
	inp=new int[n];
	int i;
	for(i=0;i<n;i++)
        scanf("%d",&inp[i]);
	if(n&(n-1)!=0)
	{
		int p=pow(2,(int)log2(n)+1);
        segment=new vector<int>[2*p-1];
	}
	else
	{
	    segment=new vector<int>[2*n-1];
	}

	build_Segtree(0,n-1,0);

	int q;
	scanf("%d",&q);
	int j;
	vector <int> res;
	while(q--)
	{
		scanf("%d %d",&i,&j);
        res=different_Int(i-1,j-1,0,n-1,0);
        printf("%d\n",res.size());
	}
	return 0;

}
