#include <iostream>
using namespace std;

typedef double element;
const int MAX_STACK_SIZE = 100;
//중위표기식을 입력받아 후위 표기식으로 변환

/*
실전에서
#include <stack> - 그러나 이 스택 우리가 배운 것과 차이 있음

main 안에 stack<double> s;
*/

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

	element push(element value) {
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

int main() {

	Stack s;
	char exp[100];
	char postfix[100]; //변환된 후위 표기식

	cout << "Enter infix expression : ";
	cin.getline(exp, 100);
	int j = 0;

	for (int i = 0; i < strlen(exp); i++) {
		if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') { //연산자라면 push
			s.push(exp[i]);
		}
		else if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[') { //여는 괄호면 무시
			continue;
		}
		else if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']') { //닫는 괄호면 pop
			//cout << s.pop();
			postfix[j++] = s.pop();
		}
		else { //피연산자면
			//cout << exp[i];
			postfix[j++] = exp[i];
		}
		postfix[j] = NULL; //중요!!!!
	}
	cout << postfix << endl;

	//후위표기식을 계산 : postfix를 읽어 수식을 계산
	for (int i = 0; i < strlen(postfix); i++) { //후위 표기 식의 각 글자에 대해

		//연산자면 두개를 pop하여 해당 연산을 적용하여 계산 후 다시 push
		if (postfix[i] == '+') {
			element op2 = s.pop();
			element op1 = s.pop();
			s.push(op1 + op2);
		}
		else if (postfix[i] == '-') {
			element op2 = s.pop();
			element op1 = s.pop();
			s.push(op1 - op2);
		}
		else if (postfix[i] == '/') {
			element op2 = s.pop();
			element op1 = s.pop();
			s.push(op1 / op2);
		}
		else if (postfix[i] == '*') {
			int op2 = s.pop();
			int op1 = s.pop();
			s.push(op1 * op2);
		}
		//피연산자면 push
		else { //문자 ASCII 값이 아니라 숫자값 저장해야 한다.
			s.push(postfix[i] - '0'); //이 방법으로 하면 숫자 저장 가능
		}
	}

	cout << exp << "=" << s.pop() << endl;
}
