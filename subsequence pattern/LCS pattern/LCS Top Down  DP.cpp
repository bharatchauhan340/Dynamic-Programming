// Top Down LCS

#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int max(int x , int y)
{
	return (x>y)?x:y;
}

int tdlcs(string x , string y , int m , int n)
{
	int t[m+1][n+1];
	
	for(int i=0;i<=m;i++)
	 { for(int j=0;j<=n;j++)
	     {
	     	if(i==0||j==0)
	     	  t[i][j]=0;
		 }
	 }
	 
	 for(int i=1;i<=m;i++)
	 {
	 	for(int j=1;j<=n;j++)
	 	   {
	 	   	    if(x[i-1]==y[j-1])
	 	   	        t[i][j]=1+t[i-1][j-1];
			    else
				    t[i][j] = max( t[i][j-1] , t[i-1][j] ); 
		   }
	 }
	 
	return t[m][n];
}

int main()
{
	string x,y;
	cout<<" Enter two strings one by one : ";
	cin>>x>>y;
	cout<<endl<<"LCS : "<<tdlcs(x,y,x.length(),y.length());
	
	return 0;
}
