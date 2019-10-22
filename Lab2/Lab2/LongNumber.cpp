#include "LongNumber.h"
using namespace std;
LongNumber::LongNumber() {
	digits.push_back(0);
	sign = false;
}
LongNumber::LongNumber(string Number) {
	string UnsignedNumber;
	if (Number[0] == '-') {
		UnsignedNumber = Number.substr(1);
		sign = true;
	}
	else
	{
		UnsignedNumber = Number;
		sign = false;
	}
	ConvertFromStringToVector(UnsignedNumber);

}

void LongNumber::ConvertFromStringToVector(string &Number) {
	string temp;
	for (int i = 0; i < Number.length(); i++) {
		temp = Number[i];
		digits.push_back(stoi(temp));

	}

}
bool LongNumber::GetSign() {
	return sign;
}