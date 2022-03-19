#include"Donor.h"
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include <Windows.h>
#include <map>
using namespace std;

Donor::Donor()
{
	id = 0;
	name = "";
	mail = "";
	password = "";
	age = 0;
	gender = {};
	bloodtype = "";
	lastdonationdate.day = 0;
	lastdonationdate.month = 0;
	lastdonationdate.year = 0;
	medcine =false;

}
void Donor::menu()
{
		cout << "1.Register" << endl;
		cout << "2.Login" << endl;	
		cout << "3.Exit" << endl; 
	while (true)
	{
		int choice; 
		cout << "Choose the number that meets your need:" << endl;
		cin >> choice;
		if (choice == 1)
		{
			reg(); 
			break;
		}
		else if (choice == 2)
		{
			login(); 
			break;
		}
		else if (choice == 3)
		{
			break; 
		}
		else
		{
			cout << "Invalid choice " << endl;
		}
	}
}
void Donor::reg()
{
	cout << "Enter your id : " << endl;
	cin >> id;
	cout << "Enter your name : " << endl;
	cin.ignore();
	getline(cin, name);
	cout << "Enter your mail : " << endl;
	cin >> mail;
	cout << "Enter your passwrod : " << endl;
	cin >> password;
	cout << "Enter your age : " << endl;
	cin >> age;
	cout << "Enter your gender (M / F) : " << endl;
	cin >> gender;
	cout << "Enter your blood type : " << endl;
	cin >> bloodtype;
	cout << "Enter your last donation date :" << endl;
	cout << "Day : "; 
	cin >> lastdonationdate.day;
	cout << "Month : ";
	cin >> lastdonationdate.month;
	cout << "Year : ";
	cin	>>lastdonationdate.year;
	fstream Regfile;
	Regfile.open("DonorRegister.txt", ios::app);
	Regfile << id  << " "  << name << " " << mail << " "  << password << " "  << age <<  " "  << gender << " "  << bloodtype << " "  << lastdonationdate.day << " " << lastdonationdate.month << " " << lastdonationdate.year << endl;
	Regfile.close();
	system("pause");
	system("cls");
	menu();
}
bool Donor::Disease()
{
	int choice2 , noOfdisease;
	ofstream Regfile; 
	cout << "Are you suffer from any of these diseases (blood pressure disorders, thyroid disease, diabetes, cancer, heart disorders, hepatitis)? " << endl;
	cout << "if yes enter 1 , if no enter 2 " << endl;
	cin >> choice2;
	if (choice2 == 1)
	{
		cout << "How many diseases ? " << endl;
		cin >> noOfdisease;
		cout << "Enter diseases : " << endl; 
		Regfile.open("DonorRegister.txt", ios::app);
		for (int i = 0; i < noOfdisease; i++)
		{
			if (i<1)
			{
				cin.ignore();
			}
			getline(cin, disease[i]);
			Regfile << disease[i] << " " ;
		}
		Regfile.close();
	}
	else if (choice2 == 2)
	{
		string anotherDisease , medicine;
		cout << "1.Do you have any another disease ? " << endl;
		cout << "2.Do you take any medicine ? "  << endl;
		cout << "3.No" << endl; 
		cin >> choice2;
		if (choice2 == 1)
		{
			cout << "Enter name of this disease " << endl; 
			Regfile.open("DonorRegister.txt", ios::app);
			cin.ignore(); 
			getline(cin,anotherDisease);
			Regfile << anotherDisease << " " ; 
			Regfile.close();
			return true;
		}
		else if (choice2 == 2)
		{
			cout << "Enter name of this medicine " << endl;
			Regfile.open("DonorRegister.txt", ios::app);
			cin.ignore();
			getline(cin, medicine);
			Regfile << medicine << " " ;
			Regfile.close();
			return true;
		}
		else
		{
			return false; 
		}
		
	}
}
bool Donor::donationreq(int id)
{
	SYSTEMTIME t;
	GetLocalTime(&t);
	int day = t.wDay;
	int month = t.wMonth;
	int year = t.wYear;
	int expdate, expdate1, diffdate;
	int age;
	string ID, name, mail, password, gender, bloodtype;
	Date lastdonationdate;
	Donor D;
	fstream RegFile , Temp;
	bool valid = false;
	map <string, int> Donation;
	Donation["A+"] = 0; 
	Donation["A-"] = 0;
	Donation["B+"] = 0;
	Donation["B-"] = 0;
	Donation["AB-"] = 0;
	Donation["AB+"] = 0;
	Donation["O-"] = 0;
	Donation["O+"] = 0;
	RegFile.open("DonorRegister.txt", ios::in);
	Temp.open("DonatedBlood.txt", ios::app);
	while (RegFile >>D.id >> D.name>> D.mail >> D.password>> D.age >> D.gender >> D.bloodtype >>  D.lastdonationdate.day >> D.lastdonationdate.month >> D.lastdonationdate.year)
	{
		if (id == D.id) 
		{
			expdate = D.lastdonationdate.year * 360 + D.lastdonationdate.month * 30 + D.lastdonationdate.day;
			expdate1 = t.wYear * 360 + t.wMonth * 30 + t.wDay;
			diffdate = expdate1 - expdate;
			int years = diffdate / 360;
			int months = (diffdate - years * 360) / 30;
			int days = diffdate - years * 360 - months * 30;
			if (D.age > 17 && D.age < 60 && months <= 3 && !Disease())
			{
				cout << "Confirm" << endl;
				Donation[bloodtype]++; 
				Temp << D.bloodtype << " " << Donation[bloodtype] << endl;
				return true; 
			}
			else
			{
				cout << "Not Confirmed " << endl;
				return false; 
			}
		}
	}
	RegFile.close(); 
	Temp.close();

}
void Donor::login()
{
	fstream RegFile;
	int choice , ID; 
	RegFile.open("DonorRegister.txt", ios::in);
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
	string pass, mail;
	Donor D;
	bool isFound = 0;
	int id;
	while (RegFile >>D.id>> D.name >>D.mail>> D.password>>D.age>>D.gender>>D.bloodtype>>D.lastdonationdate.day>> D.lastdonationdate.month>> D.lastdonationdate.year)
	{
		id = D.id;
		if (( ID == D.id) && (password == D.password))
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
		}
	/*while (!RegFile.eof())
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

	}*/
	if (RegFile.eof() && (!isFound))
	{
		cout << "login failed" << endl;
	}
	RegFile.close();
	
	if (isFound)
	{
		cout << "1.Donation request" << endl;
		cout << "2.Update Data" << endl;
		cout << "3.Delete Account" << endl;
		cout << "4.Back" << endl;
		cin >> choice;
		if (choice == 1)
		{
			donationreq(id);

		}
		else if (choice == 2)
		{
			update();
		}
		else if (choice == 3)
		{
			Delete();
		}
		else if (choice == 4)
		{
			menu();
		}
	}
	system("pause");
	system("cls");
}
void Donor::update()
{
	string ID, name, mail, password, gender, blood_type;
	int age;
	Date lastdonationdate;
	fstream RegFile;
	fstream temp;
	string n;
	RegFile.open("DonorRegister.txt", ios::in);
	temp.open("temp.txt", ios::out);
	cout << "enter ID" << endl;
	cin >> n;
	int x;
	while (RegFile >> ID >> name >> mail >> password >> age >> gender >> blood_type )
	{
		if (n == ID)
		{
			cout << " Press 1 to edit name : \n Press 2 to edit mail : \n  Press 3 to edit password : \n  press 4 to edit age : \npress 5 to edit Doctor_of_the_case:\n";
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
				cout << "Enter the new donation date " << endl;
				cin >> lastdonationdate.day >> lastdonationdate.month >> lastdonationdate.year;
				break;
			default:
				cout << "invalid number" << endl;
			}

			temp << ID << endl << name << endl << mail << endl << password << endl << age << endl << gender << endl << blood_type << endl << lastdonationdate.day << lastdonationdate.month << lastdonationdate.year;
		}

		else
		{
			temp << ID << endl << name << endl << mail << endl << password << endl << age << endl << gender << endl << blood_type << endl;
		}

	}
	temp.close();
	RegFile.close();
	remove("DonorRegister.txt");
	rename("temp.txt", "DonorRegister.txt");
	system("pause");
	system("cls");
	menu();

}
void Donor::Delete()
{
	fstream RegFile;
	fstream temp;
	RegFile.open("DonorRegister.txt", ios::in);
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
	RegFile.open("DonorRegister.txt", ios::out);
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
	menu();
}
Donor::~Donor()
{
	
}