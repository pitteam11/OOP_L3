#include <iostream>
#include "point.h"
#include "fraction.h"

using namespace std;

class C1;
void test_C1() {
	/*C1 c1;
	c1.show();
	*/
}

class Animal {
public:
	void say() {
		cout << "AAAAAAAAA" << endl;
	}
};

class Cat : public Animal {
public:
	void say() {		
		cout << "Myau" << endl;
	}
};

class Dog : public Animal {
public:
	Dog() {}
	Dog(int x) {}
	void say() {
		cout << "Gav" << endl;
	}
};

void fun(Dog dog) {
	cout << "Dog : ";
	dog.say();
}

void test_Animal() {
	Cat cat;
	Dog dog;

	cat.say();
	dog.say();
	cat.Animal::say();
	Animal animal = cat;
	animal.say();

	fun(1);
}

void test_point() {
	const int n = 10;
	Point* pt = new Point[n];
	/*for (int k = 0; k < n; k++) {
		pt[k] = Point(k, 2 * k, 3 * k);
	}
	*/
	/*
	ofstream fout("points.txt", ios_base::app);
	for (int k = 0; k < n; k++) {
		cout << pt[k].toString() << endl;
		pt[k].write(fout);
	}
	fout.close();
	*/
	ifstream fin("points.txt");
	while (!fin.eof()) {
		pt[0].read(fin);
		cout << pt[0].toString() << endl;
	}
	fin.close();
	delete[] pt;

}

void main() {
	Fraction val1(1, 2);
	Fraction val2(2, 3);
	Fraction val3;
	val3 = val1.add(val2);
	
	
	val1.show();
	cout << " + ";
	val2.show();
	cout << " = ";
	val3.show(); // 5/6
	cout << endl;

}


class C1 {
	int x;
	int y;
public:
	C1(int x, int y) //: x{ x }, y{ y }
	{
		this->x = x;
		this->y = y;
	}

	C1() : C1(0, 0)
	{
	}

	~C1() {}

	void show() {
		cout << x << " " << y << endl;
	}
};
