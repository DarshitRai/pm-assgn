#include<iostream>
using namespace std;
 int main()
{
  int nov;
  cout<<"\nEnter the number of the business offices == ";
  cin>>nov;
  int mat[nov][nov];
  int visited[nov];
  int dist[nov];
  int parent[nov];
  int i,j;
  
  for(i=1;i<=nov;i++)
     {
	   visited[i]=0;
	   parent[i]=0;
	   dist[i]=10000;
	   for(j=1;j<=nov;j++)
	      {
		    mat[i][j]=0;
		  } 
	 }
  
   int wt,min;
   int cho;
      do
      {
         cout<<"\nEnter the two offices and lenght between them == ";
        cin>>i>>j>>wt;
        mat[i][j]=mat[j][i]=wt;
        cout<<"\nIs there more offices...?(1/0)";
        cin>>cho;
	  }while(cho==1);   
   int current=1,k;
   dist[1]=0;
   parent[1]=0;
   for(k=0;k<nov;k++)
       {
         visited[current]=1;
	     for(i=1;i<=nov;i++)
	        {
		      if(dist[i]>mat[current][i] && mat[current][i]!=0 && visited[i]!=1)
			    {
				   dist[i]=mat[current][i]; 
			       parent[i]=current; 
			    } 	  
  			}
         min=10000;  
	     for(i=1;i<=nov;i++)
	        {
	          if(visited[i]!=1)
			    { 	
		         if(min>dist[i])
			       {
                     min=dist[i];
			         current=i;
				   }
			    }
  			}
	  }  
	  int wmst=0; 

	  for(i=1;i<=nov;i++)
        {
          wmst=wmst+dist[i];
        }
      cout<<"the minimum lenght of wire required is == "<<wmst<<endl;      
}
