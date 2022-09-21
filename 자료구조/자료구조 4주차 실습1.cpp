#include <iostream>
using namespace std;

void main() {
	int score[3][4] = { {1,2,3,4},{10,20,30,40},{100,110,120,130} };

	cout << score << " : " << &score << " : " << &score[0][0] << endl;
	cout << "-------------------------------" << endl;
	cout << score << score + 1 << " : " << score + 2 << " : " << endl;
	//score + 3
	//score+3은 범위를 넘어감 위험!!
	cout << "-------------------------------" << endl;
	// *(score+i)==score[i]
	cout << *score << " : " << *(score + 1) << " : " << *(score + 2) << endl;
	cout << "-------------------------------" << endl;
	cout << score[0] << " : " << score[1] << " : " << score[2] << endl;
}