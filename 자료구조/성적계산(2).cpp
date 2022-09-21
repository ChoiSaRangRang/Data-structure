#include <iostream>
using namespace std;

const int StudentNumber = 10;
const int SubjectNumber = 3;

int main() {
	//ST_Num 명의 성적 평균을 구하자
	//10명의 학생의 국어, 영어, 수학 성적 점수
	float scores[SubjectNumber][StudentNumber] = { { 55,63,75,95,68,71,99,45,73,100 },
	{ 32,77,65,45,69,72,81,74,80,100 }, { 100,37,30,49,55,69,76,88,91,98 } };

	//각 과목에 대해 합계를 구하고 평균을 구하자
	for (int subj = 0; subj < SubjectNumber; subj++) {
		//과목별 합계를 구하자
		double sum = 0;
		for (int student = 0; student < StudentNumber; student++) {
			sum += scores[subj][student];
		}
		cout << subj << "번째 과목의 합계는 " << sum << endl;

		//과목별 평균을 구라자
		double average = sum / StudentNumber;
		cout << subj << "번째 과목의 평균은 " << average << endl;
	}

	//개인별 평균을 구하자
	for (int i = 0; i < StudentNumber; i++) {
		double per_sum = 0;
		for (int j = 0; j < SubjectNumber; j++) {
			per_sum += scores[j][i];
		}
		double per_average = per_sum / SubjectNumber;
		cout << i << "번째 학생의 개인 평균은 " << per_average << endl;
	}
}