#include "LongNumber.h"
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

	LongNumber num1("-882121334");
	LongNumber num2("-213245678");
	cout << num1 + num2;
	system("pause");
	return 0;
}