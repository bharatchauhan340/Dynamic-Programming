// Longest repeating subsequence

#include<bits/stdc++.h>
using namespace std;

int longrepsubsequence(string x, int m)
{
	// here we have only one string.... 
    string y;
    y = x;
    int n = y.length();
	// Now we will check LCS btw X & X (Y)      **but not at same index**  i.e. LRS
	
	// writting code for LRS	
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
	 	if(x[i-1]==y[j-1] && i!=j)  // **( && i!=j )  only this diff bw LCS & LRS **
	 	 { t[i][j]=1+t[i-1][j-1];
		  }
		  
		else
		  t[i][j]=max(t[i-1][j] , t[i][j-1]);
	 }
	}
	
	return t[m][n];
	
	
}

int main()
{
	string x;
	cout<<" Enter string : ";
	cin>>x;
	
    cout<<endl<<" length of longest repeating subsequence : "<<longrepsubsequence(x,x.length());
	
	
	return 0;
	
}
