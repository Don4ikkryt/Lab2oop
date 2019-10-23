#pragma once
#include <string>
#include "LongNumber.h"
#include <vector>

class Caratsybi {
private:
	LongNumber DivedeIntoTwoPartsVector(LongNumber Number, int from, int to);
	void VectorExtension(LongNumber *number, int Lenght);
	void AddZero(LongNumber *number, int amount);
public:
	LongNumber Multiplication(LongNumber FirstNumber, LongNumber SecondNumber);
	
};