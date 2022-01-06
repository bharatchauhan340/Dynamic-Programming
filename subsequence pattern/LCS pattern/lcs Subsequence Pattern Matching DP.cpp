// Subsequence pattern matching

#include<bits/stdc++.h>
using namespace std;

int lcs(string x, string y, int n, int m)
{
	int t[n+1][m+1];
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<m+1;j++)
		{
			if(i==0||j==0)
			{
				t[i][j]=0;
			}
		}
	}
	
	for(int i=1;i<n+1;i++)
	{for(int j=1;j<m+1;j++)
	  {
	  	if(x[i]==y[j])
	  	  { 
	  	    t[i][j]=1+t[i-1][j-1];
		  }
		else
		  {
		  	t[i][j]=max(t[i-1][j] , t[i][j-1]);
		  }
	  }
	}
	
	return t[n][m];
}

int main()
{
	string x , y;
	cout<<" Enter both strings one by one : ";
	cin>>x>>y;
	if(lcs(x,y,x.length(),y.length()) == min(x.length() , y.length() ) )
	{
		cout<<endl<<" Subsequence pattern matched...";
	}
	else
	  cout<<" Subsequence pattern not matched !!!";
	
	return 0;
}
