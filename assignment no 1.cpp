#include<iostream>
using namespace std;
int check(int arr[],int num,int len)
{
   int i;
   for(i=0;i<len;i++)
      {
        if(arr[i]==num)
          {
	        return 1;
          } 
     }
}
void insert(int arr[],int len,int num)
{
   int i,c;
       i=len;
       i--;
       arr[i]=num;
}
void del(int arr[],int len,int num)
{
   int i,j,temp,k,pos,c;
   c=check(arr,num,len);
   if(c==1) 
     {
	  for(k=0;k<len;k++)
        {
	      if(num==arr[k])
	         {
		   	   pos=k;
		 	 } 
	    } 
     for(i=pos;i<len;i++)
        {
          j=i;
          j++;
	      arr[i]=arr[j];
        } 
     }
    else
	 {
	   cout<<"\nElement not present";
	 }   
}

void accept(int *ptr,int len)
{
  int i;
  for(i=0;i<len;i++)
     { 	
      cout<<"\nEnter the element of set == ";
      cin>>*ptr;
      ptr++;
     }
}
void display(int *ptr,int len)
{
  int i;
  cout<<"{ ";
  for(i=0;i<len;i++)
     { 	
      cout<<"\t"<<*ptr<<",";
      ptr++;
     }
  cout<<"\t}\n";   
}
void un(int arr1[],int arr2[],int len1,int len2)
{
  int *arr=new int[len1+len2];
  int i,result;
  for(i=0;i<len1;i++)
     { 	
        arr[i]=arr1[i];
     }
  int j=len1;	
  for(i=0;i<len2;i++)
     {
	   result=check(arr,arr2[i],j);
	       if(result!=1)
		     {
			   arr[j]=arr2[i];
			   j++;
			 }  
	 } 
  cout<<"\nUnion of sets == \n";	 
  display(arr,j);
}
void inter(int arr1[],int arr2[],int len1,int len2)
{
  int i,result,len;
  if(len1>len2)
    {
	  len=len1;
	}
  else
    {
	 len=len2; 
	}	
  	 
  int *arr=new int[len];
  int j=0;	
  for(i=0;i<len2;i++)
     {
	   result=check(arr1,arr2[i],len1);
	       if(result==1)
		     {
			   arr[j]=arr2[i];
			   j++;
			 }  
	 } 
  cout<<"\nIntersection == \n";	 
  display(arr,j);
}
void diff(int arr1[],int arr2[],int len1,int len2)
{
  int i,result,len;
  if(len1>len2)
    {
	  len=len1;
	}
  else
    {
	 len=len2; 
	}	
  	 
  int *arr=new int[len];
  int j=0;	
  for(i=0;i<len1;i++)
     {
	   result=check(arr2,arr1[i],len2);
	       if(result!=1)
		     {
			   arr[j]=arr1[i];
			   j++;
			 }  
	 } 
  cout<<"\nDifferance is == \n";	 
  display(arr,j);
}
void sub(int arr1[],int arr2[],int len1,int len2)
{
  int i,result,len;
   int j=0;	
  for(i=0;i<len2;i++)
     {
	   result=check(arr1,arr2[i],len1);
	       if(result==1)
		     {
			   j++;
			 }  
	 } 
  if(len2==j)
     {
	   cout<<"\nSubset...........!\n";
	 }
  else
     {
	  cout<<"\nNot a subset.........!\n"; 
	 }	 
}

int main()
{
 int len1,len2,pos,num,sc; 	
 cout<<"\nEnter the length of set 1 == ";
 cin>>len1; 
 cout<<"\nEnter the length of set 2 == ";
 cin>>len2;
 int c,set1[len1],set2[len2],cho; 
 do
    {
       cout<<"\n\t1.Accept\n\t2.Display\n\t3.Union\n\t4.Intersection\n\t5.Differance\n\t6.Subset\n\t7.Insert\n\t8.Delete\n\t9.length";
  	   cout<<"\nEnter the choice == "; 
       cin>>cho; 
       switch(cho)
          {
		    case 1:
                  cout<<"\nEnter the first set == \n";
                  accept(set1,len1); 
                  cout<<"\nEnter the second set == \n";
                  accept(set2,len2); 
                  break;
		    case 2:
                  cout<<"\nFirst set is == \n";
                  display(set1,len1);
                  cout<<"\nSecond set is == \n";
                  display(set2,len2);
  			      break;
			case 3:
			      un(set1,set2,len1,len2);
				  break;		 		   		       
			case 4:
			      inter(set1,set2,len1,len2);
				  break;		 		   		       
			case 5:
			      diff(set1,set2,len1,len2);
				  break;		 		   		       
			case 6:
			      sub(set1,set2,len1,len2);
				  break;		 		   		       
			case 7:
			      cout<<"\nEnter the number to insert == ";
				  cin>>num;
				  cout<<"\nEnter the set in which u want to insert == ";
				  cin>>sc;
                  c=check(set1,num,len1);
                  if(c==1)
                  {
                    cout<<"\nElement is already present"; 
                  }
                  else 
                  { 
				  		if(sc==1)
				   			{
                    			set1[len1]=set1[len1++]; 
				    			insert(set1,len1,num);
				  			}
			  			else
				  			{
				   				set2[len2]=set2[len2++]; 	
				   				insert(set2,len2,num);  
				  			} 
                  }
                  
				  break;		 		   		       
			case 8:
			      cout<<"\nEnter the value of element== ";
				  cin>>num;
				  pos--; 
				  cout<<"\nEnter the set in which u want to insert == ";
				  cin>>sc;
				  if(sc==1)
				  {
                    del(set1,len1,num);
                    set1[len1]=set1[len1--];
				  }
				  else
				  {
				   del(set2,len2,num);
				   set2[len2]=set2[len2--];  
				  } 
				  break;		 		   		       
           case 9:
		          cout<<"\n\nLength of set 1== "<<len1;
				  cout<<"\nLength of set 2== "<<len2<<endl;  
                  break;
		  }
    }while(cho>0 && cho<10); 
}
