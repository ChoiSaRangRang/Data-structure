#include <iostream>
using namespace std;

class Node {
public:
	int coef;
	int exponent;
	Node* link;
};

//전역변수로 헤드 포인트 선언
Node* A = NULL;
Node* B = NULL;
Node* C = NULL;


void insert_node(Node *ptr, int value1, int value2) {
	Node* new_node = new Node; //동적메모리 할당

	new_node->coef = value1;
	new_node->exponent = value2;
	new_node->link = NULL;


}