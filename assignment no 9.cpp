#include<fstream>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct sdetail
{
  int rn,index;
  char name[20],div;
  string add;

  void accept()
     {
	   cout<<"\nEnter the roll number == ";
	   cin>>rn;
	   cout<<"\nEnter the div == ";
	   cin>>div;
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
void inserts()
{
  sdetail obj;
  fstream file;
  obj.accept();
  file.open("result.txt",ios::out|ios::binary|ios::app);
  file.write((char *)&obj,sizeof(sdetail));
  file.close();
}
int del()
{
  int rn;
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
	      }
		else
		  {
			    file1.write((char *)&obj,sizeof(sdetail));
		  }
	  }
      file.close();
      file1.close();
      remove("result.txt");
	  rename("temp.txt","result.txt");
}
int main()
{
  sdetail obj;
  fstream file1,file2;
  int nos,i,cho,index=0,rn;
  do
  {
    cout<<"\n\t1.Add\n\t2.Display\n\t3.Insert\n\t4.Delete\n\t5.exit";
    cout<<"\nEnter the choice == ";
	cin>>cho;
    switch(cho)
	    {
		  case 1:
				  cout<<"\nEnter the number of student == ";
				  cin>>nos;
				  cout<<"\nbl";
				  file1.open("result.txt",ios::out|ios::binary);
				  for(i=0;i<nos;i++)
				     {
					   	obj.accept();
	   					file1.write((char *)&obj,sizeof(sdetail));
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
                  inserts();
				  break;
         case 4:
                  del();
				  break;
		}
  }while(cho>0 && cho<5);
}



