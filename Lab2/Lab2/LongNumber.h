#pragma once
#include <vector>
#include <string>


class LongNumber {
private:
	std::vector<int> digits;
	void ConvertFromStringToVector(std::string &Number);
	bool sign;
	
public:
	void ChangeSign();
	LongNumber();
	void SetDigits(std::vector<int> &NewDigits);
	LongNumber(std::string Number);
	bool GetSign();
	int GetLenght();
	std::vector<int> GetDigits();
	LongNumber operator +(LongNumber other);
	LongNumber operator -(LongNumber other);
	LongNumber& operator =(LongNumber other);
	LongNumber operator*(LongNumber other);
	
};