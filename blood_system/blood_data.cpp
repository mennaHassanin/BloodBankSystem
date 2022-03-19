#include "blood_data.h"
#include<iostream>

blood_data::blood_data()
{
	quantity = 0;

}

blood_data::blood_data(int quant, string type, string date) {

	quantity = quant;
	blood_type = type;
	str_date = date;

}
int blood_data::getQuantity() const
{
	return quantity;
}
string blood_data::getType() const
{
	return blood_type;
}
string blood_data::getDate() const
{
	return str_date;

}


void blood_data::setQuantity(int newQuantity) {
	quantity = newQuantity;
}

blood_data::~blood_data()
{

}