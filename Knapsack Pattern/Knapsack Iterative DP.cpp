// Iterative version Knapsack
#include<iostream>
#include<cstring>
using namespace std;

int max(int x,int y)
{
    return x > y ? x:y;
}

int knapsack(int wt[], int val[], int w, int n)
{
	int t[n+1][w+1];
	
	// Initialisation
	for(int i=0;i<n+1;i++)
	{ for(int j=0;j<w+1;j++)
	   {
	   	 if(i==0||j==0)
	   	    t[i][j]=0;
	   }
    }

	for(int i=1;i<n+1;i++)
	{ for(int j=1;j<w+1;j++)
	   {
	   	 
	   	 if(wt[i-1]<=j)
	   	    t[i][j]=max(val[i-1]+t[i-1][j-wt[i-1]] , t[i-1][j]);
	   	    
	   	 else
	   	    t[i][j]=t[i-1][j];
	   }
	   
	}
	return t[n][w]; 
	 
}

int main()
{
	 int n,i,j,W;
    int wt[100],val[100];
    cout<<"Enter size of array : ";
    cin>>n;

    cout<<"Enter weight array : ";
    for(i=0;i<n;i++)
        cin>>wt[i];
    cout<<"Enter value array : ";
    for(i=0;i<n;i++)
        cin>>val[i];
    cout<<"Enter max capacity(W) : ";
    cin>>W;    
    
    cout<<"Answer is "<<knapsack(wt,val,W,n);
    return 0;
	
}
