#include <iostream>

using namespace std;

class  Sweet abstract {
public:
	int price;
	virtual ~Sweet() {};
};


class IceCream : public Sweet {
public:
	IceCream() {
		price = 92;
	}
	~IceCream() {
		cout << "I ate a IceCream. " << price << " spend.\n";
	};
};

class LimonCake : public Sweet {
public:
	LimonCake() {
		price = 130;
	}
	~LimonCake() {
		cout << "I ate a LimonCake. " << price << " spend.\n";
	};
};

class Ñonfectioner {
public:
	Sweet* createLimonCake() {
		return new LimonCake();
	}

	Sweet* createIceCream() {
		return new IceCream();

	}
};

class YoungMan {
public:
	void Eat(Sweet* &sweet) {
		delete sweet;
		sweet = nullptr;
	}
};

void main() {
	cout << "start\n";
	Ñonfectioner conditer;

	Sweet* sweets[]{ conditer.createIceCream(), conditer.createIceCream(),
	conditer.createLimonCake() };
	cout << sweets[0]->price << endl;
	
	YoungMan Vasya;
	Vasya.Eat(sweets[0]);
	Vasya.Eat(sweets[2]);
	
	for (int k = 0; k < 3; k++){
		if (sweets[k])
			cout << sweets[k]->price << endl;
		else
			cout << "Etead" << endl;
	}
	cout << "finish\n";
}
