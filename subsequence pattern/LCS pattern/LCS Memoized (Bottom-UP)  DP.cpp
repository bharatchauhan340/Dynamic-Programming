// Longest Common Subsequence (Memoized) Bottom-Up

#include<iostream>
#include<cstring>
#include<string>
using namespace std;

// declaring matrix
int static t[101][101];


int lcs(string x , string y , int n , int m)
{
	//checking value in matrix
	if(t[n][m]!=-1)
	   return t[n][m];
	
	if(n==0||m==0)
	   return 0;
	
	if(x[n-1]==y[m-1])
	   return(1+lcs(x,y,n-1,m-1));
	else
	   return max(lcs(x,y,n-1,m) , lcs(x,y,n,m-1));
}

int main()
{
	// initialising matrix with -1
	memset(t,-1,sizeof(t));
	
	string x ,y;
	cout<<" Enter both strings one by one ";
	cin>>x>>y;
	int n=x.length();
	int m=y.length();
	
	cout<<" LCS : "<<lcs(x,y,n,m);
	
	return 0;
}
