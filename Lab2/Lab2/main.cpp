#include "LongNumber.h"
#include "Caratsybi.h"
#include "Shenhage.h"
#include <iostream>
#include <ostream>
using namespace std;
ostream& operator<<(ostream &out, LongNumber longnumber) {
	if (longnumber.GetSign()) {
		out << "-";
	}
	for (int i = 0; i < longnumber.GetLenght(); i++) {
		out << longnumber.GetDigits()[i];
	}
	return out;
}

int main() {

	LongNumber num1("8821213");
	LongNumber num2("-213245");
	LongNumber num3("882");
	LongNumber num4("1213");
	cout << num3 + num4;
	cout << num1 + num2<<endl;
	cout << num1 - num2;
	cout << num1<<endl;
	Caratsybi car;
	LongNumber num5;
	num5 = car.Multiplication(num2 ,num1);
	Shenhage sh;
	cout << num5;
	num5 = sh.Multiplication(num1, num2);
	cout << num5;
	system("pause");
	return 0;
}