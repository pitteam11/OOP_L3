#include <iostream>
#include <Windows.h>

using namespace std;

class Worker {
private:
	int cash = 0;

public:
	Worker(int cash) : cash{ cash } {};

	int getCash() {
		return cash;
	}

	void setCash(int cash) {
		this->cash = cash;
	}
};



class Programer : public Worker {
	const int sallary = 110;


public:
	static int countProgrammer;
	//Programer() : Worker(120) { countProgrammer++; }
	Programer(int cash, int r) : Worker(cash) { countProgrammer++; }

	int getCount() {
		return countProgrammer;
	}

	void work() {
		cout << "Programer do work\n";
		setCash(getCash() +  sallary);
	}

	static int convertMoney(int money) {
		///cout << this->sallary; - это не работает
		return money * 63.50;
	}
};

int Programer::countProgrammer = 0;

class Designer : public Worker {
	const int sallary = 90;
public:
	Designer() : Worker(1000) {}
	Designer(int cash) : Worker(cash) {}
	void work() {
		cout << "Designer do work\n";
		setCash(getCash() + sallary);
	}
};

void main() {
	Programer prog1(100, 1);
	Designer desgn1(-100);
	
	prog1.work();
	prog1.work();

	cout << prog1.getCash() << endl;
	desgn1.work();
	cout << desgn1.getCash() << endl;

	Programer prog2(120, 1);
	prog2.countProgrammer++;

	cout << prog1.countProgrammer << endl;
	cout << Programer::countProgrammer << endl;
	cout << Programer::convertMoney(500) << endl;


	Programer progs[5]{ {102,1}, {102,1}, {102,1} , {152,1}, {102,1} };
	Programer* prog = new Programer[2]{ {1,1}, {2,2} };


	cout << "Before works" << endl;
	for (int k = 0; k < 5; k++) {
		cout << k << " : " << progs[k].getCash() << endl;
	}
	srand(time(0));
	for (int k = 0; k < 10; k++) {
		progs[rand()%5].work();
	}
	cout << "Afrer works" << endl;
	for (int k = 0; k < 5; k++) {
		cout << k << " : " << progs[k].getCash() << endl;
	}

	cout << Programer::countProgrammer << endl;
	delete[] prog;
	Worker workers[2]{ 0, 0 };
	workers[0] = prog1;
	workers[1] = desgn1;

	for (int k = 0; k < 2; k++) {
		cout << workers[k].getCash() << endl;
	}
}
