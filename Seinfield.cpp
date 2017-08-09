#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with-stdio(false);
	int t=1;
	string ss;
	cin>>ss;
	int w=0;
	int c=0;
	while(ss[0]!='-')
	{
        stack <int> st;        
		int i=0;
        w=0;c=0;
		while(i<ss.size())
		{
			if(ss[i]=='{')
			{
				st.push(1);
			}
			else if(ss[i]=='}'&&st.size()!=0)
				st.pop();
			else
				w++;
            
            i++;
        }
        if(st.size()%2==1)
        	c++;
        if(w%2==1)
            c++;
        c=c+w/2+st.size()/2;
        printf("%d. %d\n",t,c);
        t++;   
        cin>>ss; 	 
	}
	return 0;
}