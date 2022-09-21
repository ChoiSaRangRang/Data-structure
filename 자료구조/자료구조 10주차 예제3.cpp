#include <iostream>
using namespace std;

typedef double element;
//큐의 구현(연결리스트(객체)을 이용하여)

class Node {
public:
	element data;
	Node* link;
};

class Queue {
public:
	Node *front, *rear;

	Queue() {
		front = rear = NULL;
	}

	bool is_queue_empty() {
		return(front == NULL); //비교 수식 자체를 리턴하면 한줄로 정리가능
		//return(rear==NULL) or return(front==NULL || rear==NULL)	
	}

	void enQueue(element value) {
		//새로운 노드를 할당, 세팅 후 연결리스트 제일 뒤에 추가
		Node* new_node = new Node;
		new_node->data = value;
		new_node->link = NULL;

		//기존 리스트에 추가(마지막 노드로)
		//if(rear==NULL)
		if (is_queue_empty()) {
			front = rear = new_node;
		}
		else {
			rear->link = new_node;
			rear = new_node;
		}
	}

	element deQueue() {
		if (is_queue_empty()) {
			cout << "ERROR : Queue Underflow" << endl;
			exit(1);
		}
		else {
			element x = front->data;
			front = front->link;
			if (front == NULL) {
				rear = NULL;
			}
			return x;
		}
	}

	element peek() {
		if (is_queue_empty()) {
			cout << "ERRPR : Queue is Empty" << endl;
			exit(1);
		}
		else {
			return front->data;
		}
	}

		void print_queue() {
			cout << "##큐 상태 출력##" << endl;
			//스택 성격상 top부터 위에서 아래로 출력
			for (Node* list = front; list != NULL; list = list->link) {
				cout << list->data << " ";
			}
			cout << endl;
		}
};

int main() {
	Queue q;
	//queue<int> q2; -> 제공되는 것 사용하기(구글 검색하면 함수 종류 다양하다)

	q.enQueue(10);
	q.enQueue(20);
	q.enQueue(30);
	q.enQueue(40);
	q.deQueue();
	q.deQueue();
	q.enQueue(50);
	q.enQueue(60);
	q.deQueue();
	q.deQueue();
	q.enQueue(70);

	q.print_queue();
}