#include <iostream>
using namespace std;

void main() {
	int* ptr;
	int num;

	cout << "�л� ���� ";
	cin >> num;

	ptr = new int[num];
	int sum = 0;
	for (int i = 0; i < num; i++) {
		cin >> ptr[i];
		//*(ptr+i)
		sum += ptr[i];
	}
	cout << "AVERAGE = " << (double) sum / num << endl;
}