#include <iostream>
using namespace std;

const int StudentNumber = 20;
// �л� ���� �ٲ� �� ���� ����. �ʱ�ȭ�� ���� �ؾ������� �� �� ���� ������ �ش� ���� ����ϸ�
//�ڵ����� �ٲ�

int main() {
	//10���� ���� ����� ������
	int scores[10] = { 100,92,78,90,100,90,80,100,92,79 };

	//������ ���� �Է¹���
	for (int st = 0; st < StudentNumber; st++) {
		cout << st << "��° �л� ������ �Է��ϼ���.";
		cin >> scores[st];
	}

	double sum = 0;

	for (int i = 0; i < 10; i++) {
			sum = sum + scores[i];
		}

	double average = /*(double)*/ sum / 10;

	cout << "SUM = " << sum << endl;
	cout << "AVERAGE = " << average << endl;
}