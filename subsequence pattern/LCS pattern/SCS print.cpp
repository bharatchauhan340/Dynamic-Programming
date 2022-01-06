// prining shortest common supersequence

#include<bits/stdc++.h>
#include<string>
using namespace std;

string printscs(string x , string y , int m , int n)
{
	int t[m+1][n+1];
	
	for(int i=0;i<m+1;i++)
	{for(int j=0;j<n+1;j++)
	 {
	 	if(i==0||j==0)
	 	 t[i][j]=0;
	 }
	}
	
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
	// till now Matrix has been filled
	
	
	int i=m,j=n;
	string S;
	while(i>0&&j>0)
	{
		if(x[i-1]==y[j-1])
		 {
		 	S.push_back(x[i-1]);
		 	i--;
		 	j--;
		 }
		
		else
		 {
		 	if(t[i][j-1]>t[i-1][j])
		 	  {
			   S.push_back(y[j-1]);
		 	   j--;
			  }
		 	  
		 	else
		 	  {
			   S.push_back(x[i-1]);
		 	   i--;
		      }
		 }
	}
	
	
	// pushing array which is left to string S
	while(i>0)
	{
		S.push_back(x[i-1]);
		i--;
	}
	
	while(j>0)
	{
		S.push_back(y[j-1]);
		j--;
	}
	
	
	
	string reversed_word;
    reversed_word = string(S.rbegin(), S.rend()); 
//	return ( reverse(S.begin(),S.end()) );
    return(reversed_word);
}


int main()
{
	string x,y;
	cout<<" Enter both strings one by one : ";
	cin>>x>>y;
	
    cout<<endl<<" Longest Common Subsequence : "<<printscs(x,y,x.length(),y.length());
	
	return 0;
}
