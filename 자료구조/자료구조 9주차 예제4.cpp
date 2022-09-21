#include <iostream>
using namespace std;

#define element int

//��ü�� ���Ḯ��Ʈ �̿��� ����

class SNode {
public:
	element data;
	SNode* link;
};

class Stack {
public:
	SNode* SP; //Head

	Stack() { //������ �Լ��� �ʱ�ȭ
		SP = NULL;
	}

	bool is_empty_stack() {
		return(SP == NULL);
	}

	void push(int value) {
		SNode* new_node = new SNode;
		new_node->data = value;
		//new_node->link = NULL;

		new_node->link = SP;
		SP = new_node;

	}

	int pop() {
		if (is_empty_stack()) {
			cout << "ERROR : Stack Underflow" << endl;
			exit(1);
		}
		else {
			element x = SP->data;
			SP = SP->link;
			return x;
		}
	}

	int peek() {
		if (is_empty_stack()) {
			cout << "ERROR : Stack Empty" << endl;
		}
		else {
			return SP->data;
		}
	}

	void print_stack() {
		cout << "##���� ���� ���##" << endl;
		//���� ���ݻ� top���� ������ �Ʒ��� ���
		for (SNode* list = SP; list != NULL; list=list->link) {
			cout << SP->data << endl;
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