#include <iostream>
#include <stdio.h>
#include <io.h>
#include <direct.h>

using namespace std;

void test_rename() {
	cout << "out_rename: " << rename("test.txt", "new_test.txt") << endl;
}

void test_remove() {
	cout << "out_rename: " << remove("new_test.txt") << endl;
}

void test_open(const char* name);

void test_find() {
	_finddata_t* fileinfo = new _finddata_t;
	intptr_t done = _findfirst("my*", fileinfo);
	intptr_t isFind = done;
	while (isFind != -1) {
		cout << fileinfo->name << " " << fileinfo->attrib << " " << _A_SUBDIR;
		if (fileinfo->attrib & _A_SUBDIR) {
			cout << " dir ";
		}
		cout << "\n";
		//test_open(fileinfo->name);
		isFind = _findnext(done, fileinfo);
	}
	delete fileinfo;
}

void test_open(const char* name) {
	FILE* pf;
	fopen_s(&pf, name, "r");
	char str;
	while (!feof(pf)) {		
		fread_s(&str, sizeof(char), 1, 1, pf);
		if(str != '\n')
			cout << str;
	}
	cout << endl;
	fclose(pf);	
}

void test_createdir() {
	cout << "out_mkdir: " << _mkdir("my_dir") << endl;
}

void test_renamedir() {
	cout << "out_rename: " << rename("my_dir", "new_dir") << endl;
}

void test_rmdir() {
	cout << "out_rmdir: " << _rmdir("new_dir") << endl;
}

void main(int argc, char* argv[]) {
	cout << "We start!\n";
	//test_find();
	setlocale(LC_ALL, "rus");
	for (int k = 0; k < argc; ++k)
		cout << argv[k] << endl;
	cout << "We finish!\n";
	system("pause");
}