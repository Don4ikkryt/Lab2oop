#pragma once
#include <complex>
#include <vector>
#include "LongNumber.h"
 
typedef std::complex<double> base;

class Shenhage {
private:
	void Normalize(std::vector<int>& Coefficients);
	void fft(std::vector<base> & a, bool invert);
	void multiply(const std::vector<int> & a, const std::vector<int> & b, std::vector<int> & res);
public:
	LongNumber Multiplication(LongNumber number1, LongNumber number2);
};