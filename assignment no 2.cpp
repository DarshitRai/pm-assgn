#include<iostream>
using namespace std;
class node
{
  public:
   int data;
   int lth,rth;
   struct node*left;
   struct node*right;
   struct node*root;
   struct node*dummy;
   
  public:
   node()
    {
       root=NULL;
	   dummy=new node;
       dummy->data=-999;
	   dummy->left=NULL;
	   dummy->right=dummy; 
       dummy->lth=dummy->rth=0; 
	}  

 void create(node*temp ,node*n)
    {
      cout<<"\nin create";
      if(temp->data>n->data)
        {
          while(temp->left!=dummy)
           {
             cout<<"\nin left loop";
		     temp=temp->left;
		   }
		   n->left=temp->left;
		   n->lth=n->rth=1;
		   n->right=temp;
		   temp->left=n;
	   }
     else if(temp->data<n->data)
       {
         while(temp->right!=dummy)
           {
	         cout<<"\nin right loop"; 
	   	     temp=temp->right;
		   }
		   n->right=temp->right;
		   n->lth=n->rth=1;
		   n->left=temp;
		   temp->right=n;
	   }
     else 
       {
	     cout<<"\nInvalid input";
	   }
  }
   
 void newnode(int val)
  {   
	node*n=new node;
	n->data=val;
	n->left= NULL;
	n->right= NULL; 
    n->lth=n->rth=0; 
	if(root== NULL)
	  {
        n->lth=n->rth=1;
        n->left=n->right=dummy;
		root=n;
	    dummy->left=root;	
	  }
     else
      {
        create(root,n);	  
	  }
  }
};
int main()
{ 
  node obj;
  char cho;
  int val;
  do
  { 
    cout<<"\nEnter the value == ";
    cin>>val;	
    obj.newnode(val);
    cout<<"more element  ?";
    cin>>cho;
  }while(cho=='y');

}
