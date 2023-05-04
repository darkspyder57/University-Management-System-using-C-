#include<iostream>
#include<vector>
#include<stdio.h>
#include<cstring>
#include<fstream>
#include<algorithm>
using namespace std;
class Student
{
	public:
		long int reg;
		char name[80],branch[50];
		float sem_res;
		void input()
		{
			cout<<"\n Enter student's name: ";
			gets(name);
			cout<<"\n Enter registration no: ";
			cin>>reg;
			fflush(stdin);
			cout<<"\n Enter Branch: ";
			gets(branch);
			cout<<"\n Enter Semester 1 CGPA:";
			cin>>sem_res;
		}
		void display()
		{
			system("CLS");
			cout<<"\t\t Display Records";
			cout<<"\n";
			cout<<"\n Name - "<<name;
			cout<<"\n Reg no. - "<<reg;
			cout<<"\n Branch - "<<branch;
			cout<<"\n Semester 1 CGPA -"<<sem_res;
			cout<<"\n";
			system("PAUSE");
			system("CLS");
		}
		bool operator == (Student a)
		{
			if(reg==a.reg)
				return true;
			else
				return false;
		}
};

vector <Student>v;
int search_reg(long int reg,int &i);
void get_file()
{
	Student x;
	int i=0;
	fstream f;
	f.open("University.txt",ios::in);
	if(f)
	{
		f.read((char *) &x,sizeof(class Student));
		while(!f.eof()) 
		{
			v.push_back(x);
			f.read((char *) &x,sizeof(class Student));
		}
	}
	else
		;
	f.close();
}
void bubblesort()
{
	int i,j;
	Student x;
	for(i=0;i<v.size();i++)
		for(j=0;j<v.size()-i-1;j++)
			if(v[j].reg>v[j+1].reg)
			{
				x=v[j];
				v[j]=v[j+1];
				v[j+1]=x;
			}			
}
void insert_new()
{
	char ch='Y';
	int ta;
	while(ch=='Y')
	{
		fflush(stdin);
		Student x;
		x.input();
		if(search_reg(x.reg,ta)==0)
			v.push_back(x);
		else
			cout<<"\nTHE REGISTRATION NO. ALREADY EXIST!!!\n CANNOT ADD" ;
			cout<<endl;
		cout<<"\n\t Press [Y] to enter more OR Press [S] to save till where the data had been given: ";
		cin>>ch;
		fflush(stdin);
	}
}
void write_file()
{
	bubblesort();
	fstream f;
	f.open("University.txt",ios::out);
	for(int i=0;i<v.size();i++)
	{
		Student x=v[i];
		f.write((char *) &x,sizeof(class Student));
	}
	f.close();
}
int search_reg(long int reg,int &i)
{
	int ta=0;
	for(i=0;i<v.size();i++)
		if(v[i].reg==reg)
		{
			ta=1;
			break;
		}
	return ta;
}
int search_name(char name[],vector<int> &vi)
{
	int i,ta=0;
	for(i=0;i<v.size();i++)
		if(strcmp(v[i].name,name)==0)
		{
			ta=1;
			vi.push_back(i);
		}
	return ta;
}
int search_branch(char branch[],vector<int> &vj)
{
	int i,ta=0;
	for(i=0;i<v.size();i++)
		if(strcmp(v[i].branch,branch)==0)
		{
			ta=1;
			vj.push_back(i);
		}
	return ta;
}

void search_and_show()
{
	int ch,i,j,ta=0;
	char name[80],branch[50];
	vector <int>vi; 
	vector <int>vj;
	long int reg;
	poi:
	cout<<"\n\t Press 1 to search reg no."
	<<"\n\t Press 2 to search name"
	<<"\n\t Press 3 to search branch";
	cout<<"\n\t\t";
	cin>>ch;
	switch(ch)
	{
		case 1:
			cout<<"\n\t Enter reg no.: ";
			cin>>reg;
			if(search_reg(reg,i)==1)
				v[i].display();
			else
				cout<<"\n\t RECORD NOT FOUND!!!";
			break;
		case 2:
			cout<<"\n\t Enter name: ";
			fflush(stdin);
			gets(name);
			if(search_name(name,vi)==1)
			{
				for(int k=0;k<vi.size();k++)
					v[vi[j]].display();
			}
			else
				cout<<"\n\t RECORD NOT FOUND!!!";
			break;
		case 3:
			cout<<"\n\t Enter branch: ";
			fflush(stdin);
			gets(branch);
			if(search_branch(branch,vj)==1)
			{
				for(int k=0;j<vj.size();k++)
					v[vj[j]].display();
			}
			else
				cout<<"\n\t RECORD NOT FOUND!!!";
			break;	
		default:
			cout<<"\n\t WRONG CHOICE!!!";
			goto poi;
	}
}
void show()
{
	int i;
	for(i=0;i<v.size();i++)
		v[i].display();
}
void delete_data()
{
	int i,j;
	long int reg;
	vector <Student>::iterator p=v.begin();
	cout<<"\n\t Enter Registration number: ";
	cin>>reg;
	if(search_reg(reg,i)==1)
	{
		Student x=v[i];
		cout<<"\n\t The following data is being deleted";
		x.display();
		p+=i;
		v.erase(p,p+1);
	}
}
void edit_data()
{
	int i,j;
	long int reg;
	vector <Student>vi;
	cout<<"\n\t Enter Registration number: ";
	cin>>reg;
	if(search_reg(reg,i)==1)
	{
		cout<<"\n\t Enter new data:";
		fflush(stdin);
		v[i].input();
	}
}
int main()
{
	int i=1;
	get_file();
	while(i)
	{
		system("CLS");
		system("Color 0A");
		cout<<"\t\t\t-----------------------------------------\n";
		cout<<"\t\t\t|     UNIVERSITY MANAGEMENT SYSTEM      |\n";
		cout<<"\t\t\t|      By:- JATIN BISOI &               |\n";
		cout<<"\t\t\t|          DEEPAK PATRO                 |\n";
		cout<<"\t\t\t-----------------------------------------\n";
		cout<<"\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		cout<<"\t\t\t             MAIN MENU \n";
		cout<<"\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		cout<<"\n\t\t\t Enter <1> to Add new student"
			<<"\n\t\t\t Enter <2> to Display all the student's data entered"
			<<"\n\t\t\t Enter <3> to Remove student"
			<<"\n\t\t\t Enter <4> to Edit student's information"
			<<"\n\t\t\t Enter <5> to Search student"
			<<"\n\t\t\t Enter <0> to Exit\n";
		cout<<"\n\n\t\t\t Enter Your Choice:";	
		cin>>i;
		switch(i)
		{
			case 1 :
				insert_new();
				break;
			case 2 :
				show();
				break;
			case 3 :
				delete_data();
				break;
			case 4 :
				edit_data();
				break;
			case 5 :
				search_and_show();
				break;
			case 0 :
				write_file();
				break;
			default :
				cout<<"\n WRONG CHOICE!!!\n TRY AGAIN";
				
		}
	}
	return 0;
}
