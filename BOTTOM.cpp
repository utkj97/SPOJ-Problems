#include <bits/stdc++.h>
using namespace std;
vector <int> *v1;
vector <int> *v2;
int n,e;
bool *visit;
stack <int> st;
int *aset;
void fastscan(int &number)
{
    char c;
    number = 0;
    c = getchar_unlocked();
    for (; (c>47 && c<58); c=getchar_unlocked())
        number = number *10 + c - 48;
}
void nullify()
{
	for(int i=1;i<=n;i++)
		visit[i]=false;
}
void intialize()
{
	int i;
	for(i=1;i<=n;i++)
		aset[i]=i;
}
void dfs(int src)
{
	visit[src]=true;
	for(int i=0;i<v1[src].size();i++)
	{
		if(!visit[v1[src][i]])
			dfs(v1[src][i]);
	}
	st.push(src);
}
void dfsRev(int src,vector <int> &vec,int t)
{
	visit[src]=true;
	for(int i=0;i<v2[src].size();i++)
	{
		if(!visit[v2[src][i]])
			dfsRev(v2[src][i],vec,t);
	}
	vec.push_back(src);
	aset[src]=t;

}
int main()
{
    ios_base::sync_with_stdio(false);
	cin>>n;
	int x,y;
	while(n!=0)
	{
		vector <int> result;
		vector <vector<int> > res;
		cin>>e;
		v1=new vector<int> [n+1];
		v2=new vector<int> [n+1];
		visit=new bool[n+1];
		aset=new int[n+1];
		for(int i=0;i<e;i++)
		{
			cin>>x>>y;
			v1[x].push_back(y);
			v2[y].push_back(x);
		}
		nullify();
		for(int i=1;i<=n;i++)
		{
			if(!visit[i])
				dfs(i);
		}
        //STACK created
        nullify();
        int t=1;
        intialize();
        while(!st.empty())
        {
        	int p=st.top();
        	st.pop();
        	if(!visit[p])
        	{
        		vector <int> v;
        		dfsRev(p,v,t);
        		res.push_back(v);
        		t++;
        	}
        }
        int j,k;
        for(int i=0;i<res.size();i++)
        {
        	for(j=0;j<res[i].size();j++)
        	{
        		for(k=0;k<v1[res[i][j]].size();k++)
        		{
        			if(aset[v1[res[i][j]][k]]==i+1)
        				continue;
        			break;
        		}
        		if(k!=v1[res[i][j]].size())
        		{
        			break;
        		}

        	}
        	if(j==res[i].size())
        	{
        		for(k=0;k<res[i].size();k++)
        			{
        				result.push_back(res[i][k]);
        			}

        	}

        }
        sort(result.begin(),result.end());
        vector <int>:: iterator it;
        for(it=result.begin();it!=result.end();++it)
        	  cout<<*it<<" ";
        cout<<"\n";
        cin>>n;
	}
    return 0;

}
