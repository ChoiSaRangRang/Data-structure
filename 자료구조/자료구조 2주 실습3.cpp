#include <iostream>
using namespace std;

const int year = 3; //����
const int period = 4; //�б�

int main() {
	double sales[year][period] = { {6,6.5,6.2,7},{7,65,7.5,8},{9,8.5,9,11} };

	//�⵵�� ���� �Ѿ��� ������
	for (int y = 0; y < year; y++) {

		double sales_total = 0;

		for (int p = 0; p < period; p++) {
			sales_total += sales[y][p];
		}
		cout << y << "��° �⵵ �� ������� " << sales_total << "�鸸��" << endl;
	}

	//�б⺰ ���� ���
	for (int p = 0; p < period; p++) {
		double sum = 0;

		//�б⺰ �հ踦 ������
		for (int y = 0; y < year; y++) {
			sum += sales[y][p];
		}

		//�б⺰ ����� ������
		double average = sum/year;
		cout << p << "��° �б��� ��� ������� " << average << "�鸸��" << endl;
	}
}