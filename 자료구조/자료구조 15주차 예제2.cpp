#include <iostream>
using namespace std;
#include <stack>
#include <queue>

//��������� �̿��� ���� - DFS/BFS

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

bool visited[NODE_NUM] = { }; //��� ���� 0����(bool�̴ϱ� false) �ʱ�ȭ
string NodeName[NODE_NUM] = { "V1", "V2", "V3", "V4", "V5", "V6", "V7", "V8" };

void print_node(int v) {
	cout << NodeName[v] << "�湮�߽��ϴ�." << endl;
}

void DFS(int v) { //������� - ��ȯ �˰��� ���
	//�ش� ��尡 �̹� �湮�� ���� ������, ����
	if (visited[v] != 0) {
		return;
	}
	else {
		visited[v] = 1;
	}

	print_node(v); //��� �湮 ��� ���

	for (int w = 0; w < NODE_NUM; w++) { //�� : v, �� ���� ���� 
		if (adj[v][w] == 0) { //�̿���
			continue;
		}
		if (visited[w] != 0) { //�̹� �湮
			continue;
		}
		DFS(w);
	}
}

stack<int>mystack;
void DFS_stack(int v) {
	//���ù���
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

		for (int w = 0; w < NODE_NUM; w++) { //�� : v, �� ���� ���� 
			if (adj[v][w] == 0) { //�̿���
				continue;
			}
			if (visited[w] != 0) { //�̹� �湮
				continue;
			}
			mystack.push(w);
		}
	}
}

queue<int>myqueue;
void BFS(int v) {
	//���ù���
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

		for (int w = 0; w < NODE_NUM; w++) { //�� : v, �� ���� ���� 
			if (adj[v][w] == 0) { //�̿���
				continue;
			}
			if (visited[w] != 0) { //�̹� �湮
				continue;
			}
			myqueue.push(w);
		}
	}
}

void main() {
	//�׷��� ����

	/*
	for (int i = 0; i < NODE_NUM; i++) {
		VertexList[i] = NULL;
	}
	*/


	//DFS ��ȸ
	//DFS(0); //V1���� DFS ��ȸ�� �Ͻÿ�
	//DFS_stack(0);

	//BFS ��ȸ
	BFS(0);
}