#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 50005
vector < pair<int,int> > *city;
int dist[MAXSIZE];
int n;
bool visited[MAXSIZE];
void initialize()
{
    int i;
    for(i=1;i<=n;i++)
        {
            dist[i]=0;
            visited[i]=false;
        }
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int i;
        int x,y,w;
        city= new vector < pair<int,int> > [n+1];
        for(i=1;i<=n-1;i++)
        {
            cin>>x>>y>>w;
            city[x].push_back(make_pair(y,w));
            city[y].push_back(make_pair(x,w));
        }
        initialize();
        queue <int> Q;
        Q.push(1);
        dist[1]=0;
        while(!Q.empty())
        {
            x=Q.front();
            Q.pop();
            visited[x]=true;
            for(int i=0;i<city[x].size();i++)
            {
                if(visited[city[x][i].first]==false)
                {
                    Q.push(city[x][i].first);
                    dist[city[x][i].first]=city[x][i].second+dist[x];
                }
            }
        }
        int max1=dist[1];
        int p=1;
        for(int i=2;i<=n;i++)
            if(dist[i] > max1)
            {
                max1=dist[i];
                p=i;
            }
        initialize();
        Q.push(p);
        dist[p]=0;
        while(!Q.empty())
        {
            x=Q.front();
            Q.pop();
            visited[x]=true;
            for(int i=0;i<city[x].size();i++)
            {
                if(visited[city[x][i].first]==false)
                {
                    Q.push(city[x][i].first);
                    dist[city[x][i].first]=city[x][i].second+dist[x];
                }
            }
        }
        int max2=0;
        for(i=1;i<=n;i++)
        {
            if(dist[i]>max2)
                max2=dist[i];
        }
        cout<<max2<<"\n";
    }
    return 0;
}
