#include "recipients.h"
#include<iostream>
#include<fstream>
#include <string>
using namespace std;
void recipients::recipient_menu()
{
		cout << "1-Register " << endl;
		cout << "2-login " << endl;
		cout << "3-update your account " << endl;
		cout << "4-Delete your account " << endl;
		cout << "5-search for the availability of blood type " << endl;
		cout << "6-Display blood data " << endl;
		cout << "7-Request donation " << endl;
		cout << "8-exit" << endl;
		while (true)
		{
			int choice;
			cout << "Choose the number that meets your need:" << endl;
			cin >> choice;
			if (choice == 1)
			{
				Register();
				break;
			}
			else if (choice == 2)
			{
				login();
				break;
			}
			else if (choice == 3)
			{
				update();
				break;
			}
			else if (choice == 4)
			{
				Delete();
				break;
			}
			else if (choice == 5)
			{
				search();
				break;
			}
			else if (choice == 6)
			{
				display();
				break;
			}
			else if (choice == 7)
			{
				Request();
				break;
			}
			else if (choice == 8)
			{
				exit(0);
				break;
			}
			else
				cout << "wrong choice! please try again" << endl;
			continue;
	    }
}
void recipients::Register()
{
	cout << "Enter your id : "<<endl;
	cin>>ID;
	cout << "Enter your name : " << endl;
	cin.ignore();
	getline(cin, name);
	cout << "Enter your mail : " << endl;
	cin >> mail;
	cout << "Enter your passwrod : " << endl;
	cin >> password;
	cout << "Enter your age : " << endl;
	cin >> age;
	cout << "Enter your gender : " << endl;
	cin >> gender;
	cout << "Enter your blood type : " << endl;
	cin >> blood_type;
	cout << "Enter the hospital name : " << endl;
	cin.ignore();
	getline(cin, hospital_name);
	cout << "Enter doctor name : " << endl;
	cin.ignore();
	getline(cin, doctor_name);
	cout << "account is created successfully " << endl;
	fstream RegFile;
	RegFile.open("Register.txt", ios::app);
	RegFile << ID << endl << name << endl << mail << endl << password << endl << age << endl << gender << endl << blood_type << endl <<hospital_name << endl << doctor_name << endl;
	RegFile.close();
	system("pause");
	system("cls");
	recipient_menu();
}
void recipients::update()

{
	login();
	int choice;
	cout << "1- name" << endl;
	cout << "2- mail" << endl;
	cout << "3- password" << endl;
	cout << "4- age" << endl;
	cout << "5- doctor name" << endl;
	cout << "what do you want to update:" << endl;
	cin >> choice;
	if (choice == 1)
	{
		cout << "enter new name : " << endl;
	}
	else if (choice == 2)
	{
		cout << "enter new mail : " << endl;
	}
	else if (choice == 3)
	{
		cout << "enter new password : " << endl;
	}
	else if (choice == 4)
	{
		cout << "enter new age : " << endl;
	}
	else if (choice == 5)
	{
		cout << "enter new doctor name : " << endl;
	}
	else
		cout << "wrong choice : " << endl;

}
recipients::recipients()
{
	 ID = 0;
	 name = "";
	 mail = "";
	 password = "";
	 age=0;
	 gender = "";
	 blood_type = "";
	 hospital_name = "";
	 doctor_name = "";
}
void recipients::Delete()
{
	fstream RegFile;
	fstream temp;
	RegFile.open("Register.txt", ios::in);
	temp.open("temp.txt", ios::out);
	string ID, name, mail, password, gender, blood_type, hospital_name, doctor_name;
	int age;
	string n;
	cout << "enter ID" << endl;
	cin >> n;
	while (RegFile >> ID >> name >> mail >> password >> age >> gender >> blood_type >> hospital_name >> doctor_name)
	{
		if (ID == n)
		{
			continue;
		}
		else
		{
			temp << ID << endl << name << endl << mail << endl << password << endl << age << endl << gender << endl << blood_type << endl << hospital_name << endl << doctor_name << endl;
		}

	}
	RegFile.close();
	temp.close();
	RegFile.open("Register.txt", ios::out);
	temp.open("temp.txt", ios::in);
	while (temp >> ID >> name >> mail >> password >> age >> gender >> blood_type >> hospital_name >> doctor_name)
	{
		RegFile << ID << endl << name << endl << mail << endl << password << endl << age << endl << gender << endl << blood_type << endl << hospital_name << endl << doctor_name << endl;
	}
	temp.close();
	RegFile.close();
	remove("temp.txt");
	cout << "account deleted successfully" << endl;
	system("pause");
	system("cls");
	recipient_menu();
}
void recipients::display()
{

}
void recipients::login()
{
	fstream RegFile;
	RegFile.open("Register.txt", ios::in);			
	if (RegFile.fail())
	{
		cout << "Register file opening failed";
		exit(1);
	}
	string n;
	cout << "enter your name :" << endl;
	cin.ignore();
	getline(cin, n);
	cout << "enter password :" << endl;
	cin >> n;
	bool isFound = 0;
	while (!RegFile.eof())
	{
		string line = "";
		getline(RegFile, line);
		for (int i = 0; i < n.size(); i++)
		{
			if (line[i] == n[i])
				isFound = 1;
			else
			{
				isFound = 0;
				break;
			}
		}

		if (isFound)
		{
			cout << "login successfully" << endl;
			break;
		}

	}

	if (RegFile.eof() && (!isFound))
	{
		cout << "login failed" << endl;
	}
	RegFile.close();
	system("pause");
	system("cls");
	recipient_menu();
}
void recipients::Request()
{
	cout <<"Enter blood type : " << endl;
	cin >> blood_type;

	cout << "Enter the quantity of that blood type you need : " << endl;
	
	cout << "Enter hospital name : " << endl;
	cin >> hospital_name;



}
void recipients::search()
{

}

