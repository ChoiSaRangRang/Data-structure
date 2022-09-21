#include <iostream>
using namespace std;

typedef double element;
const int MAX_STACK_SIZE = 100;
//����ǥ����� �Է¹޾� ���� ǥ������� ��ȯ

/*
��������
#include <stack> - �׷��� �� ���� �츮�� ��� �Ͱ� ���� ����

main �ȿ� stack<double> s;
*/

class Stack {
public:
	element stack[MAX_STACK_SIZE];
	int top; //��ü�� �� ���� �ʱ�ȭ�� �� ����. ������ �Լ� ���

	Stack() { //������ �Լ��� �ʱ�ȭ
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

		return(top == -1); //�� ���� ��ü�� �����ϸ� ���ٷ� ��������
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
		return(top == MAX_STACK_SIZE - 1); //�� ��ü�� �����ϸ� ���ٷ� ��������
	}

	element push(element value) {
		if (is_stack_full()) {
			cout << "ERROR : Stack Overflow" << endl;
			exit(1); //���α׷� ��ü�� ����
		}
		else {
			/*
			top++;
			stack[top] = value;
			 */
			stack[++top] = value; //���ٷ� ���� ����(top�� ���� ������Ű�� stack�� ����ϱ�
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
			return stack[top--]; //���ٷ� ���� ����(���� stack ���� �����ϰ� top�� ���Ŀ� �ٿ���
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
		cout << "##���� ���� ���##" << endl;
		//���� ���ݻ� top���� ������ �Ʒ��� ���
		for (int i = top; i >= 0; i--) {
			cout << stack[i] << endl;
		}
	}
};

int main() {

	Stack s;
	char exp[100];
	char postfix[100]; //��ȯ�� ���� ǥ���

	cout << "Enter infix expression : ";
	cin.getline(exp, 100);
	int j = 0;

	for (int i = 0; i < strlen(exp); i++) {
		if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') { //�����ڶ�� push
			s.push(exp[i]);
		}
		else if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[') { //���� ��ȣ�� ����
			continue;
		}
		else if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']') { //�ݴ� ��ȣ�� pop
			//cout << s.pop();
			postfix[j++] = s.pop();
		}
		else { //�ǿ����ڸ�
			//cout << exp[i];
			postfix[j++] = exp[i];
		}
		postfix[j] = NULL; //�߿�!!!!
	}
	cout << postfix << endl;

	//����ǥ����� ��� : postfix�� �о� ������ ���
	for (int i = 0; i < strlen(postfix); i++) { //���� ǥ�� ���� �� ���ڿ� ����

		//�����ڸ� �ΰ��� pop�Ͽ� �ش� ������ �����Ͽ� ��� �� �ٽ� push
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
		//�ǿ����ڸ� push
		else { //���� ASCII ���� �ƴ϶� ���ڰ� �����ؾ� �Ѵ�.
			s.push(postfix[i] - '0'); //�� ������� �ϸ� ���� ���� ����
		}
	}

	cout << exp << "=" << s.pop() << endl;
}
