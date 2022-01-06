// minimum no of insertion & deletion to convert a string X to string Y

#include<bits/stdc++.h>
using namespace std;

void convXtoY(string x , string y, int m , int n)
{
	// writting code for LCS	
    int t[m+1][n+1];
    
    // initialising matrix 
	for(int i=0;i<m+1;i++)
	{for(int j=0;j<n+1;j++)
	 {
	 	if(i==0||j==0)
	 	 t[i][j]=0;
	 }
	}
	
	// filling matrix 
	for(int i=1;i<m+1;i++)
	{for(int j=1;j<n+1;j++)
	 {
	 	if(x[i-1]==y[j-1])
	 	 { t[i][j]=1+t[i-1][j-1];
		  }
		  
		else
		  t[i][j]=max(t[i-1][j] , t[i][j-1]);
	 }
	}
	
	int lcs=t[m][n];
	cout<<endl<<" insertion : "<<n-lcs<<endl<<" deletion : "<<m-lcs;
	
}

int main()
{
	string x,y;
	cout<<" Enter both strings one by one : ";
	cin>>x>>y;
	
    cout<<endl<<" Min. no of insertion & deletion required : ";
    convXtoY(x,y,x.length(),y.length());
	
	
	return 0;
}
