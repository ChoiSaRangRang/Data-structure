#include <iostream>
using namespace std;

void main() {
	int scores[10] = { 10,20,30,40,50,60,70,80,90,100 };

	cout << scores << endl;
	cout << &scores << endl;
	cout << &scores[0] << endl;
	
	for (int i = 0; i < 10; i++) {
		cout << scores + i << endl;
	}

	for (int j = 0; j < 10; j++) {
		cout << *(scores + j) << endl;
		cout << scores[j] << endl;
	}
}