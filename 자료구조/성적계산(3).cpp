#include <iostream>
using namespace std;

const int cls = 3; //반 개수
const int subject = 3; //과목수
const int st_num = 10; //반별 학생 수

int main() {
	double scores[cls][subject][st_num] = { {{87,90,76,90,100,45,71,61,53,93},
		{87,80,55,92,73,66,100,51,89,90},{92,64,78,96,85,100,80,71,99,76}},
		{{90,100,27,45,55,63,97,76,67,71},{80,77,100,39,73,93,44,75,69,83},
		{90,63,100,100,51,95,61,91,58, 76}}, {{100,57,63,83,76,92,69,89,51,91},
		{90,100,75,53,80,61,59,63,96,70},{98,86,100,99,69,55,73,57,60,81}} };

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
		cout << "해당 학년의 " << sbj << "번째 과목의 평균값은 " << average << endl;
	}
}
