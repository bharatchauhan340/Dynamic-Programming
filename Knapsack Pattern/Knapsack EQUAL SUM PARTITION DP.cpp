// Equal sum partition problem ( Knapsack )

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
	  	  t[i][j]= t[i][j-arr[i-1]] || t[i-1][j];
	  	else
	  	  t[i][j]=t[i-1][j];
	  }
	}
	return t[i][j];
}

bool eqsumpartition(int arr[], int n)
{
	int sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=arr[i];
	}
	if(sum%2!=0)
	  return false;
	else
	  return subsetsum(arr, sum/2, n);
}

int main()
{
	int n,i,j;
    int arr[100];
    cout<<"Enter size of array : ";
    cin>>n;

    cout<<"Enter array : ";
    for(i=0;i<n;i++)
        cin>>arr[i];
    
    cout<<"Answer is "<<eqsumpartition(arr,n);
    return 0;
}
