#include <iostream>
using namespace std;

//#define element int
typedef int element;

class SNode {
public:
	element data;
	SNode* link;
};

SNode* Top = NULL;

//��ü ���(���Ḯ��Ʈ)���� ����

bool is_empty_stack() {
	return(Top == NULL);
}

void push(int value) {
	//stack[++Top] = value;
	SNode* new_node = new SNode;
	new_node->data = value;
	//new_node->link = NULL;

	//ù ����, ��ܿ� �߰�
	new_node->link = Top;
	Top = new_node;
}

int pop() {
	if (is_empty_stack()) {
		cout << "ERROR : Stack Underflow" << endl;
		exit(1);
	}
	else {
		element x = Top->data;
		Top = Top->link;
		return x;
	}
}

int peek() {
	if (is_empty_stack()) {
		cout << "ERRPR : Stack Empty" << endl;
	}
	else {
		return Top->data;
	}
}

void print_stack() {
	cout << "##���� ���� ���##" << endl;
	//���� ���ݻ� top���� ������ �Ʒ��� ���
	for (SNode* list = Top; list != NULL; list = list->link) {
		cout << list->data << endl;
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