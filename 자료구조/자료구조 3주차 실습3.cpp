#include <iostream>
using namespace std;

void swap(int *x, int *y) {
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

void main() {
	int i = 20;
	int j = 40;

	swap(&i, &j);

	cout << "I = " << i << endl;
	cout << "J = " << j << endl;
}