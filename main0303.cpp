#include <iostream>
#include <io.h>
#include <stdio.h>
#include <direct.h>

using namespace std;

class IHandler {
protected:
	IHandler* next;
public:
	virtual void show(string path) = 0;
	void set_next(IHandler* next) {
		this->next = next;
	}
	virtual ~IHandler() {};
protected:
	bool isPath(string path) {
		_finddata_t* fileinfo = new _finddata_t;
		intptr_t done = _findfirst(path.data(), fileinfo);
		if (done != -1 && (fileinfo->attrib & _A_SUBDIR))
			return true;
		else
			return false;
	}	
};

class Handler_Path : public IHandler {
public:
	void show_path(string path) {
		_finddata_t* fileinfo = new _finddata_t;
		intptr_t done = _findfirst((path + "/*.*").data(), fileinfo);
		intptr_t isFind = done;
		while (isFind != -1) {
			cout << fileinfo->name << "\n";
			show(path + "/" + fileinfo->name);
			/*
			if (fileinfo->attrib & _A_SUBDIR) {
				cout << " dir ";
			}
			*/
			cout << "\n";
			//test_open(fileinfo->name);
			isFind = _findnext(done, fileinfo);
		}
		delete fileinfo;
	}


	void show(string path) override {
		if (!isPath(path)) {
			if (next)
				next->show(path);
		}
		else
			if(path[path.length() - 1] != '.')
				show_path(path);
	}
	~Handler_Path() {}
};

class Handler_Txt : public IHandler {
private:
	void test_open(const char* name) {
		FILE* pf;
		fopen_s(&pf, name, "r");
		char str;
		while (!feof(pf)) {
			fread_s(&str, sizeof(char), 1, 1, pf);
			//if (str != '\n')
			cout << str;
		}
		cout << endl;
		fclose(pf);
	}

	void show(string path) override {
		if (path.find(".txt") != -1 
			/* || path.find(".cpp") != -1 
			|| path.find(".h") != -1*/) {
			cout << endl;
			test_open(path.data());
		}
		else
			if(next)
				next->show(path); 
	}
	~Handler_Txt() {}
};

class Handler_Png : public IHandler {
	void show(string path) override {
		if (path.find(".png") != -1)
			cout << "Hello I'm Handler_Png\n";
		else
			if(next)
				next->show(path);
	}
	~Handler_Png() {}
};


void main() {
	cout << "Start \n";
	IHandler* path_shower = new Handler_Path();
	IHandler* txt_shower = new Handler_Txt();
	IHandler* png_shower = new Handler_Png();

	path_shower->set_next(txt_shower);
	txt_shower->set_next(png_shower);
	/*
	path_shower->show("test.txt");
	path_shower->show("");
	path_shower->show("1.png");
	*/

	cout << "-----------------\n";
	((Handler_Path*)path_shower)->show_path("C:/Users/Преподаватель/Documents/goncharov_p/Project5/Project5");

	if (0) {
		_finddata_t* fileinfo = new _finddata_t;
		intptr_t done = _findfirst("*.*", fileinfo);
		intptr_t isFind = done;
		while (isFind != -1) {
			cout << fileinfo->name << " ";
			path_shower->show(fileinfo->name);
			/*
			if (fileinfo->attrib & _A_SUBDIR) {
				cout << " dir ";
			}
			*/
			cout << "\n";
			//test_open(fileinfo->name);
			isFind = _findnext(done, fileinfo);
		}
		delete fileinfo;
	}
	delete path_shower;
	delete txt_shower;
	delete png_shower;
}