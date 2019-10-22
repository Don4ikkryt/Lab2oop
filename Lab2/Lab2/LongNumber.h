#pragma once
#include <vector>
#include <string>

class LongNumber {
private:
	std::vector<int> digits;
	void ConvertFromStringToVector(std::string &Number);
	bool sign;
public:
	LongNumber();
	LongNumber(std::string Number);
	bool GetSign();
};