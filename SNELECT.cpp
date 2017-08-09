#include <bits/stdc++.h>
using namespace std;
int main()
{   
    int t;
    scanf("%d",&t);
    while(t--)
    {
    	string ss;
    	cin>>ss;
    	int n=ss.size();
    	int i;
    	int m=0,x=0;
    	for(i=0;i<n;i++)
    	{
    		if(ss[i]=='m')
    		{   
    			m++;
    			if(i!=0&&ss[i-1]=='s')
    			{
    					ss[i-1]='*';
    					x++;
    			}
    			else if(i!=n-1&&ss[i+1]=='s')
    			{
    				    ss[i+1]='*';
    				    x++;
    			}
    		}
    	}
    	if(m==n-m-x)
    	   printf("tie\n");
    	else if(m>n-m-x)
    	   printf("mongooses\n");
    	else
    	   printf("snakes\n");      	 

    }
    return 0;
}