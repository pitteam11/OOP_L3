#include <iostream>

using namespace std;

class IMan {
public:
	virtual void show() = 0;
};

class Adult : public IMan {
public:
	void show()  override {
		cout << "adult";
	}
};

class Child : public IMan {
public:
	void show()  override {
		cout << "chaild";
	}
};

class IDecorator : public IMan {
public:
	IMan *man;
	IDecorator(IMan* man) : man{ man } {};
};

class Cap : public IDecorator {
public:
	Cap(IMan* man) : IDecorator(man) {};

	void show() override {
		man->show();
		cout << " has a cap";
	}
};

class Coat : public IDecorator {
public:
	Coat(IMan* man) : IDecorator(man) {};

	void show() override {
		man->show();
		cout << " has a coat";
	}
};

void main() {


	IMan *mans[]{
		 new  Adult(),
		 new Child(),
		 new Coat( new Adult()),
		 new Cap(new Child())};

	for (int k = 0; k < 4; k++) {
		mans[k]->show();
		cout << endl;
	}
	//delete mans;
}

