// Longest common substring

#include<bits/stdc++.h>
#include<string>
using namespace std;

int lcstring(string x , string y , int m , int n)
{
	int t[m+1][n+1];  // Matrix decleration
	// Matrix initialisation
	for(int i=0;i<m+1;i++)
	{for(int j=0;j<n+1;j++)
	 {
	 	if(i==0||j==0)
	 	 { t[i][j]=0;
		  }
	 }
	}
	
    for(int i=1;i<=m;i++)
    {
    	for(int j=0;j<=n;j++)
    	{
    		if(x[i-1]==y[j-1])
    		   t[i][j]=1+t[i-1][j-1];
    		
    		else
    		   t[i][j]=0;
		}
	}
   	
   	int maxstr=0;
   	for(int i=0;i<=m;i++)
   	{
   		for(int j=0;j<=n;j++)
   		 {
   		 	if(maxstr<t[i][j])
   		 	  maxstr=t[i][j];
			}
	   }
	   
	return maxstr;
   	
}

int main()
{
	string x ,y;
	cout<<" Enter both strings one by one : ";
	cin>>x>>y;
	cout<<endl<<" Longest commont substring's length : "<<lcstring(x,y,x.length(),y.length() );
	
	return 0;
}
