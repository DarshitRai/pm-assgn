#include<iostream>
using namespace std;
void maxheapfy(int a[],int i,int s)
  {
      int l=2*i;
	  int r=(2*i)+1;
      int large=0,temp=0;
      
      if(l<=s && a[l]>a[i])
	    {
           large=l;		
		}
	  else
	    {
          large=i;  		  
 		}
	  if(r<=s && a[large]<a[r])
	    {
		  large=r;
		}	 		   
      if(large!=i)
        {
		  temp=a[i];
		  a[i]=a[large];
		  a[large]=temp; 
          maxheapfy(a,large,s);          
		}
  }
void minheapfy(int a[],int i,int s)
  {
      int l=2*i;
	  int r=(2*i)+1;
      int small=0,temp=0;
      
      if(l<=s && a[l]<a[i])
	    {
           small=l;		
		}
	  else
	    {
          small=i;  		  
 		}
	  if(r<=s && a[small]>a[r])
	    {
		  small=r;
		}	 		   
      if(small!=i)
        {
		  temp=a[i];
		  a[i]=a[small];
		  a[small]=temp; 
          minheapfy(a,small,s);          
		}
  }
void maxbuild(int a[],int s)
  {
    int i;
    for(i=s/2;i>0;i--)
       {
          maxheapfy(a,i,s);          
	   }
  }
void minbuild(int a[],int s)
  {
    int i;
    for(i=s/2;i>0;i--)
       {
          minheapfy(a,i,s);          
	   }
  }

int main()
{
  int len;
  cout<<"\nEnter the length of the array == ";
  cin>>len;
  int arr[len];
  int i;
  for(i=1;i<=len;i++)
     {
	   cout<<"\nEnter the value == ";
	   cin>>arr[i];
	 }  
  maxbuild(arr,len);
  cout<<"\nMax marks obtained is == "<<arr[1]<<endl;
  minbuild(arr,len);
  cout<<"\nMin marks obtained is == "<<arr[1]<<endl;
  cout<<endl;

}

