#include <iostream>
using namespace std;

typedef double element;
const int MAX_QUEUE_SIZE = 100;
//큐의 구현(배열을 이용하여)

class Queue {
public:
	element queue[MAX_QUEUE_SIZE];
	int front, rear;

	Queue() { 
		front = rear = -1;
	}

	bool is_queue_empty() {
		return(front == rear); //비교 수식 자체를 리턴하면 한줄로 정리가능
	}

	bool is_queue_full() {
		return(rear == MAX_QUEUE_SIZE -1); //식 자체를 리턴하면 한줄로 정리가능
	}

	void enQueue(element value) {
		if (is_queue_full()) {
			cout << "ERROR : Queue Overflow" << endl;
			exit(1); //프로그램 자체를 끝냄
		}
		else {
			queue[++rear] = value; //한줄로 정리 가능(top을 먼저 증가시키고 stack에 사용하기
		}

	}

	element deQueue() {
		if (is_queue_empty()) {
			cout << "ERROR : Queue Underflow" << endl;
			exit(1);
		}
		else {
			return queue[++front]; //한줄로 정리 가능(먼저 stack 값을 리턴하고 top을 이후에 줄여라
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
		cout << "##큐 상태 출력##" << endl;
		//스택 성격상 top부터 위에서 아래로 출력
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
