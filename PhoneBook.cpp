#include <iostream>
#include "abonent.h"

using namespace std;


class C1 {
public:
	int val1;
	int* arr;
	C1() {};

	C1(const C1 &val) {
		val1 = val.val1;
		int sz = sizeof(arr) / sizeof(arr[0]);
		arr = new int[sz];
		for (int k = 0; k < sz; ++k) {
			arr[k] = val.arr[k];
		}
	}

	~C1() {
		delete[] arr;
	}
};




void main() {
	C1 x;
	x.val1 = 14;
	x.arr = new int[2]{ 13,17 };

	C1 y(x); //  про конструктор коппирования
	
	cout << y.val1 << " " << y.arr[0] << " " << y.arr[1] << endl;
	cout << x.val1 << " " << x.arr[0] << " " << x.arr[1] << endl;

	x.arr[0] = 2222;
	
	cout << y.val1 << " " << y.arr[0] << " " << y.arr[1] << endl;
	cout << x.val1 << " " << x.arr[0] << " " << x.arr[1] << endl;



	/*PhoneBook pb;
	pb.add("Pol", "12234");
	pb.add("Lans", "43525");
	pb.add("Hetfild", "12312");
	pb.add("Devid", "13312");
	pb.show();
	pb.write("pb.txt");
	*/
	//PhoneBook pb2("pb.txt");
	//pb2.show();
}