#include<iomanip>
#include<fstream>
#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
struct sdetail
{
  int rn,index;
  char name[20],div;
  char add[50];
  
  void accept(int i)
     {
       cout<<"iA";	
	   index=i;
	   cout<<"\nEnter the roll number == ";
	   cin>>rn;
	   cout<<"\nEnter the div == ";
	   cin>>div;
	   cout<<"\nEnter the name == ";
	   cin>>name;
	   cout<<"\nEnter the address == ";
	   cin>>add; 
	 }
 void display()
     {
       cout<<"\nIndex          == "<<index;
	   cout<<"\nRoll number    == "<<rn;
	   cout<<"\nDiv            == "<<div;
	   cout<<"\nName           == "<<name;
	   cout<<"\nAddress        == "<<add;
	 }
};
int insert(int i)
{
  sdetail obj;
  fstream file;
  obj.accept(i);
  file.open("result.txt",ios::out|ios::binary|ios::app);
  file.write((char *)&obj,sizeof(sdetail));
  file.close();
  i++;
  return i;
} 
void del()
{
  int rn,flag=0;
  sdetail obj;
  fstream file,file1;
  file.open("result.txt",ios::in|ios::binary);
  file.seekg(0,ios::beg);
  file1.open("temp.txt",ios::out|ios::binary); 
  cout<<"\nEnter the roll number to delete == ";
  cin>>rn;
  while(file.read((char *)&obj,sizeof(sdetail)))
      {
	    if(rn==obj.rn)
	      {
		   cout<<"\nRecord deleted successfully......!\n";
	       flag=1;
	      }
	  }
      file.close();
      file1.close();
      remove("result.txt");
	  rename("temp.txt","result.txt");  
} 
void search()
{
  int rn,flag=0;
  sdetail obj;
  fstream file;
  file.open("result.txt",ios::in|ios::binary);
  file.seekg(0,ios::beg);
  cout<<"\nEnter the roll number to delete == ";
  cin>>rn;
  while(file.read((char *)&obj,sizeof(sdetail)))
      {
	    if(rn==obj.rn)
	      {
		    obj.display();
            flag=1;
	      }
	  }
		  if(flag==0)
		      {
			    cout<<"\nRecord not found....!"<<endl;
			  }

      file.close();
} 
int main()
{
  sdetail obj;
  fstream file1,file2;
  int nos,i,cho,index=0,rn;
  do
  {
    cout<<"\n\t1.Add\n\t2.Display\n\t3.Insert\n\t4.Delete\n\t5.Search\n\t6.exit";
    cout<<"\nEnter the choice == ";
	cin>>cho;  
    switch(cho)
	    {
		  case 1:
				  cout<<"\nEnter the number of student == ";
				  cin>>nos;
				  cout<<"\nbl"; 
				  file1.open("result.txt",ios::out|ios::binary);
				  cout<<"af";
				  for(i=0;i<nos;i++)
				     {
       				    cout<<"il";
					   	obj.accept(index);
	   					file1.write((char *)&obj,sizeof(sdetail));
				        index++;
					 }      
                  file1.close(); 		         
                  break;
		  case 2:
				  file2.open("result.txt",ios::in|ios::binary);
				  file2.seekg(0,ios::beg);
				  if(file2.read((char *)&obj,sizeof(sdetail))==0)
				    {
					  cout<<"\nOops....no record is present.............!\n";
					}
				  else
				    {	 
		             obj.display();
				     while(file2.read((char *)&obj,sizeof(sdetail)))
				         {
					      obj.display();
				          cout<<endl;
					     }      
				    }
				  file2.close();
                  break; 		         		   
         case 3:
                  index=insert(index);
				  break;  		               
         case 4:
                  del();
				  break;  		               
         case 5:
                  search();
				  break;  		               
		}  
  }while(cho>0 && cho<6);
} 



