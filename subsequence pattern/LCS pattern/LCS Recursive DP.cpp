// Longest Common Subsequence (Recursive)

#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int lcs(string x , string y , int n , int m)
{
	if(n==0||m==0)
	   return 0;
	
	if(x[n-1]==y[m-1])
	   return(1+lcs(x,y,n-1,m-1));
	else
	   return max(lcs(x,y,n-1,m) , lcs(x,y,n,m-1));
}

int main()
{
	string x ,y;
	cout<<" Enter both strings one by one ";
	cin>>x>>y;
	int n=x.length();
	int m=y.length();
	
	cout<<" LCS : "<<lcs(x,y,n,m);
	
	return 0;
}
