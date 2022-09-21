#include <iostream>
using namespace std;

void main() {
	int score[3][4] = { {1,2,3,4},{10,20,30,40},{100,110,120,130} };
	cout << *score[0] << " : " << *score[1] << " : " << *score[2] << endl;

	cout << *(score[0] + 1) << " : " << *(score[1] + 1) << " : " << *(score[2] + 1) << endl;

	cout << score[0] + 2 << " : " << score[1] + 2 << " : " << score[2] + 2 << endl;

	cout << score[0] << " : " << &score[0] << endl;
	cout << score[1] << " : " << &score[1] << endl;
	cout << score[2] << " : " << &score[2] << endl;
}