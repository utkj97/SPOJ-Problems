#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,c;
	scanf("%d %d",&n,&c);
	int *arr=new int[n];
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	int m;
	scanf("%d",&m);
	int a,b;
	while(m--)
	{ 
		scanf("%d %d",&a,&b);
		vector<int> v(arr+(a-1),arr+b);
        sort(v.begin(),v.end());
        int p=v.size();
        int mid=p/2;
        if(upper_bound(v.begin(),v.end(),v[mid])-lower_bound(v.begin(),v.end(),v[mid])>p/2)
           printf("yes %d\n",v[mid]);
        else
           printf("no\n");
	}
	return 0;
	
}