#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* llink;
	Node* rlink;
};

Node* Head = NULL;

void insert_node(int value) {
	Node* new_node = new Node; //���� �޸� �Ҵ�

	new_node->data = value;
	new_node->llink = NULL;
	new_node->rlink = NULL;

	new_node->llink = Head;
	new_node->rlink = Head->rlink;
	Head->rlink->llink = new_node;
	Head->rlink = new_node;

}


void delete_node(int value) { //value ���� ���� ��带 ���Ḯ��Ʈ���� ����
	Node* list;

	for (Node* list = Head->rlink; list != Head; list = list->rlink) {
		if (list->data == value) { //���� �츮�� ã�� �����Ͷ�� ����, �ƴϸ� ���� ����
			list->llink->rlink = list->rlink;
			list->rlink->llink = list->llink;
			return;
		}
	}
	//������ ���Ƶ� ã�� �����Ͱ� ���ٸ�
	cout << "�ش� ��尡 �����ϴ�." << endl;
}

void print_list() {
	cout << "���߿��Ḯ��Ʈ ���� ���" << endl;
	if (Head == Head->llink) {
		cout << "�󸮽�Ʈ�Դϴ�." << endl;
	}
	//��������Ʈ�� list�� ���� ��ġ�ϸ� �׸��ؾ���. NULL�� �����ϸ� ���ѷ��� ���ƿ�
	for (Node* list = Head->llink; list != Head; list = list->llink) {
		cout << list->data;
		if (list->llink != Head) {
			cout << "->";
		}
	}
	cout << endl;
}

void main() {
	//����� ����
	Head = new Node;
	//�ڱ��ڽ��� ������
	Head->llink = Head;
	Head->rlink = Head;
	//Head->llink = Head->rlink=Head;

	insert_node(10);
	insert_node(20);
	insert_node(30);
	insert_node(40);
	insert_node(50);
	insert_node(60);
	insert_node(70);
	insert_node(80);

	print_list();

	delete_node(60);
	print_list();
	delete_node(10);
	print_list();
	delete_node(45);
	print_list();
	delete_node(30);
	print_list();
	delete_node(20);
	print_list();
	delete_node(50);
	print_list();
	delete_node(80);
	print_list();
	delete_node(70);
	print_list();
	delete_node(40);
	print_list();

}