#include<fstream>
#include "Donor.h"
#include "recipients.h"
#include <iostream>
using namespace std;
int main()
{

	recipients r;
	Donor donor;
	cout << "1.Donor" << endl;
	cout << "2.Recpient" << endl;
	cout << "3.Exit" << endl;
	while (true)
	{
		int choice;
		cout << "Enter your choice : " << endl;
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

			cout << "Invalid choice ! try again" << endl;
		continue;
	}
}
