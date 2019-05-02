#include<iostream>
using namespace std;
int hash(int val,int s,int arr[])
{
  int ix;
  ix=val%s;
  while(arr[ix]!=-1)
     {
        ix=1+val%(s-1); 
	 } 
  return ix; 
} 
int search(int val,int s,int arr[])
{
  int ix;
  ix=val%s;
  while(arr[ix]!=val)
       {
        ix=1+val%(s-1); 
	   }  
  return ix; 
} 
int main()
{ 
  int len,nov;	 
  cout<<"\nEnter the lenght of the array and number of values == ";
  cin>>len>>nov;
  int arr[len];
  int i,val,cho,j;
  for(i=0;i<len;i++)
     {
	   arr[i]=-1;
	 }
  for(i=0;i<nov;i++)  
     {
       cout<<"\nEnter the val == ";
	   cin>>val;
	   j=hash(val,len,arr);
	   arr[j]=val;	 
	 }
  for(i=0;i<len;i++)
     {
	   cout<<arr[i]<<endl;
	 }

   cout<<"\nEnter the value to search == ";
   cin>>val;
   j=search(val,len,arr);
   cout<<arr[j]<<endl; 
}

