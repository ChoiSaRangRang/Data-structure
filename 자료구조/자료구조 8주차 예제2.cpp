#include <iostream>
using namespace std;

/*
������ ��� int�� ������->������ �ȿ� �پ��� ���� �� �� ����
���� ���
#define element int : element�� int�� ����.
int pop() -> element pop() ���� ����
���� �Ǽ������� �ٲٰ� �ʹٸ� element ���� �ٲٸ� �ȴ�.
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
	
	return(top==-1); //�� ���� ��ü�� �����ϸ� ���ٷ� ��������
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
	return(top==MAX_STACK_SIZE-1); //�� ��ü�� �����ϸ� ���ٷ� ��������
}

void push(int value) {
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
		return stack[top--]; //���ٷ� ���� ����(���� stack ���� �����ϰ� top�� ���Ŀ� �ٿ���
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
	cout << "##���� ���� ���##" << endl;
	//���� ���ݻ� top���� ������ �Ʒ��� ���
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