#include<string>
#include<vector>
#include<Windows.h>
using namespace std;
class blood_data
{
private:
	string blood_type;
	int quantity;
	string str_date;

public:
	blood_data();
	blood_data(int quantity, string blood_type, string str_date);
	int getQuantity() const;
	string getType() const;
	string getDate() const;
	void setQuantity(int quantity);
	~blood_data();
};

