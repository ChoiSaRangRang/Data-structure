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
	Node* new_node = new Node; //동적 메모리 할당

	new_node->data = value;
	new_node->llink = NULL;
	new_node->rlink = NULL;

	new_node->llink = Head;
	new_node->rlink = Head->rlink;
	Head->rlink->llink = new_node;
	Head->rlink = new_node;

}


void delete_node(int value) { //value 값을 갖는 노드를 연결리스트에서 삭제
	Node* list;

	for (Node* list = Head->rlink; list != Head; list = list->rlink) {
		if (list->data == value) { //만약 우리가 찾는 데이터라면 삭제, 아니면 루프 돌아
			list->llink->rlink = list->rlink;
			list->rlink->llink = list->llink;
			return;
		}
	}
	//루프를 돌아도 찾는 데이터가 없다면
	cout << "해당 노드가 없습니다." << endl;
}

void print_list() {
	cout << "이중연결리스트 내용 출력" << endl;
	if (Head == Head->llink) {
		cout << "빈리스트입니다." << endl;
	}
	//원형리스트라서 list가 헤드와 일치하면 그만해야함. NULL로 설정하면 무한루프 돌아요
	for (Node* list = Head->llink; list != Head; list = list->llink) {
		cout << list->data;
		if (list->llink != Head) {
			cout << "->";
		}
	}
	cout << endl;
}

void main() {
	//헤드노드 생성
	Head = new Node;
	//자기자신을 가르켜
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