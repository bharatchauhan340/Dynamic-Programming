// Rod cutting problem

#include<iostream>
#include<cstring>
using namespace std;



int max(int x,int y)
{
    return x > y ? x:y;
}

int rodcutting(int length[], int price[], int l, int n )
{
	int t[n+1][l+1];
	for(int i=0;i<n+1;i++)
	{ for(int j=0;j<l+1;j++)
	  {
	  	if(i==0||j==0)
	  	 t[i][j]=0;
	  }
	}
	
   for(int i=1;i<n+1;i++)
   {
   	for(int j=1;j<l+1;j++)
   	 {
   	 	if(length[i-1]<=j)
   	 	{ t[i][j]=max(price[i-1]+t[i][j-length[i-1]] , t[i-1][j]);
		}
		
		else
		{t[i][j]-t[i-1][j];
		}
		 	
     }
   }
   
   return t[n][l];
   
}



int main()
{
	 int n,i,j,W;
    int wt[100],val[100];
    cout<<"Enter size of array : ";
    cin>>n;

    cout<<"Enter length array : ";
    for(i=0;i<n;i++)
        cin>>wt[i];
    cout<<"Enter value array : ";
    for(i=0;i<n;i++)
        cin>>val[i];
    cout<<"Enter length of rod (l) : ";
    cin>>W;    
    
    cout<<"Answer is "<<rodcutting(wt,val,W,n);
    return 0;
	
}
