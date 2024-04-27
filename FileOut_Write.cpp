#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

const int length =25;

typedef struct
{
	int day;
	int month;
	int year;
}Date;

typedef struct
{
	char name[20];
	Date birthday;
	char role[20];
	float salary; 
}Employee;

int main()
{
	char fileName[length];
	cout<<"Ten tep tin: ";
	cin>>fileName;
	
	int numberofrecord;
	cout<<"\nSo luong ban ghi: ";
	cin>>numberofrecord;
	
	fstream fileOut(fileName, ios::out|ios::binary);
	if(!fileOut)
	{
		cout<<"\nKhong the tao duoc tep tin."<<fileName<<endl;
		return 0;
	}
	
	Employee myEmployee;
	for(int i=0; i<numberofrecord; i++)
	{
		cout<<"\nBan ghi thu "<<i+1<<endl;
		cout<<"\nName: ";
		cin>>myEmployee.name;
		cout<<"\nBirthday\nDay: ";
		cin>>myEmployee.birthday.day;
		cout<<"\nMonth: ";
		cin>>myEmployee.birthday.month;
		cout<<"\nYear: ";
		cin>>myEmployee.birthday.year;
		cout<<"\nRole: ";
		cin>>myEmployee.role;
		cout<<"\nSalary: ";
		cin>>myEmployee.salary;
		
		fileOut.write(reinterpret_cast<char*>(&myEmployee),sizeof(Employee));
	}
	
	fileOut.close();
	return 0;
}