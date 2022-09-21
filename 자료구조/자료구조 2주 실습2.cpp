#include <iostream>
using namespace std;

const int StudentNumber = 10;
const int SubjectNumber = 3;

int main() {
	//ST_Num 명의 성적 평균을 구하자
	float scores[3][StudentNumber] = { { 10,20,30,40,50,60,70,80,90,100 },
	{ 15,25,35,40,50,68,78,80,95,100 }, { 10,20,30,49,55,60,88,93,95,100 } };

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
}