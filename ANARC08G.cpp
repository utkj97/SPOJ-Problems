#include <bits/stdc++.h>
using namespace std;
int n;
int arr[1005][1005];
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n;
	int in[1005]={0};
	int out[1005]{0};
	int t=1;
	while(n!=0)
	{
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			out[i]=0;
			for(int j=1;j<=n;j++)
			{
				cin>>arr[i][j];
				out[i]=out[i]+arr[i][j];
				sum=sum+arr[i][j];
			}
		}
		for(int i=1;i<=n;i++)
		{
			in[i]=0;
			for(int j=1;j<=n;j++)
			{
				in[i]=in[i]+arr[j][i];
			}
		}
		int s=0;
		for(int i=1;i<=n;i++)
		{
			s=s+abs(in[i]-out[i]);
		}
        cout<<t<<". "<<sum<<" "<<s/2<<"\n";
        t++;
        cin>>n;
	}

	return 0;
}
