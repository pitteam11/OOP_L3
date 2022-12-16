#pragma once
#include <iostream>

using namespace std;

class Size {
public:
	int width;
	int height;
};

class Point {
public:
	int x;
	int y;
};

class Rectangle : public Size, public Point {
public:
	void show() {
		cout << "Rectangle: " << width << " X " << height << "at ..." << endl;
	}
};

void test_multi() {
	Rectangle rect;
	rect.x = 10;
	rect.y = 12;
	rect.width = 100;
	rect.height = 100;
	rect.show();
}