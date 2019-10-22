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
int LongNumber::GetLenght() {
	return digits.size();
}
vector<int> LongNumber::GetDigits() {
	return digits;
}
LongNumber LongNumber::operator+(LongNumber other) {
	if (this->GetSign() && other.GetSign() || !this->GetSign() && !other.GetSign()) {
		LongNumber *minSize = this->GetLenght() > other.GetLenght() ? &other : this;
		LongNumber *maxSize = this->GetLenght() > other.GetLenght() ? this : &other;
		int dozen = 0;
		int res;
		
		string NewNumber = "";
		for (int i = 0; i < minSize->GetLenght(); i++) {
			res = maxSize->GetDigits()[maxSize->GetLenght()-i-1] + minSize->GetDigits()[minSize->GetLenght()-i-1]+dozen;
			if (res >= 10) {
				dozen = res / 10;
				res = res % 10;
			}
			else {
				dozen = 0;
			}

			NewNumber = to_string(res) + NewNumber;
		}
		for (int i = maxSize->GetLenght() - minSize->GetLenght()-1; i >= 0; i--) {
			res = maxSize->GetDigits()[i]+ dozen;
			if (res >= 10) {
				dozen = res / 10;
				res = res % 10;
			}
			NewNumber = to_string(res) + NewNumber;
		}
		if (dozen != 0) {
			NewNumber = to_string(dozen) + NewNumber;
		}
		if (this->GetSign() && other.GetSign()) {
			NewNumber = "-" + NewNumber;
		}
		return LongNumber(NewNumber);
	}
	/*else
	{
		if (this->GetSign() && !other.GetSign()) {
			return other - this;
		}
		else
		{
			return this - other;
		}
	}*/
	return LongNumber("0");
}
