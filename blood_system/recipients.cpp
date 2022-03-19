#include "recipients.h"
#include<iostream>
#include<fstream>
#include <string>
using namespace std;
void recipients::recipient_menu()
{
	cout << "1-Register " << endl;
	cout << "2-login " << endl;
	cout << "3-exit" << endl;
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
			exit(0);
			break;
		}
		else
			cout << "wrong choice! please try again" << endl;
		continue;
	}
}
void recipients::sub_menu()
{
		cout << "1-update your Data " << endl;
		cout << "2-Delete your account " << endl;
		cout << "3-search for the availability of blood type " << endl;
		cout << "4-Display blood data " << endl;
		cout << "5-Request donation " << endl;
		cout << "6-Back" << endl;
	while (true)
	{
		int choice;
		cout << "Choose the number that meets your need:" << endl;
		cin >> choice;
		if (choice == 1)
		{
			update();
			break;

		}
		else if (choice == 2)
		{
			Delete();
			break;
		}
		else if (choice == 3)
		{
			search();
			break;
		}
		else if (choice == 4)
		{
			display();
			break;
		}
		else if (choice == 5)
		{
			Request();
			break;
		}
		else if (choice == 6)
		{
			recipient_menu();
			break;
		}
		else
			cout << "wrong choice ! try again" << endl;
		continue;
	}

	system("pause");
	system("cls");
}
void recipients::Register()
{
	cout << "Enter your id : " << endl;
	cin >> ID;
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
	cin.ignore();
	cout << "Enter doctor name : " << endl;
	getline(cin, doctor_name);
	cout << "account is created successfully " << endl;
	fstream RegFile;
	RegFile.open("Register.txt", ios::app);
	RegFile << ID << endl << name << endl << mail << endl << password << endl << age << endl << gender << endl << blood_type << endl << hospital_name << endl << doctor_name << endl;
	RegFile.close();
	system("pause");
	system("cls");
	sub_menu();
}
void recipients::update()

{
	string ID, name, mail, password, gender, blood_type, hospital_name, doctor_name;
	int age;
	fstream RegFile;
	fstream temp;
	string n;
	RegFile.open("Register.txt", ios::in);
	temp.open("temp.txt", ios::out);
	cout << "enter ID" << endl;
	cin >> n;
	int x;
	while (RegFile >> ID >> name >> mail >> password >> age >> gender >> blood_type >> hospital_name >> doctor_name)
	{
		if (n == ID)
		{
			cout << " Press 1 to edit name : \n Press 2 to edit mail : \n  Press 3 to edit password : \n  press 4 to edit age : \n press 5 to edit Doctor_name: \n";
			cin >> x;
			switch (x)
			{

			case 1:
				cout << "Enter the new name" << endl;
				cin.ignore();
				getline(cin, name);
				break;
			case 2:
				cout << "Enter the new mail" << endl;
				cin >> mail;
				break;
			case 3:
				cout << "Enter the new password " << endl;
				cin >> password;
				break;

			case 4:
				cout << "Enter the new age " << endl;
				cin >> age;

			case 5:
				cout << "enter the new Doctor_of_the_case" << endl;
				cin.ignore();
				getline(cin, doctor_name);
				break;
			default:
				cout << "invalid number" << endl;
			}

			temp << ID << endl << name << endl << mail << endl << password << endl << age << endl << gender << endl << blood_type << endl << hospital_name << endl << doctor_name << endl;
		}

		else
		{
			temp << ID << endl << name << endl << mail << endl << password << endl << age << endl << gender << endl << blood_type << endl << hospital_name << endl << doctor_name << endl;
		}

	}
	temp.close();
	RegFile.close();
	remove("Register.txt");
	rename("temp.txt", "Register.txt");
	system("pause");
	system("cls");
	recipient_menu();

}
recipients::recipients()
{
	ID = 0;
	name = "";
	mail = "";
	password = "";
	age = 0;
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
	while (true)
	{
		fstream RegFile;
		int ID;
		RegFile.open("Register.txt", ios::in);
		if (RegFile.fail())
		{
			cout << "Register file opening failed";
			exit(1);
		}
		string password;
		cout << "Enter your ID :" << endl;
		cin >> ID;
		cout << "enter password :" << endl;
		cin >> password;
		recipients r;
		bool isFound = 0;
		int id;
		while (RegFile >> r.ID >> r.name >> r.mail >> r.password >> r.age >> r.gender >> r.blood_type >> r.hospital_name >> r.doctor_name)
		{
			id = r.ID;
			if ((ID == r.ID) && (password == r.password))
			{
				isFound = 1;
				break;
			}
			else
			{
				isFound = 0;
				break;
			}
		}
		if (isFound)
		{
			cout << "login successfully" << endl;
			system("pause");
			system("cls");
		}

		if ((!isFound))
		{
			cout << "login failed! try again" << endl;
			continue;
		}
		RegFile.close();

		if (isFound)
		{
			sub_menu();
			
		}
	}
}
void recipients::Request()
{


}
void recipients::search()
{

}

