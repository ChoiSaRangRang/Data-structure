#include <iostream>
using namespace std;

const int StudentNumber = 10;
const int SubjectNumber = 3;

int main() {
	//ST_Num ���� ���� ����� ������
	//10���� �л��� ����, ����, ���� ���� ����
	float scores[SubjectNumber][StudentNumber] = { { 55,63,75,95,68,71,99,45,73,100 },
	{ 32,77,65,45,69,72,81,74,80,100 }, { 100,37,30,49,55,69,76,88,91,98 } };

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

	//���κ� ����� ������
	for (int i = 0; i < StudentNumber; i++) {
		double per_sum = 0;
		for (int j = 0; j < SubjectNumber; j++) {
			per_sum += scores[j][i];
		}
		double per_average = per_sum / SubjectNumber;
		cout << i << "��° �л��� ���� ����� " << per_average << endl;
	}
}