#include <iostream>
#include "multi_inheritance.h"
#include "my_vect.h"

using namespace std;

class MyArray {
	int size;
	int* data;

	void generate() {
		for (int k = 0; k < size; k++) {
			data[k] = size - k;
		}
	}

	friend void show(MyArray arr);

public:
	MyArray(int size = 10) : size{size} {
		data = new int[size];
		generate();
	}

	~MyArray() {
		delete[] data;
	};

	
};

void show(MyArray arr) {
	for (int k = 0; k < arr.size; ++k)
		cout << arr.data[k] << ", ";
	cout << endl;
}


void main() {
	//test_multi();
	//test_myvect();
	MyArray arr(20);
	show(arr);
	int x = 3;
	show(MyArray(x));


}
