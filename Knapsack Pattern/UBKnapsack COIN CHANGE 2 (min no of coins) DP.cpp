// Coin change problem 2 (Min no of coins)

#include<iostream>
#include<cstring>
using namespace std;

int min(int a , int b)
{
	return( a<b ? a : b);
}

int coinchange2(int coin[],int n,int sum)
{
	int t[n+1][sum+1];
	// initialisation
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<sum+1;j++)
		{
			if(j==0)
			  t[i][j]=0;
			if(i==0)
			  t[i][j]=INT_MAX-1;
			// 2nd row initialisation
			if(i==1&&j>0)
			{
				if(j%coin[0]==0)
				   t[i][j]=j/coin[0];
				else
				   t[i][j]=INT_MAX-1;
			}
		}
	}
	
	// rest code
	
	for(int i=2;i<n+1;i++)
	{for(int j=1;j<sum+1;j++)
	  {
	  	if(coin[i-1]<=j)
	  	{
	  	   t[i][j]=min(1+t[i][j-coin[i-1]] , t[i-1][j]);	
		}
	  }
	}
	
	return t[n][sum];
}



int main()
{
	cout<<"Enter size of coin array : ";
	int n;
	cin>>n;
	int coin[n],sum;
    cout<<endl<<" Coin Array : ";
	for(int i=0;i<n;i++)
	{ cin>>coin[i];
		}	
	cout<<endl<<" Enter Sum : ";
	cin>>sum;
	int mincoin = coinchange2(coin,n,sum);
	cout<<endl<<" Min no of coins required are : "<<mincoin;
	return 0;
}
