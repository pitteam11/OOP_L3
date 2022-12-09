#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Point {
	double x, y, z;

public:
	Point(double x, double y, double z) :
		x{ x }, y{ y }, z{ z }{}
	Point() : Point(0, 0, 0) {}
	
	string toString() {
		string str = to_string(x) +
			" " + to_string(y) + 
			" " + to_string(z);
		return str;
	}

	bool write(string filename) {
		ofstream fout(filename, ios_base::app);
		if (fout.is_open()) {
			fout << this->toString() << endl;
			fout.close();
			return true;
		}
		return false;
	}
	
	/*
	bool read(string filename) {
		ifstream fin(filename);
		if (fin.is_open()) {			
			fin >> x;
			fin >> y;
			fin >> z;
			fin.close();
			return true;
		}
		return false;
	}
	*/

	bool write(ofstream &fout) {
		if (fout.is_open()) {
			fout << this->toString() << endl;
			return true;
		}
		return false;
	}

	bool read(ifstream &fin) {
		if (fin.is_open()) {
			fin >> x;
			fin >> y;
			fin >> z;			
			return true;
		}
		return false;
	}

};
