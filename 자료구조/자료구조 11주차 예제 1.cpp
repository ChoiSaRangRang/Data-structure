#include <iostream>
using namespace std;

typedef double element;
const int MAX_QUEUE_SIZE = 5;
//원형큐의 구현(배열을 이용하여)

//template <typename element> -사용할 때마다 선언(시스템 제공)
class CQueue {
public:
	element queue[MAX_QUEUE_SIZE];
	int front, rear;

	CQueue() { 
		front = 0;
		rear = 0;
	}

	bool is_queue_empty() {
		return(front == rear); //비교 수식 자체를 리턴하면 한줄로 정리가능
	}

	bool is_queue_full() {
		return (front == (rear + 1) % MAX_QUEUE_SIZE);
		//front와 rear 하나차이
	}

	void enQueue(element value) {
		if (is_queue_full()) {
			cout << "ERROR : Queue Overflow" << endl;
			exit(1); //프로그램 자체를 끝냄
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
		cout << "##큐 상태 출력##" << endl;
		if (front <= rear) { //이때는 걱정 없음
			for (int i = front + 1; i <= rear; i++) {
				cout << queue[i] << " ";
			}
		}
		else { //이떄는 고민 필요(front가 더 큰 경우)
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
	일반 배열 dequeue 있어도 오버플로우 
	But 원형큐는 dequeue 인식해서 오버플로우 아님.
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
