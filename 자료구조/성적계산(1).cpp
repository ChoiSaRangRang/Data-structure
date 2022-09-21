#include <iostream>
using namespace std;

const int StudentNumber = 10;
// 학생 수가 바뀔 때 쓰면 좋음. 초기화는 직접 해야하지만 그 외 수정 사항은 해당 변수 사용하면
//자동으로 바뀜

int main() {
	//10명의 성적 평균을 구하자
	int scores[StudentNumber] = { 100,92,78,88,100,96,66,100,57,51 };

	double sum = 0;

	for (int i = 0; i < 10; i++) {
		sum = sum + scores[i];
	}

	double average = sum / 10;

	cout << "SUM = " << sum << endl;
	cout << "AVERAGE = " << average << endl;
}