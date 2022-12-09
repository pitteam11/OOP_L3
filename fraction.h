#pragma once
#include <iostream>


using namespace std;


class Fraction{
	int Cisl;
	int Znam;

public:
	Fraction(int Cisl, int Znam):
		Cisl{ Cisl }, Znam{Znam}{}
	Fraction() :Fraction(1, 0) {}

	void show() {
		cout << Cisl << "/" << Znam;
	}

	Fraction add(Fraction val) {
		Fraction res = val;
		res.Znam = Znam * val.Znam;
		res.Cisl = Cisl * val.Znam + val.Cisl * Znam;
		return res;
	}

};

