#include <iostream>
#include <string>

using namespace std;

class Container {
public:
	int size;
	int* arr;
	string* strs;

	void generate() {
		char buff[4];
		for (int k = 0; k < size / 2; k++) {
			arr[k] = 100 + k;			
			strs[k] = "Hello";
		}
	}

public:
	Container(int size) : size{ size } {
		arr = new int[size / 2];
		strs = new string[size / 2];
		generate();
	}

	virtual ~Container() {
		if (arr) delete[] arr;
		if (strs) delete[] strs;
	}
};



void main() {
	cout << "start\n";

	Container* elements = new Container(10);
	cout << elements->strs[2] << endl;
	
	/*Iterator it = elements.first();

	while (it != elements.end()) {
		cout << it;
		it = it.next();
	}
	*/
	cout << "finish\n";
}