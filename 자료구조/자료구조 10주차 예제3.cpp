#include <iostream>
using namespace std;

typedef double element;
//ť�� ����(���Ḯ��Ʈ(��ü)�� �̿��Ͽ�)

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
		return(front == NULL); //�� ���� ��ü�� �����ϸ� ���ٷ� ��������
		//return(rear==NULL) or return(front==NULL || rear==NULL)	
	}

	void enQueue(element value) {
		//���ο� ��带 �Ҵ�, ���� �� ���Ḯ��Ʈ ���� �ڿ� �߰�
		Node* new_node = new Node;
		new_node->data = value;
		new_node->link = NULL;

		//���� ����Ʈ�� �߰�(������ ����)
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
			cout << "##ť ���� ���##" << endl;
			//���� ���ݻ� top���� ������ �Ʒ��� ���
			for (Node* list = front; list != NULL; list = list->link) {
				cout << list->data << " ";
			}
			cout << endl;
		}
};

int main() {
	Queue q;
	//queue<int> q2; -> �����Ǵ� �� ����ϱ�(���� �˻��ϸ� �Լ� ���� �پ��ϴ�)

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