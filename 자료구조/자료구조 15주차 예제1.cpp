#include <iostream>
using namespace std;
#include <stack>
#include<queue>

//인점 리스트를 이용한 구현 version 2

const int NODE_NUM = 8;

class Node {
public:
	int index;
	Node* link;

	Node(int  xindex) {
		index = xindex;
		link = NULL;
	}
};

bool visited[NODE_NUM] = { }; //모든 값을 0으로(bool이니까 false) 초기화
string NodeName[NODE_NUM] = { "V1", "V2", "V3", "V4", "V5", "V6", "V7", "V8" };

Node* VertexList[NODE_NUM] = { NULL }; //해당 노드(정점)의 헤드 포인터와 배열

void insert_node(int v, int w) { //(v,w) 에지 정보를 리스트에 추가
	Node* new_node = new Node(w);
	new_node->link = VertexList[v];
	VertexList[v] = new_node;
}

void print_graph() {
	cout << "### 인접리스트 결과 ###" << endl;
	for (int i = 0; i < NODE_NUM; i++) {
		cout << "정점 " << NodeName[i] << ": ";
		for (Node* list = VertexList[i]; list != NULL; list = list->link) {
			//cout << "--> " << list->index;
			cout << "---> " << NodeName[list->index];
		}
		cout << endl;
	}
}

void print_node(int v) {
	cout << NodeName[v] << "방문했습니다." << endl;
}

void DFS(int v) { //순환 알고리즘 방식
	//해당 노드가 이미 방문한 적이 있으면, 무시
	if (visited[v] != 0) {
		return;
	}
	else {
		visited[v] = 1;
	}

	print_node(v); //노드 방문 결과 출력

	for (Node* w = VertexList[v]; w != NULL; w = w->link) {
		if (visited[w->index] == 0) {
			DFS(w->index);
		}
	}
}

stack<int>mystack;
void DFS_stack(int v) {
	//스택버전
	mystack.push(v);

	while (!mystack.empty()) {
		v = mystack.top();
		mystack.pop(); // v=pop();

		if (visited[v] != 0) {
			continue;
		}
		else {
			visited[v] = 1;
		}

		print_node(v);

		for (Node* w = VertexList[v]; w != NULL; w = w->link) {
			if (visited[w->index] == 0) {
				mystack.push(w->index);
			}
		}
	}
}

queue<int>myqueue;
void BFS(int v) {
	//큐 이용
	myqueue.push(v);

	while (!myqueue.empty()) {
		v = myqueue.front();
		myqueue.pop(); // v=dequeue();

		if (visited[v] != 0) {
			continue;
		}
		else {
			visited[v] = 1;
		}

		print_node(v);

		for (Node* w = VertexList[v]; w != NULL; w = w->link) {
			if (visited[w->index] == 0) {
				myqueue.push(w->index);
			}
		}
	}
}

void main() {
	//그래프 생성

	/*
	for (int i = 0; i < NODE_NUM; i++) {
		VertexList[i] = NULL;
	}
	*/

	//노드0, V1 인접 노드 연결
	insert_node(0, 1); //V1-V2
	insert_node(0, 2); //V1-V3

	//노드1, V2 인접 노드 연결
	insert_node(1, 0); //V2-V1
	insert_node(1, 3); //V2-V4
	insert_node(1, 4); //V2-V5

	//노드2, V3 인접 노드 연결
	insert_node(2, 0); //V3-V1
	insert_node(2, 5); //V3-V6
	insert_node(2, 6); //V3-V7

	//노드3, V4 인접 노드 연결
	insert_node(3, 1); //V4-V2
	insert_node(3, 7); //V4-V8

	//노드4, V5 인접 노드 연결
	insert_node(4, 1); //V5-V2
	insert_node(4, 7); //V5-V8

	//노드5, V6 인접 노드 연결
	insert_node(5, 2); //V6-V3
	insert_node(5, 7); //V6-V8

	//노드6, V7 인접 노드 연결
	insert_node(6, 2); //V7-V3
	insert_node(6, 7); //V7-V8

	//노드7, V8 인접 노드 연결
	insert_node(7, 3); //V8-V4
	insert_node(7, 4); //V8-V5
	insert_node(7, 5); //V8-V6
	insert_node(7, 6); //V8-V7

	//출력해보자
	print_graph();

	//DFS 순회
	//DFS(0); //V1부터 DFS 순회를 하시오
	//DFS_stack(0);

	//BFS 순회
	BFS(0);
}