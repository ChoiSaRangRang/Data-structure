#include <iostream>
using namespace std;

const int cls = 3; //반 개수
const int subject = 3; //과목수
const int st_num = 10; //반별 학생 수

int main() {
	double scores[cls][subject][st_num] = { {{10,20,30,40,50,60,70,80,90,100},
		{90,50,30,40,50,60,70,80,90,100},{15,70,30,45,50,90,70,80,90,100}},
		{{10,20,30,40,50,60,70,80,90,100},{90,50,30,40,50,60,70,80,90,100},
		{15,70,30,45,50,90,70,80,90,100}}, {{10,20,30,40,50,60,70,80,90,100},
		{90,50,30,40,50,60,70,80,90,100},{15,70,30,45,50,90,70,80,90,100}} };

	//각 반별, 과목별 평균 값
	for (int cl = 0; cl < cls; cl++) {

		for (int sbj = 0; sbj < subject; sbj++) {
			double sum;
			sum = 0;
			for (int st = 0; st < st_num; st++) {
				sum += scores[cl][sbj][st];
			}

			double average = sum / st_num;

			cout << cl << "반의 " << sbj << "번째 과목의 평균은 " << average << endl;
		}
	}

	//해당 학년의 과목 평균 구하자
	for (int sbj = 0; sbj < subject; sbj++) {
		double sum = 0;
		for (int cl = 0; cl < cls; cl++) { //모든 반
			for (int st = 0; st < st_num; st++) { //모든 학생
				sum += scores[cl][sbj][st];
			}
		}
		double average = sum / (cls * st_num);
		cout << "해당 학년의 평균값은 " << average << endl;
	}
}
