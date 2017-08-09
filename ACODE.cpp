#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    string ss;
    cin>>ss;
    int n;
    int i;
    ll *dp;
    int x;
    while(ss[0]!='0')
    {
       n=ss.size();
       i=0;
       dp=new ll[n+1];
       dp[0]=1;
       while(i<n)
       {

         if(ss[i]!='0')
         {
         	dp[i+1]=dp[i];
         }
         else
         	dp[i+1]=0;
         if(i!=0)
         {   x=((int)ss[i-1]-48)*10+(int)ss[i]-48;
         	if(ss[i-1]!='0'&&(x>=10&&x<=26))
            {
               dp[i+1]+=dp[i-1];
            }
         }

          i++;
       }
        printf("%lld\n",dp[n]);
        cin>>ss;
    }
    return 0;
}
