#include <iostream>
using namespace std;

class CNode {
public:
	int data;
	CNode* link;
};

CNode* Head = NULL;

void insert_node_at_middle(CNode* new_node) { //A
}

void insert_node_at_rear(CNode* new_node) { //원형 연결리스트 마지막 노드로 삽입
	if (Head == NULL) { //노드가 하나
		new_node->link = new_node;
		Head = new_node;
	}
	else { //헤드포인트 끝 노드 가지고 있음(마지막 노드가 헤드포인트 가지고 있음)
		new_node->link = Head->link;
		Head->link = new_node;
		Head = new_node;
	}

}

void insert_node_at_front(CNode* new_node) { //C
	new_node->link = Head;
	Head = new_node;
}

void insert_node(int value) {
	CNode* new_node = new CNode; //동적 메모리 할당

	new_node->data = value;
	new_node->link = NULL;

	insert_node_at_rear(new_node);
}

void delete_node(int value) {
	if (Head == NULL) {
		cout << "빈리스트입니다." << endl;
		return;
	}
	else if (Head->link == Head && Head->data) { // 노드가 1개 & 하필 그게 우리가 지울거라면
		Head = NULL;
	}
	else { //일반적인 경우
		CNode* list = Head;

		do {
			if (list->link->data == value) {
				CNode* removed = list->link;
				list->link = removed->link; //list->link = list->link->link;
				if (Head == removed) { //지울 노드가 마지막 노드면 헤드는 그 앞 로드(list)를 가르켜야 함
					Head = list;
					return;
				}
			}
			list = list->link;
		} while (list != Head);
	}
}

void print_list() {
	cout << "원형연결리스트 내용 출력:" << endl;
	if (Head == NULL) {
		cout << "빈리스트 입니다." << endl;
		return;
	}
	else {
		CNode* list;

		list = Head; //list=Head->link;
		do {
			cout << list->link->data<<" ";
			list = list->link;
		} while (list != Head);
	}
	cout << endl;

	//단순연결리스트처럼 프린트하면 무한루프 돌아 -> NULL이 없기 때문에 무한 루프 도는 중
	/*for (CNode* list = Head; list != NULL; list = list->link) {
		cout << list->data;
			if (list->link != NULL) {
				cout << "->";
		}
	}
	cout << endl;*/
}



void main() {
	insert_node(10);
	insert_node(20);
	insert_node(30);
	insert_node(40);
	insert_node(50);
	insert_node(60);

	print_list();

	delete_node(60);
	delete_node(50);
	delete_node(45);
	delete_node(10);

	print_list();
}