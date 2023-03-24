#include <iostream>
using namespace std;




class Car {
	string name;
	int price = 12;
	static int car_count;
public:

	static int getCount() {
		return car_count;
	}

	Car(string name, int price)
		:name{ name }, price{ price }{
		price = 15;
		car_count++;
	}

	Car(string name) : Car(name, 20) {

	}

	int getPrice() const {	
		cout << "Const" << endl;
		return price;
	}

	int getPrice() {
		cout << "Ne CONST" << endl;
		return price;
	}

	void setPrice(int price) {
		this->price = price;
	}

	void setPrice2(int val) {
		price = val;
	}

	friend ostream& operator<<(ostream& out, Car& car);
};

int Car::car_count = 0;

ostream& operator<<(ostream& out, Car& car) {
	out << car.name << " " << car.price << "\n";
	return out;
}

void show(const int &x) {	
	//x++;
	cout << x << endl;
}

int& fun2() {
	int x = 333;
	return x;
}

void test_first_lesson() {
	const int y77 = 21;
	show(y77);
	cout << y77 << endl;

	const int x77 = fun2();
	cout << x77 << endl;


	Car* cars = new Car[]{ {"a1", 10}, {"b2", 12} };
	cout << cars[0];
	cout << cars[1];
	delete[] cars;

	Car* BMW = new Car("BMW", 13);
	delete BMW;

	Car stat_cars[]{ {"a1", 10}, {"b2", 12} };

	Car car1 = Car("a3", 5.5); // вар.1
	Car car2("a3", 5.5);       // вар.2
	Car car3{ "a3", 5 };     // вар.2


	int x = 7.5;   // вар.1
	int y{ 7 };  // вар.2 

	cout << x << " " << y << endl;
	cout << "car count: " << Car::getCount();


	const Car const_car{ "vaz", 15 };
	const_car.getPrice();
	car3.getPrice();
}


void dich() {
	class C1 {
	public:
		int x = 1;
	};
	C1 c1;
	c1.x = 5;

	struct {
		int x;
		int y;
	} data, data1, data2;

	class {
	public:
		//????????
		int x;
		int y;
	} obj1;

	obj1.x = 12;
	cout << obj1.x << endl;
}

class C1 {
	static bool is_del;
public:	
	int* data;
	C1() {}
	C1(C1& c) {
		data[0] = c.data[0];
		data[1] = c.data[1];
		data[2] = c.data[2];
	}
	~C1() {
		if (is_del) {
			delete[] data;
			is_del = false;
		}
	}
};

bool C1::is_del = true;

void main() {
	C1 c_1;
	c_1.data = new int[] {1, 2, 3};
	C1 c_2 = c_1;
	
	c_2.data[0] = 777;
	cout << c_1.data[0] << endl; // 777


	int* pD = new int[] {1, 2, 3};
	int* pD2 = pD;
	pD2[0] = 888;

	cout << pD[0] << endl;
	
}