// Knapsack Memoized code

#include<iostream>
#include<cstring>
using namespace std;

int static t[100][1000];

	
int knapsack(int wt[], int val[], int w, int n)
{
	if(n==0||w==0)
	   return 0;
	   
	if(t[n][w]!=-1)
	   return t[n][w];
	   
	if(wt[n-1]<=w)
	   return t[n][w]=max( val[n-1]+knapsack(wt,val,w-wt[n-1],n-1) , knapsack(wt,val,w,n-1));
	
	else if(wt[n-1]>w)
	   return t[n][w] = knapsack(wt,val,w,n-1);  
}

int main()
{
	
	 int n,i,W,result;
    cout<<"Enter size of array : ";
    cin>>n;
    int wt[n],val[n];
    memset(t, -1, sizeof(t));
    cout<<"Enter weight array : ";
    for(i=0;i<n;i++)
        cin>>wt[i];
    cout<<"Enter value array : ";
    for(i=0;i<n;i++)
        cin>>val[i];
    cout<<"Enter max capacity(W) : ";
    cin>>W;    
    result = knapsack(wt,val,W,n);
    cout<<"Answer is "<<result;
    return 0;
	
/*	int wt_array[] = {1,2,4,6};
	int val_array[] = {1,4,5,6};
	int weight = 8;
	memset(t,-1,sizeof(t)); // Intializes whole matrix by -1	
	int max_prof = knapsack(wt_array,val_array,weight,sizeof(wt_array));
	cout<<" Max Profit is : "<<max_prof<<endl; */
	
	
	
	return 0;
}
