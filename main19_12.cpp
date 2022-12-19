#include <iostream>

using namespace std;

class Demo {
	int x;

public:
	explicit Demo(int x ,int y = 8) : x{x} {};

	int getX() const {
		return x;
	}
};

void show(Demo val) {
	cout << "show: " << val.getX() << endl;
}

Demo& operator+(const Demo& a, const Demo& b) {
	Demo res(a.getX() + b.getX());
	return res;
}

bool operator<<(int x, string y) {
	return x;
}

void test_explicit() {
	Demo d(12, 13);
	d = (Demo)13;
	cout << d.getX() << endl;
	show(d);
	show((Demo)15);
}

class Man {

	string name;
	string surname;
	int age;

public:
	Man(){}
	Man& setName(string name) {
		this->name = name;
		return *this;
	}

	Man& setAge(int age) {
		this->age = age;
		return *this;
	}

	Man& setSurname(string surname) {
		this->surname = surname;
		return *this;
	}

	void show() {
		cout << name << " " << surname << " " << age << " age\n";
	}
};


void test_chain() {
	Man m;

	m.setAge(14).setName("Pol").setSurname("Makartney");
	m.show();
}

void test_firstOperator() {
	Man m;

	m.setAge(14).setName("Pol").setSurname("Makartney");
	m.show();
}

class Fraction {
	int cisl;
	int znam;
public:
	
	Fraction(int cisl, int znam = 1) : cisl{ cisl }, znam{ znam }{
		if (znam == 0) {
			cout << "Error" << endl;
		}
	}

	int getCisl() const {
		return cisl;
	}

	int getZnam() const {
		return znam;
	}

	Fraction& operator*(const Fraction b) {
		Fraction res(cisl * b.cisl, znam * b.znam);
		return res;
	}


    /* // OPERATOR -  LIKE METHOD
 	Fraction& operator+(const Fraction b) {
		Fraction res(cisl * b.znam + b.cisl * znam , znam * b.znam);
		return res;
	}
	*/
/*
	void show() {
		cout << cisl << "/" << znam;
	}

	ostream& fun() {
		ostream &res(cout);
		res << cisl << "/" << znam;
		return res;
	}
	*/
	friend ostream& operator<<(ostream& stream, Fraction& fr);
	friend istream& operator>>(istream& stream, Fraction& fr);
	//friend Fraction& operator+(const Fraction a, const Fraction b);
};

/* // OPERATOR - FRIEND FUNCTION
Fraction& operator+(const Fraction a, const Fraction b) {
	Fraction res(a.cisl * b.znam + b.cisl * a.znam, a.znam * b.znam);
	return res;
}
*/

 // OPERATOR - GLOBAL FUNCTION
Fraction& operator+(const Fraction a, const Fraction b) {
	Fraction res(a.getCisl() * b.getZnam() + b.getCisl() * a.getZnam(),
		a.getZnam() * b.getZnam());
	return res;
}

Fraction& operator-(const Fraction a, const Fraction b) {
	Fraction res = a + (Fraction(-1) * b);
	return res;
}

ostream& operator<<(ostream& stream, Fraction& fr) {
	stream << fr.cisl << "/" << fr.znam;
	return stream;
}

istream& operator>>(istream& stream, Fraction& fr) {
	string str;
	stream >> fr.cisl >> fr.znam;
	return stream;
}


void main() {
	Fraction fr(5, 7);	
	cout << fr << endl;
	//cin >> fr;
	//cout << fr << endl;
	Fraction a = Fraction(1, 2);
	Fraction b = Fraction(1, 3);
	Fraction c = a + b + a;
	c = a - b;

	cout << c << endl;

	Fraction d(2, 3);
	Fraction e(3, 2);
	Fraction f = d * e;
	cout << f << endl;

}