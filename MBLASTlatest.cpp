#include <bits/stdc++.h>
using namespace std;
#define MIN(a,b,c) min(min(a,b),c)
int k;
int dist(char a,char b)
{
  
  if(a=='-'||b=='-')
  	 return k;
  else
     return abs(a-b);	
}
int strmblast(string str1,string str2,int m,int n)
{
   int dp[m+1][n+1];
   int i=0,j=0;
   while(i<=m)
   {  j=0;
      while(j<=n)
      {   
      	  
          if(i==0)
          	 dp[i][j]=k*j;
          else if(j==0)
             dp[i][j]=k*i;
          else 
          {
          	dp[i][j]=MIN(dist(str1[i-1],str2[j-1])+dp[i-1][j-1],dist(str1[i-1],'-')+dp[i-1][j],dist(str2[j-1],'-')+dp[i][j-1]);
          }
          
                	
          j++;
      }
      i++;
   }
   return dp[m][n];
}
int main()
{   
	ios_base::sync_with_stdio(false);
	string ss1,ss2;
	cin>>ss1;
	cin>>ss2;

	cin>>k;
	printf("%d\n",strmblast(ss1,ss2,ss1.size(),ss2.size()));
	return 0;
}