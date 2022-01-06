// Target sum

// Same as count of subset with given diff
// Way of asking question is diff otherwise as it is.....
#include<iostream>
#include<cstring>
using namespace std;

int countsubsetsum(int arr[], int sum, int n)
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
	  	  t[i][j]= ( t[i-1][j-arr[i-1]] ) + ( t[i-1][j]) ;
	  	else
	  	  t[i][j]=t[i-1][j];
	  }
	}
	return t[n][sum];
}

int Targetsum(int arr[], int sum, int n) 
{
	int tsum=0;
	for(int i=0;i<n;i++)
	{
		tsum+=arr[i];
	}
	
	return countsubsetsum(arr,(tsum+sum)/2,n);
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
    cout<<"Enter Target sum : ";
    cin>>sum;    
    
    cout<<"Answer is "<<Targetsum(arr,sum,n);
    return 0;
}

