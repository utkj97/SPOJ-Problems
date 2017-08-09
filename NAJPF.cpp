#include <bits/stdc++.h>
using namespace std;
#define MAX 1000007
int main()
{
	int t;
	cin>>t;
	string str;
	string pat;
	while(t--)
	{
		cin>>str>>pat;
		int lps[pat.size()];
		int j,i;
		lps[0]=0;
		int c=0;
		j=0;
		vector <int> v;
		for(i=1;i<pat.size();)
		{
			if(pat[i]==pat[j])
			{
				lps[i]=j+1;
				i++;
				j++;
			}
			else
			{
				if(j==0)
				{
					lps[i]=0;
					i++;
				}
				else
				{
					j=lps[j-1];
				}
			}
		}
		int m=pat.size();
		j=0;
		for(i=0;i<str.size();)
		{
			if(pat[j]==str[i])
			{
				i++;
				j++;
			}
			else
			{
				if(j==0)
					i++;
				else
					j=lps[j-1];
			}
			if(j==m)
			{
               c++;
               v.push_back(i-m+1);
               j=lps[j-1];

			}
		}
		if(c==0)
		{
			cout<<"Not Found\n";
		}
        else
        {
        	cout<<c<<"\n";
        	for(int x=0;x<v.size();x++)
        	{
        		cout<<v[x]<<" ";
        	}
        	cout<<"\n";
        }
        cout<<"\n";
	}
	return 0;
}
