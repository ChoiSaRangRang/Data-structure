#include <iostream>
using namespace std;

#define element int

//객체와 연결리스트 이용한 스택

class SNode {
public:
	element data;
	SNode* link;
};

class Stack {
public:
	SNode* SP; //Head

	Stack() { //생성자 함수로 초기화
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
		cout << "##스택 상태 출력##" << endl;
		//스택 성격상 top부터 위에서 아래로 출력
		for (SNode* list = SP; list != NULL; list=list->link) {
			cout << SP->data << endl;
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