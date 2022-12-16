#pragma once
#include <iostream>

using namespace std;

struct Point3d {
	int x, y, z;
	Point3d(int x, int y, int z) : x{ x }, y{ y }, z{ z }{};
	Point3d() : Point3d(0, 0, 0) {}
};

class MyVector {
	Point3d start;
	Point3d finish;
public:
	MyVector(Point3d finish, Point3d start = Point3d()) :
		finish{ finish }, start{ start }{};


	void show() const {
		cout << finish.x << ", " << finish.y << ", " << finish.z << endl;
	}

	double getLenght() const {
		Point3d d = toZeroPoint();
		return sqrt(d.x * d.x + d.y * d.y + d.z * d.z);
	}

	double dot(MyVector& v) const {
		Point3d d1 = toZeroPoint();
		Point3d d2 = v.toZeroPoint();
		return d1.x * d2.x + d1.y * d2.y + d2.z * d2.z;
	}

	friend double dot(MyVector& v1, MyVector& v2);
	static double dot(MyVector& v1, MyVector& v2);

private:
	Point3d toZeroPoint() const {
		Point3d res;
		res.x = finish.x - start.x;
		res.y = finish.y - start.y;
		res.z = finish.z - start.z;
		return res;
	}
};

double MyVector::dot(MyVector& v1, MyVector& v2) {
	Point3d d1 = v1.toZeroPoint();
	Point3d d2 = v2.toZeroPoint();
	return d1.x * d2.x + d1.y * d2.y + d2.z * d2.z;
}

double dot(MyVector& v1, MyVector& v2) {
	Point3d d1 = v1.toZeroPoint();
	Point3d d2 = v2.toZeroPoint();
	return d1.x * d2.x + d1.y * d2.y + d2.z * d2.z;
}

void test_myvect() {
	MyVector vect(Point3d(3, 4, 7), Point3d(0, 0, 7));
	cout << "Length: " << vect.getLenght() << endl;
	MyVector vect2(Point3d(1, 0, 0));
	cout << vect.dot(vect2) << endl;
	cout << dot(vect, vect2) << endl;
	cout << MyVector::dot(vect, vect2) << endl;

	const MyVector c_vector(Point3d(0, 0, 100));
	c_vector.show();
	vect2.show();
	cout << c_vector.dot(vect) << endl;
}

