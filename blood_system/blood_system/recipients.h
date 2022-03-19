#pragma once
#include <string>
using namespace std;
class recipients
{
private:
	int ID;
	string name;
	string mail;
	string password;
	int age;
	string gender;
	string blood_type;
	string hospital_name;
	string doctor_name;

public:
	recipients();
	void recipient_menu();
	void Register();
	void login();
	void update();
	void Delete();
	void display();
	void search();
	void Request();
	
};

