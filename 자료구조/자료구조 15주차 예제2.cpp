#include <iostream>
using namespace std;
#include <stack>
#include <queue>

//인접행렬을 이용한 구현 - DFS/BFS

const int NODE_NUM = 8;

int adj[NODE_NUM][NODE_NUM] =
{ 0, 1, 1, 0, 0, 0, 0, 0,
  1, 0, 0, 1, 1, 0, 0, 0,
  1, 0, 0, 0, 0, 1, 1, 0,
  0, 1, 0, 0, 0, 0, 0, 1,
  0, 1, 0, 0, 0, 0, 0, 1,
  0, 0, 1, 0, 0, 0, 0, 1,
  0, 0, 1, 0, 0, 0, 0, 1,
  0, 0, 0, 1, 1, 1, 1, 0
};

bool visited[NODE_NUM] = { }; //모든 값을 0으로(bool이니까 false) 초기화
string NodeName[NODE_NUM] = { "V1", "V2", "V3", "V4", "V5", "V6", "V7", "V8" };

void print_node(int v) {
	cout << NodeName[v] << "방문했습니다." << endl;
}

void DFS(int v) { //인접행렬 - 순환 알고리즘 방식
	//해당 노드가 이미 방문한 적이 있으면, 무시
	if (visited[v] != 0) {
		return;
	}
	else {
		visited[v] = 1;
	}

	print_node(v); //노드 방문 결과 출력

	for (int w = 0; w < NODE_NUM; w++) { //행 : v, 각 열에 대해 
		if (adj[v][w] == 0) { //미연결
			continue;
		}
		if (visited[w] != 0) { //이미 방문
			continue;
		}
		DFS(w);
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

		for (int w = 0; w < NODE_NUM; w++) { //행 : v, 각 열에 대해 
			if (adj[v][w] == 0) { //미연결
				continue;
			}
			if (visited[w] != 0) { //이미 방문
				continue;
			}
			mystack.push(w);
		}
	}
}

queue<int>myqueue;
void BFS(int v) {
	//스택버전
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

		for (int w = 0; w < NODE_NUM; w++) { //행 : v, 각 열에 대해 
			if (adj[v][w] == 0) { //미연결
				continue;
			}
			if (visited[w] != 0) { //이미 방문
				continue;
			}
			myqueue.push(w);
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


	//DFS 순회
	//DFS(0); //V1부터 DFS 순회를 하시오
	//DFS_stack(0);

	//BFS 순회
	BFS(0);
}