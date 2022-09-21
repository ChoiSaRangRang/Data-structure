#include <iostream>
using namespace std;

const int cls = 3; //�� ����
const int subject = 3; //�����
const int st_num = 10; //�ݺ� �л� ��

int main() {
	double scores[cls][subject][st_num] = { {{10,20,30,40,50,60,70,80,90,100},
		{90,50,30,40,50,60,70,80,90,100},{15,70,30,45,50,90,70,80,90,100}},
		{{10,20,30,40,50,60,70,80,90,100},{90,50,30,40,50,60,70,80,90,100},
		{15,70,30,45,50,90,70,80,90,100}}, {{10,20,30,40,50,60,70,80,90,100},
		{90,50,30,40,50,60,70,80,90,100},{15,70,30,45,50,90,70,80,90,100}} };

	//�� �ݺ�, ���� ��� ��
	for (int cl = 0; cl < cls; cl++) {

		for (int sbj = 0; sbj < subject; sbj++) {
			double sum;
			sum = 0;
			for (int st = 0; st < st_num; st++) {
				sum += scores[cl][sbj][st];
			}

			double average = sum / st_num;

			cout << cl << "���� " << sbj << "��° ������ ����� " << average << endl;
		}
	}

	//�ش� �г��� ���� ��� ������
	for (int sbj = 0; sbj < subject; sbj++) {
		double sum = 0;
		for (int cl = 0; cl < cls; cl++) { //��� ��
			for (int st = 0; st < st_num; st++) { //��� �л�
				sum += scores[cl][sbj][st];
			}
		}
		double average = sum / (cls * st_num);
		cout << "�ش� �г��� ��հ��� " << average << endl;
	}
}
