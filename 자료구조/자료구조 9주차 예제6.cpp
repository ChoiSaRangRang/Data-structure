#include <iostream>
using namespace std;

//#define element char
typedef char element;
const int MAX_STACK_SIZE = 100;

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

	element push(int value) {
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

bool check_matching(char exp[]) { //��ȣ �˻� �Լ�
	Stack s;

	for (int i = 0; i < strlen(exp); i++) {
		if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[') {
			s.push(exp[i]);
		}
		else if (exp[i] == '}') {
			//���� ���ڿ� pop�� ����� ���Ѵ�.
			element ch = s.pop();
			if (ch != '{') { //¦�� ����ġ�� ��
				return false;
			}
			else {
				continue; //¦�� ���� ��
			}
		}
		else if (exp[i] == ']') {
			//���� ���ڿ� pop�� ����� ���Ѵ�.
			element ch = s.pop();
			if (ch != '[') { //¦�� ����ġ�� ��
				return false;
			}
			else {
				continue; //¦�� ���� ��
			}
		}
		else if (exp[i] == ')') {
			//���� ���ڿ� pop�� ����� ���Ѵ�.
			element ch = s.pop();
			if (ch != '(') { //¦�� ����ġ�� ��
				return false;
			}
			else {
				continue; //¦�� ���� ��
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
	cout << "�־��� ���� ���� = " << exp << endl;
	cout << "��ȯ�� ���� = ";

	for (int i = 0; i < strlen(exp); i++) {
		if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') { //�����ڶ��
			s.push(exp[i]);
		}
		else if (exp[i] >= 'a' && exp[i] <= 'z' || exp[i] >= 'A' && exp[i] <= 'Z') { //�ǿ����ڶ��
			cout << exp[i];
		}
		else if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[') { //���� ��ȣ��
			continue;
		}
		else if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']') { //�ݴ� ��ȣ�� pop
			cout << s.pop();
		}
		else { //�ǿ����ڸ�
			cout << exp[i];
		}
	}
	cout << endl;
}

void main() {
	char expression[] = "((a+b)*(c/d))";
	convert_postfix(expression);
}