#include <iostream>
using namespace std;

void main() {
	char A[] = "This is a world";
	cout << A << endl;
	cout << A + 1 << endl;
	cout << A[2] << endl;
	cout << sizeof(A) << endl;
	*(A + 10) = NULL;
	cout << A << endl;
}