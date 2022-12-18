#pragma once
#include <Windows.h>

#include <iostream>
#include <fstream>

using namespace std;

class Abonent{
	char* name{ nullptr };
	char* phone{ nullptr };
	
	inline int getSize(const char* cstr) {
		return sizeof(cstr) / sizeof(char);
	}

public:
	Abonent() {
	}

	Abonent(const char* name, const char* phone) {
		int sz1 = strlen(name)+1;
		int sz2 = strlen(phone)+1;
		this->name = new char[sz1];
		this->phone = new char[sz2];
		
		for (int k = 0; k < sz1; ++k)
			this->name[k] = name[k];
		for (int k = 0; k < sz2; ++k)
			this->phone[k] = phone[k];
	}

	Abonent(const Abonent& v) {
		(*this) = v;		
	}

	Abonent& operator = (const Abonent& v){
		int sz1 = strlen(v.name) + 1;
		int sz2 = strlen(v.phone) + 1;
		this->name = new char[sz1];
		this->phone = new char[sz2];		
		for (int k = 0; k < sz1; ++k)
			name[k] = v.name[k];
		for (int k = 0; k < sz2; ++k)
			phone[k] = v.phone[k];
		return *this;
	}

	~Abonent() {		
		delete[] name;
		delete[] phone;		
	}
	const char* getName() {
		return name;
	}
	const char* getPhone() {
		return phone;
	}
};

class PhoneBook  {
	Abonent* abonents{nullptr};
	int size = 0;
public:
	PhoneBook() {};
	PhoneBook(const char* filename) {
		read(filename);
	}

	void add(const char* name, const char* phone) {		
		Abonent abon(name, phone);
		Abonent* buff = new Abonent[size + 1];
		for (int k = 0; k < size; ++k) {
			buff[k] = abonents[k]; // this is bad copy -- we must reload operator =
		}
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
				if(name.size())
					add(name.data(), phone.data());
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
		delete[] abonents;
	}
};

