#include <iostream>
using namespace std;

class Node {
public:
	int coef;
	int exponent;
	Node* link;
};

//���������� ��� ����Ʈ ����
Node* A = NULL;
Node* B = NULL;
Node* C = NULL;


void insert_node(Node *ptr, int value1, int value2) {
	Node* new_node = new Node; //�����޸� �Ҵ�

	new_node->coef = value1;
	new_node->exponent = value2;
	new_node->link = NULL;


}