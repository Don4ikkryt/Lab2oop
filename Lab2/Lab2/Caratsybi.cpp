#include "Caratsybi.h"
using namespace std;
void Caratsybi::VectorExtension(LongNumber *number, int Lenght) {
	vector<int> VectorToExtense = number->GetDigits();
	for (int i = 0; i < VectorToExtense.size() - Lenght; i++) {
		VectorToExtense.insert(VectorToExtense.begin(), 0);
	}
	number->SetDigits(VectorToExtense);
}
LongNumber Caratsybi::DivedeIntoTwoPartsVector(LongNumber number, int from, int to) {
	string NewNumber;
	for (int i = from; i < to; i++) {
		NewNumber += to_string(number.GetDigits()[i]);
	}
	return LongNumber(NewNumber);
}
LongNumber Caratsybi::Multiplication(LongNumber Number1, LongNumber Number2) {
	bool sign1 = Number1.GetSign();
	bool sign2 = Number2.GetSign();
	if (sign1) {
		Number1.ChangeSign();
	}
	if (sign2) {
		Number2.ChangeSign();
	}
	if (Number1.GetLenght() <= 6 && Number2.GetLenght() <= 6) {
		return Number1 * Number2;
	}
	LongNumber *maxSize = Number1.GetLenght() > Number2.GetLenght() ? &Number1 : &Number2;
	LongNumber *minSize = Number1.GetLenght() > Number2.GetLenght() ? &Number2 : &Number1;
	VectorExtension(minSize, maxSize->GetLenght());
	LongNumber DivededPart1 = DivedeIntoTwoPartsVector(*maxSize, 0, maxSize->GetLenght() / 2);
	LongNumber DivededPart3 = DivedeIntoTwoPartsVector(*minSize, 0, maxSize->GetLenght() / 2);
	LongNumber DivededPart2 = DivedeIntoTwoPartsVector(*maxSize, maxSize->GetLenght() / 2 , maxSize->GetLenght());
	LongNumber DivededPart4 = DivedeIntoTwoPartsVector(*minSize, maxSize->GetLenght() / 2 , maxSize->GetLenght());
	LongNumber a = Multiplication(DivededPart1, DivededPart3);
	LongNumber c = Multiplication(DivededPart2, DivededPart4);
	LongNumber sum1 = DivededPart1 + DivededPart2;
	LongNumber sum2 = DivededPart3 + DivededPart4;
	LongNumber b = Multiplication(sum1, sum2) - a - c;
	 AddZero(&a, 2 * DivededPart2.GetLenght());
	 AddZero(&b, DivededPart4.GetLenght());
	 LongNumber returning = a + b + c;
	 if ((sign1 && !sign2) || (!sign1 && sign2)) {
		 returning.ChangeSign();
	 }
	return returning;
}
void Caratsybi::AddZero(LongNumber *number, int amount) {
	vector<int> NewVector = number->GetDigits();
	for (int i = 0; i < amount; i++) {
		NewVector.push_back(0);
	}
	number->SetDigits(NewVector);
}
