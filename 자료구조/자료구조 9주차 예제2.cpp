#include <iostream>
#include <stack> //스택 관련 함수/객체 포함

using namespace std;



void main() {
	//시스템 제공 스택 이용
	//스택을 쓰겠는데 그 이름 s이다. 나는 정수형 값을 스택에 쌓아두겠다
	stack<int> s;

	s.push(10);
	s.push(20);
	cout << s.top() << endl; //제일 위에있는 거 출력

	s.pop();
	s.push(30);
	s.push(40);
	s.push(50);
	s.pop();
}