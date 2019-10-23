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
void LongNumber::ChangeSign() {
	sign = !sign;
}
LongNumber& LongNumber::operator=(LongNumber other) {
	this->sign = other.GetSign();
	this->digits.clear();
	for (int i = 0; i < other.GetLenght(); i++) {
		this->digits.push_back(other.GetDigits()[i]);
	}
	return *this;
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
			else
			{
				dozen = 0;
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
	else
	{
		if (this->GetSign() && !other.GetSign()) {
			LongNumber differentSign;
			differentSign = *this;
			differentSign.ChangeSign();
			return other - differentSign;
		}
		else
		{
			LongNumber differentSign;
			differentSign = other;
			differentSign.ChangeSign();
			return *this - differentSign;
		}
	}
	
}
LongNumber LongNumber::operator-(LongNumber other) {
	if (this->GetSign() && !other.GetSign() || !this->GetSign() && other.GetSign()) 
	{
		LongNumber differentSign;
		differentSign = other;
		differentSign.ChangeSign();
		return *this + differentSign;
	}
	else {
		LongNumber *maxSize, *minSize;
		LongNumber temp;
		maxSize = &temp;
		minSize = &temp;
		if (this->GetLenght() != other.GetLenght()) {
			minSize = this->GetLenght() > other.GetLenght() ? &other : this;
			maxSize = this->GetLenght() > other.GetLenght() ? this : &other;
		}
		else
		{
			for (int i = 0; i < this->GetDigits().size(); i--) {
				if (this->GetDigits()[i] == other.GetDigits()[i]) {
					continue;
				}
					if (this->GetDigits()[i] > other.GetDigits()[i]) {
						minSize = &other;
						maxSize = this;
						break;
					}
					else
					{
						minSize = this;
						maxSize = &other;
						break;
			    	}
				
			}
		}
		vector<int> Digits1 = maxSize->GetDigits();
		vector<int> Digits2 = minSize->GetDigits();
		int digit1, digit2, res;
		string NewNumber;
		for (int i = 0; i < minSize->GetLenght(); i++) {
			digit1 = Digits1[Digits1.size() - 1 - i];
			digit2 = Digits2[Digits2.size() - 1 - i];
			if (digit1 == digit2)
			{
				NewNumber = "0" + NewNumber;
			}
			if (digit1 > digit2) {
				res = digit1 - digit2;
				NewNumber = to_string(res) + NewNumber;
			}
			if (digit1 < digit2) {
				res = digit1 + 10 - digit2;
			 
				if (Digits1[Digits1.size() - i - 2] == 0) {
					int iter = 0;
					while (Digits1[Digits1.size() - i - 2 - iter] == 0) {
						Digits1[Digits1.size() - i - 2 - iter] = 9;
						iter++;
					}
					Digits1[Digits1.size() - i - 2 - iter] = Digits1[Digits1.size() - i - 2 - iter] - 1;
				}
				else {
					Digits1[Digits1.size() - i - 2] = Digits1[Digits1.size() - i - 2] - 1;
				}
				NewNumber = to_string(res) + NewNumber;
			}

		}
		for (int i = Digits1.size() - Digits2.size() - 1; i >= 0; i--) {
			NewNumber = to_string(Digits1[i]) + NewNumber;
		}
				
		if ((maxSize == this && !this->GetSign())|| (maxSize == &other && other.GetSign())) {
			return LongNumber(NewNumber);
		}
		else {
			return LongNumber("-" + NewNumber);
		}
		
	}

}
LongNumber LongNumber::operator*(LongNumber other) {

	if (this->GetLenght() <= 6 && other.GetLenght() <= 6) {
		int Number1=0, Number2=0;
		int discrage = 1;
		for (int i = this->GetLenght()-1; i >=0 ; i--) {
			Number1 += discrage * this->GetDigits()[i];
			discrage *= 10;
		}
		discrage = 1;
		for (int i = other.GetLenght()-1; i >=0; i--) {
			Number2 += discrage * other.GetDigits()[i];
			discrage *= 10;

		}
		int Multi = Number1 * Number2;
		return LongNumber(to_string(Multi));
	}
}
void LongNumber::SetDigits(vector<int> &NewDigits) {
	digits.clear();
	for (int i = 0; i < NewDigits.size(); i++) {
		digits.push_back(NewDigits[i]);
	}
}