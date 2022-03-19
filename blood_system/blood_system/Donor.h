#pragma once
#include<string>
#include<vector>
using namespace std;
struct Date 
{
	int day;
	int month;
	int year;

};
class Donor
{

	long long id;
	int age;
	string name, bloodtype, password, mail;
	char gender;
	Date lastdonationdate;
	bool medcine;
	string disease[6];
public:
	Donor();
	void menu();
	void reg();
	bool Disease();
	void login();
	bool donationreq(int id);
	void update();
	void Delete();
	~Donor();
};
