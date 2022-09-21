#include <iostream>
using namespace std;

#define element int
const int MAX_STACK_SIZE = 100;

//객체 방식(배열)으로 구현
class Stack {
public:
	element stack[MAX_STACK_SIZE];
	int top; //객체로 할 때는 초기화는 잘 안함. 생성자 함수 사용

	Stack() { //생성자 함수로 초기화
		top = -1;
	}

	bool is_empty_stack() {
		/*
		if (top == -1) {
			return true;
		}
		else {
			return false;
		}
		*/

		return(top == -1); //비교 수식 자체를 리턴하면 한줄로 정리가능
	}

	bool is_stack_full() {
		/*
		if (top == MAX_STACK_SIZE - 1) {
			return true;
		}
		else {
			return false;
		}
		*/
		return(top == MAX_STACK_SIZE - 1); //식 자체를 리턴하면 한줄로 정리가능
	}

	void push(int value) {
		if (is_stack_full()) {
			cout << "ERROR : Stack Overflow" << endl;
			exit(1); //프로그램 자체를 끝냄
		}
		else {
			/*
			top++;
			stack[top] = value;
			 */
			stack[++top] = value; //한줄로 정리 가능(top을 먼저 증가시키고 stack에 사용하기
		}

	}

	int pop() {
		if (is_empty_stack()) {
			cout << "ERROR : Stack Underflow" << endl;
			exit(1);
		}
		else {
			/*
			int x = stack[top];
			top--;
			return x;
			*/
			return stack[top--]; //한줄로 정리 가능(먼저 stack 값을 리턴하고 top을 이후에 줄여라
		}
	}

	int peek() {
		if (is_empty_stack()) {
			cout << "ERRPR : Stack Empty" << endl;
		}
		else {
			return stack[top];
		}
	}

	void print_stack() {
		cout << "##스택 상태 출력##" << endl;
		//스택 성격상 top부터 위에서 아래로 출력
		for (int i = top; i >= 0; i--) {
			cout << stack[i] << endl;
		}
	}
};

void main() {
	//객체를 이용해서 호출(객체지향을 이용해서 짠 코드)

	Stack s;
	
	s.push(10);
	s.push(20);
	s.pop();
	s.push(30);
	s.push(40);
	s.push(50);
	s.pop();
	s.print_stack();
}