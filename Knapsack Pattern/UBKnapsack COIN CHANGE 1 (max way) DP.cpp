// Coinchange problem 1 (max. no of ways)

#include<iostream>
#include<cstring>
using namespace std;

int coinchange1(int coin[],int n ,int sum)
{
	int t[n+1][sum+1];
	// initialisation
	for(int i=0;i<n+1;i++)
	{for(int j=0;j<sum+1;j++)
	{
		if(i==0)
		    t[i][j]=0;
		if(j==0)
		    t[i][j]=1;
	}
	}
	
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<sum+1;j++)
		{
			if(coin[i-1]<=j)
			{
				t[i][j]=(t[i-1][j]+t[i][j-coin[i-1]]);
			}
			else
			    t[i][j]=t[i-1][j];
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
	int maxway = coinchange1(coin,n,sum);
	cout<<endl<<" Max no of ways are : "<<maxway;
	return 0;
}
