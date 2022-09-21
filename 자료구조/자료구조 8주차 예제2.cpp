#include <iostream>
using namespace std;

/*
스택을 모두 int로 선언함->하지만 안에 다양한 것이 들어갈 수 있음
정수 대신
#define element int : element는 int와 같다.
int pop() -> element pop() 으로 수정
만약 실수값으로 바꾸고 싶다면 element 선언만 바꾸면 된다.
*/

//#define MAX_STACK_SIZE 100
const int MAX_STACK_SIZE = 100;

int stack[MAX_STACK_SIZE];

int top = -1;

bool is_empty_stack() {
	/*
	if (top == -1) {
		return true;
	}
	else {
		return false;
	}
	*/
	
	return(top==-1); //비교 수식 자체를 리턴하면 한줄로 정리가능
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
	return(top==MAX_STACK_SIZE-1); //식 자체를 리턴하면 한줄로 정리가능
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

void main() {
	push(10);
	push(20);
	pop();
	push(30);
	push(40);
	push(50);
	pop();
	print_stack();
}