#include <iostream>
using namespace std;

typedef double element;
const int MAX_QUEUE_SIZE = 100;
//ť�� ����(�迭�� �̿��Ͽ�)

class Queue {
public:
	element queue[MAX_QUEUE_SIZE];
	int front, rear;

	Queue() { 
		front = rear = -1;
	}

	bool is_queue_empty() {
		return(front == rear); //�� ���� ��ü�� �����ϸ� ���ٷ� ��������
	}

	bool is_queue_full() {
		return(rear == MAX_QUEUE_SIZE -1); //�� ��ü�� �����ϸ� ���ٷ� ��������
	}

	void enQueue(element value) {
		if (is_queue_full()) {
			cout << "ERROR : Queue Overflow" << endl;
			exit(1); //���α׷� ��ü�� ����
		}
		else {
			queue[++rear] = value; //���ٷ� ���� ����(top�� ���� ������Ű�� stack�� ����ϱ�
		}

	}

	element deQueue() {
		if (is_queue_empty()) {
			cout << "ERROR : Queue Underflow" << endl;
			exit(1);
		}
		else {
			return queue[++front]; //���ٷ� ���� ����(���� stack ���� �����ϰ� top�� ���Ŀ� �ٿ���
		}
	}

	element peek() {
		if (is_queue_empty()) {
			cout << "ERRPR : Queue is Empty" << endl;
			exit(1);
		}
		else {
			return queue[front+1];
		}
	}

	void print_queue() {
		cout << "##ť ���� ���##" << endl;
		//���� ���ݻ� top���� ������ �Ʒ��� ���
		for (int i = front+1; i <= rear; i++) {
			cout << queue[i] << " ";
		}
		cout << endl;
	}
};

int main() {
	Queue q;

	q.enQueue(10);
	q.enQueue(20);
	q.enQueue(30);
	q.enQueue(40);
	q.deQueue();
	q.deQueue();
	q.enQueue(50);
	q.enQueue(60);
	q.deQueue();

	q.print_queue();
}
