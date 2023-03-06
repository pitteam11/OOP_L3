#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

char inverse_case(char ch) {
	if (ch >= 'a')
		return toupper(ch);
	else
		return tolower(ch);
}


void main() {
	string str = "Hello";
	cout << str << endl;
/*
	for (int k = 0; k < str.length(); k++) {
		str[k] = toupper(str[k]);
	}
*/
	transform(str.begin(), str.end(), str.begin(), toupper);
	cout << str << endl;

	str = "HelloaA";
	transform(str.begin(), str.end(), str.begin(), inverse_case);
	cout << str << endl;

	string str2 = "       ";
	transform(str.begin(), str.end(), str2.begin(), tolower);
	cout << str2 << endl;

	str = "HelloaA";
	transform(str.begin(), str.end(), str.begin(),
		[](char ch) {return (ch == 'l') ? 'L' : ch; });
	cout << str << endl;

	vector<int> arr({ 7,2,3,4,5 });
	transform(&(arr[0]), &(arr[arr.size() - 1]), arr.begin(),
		[](int v) {cout << v << " "; return v; });
	cout << endl;

	sort(arr.begin(), arr.end());
	transform(arr.begin(), arr.end(), arr.begin(),
		[](int v) {cout << v << " "; return v; });
	cout << endl;


	transform(arr.begin(), arr.end(), arr.begin(),
		[](int v) { return pow(v, 4); });

	transform(arr.begin(), arr.end(), arr.begin(),
		[](int v) {cout << v << " "; return v; });

	cout << endl;
	for_each(arr.begin(), arr.end(), [](int v) {cout << v << " "; });
}