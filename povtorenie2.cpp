#include <iostream>
using namespace std;

class Car {
	int sz = 0;
	char* data;
	const int field;

	void create(int sz, const char* data) {
		free();
		this->data = new char[sz];
		this->sz = sz;
		for (int k = 0; k < sz; ++k) {
			this->data[k] = data[k];
		}
	}

	void free() {
		if (sz > 0) delete[] data;
		sz = 0;
	}

public:

	

	explicit Car(int sz) :field{0} {
		create(sz, "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
	}

	Car(int sz, const char* data, int bb) : field{ bb } {
		create(sz, data);
	}

	Car(string str) : Car(str.size(), str.data(), 0) {
	}

	Car(const Car& car) : field{45} {
		//field = 45;
		if (&car != this) {
			create(car.sz, car.data);
		}
	}

	Car(Car&& car) : field{ 0 } {
		if (&car != this) {
			free();
			sz = car.sz;
			data = car.data;
			car.sz = 0;
			car.data = nullptr;
		}	
	}

	Car& operator=(Car&& car) {
		if (&car != this) {
			free();
			sz = car.sz;
			data = car.data;
			car.sz = 0;
			car.data = nullptr;
		}
		return *this;
	}

	virtual ~Car() {
		free();
	}

	Car& operator=(const Car& car) {
		if (&car != this) {
			create(car.sz, car.data);
		}
		return *this;
	}

	char& operator[](int id) {
		if (0 <= id < sz)
			return data[id];
	}

	Car& operator++() {
		data[0]++;
		return *this;
	}

	Car& operator++(int) {
		data[sz-1]++;
		return *this;
	}

	Car& operator+(const Car& car) {		
		Car* res = new Car(0, nullptr,22);
		delete res->data;
		res->sz = sz + car.sz;
		res->data = new char[res->sz];
		for (int k = 0; k < sz; ++k) {
			res->data[k] = data[k];
		}
		for (int k = 0; k < car.sz; ++k) {
			res->data[k+sz] = car.data[k];
		}
		return *res;
	}

	friend ostream& operator<<(ostream&, const Car& car);
};

ostream& operator<<(ostream& out, const Car& car) {
	for (int k = 0; k < car.sz; ++k) {
		out << car.data[k];		
	}
	return out;
}

void main() {
	cout << "Start" << endl;
	Car car1(3, "ABC",22);	
	Car car2(2, "TR",22);
	Car car55('a', "sadasd", 34);

	string str = "VTY";
	
	str.length();
	str.data(); 


	cout << car1 + str << endl; // ABCVTY
	cout << car2 + car1 << endl; // TRABC
	
	cout << car1 << endl;
	++car1;
	cout << car1 << endl;
	car1++;
	cout << car1 << endl;

	if (0) {
		Car car2 = car1;

		cout << &car2 << " " << &car1 << endl;
		car1 = car2;

		Car car3(6, "CDFFGB",22);
		cout << car3[0] << endl; // C
		cout << car3[5] << endl; // B

		car1 = car1;

		cout << car1 << endl;
		cout << car2 << endl;
		cout << car3 << endl;

		car3 = car1;

		cout << car1 << endl;
		cout << car2 << endl;
		cout << car3 << endl;
	}
}