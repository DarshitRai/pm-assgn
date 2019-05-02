#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
struct node
{
  int data;
  node *next;
};
int main()
{
  int nov,i,j; 	
  cout<<"\nEnter the number of the element == ";
  cin>>nov;
  int a,cho1,cho2,val;
  int root;
  node *list[nov];
  char city[nov][20]; 
  for(i=0;i<nov;i++)
     {
	   cout<<"\nEnter the name of"<<i<<"th"<<" city == ";
	   cin>>city[i];
	 }
  for(i=0;i<nov;i++)
     {
        node*n=new node;
        cout<<"\nEnter the starting node == ";
        cin>>root;
	    n->data=root;
        n->next=NULL;
        cout<<"\nMore links == ";
        cin>>cho1;
		if(cho1==1)
		{ 
		  do  
           {
		     cout<<"\nEnter the data == ";
			 cin>>val;  
             node*n1=new node;
			 n1->data=val;
			 n1->next=NULL;
	         node*temp=n;
			 while(temp->next!=NULL)
			      {
				    temp=temp->next;    
	              }
				  temp->next=n1;       
			 cout<<"\nMOre links == ";
			 cin>>cho2; 
           }while(cho2==1);
		}
		list[i]=n;
	 }
 for(i=0;i<nov;i++)
     {
        node*n=new node;
	    n=list[i];
	    n=n->next;
        cout<<city[i];
	    while(n!=NULL)
	         {
               cout<<"->"<<city[n->data];
			   n=n->next;
			 }
	    cout<<endl;
	 }
}

