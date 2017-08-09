#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void sieve(int n,vector <int> &prime)
{
    short mark[n+1]={0};
    int i,j;
    for (i=2;i*i<=n;i++)
    {
        if(mark[i]==0)
        {
            for(j=i*2;j<=n;j+=i)
                mark[j]=1;
        }
    }
    prime.push_back(2);
    for(i=3;i<=n;i+=2)
          if(mark[i]==0)
           {prime.push_back(i);
           }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long  m,n;
        scanf("%ld %ld",&m,&n);
        int lim=floor(sqrt(n))+1;
        vector <int> prime;
        
        if(n<2)
        { printf("\n");
          continue;
        }
        else if(n==2)
             {
                 printf("2\n");
                 continue;
             }
        sieve(lim,prime);
        long low=m;
        long high=m+lim;
        if(high>n)
           high=n;
        long i,j;long ll;
        while(low<n)
        {
            short mark[lim+1]={0};

            for(i=0;i<prime.size();i++)
            {
                ll=floor(low/prime[i])*prime[i];
                if(ll<low)
                 ll=ll+prime[i];


                for(j=ll;j<=high;j+=prime[i])
                    if(j!=prime[i])
                       mark[j-low]=1;

            }
            for(i=low;i<=high;i++)
            {   
                
                if(mark[i-low]==0&&i>=2)
                  {   if(i!=high)
                      printf("%ld\n",i);
                      if(i==n)
                      printf("%ld\n",i);
                     
                  }
            }
        
              
            low+=lim;
            high+=lim;
            if(high>=n)
            high=n;
        }

        printf("\n");
    }

        return 0;

}
