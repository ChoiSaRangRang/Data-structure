#include <iostream>
using namespace std;

const int StudentNumber = 10;
const int SubjectNumber = 3;

int main() {
	//ST_Num ���� ���� ����� ������
	float scores[3][StudentNumber] = { { 10,20,30,40,50,60,70,80,90,100 },
	{ 15,25,35,40,50,68,78,80,95,100 }, { 10,20,30,49,55,60,88,93,95,100 } };

	//�� ���� ���� �հ踦 ���ϰ� ����� ������
	for (int subj = 0; subj < SubjectNumber; subj++) {
		//���� �հ踦 ������
		double sum = 0;
		for (int student = 0; student < StudentNumber; student++) {
			sum += scores[subj][student];
		}
		cout << subj << "��° ������ �հ�� " << sum << endl;

		//���� ����� ������
		double average = sum / StudentNumber;
		cout << subj << "��° ������ ����� " << average << endl;
	}
}