#include "Shenhage.h"
#define PI 3.14159265358979323846  
#include <cmath>
#include <algorithm>   

using namespace std;


void Shenhage::Normalize(std::vector<int>& Coefficients)
{
	int carry = 0;
	for (size_t i = 0; i < Coefficients.size(); ++i) {
		Coefficients[i] += carry;
		carry = Coefficients[i] / 10;
		Coefficients[i] %= 10;
	}
}
void Shenhage::fft(std::vector<base> & a, bool invert) {
	int n = (int)a.size();
	if (n == 1)  return;

	vector<base> a0(n / 2), a1(n / 2);
	for (int i = 0, j = 0; i < n; i += 2, ++j) {
		a0[j] = a[i];
		a1[j] = a[i + 1];
	}
	fft(a0, invert);
	fft(a1, invert);

	double ang = 2 * PI / n * (invert ? -1 : 1);
	base w(1), wn(cos(ang), sin(ang));
	for (int i = 0; i < n / 2; ++i) {
		a[i] = a0[i] + w * a1[i];
		a[i + n / 2] = a0[i] - w * a1[i];
		if (invert)
			a[i] /= 2, a[i + n / 2] /= 2;
		w *= wn;
	}
}
void Shenhage::multiply(const std::vector<int> & a, const std::vector<int> & b, std::vector<int> & res) {
	vector<base> fa(a.begin(), a.end()), fb(b.begin(), b.end());
	size_t n = 1;
	while (n < max(a.size(), b.size()))  n <<= 1;
	n <<= 1;
	fa.resize(n), fb.resize(n);

	fft(fa, false), fft(fb, false);
	for (size_t i = 0; i < n; ++i)
		fa[i] *= fb[i];
	fft(fa, true);

	res.resize(n);
	for (size_t i = 0; i < n; ++i)
		res[i] = int(fa[i].real() + 0.5);
}
LongNumber Shenhage::Multiplication(LongNumber number1, LongNumber number2) {
	bool sign1 = number1.GetSign();
	bool sign2 = number2.GetSign();
	vector<int> firstNum = number1.GetDigits();
	vector<int> secondNum = number2.GetDigits();
	vector<int> result;
	multiply(firstNum, secondNum, result);
	Normalize(result);
	LongNumber returning;
	returning.SetDigits(result);
	if ((sign1 && !sign2) || (!sign1 && sign2)) {
		returning.ChangeSign();
	}
	return returning;
}