#include <iostream>
using namespace std;

//#define element char
typedef char element;
const int MAX_STACK_SIZE = 100;

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

	element push(int value) {
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

	element pop() {
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

	element peek() {
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

bool check_matching(char exp[]) { //괄호 검사 함수
	Stack s;

	for (int i = 0; i < strlen(exp); i++) {
		if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[') {
			s.push(exp[i]);
		}
		else if (exp[i] == '}') {
			//현재 글자와 pop한 결과를 비교한다.
			element ch = s.pop();
			if (ch != '{') { //짝이 불일치할 때
				return false;
			}
			else {
				continue; //짝이 맞을 때
			}
		}
		else if (exp[i] == ']') {
			//현재 글자와 pop한 결과를 비교한다.
			element ch = s.pop();
			if (ch != '[') { //짝이 불일치할 때
				return false;
			}
			else {
				continue; //짝이 맞을 때
			}
		}
		else if (exp[i] == ')') {
			//현재 글자와 pop한 결과를 비교한다.
			element ch = s.pop();
			if (ch != '(') { //짝이 불일치할 때
				return false;
			}
			else {
				continue; //짝이 맞을 때
			}
		}
		else continue;
	}
	if (s.is_empty_stack()) {
		return true;
	}
	else {
		false;
	}
}
void convert_postfix(char exp[]) {
	Stack s;
	cout << "주어진 연산 수식 = " << exp << endl;
	cout << "변환된 수식 = ";

	for (int i = 0; i < strlen(exp); i++) {
		if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') { //연산자라면
			s.push(exp[i]);
		}
		else if (exp[i] >= 'a' && exp[i] <= 'z' || exp[i] >= 'A' && exp[i] <= 'Z') { //피연산자라면
			cout << exp[i];
		}
		else if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[') { //여는 괄호면
			continue;
		}
		else if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']') { //닫는 괄호면 pop
			cout << s.pop();
		}
		else { //피연산자면
			cout << exp[i];
		}
	}
	cout << endl;
}

void main() {
	char expression[] = "((a+b)*(c/d))";
	convert_postfix(expression);
}