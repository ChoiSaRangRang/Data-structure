#include <iostream>
using namespace std;

const int StudentNumber = 10;
// �л� ���� �ٲ� �� ���� ����. �ʱ�ȭ�� ���� �ؾ������� �� �� ���� ������ �ش� ���� ����ϸ�
//�ڵ����� �ٲ�

int main() {
	//10���� ���� ����� ������
	int scores[StudentNumber] = { 100,92,78,88,100,96,66,100,57,51 };

	double sum = 0;

	for (int i = 0; i < 10; i++) {
		sum = sum + scores[i];
	}

	double average = sum / 10;

	cout << "SUM = " << sum << endl;
	cout << "AVERAGE = " << average << endl;
}