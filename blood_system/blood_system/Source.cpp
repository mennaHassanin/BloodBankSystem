#include"recipients.h"
#include "Donor.h"
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	
	recipients r;
	Donor donor ; 
	int choice; 
	while (true)
	{
		cout << "1.Donor" << endl; 
		cout << "2.Recpient" << endl; 
		cout << "3.Exit" << endl; 
		cout << "Enter choice : " << endl; 
		cin >> choice; 
		if (choice == 1)
		{
			donor.menu();
		}
		else if (choice == 2)
		{
			r.recipient_menu();
		}
		else if (choice == 3)
		{
			break; 
		}
		else
		{
			cout << "Invalid choice" << endl; 
		}
	}
}
