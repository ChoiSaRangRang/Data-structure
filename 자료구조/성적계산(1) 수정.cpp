#include <iostream>
using namespace std;

int main() {
	int* ptr;
	int num;

	cout << "�л� ���� ";
	cin >> num;

	ptr = new int[num];
	double sum = 0;

	cout << "�л����� ������ �Է��ϼ���. ";

	for (int i = 0; i < num; i++) {
		cin >> ptr[i];
		sum += ptr[i];
	}

	double average = sum / num;

	cout << "SUM = " << sum << endl;
	cout << "AVERAGE = " << average << endl;
}