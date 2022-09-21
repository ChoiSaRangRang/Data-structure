#include <iostream>
using namespace std;

int main() {
	int* ptr;
	int num;

	cout << "학생 수는 ";
	cin >> num;

	ptr = new int[num];
	double sum = 0;

	cout << "학생들의 점수를 입력하세요. ";

	for (int i = 0; i < num; i++) {
		cin >> ptr[i];
		sum += ptr[i];
	}

	double average = sum / num;

	cout << "SUM = " << sum << endl;
	cout << "AVERAGE = " << average << endl;
}