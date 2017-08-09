#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE 1000005
int par[MAX_SIZE+1];
int n,m;
int compo;
//Question doenot support getchar()
void fastscan(int &number)
{
    char c;

    number = 0;
    c = getchar();
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;

}
int root(int x)
{
   while(x!=par[x])
   {
    par[x]=par[par[x]];
    x=par[x];
   }
   return x;

}
void union_set(int a,int b)
{
  int x=root(a);
  int y=root(b);
  if(x==y)
    return;

  par[x]=par[y];
  compo--;

}
inline void initialize()
{

    for(int i=0;i<=MAX_SIZE;i++)
        par[i]=i;
}
int main()
{
	fastscan(n);
	fastscan(m);
	ios_base::sync_with_stdio(false);
    compo=m*n;
    initialize();
    int i,j;
    char ch;
    int x=1;;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
         cin>>ch;
         switch(ch)
         {
         case 'N':{union_set(x,x-m);
                   break;}
         case 'S':{union_set(x,x+m);
                   break;}
         case 'E':{union_set(x,x+1);
                   break;}
         case 'W':{union_set(x,x-1);
                   break;}
         }
          x++;
        }
    }
    cout<<compo<<"\n";
    return 0;
}
