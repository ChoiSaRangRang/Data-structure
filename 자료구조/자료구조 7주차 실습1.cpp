#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* link;
};

Node* Head = NULL;

void insert_node_at_middle(Node* new_node) { //A
}

void insert_node_at_rear(Node* new_node) { //B
	if (Head == NULL) {
		Head = new_node;
	}
	else {
		Node* list = Head;
		while (list->link != NULL) { //마지막 원소가 아닌 경우
			list = list->link;
		}
		list->link = new_node;
	}

}

void insert_node_at_front(Node* new_node) { //C
	new_node->link = Head;
	Head = new_node;
}

void insert_node(int value) {
	Node* new_node = new Node; //동적 메모리 할당

	new_node->data = value;
	new_node->link = NULL;

	insert_node_at_rear(new_node);
}

void insert_node_two(int value) {
	Node* new_node = new Node; //동적 메모리 할당

	new_node->data = value;
	new_node->link = NULL;

	insert_node_at_front(new_node);
}

void delete_node(int value) {
	Node* list = Head;

	if (Head == NULL) {
		cout << "빈리스트는 지울 수 없음" << endl;
	}
	else if (Head->data == value) {
		Head = Head->link;
	}
	else {
		while (list->link != NULL) { //다음 원소가 있는 동안
			if (list->link->data == value) {
				list->link = list->link->link;
				return;
			}
			else {
				list = list->link;
			}
		}
	}
}

void print_list() {
	cout << "연결리스트 내용 출력" << endl;
	for (Node* list = Head; list != NULL; list = list->link) {
		cout << list->data;
		if (list->link != NULL) {
			cout << "->";
		}
	}
	cout << endl;
}

void reverse_list() {
	Node* p, * q, * r;

	p = Head;
	q = NULL; //r=NULL;
	while (p != NULL) {
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}
	Head = q; //역순이니까 Head 바꾸는 거 중요!!!
}

void main() {
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
	delete_node(30);
	print_list();

	insert_node_two(100);
	insert_node_two(200);
	insert_node_two(300);
	insert_node_two(400);
	insert_node_two(500);
	insert_node_two(600);
	insert_node_two(700);
	insert_node_two(800);
	print_list();

	delete_node(700);
	print_list();
	delete_node(400);
	print_list();
	delete_node(100);
	print_list();

	//역순 구성
	cout<<"역순 구성"<<endl;
	reverse_list();
	print_list();
}