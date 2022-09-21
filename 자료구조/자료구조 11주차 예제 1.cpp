#include <iostream>
using namespace std;

typedef double element;
const int MAX_QUEUE_SIZE = 5;
//����ť�� ����(�迭�� �̿��Ͽ�)

//template <typename element> -����� ������ ����(�ý��� ����)
class CQueue {
public:
	element queue[MAX_QUEUE_SIZE];
	int front, rear;

	CQueue() { 
		front = 0;
		rear = 0;
	}

	bool is_queue_empty() {
		return(front == rear); //�� ���� ��ü�� �����ϸ� ���ٷ� ��������
	}

	bool is_queue_full() {
		return (front == (rear + 1) % MAX_QUEUE_SIZE);
		//front�� rear �ϳ�����
	}

	void enQueue(element value) {
		if (is_queue_full()) {
			cout << "ERROR : Queue Overflow" << endl;
			exit(1); //���α׷� ��ü�� ����
		}
		else {
			rear = (rear + 1) % MAX_QUEUE_SIZE; //rear++;
			queue[rear] = value;
		}

	}

	element deQueue() {
		if (is_queue_empty()) {
			cout << "ERROR : Queue Underflow" << endl;
			exit(1);
		}
		else {
			front = (front + 1) % MAX_QUEUE_SIZE; //font++;
			return queue[front];
		}
	}

	element peek() {
		if (is_queue_empty()) {
			cout << "ERRPR : Queue is Empty" << endl;
			exit(1);
		}
		else {
			return queue[(front + 1) % MAX_QUEUE_SIZE];
		}
	}

	void print_queue() {
		cout << "##ť ���� ���##" << endl;
		if (front <= rear) { //�̶��� ���� ����
			for (int i = front + 1; i <= rear; i++) {
				cout << queue[i] << " ";
			}
		}
		else { //�̋��� ��� �ʿ�(front�� �� ū ���)
			for (int i = front + 1; i <= rear + MAX_QUEUE_SIZE; i++) {
				cout << queue[i % MAX_QUEUE_SIZE] << " ";
			}
		}
		cout << endl;
	}
};

int main() {
	/*
	CQueue<int> q;
	CQueue<double> dq;
	priority_queue<int> pq;
	*/
	CQueue q;

	/*
	�Ϲ� �迭 dequeue �־ �����÷ο� 
	But ����ť�� dequeue �ν��ؼ� �����÷ο� �ƴ�.
	*/
	q.enQueue(10);
	q.enQueue(20);
	q.enQueue(30);
	q.deQueue();
	q.enQueue(40);
	q.deQueue();
	q.deQueue();
	q.enQueue(50);
	q.deQueue();
	q.enQueue(60);

	q.print_queue();
}
