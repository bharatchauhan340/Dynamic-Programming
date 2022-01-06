// Subset sum problem ( Knapsack )

#include<iostream>
#include<cstring>
using namespace std;

bool subsetsum(int arr[], int sum, int n)
{
	int t[n+1][sum+1];
	for(int i=0;i<n+1;i++)
	{ for(int j=0;j<sum+1;j++)
	   {
	   	if(i==0)
	   	  t[i][j]=false;
	   	if(j==0)
	   	  t[i][j]=true;
	   	  
	   }
	}
	int i,j;
	for( i=1;i<n+1;i++)
	{ for( j=1;j<sum+1;j++)
	  {
	  	if(arr[i-1]<=j)
	  	  t[i][j]= t[i-1][j-arr[i-1]] || t[i-1][j];
	  	else
	  	  t[i][j]=t[i-1][j];
	  }
	}
	return t[n][sum];
}

int main()
{
	 int n,i,j,sum;
    int arr[100];
    cout<<"Enter size of array : ";
    cin>>n;

    cout<<"Enter array : ";
    for(i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Enter sum : ";
    cin>>sum;    
    
    cout<<"Answer is "<<subsetsum(arr,sum,n);
    return 0;
}
