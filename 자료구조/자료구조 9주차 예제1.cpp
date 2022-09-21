#include <iostream>
using namespace std;

#define element int
const int MAX_STACK_SIZE = 100;

//��ü ���(�迭)���� ����
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
};

void main() {
	//��ü�� �̿��ؼ� ȣ��(��ü������ �̿��ؼ� § �ڵ�)

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