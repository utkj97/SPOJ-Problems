#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,q;
    scanf("%d %d",&n,&q);
    vector <int> v;
    int x;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        v.push_back(x);
    }
    int ch;
    int k;
    while(q--)
    {
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: scanf("%d %d",&k,&x);
                    v.insert(v.begin()+(k-1),x);
                    break;
            case 2:scanf("%d",&k);
                   v.erase(v.begin()+(k-1));
                    break;
            case 3:scanf("%d",&k);
                   printf("%d\n",v[k-1]);
                   break;                
        }
    }
    return 0;
}