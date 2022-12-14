#pragma once
#include <Windows.h>

#include <iostream>
#include <fstream>

using namespace std;

class Abonent{
	const char* name;
	const char* phone;
/*
	inline int getSize(char* cstr) {
		return _msize(cstr) / sizeof(char);
	}
*/
public:
	Abonent() {}
	Abonent(const char* name, const char* phone) :
		name{ name },
		phone{ phone } {}
	~Abonent() {		
	}
	const char* getName() {
		return name;
	}
	const char* getPhone() {
		return phone;
	}
/*
	char* toCString() {
		int szName = getSize(name);
		int szPhone = getSize(phone);
		char* res = new char[(int)szName + szPhone];		
		for (int k = 0; k < getSize(name); ++k) {
			res[k] = name[k];
		}
		res[szName-1] = ' ';
		for (int k = 0; k < szPhone; ++k) {
			res[k + szName] = phone[k];
		}
		return res;
	}
*/
};

class PhoneBook  {
	Abonent* abonents;
	int size = 0;
public:

	PhoneBook() {};
	PhoneBook(const char* filename) {
		read(filename);
	}

	void add(const char* name, const char* phone) {		
		Abonent abon(name, phone);
		Abonent* buff = new Abonent[size + 1];
		for (int k = 0; k < size; ++k)
			buff[k] = abonents[k];
		buff[size] = abon;
		delete[] abonents;
		abonents = buff;
		size++;
	}

	void add(string name, string phone) {
		Abonent abon(name.data(), phone.data());
		Abonent* buff = new Abonent[size + 1];
		for (int k = 0; k < size; ++k)
			buff[k] = abonents[k];
		buff[size] = abon;
		delete[] abonents;
		abonents = buff;
		size++;
	}

	void write(const char* filename) {
		ofstream fout(filename);
		for (int k = 0; k < size; k++) {
			fout << abonents[k].getName() << " ";
			fout << abonents[k].getPhone() << endl;
		}
		fout.close();
	}

	void read(const char* filename) {
		ifstream fin(filename);
		if (fin.is_open()) {
			while (!fin.eof()) {
				string name, phone;
				fin >> name;
				fin >> phone;				
				//add(name.data(), phone.data());
				cout << name.data() << " " << phone.data() << endl;
			}
			fin.close();
		}
	}

	inline void show() {
		for (int k = 0; k < size; ++k) {
			cout << abonents[k].getName() << " "
				<< abonents[k].getPhone() << endl;
		}
	}

	~PhoneBook() {
		/*
		for (int k = 0; k < size; ++k) {
			delete[] (abonents[k].getName());
			delete[] (abonents[k].getPhone());
		}
		*/
		delete[] abonents;
	}
};

