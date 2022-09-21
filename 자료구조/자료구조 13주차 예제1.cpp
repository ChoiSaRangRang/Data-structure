#include <iostream>
using namespace std;
//인접리스트를 이용한 구현

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

class VNode {
public:
	string name;
	bool visited;
	Node* link;

} graph[NODE_NUM];

void insert_node(int node_index, int adjacent_node_num) {
	//graph[node_index].link 뒤에 adjacent_node_num 노드를 연결
	Node* new_node = new Node(adjacent_node_num);
	new_node->link = graph[node_index].link;
	graph[node_index].link = new_node;
}

void print_graph() {
	for (int i = 0; i < NODE_NUM; i++) {
		cout << "정점 " << graph[i].name << ": ";
		for (Node* list = graph[i].link; list != NULL; list = list->link) {
			//cout << "--> " << list->index;
			cout << "---> " << graph[list->index].name;
		}
		cout << endl;
	}
}

void print_node(int v) {
	cout << graph[v].name << "방문했습니다." << endl;
}

void DFS(int v) { //순환알고리즘 방식
	//해당 노드가 이미 방문한 적이 있으면, 무시
	if (graph[v].visited != 0) {
		return;
	}
	else {
		graph[v].visited = 1;
	}

	print_node(v); //노드 방문 결과 출력

	for (Node* w = graph[v].link; w != NULL; w = w->link) {
		if (graph[w->index].visited == 0) {
			DFS(w->index);
		}
	}
}

void main() {
	//그래프 생성
	graph[0].name = "V1";
	graph[1].name = "V2";
	graph[2].name = "V3";
	graph[3].name = "V4";
	graph[4].name = "V5";
	graph[5].name = "V6";
	graph[6].name = "V7";
	graph[7].name = "V8";

	//초기화
	for (int i = 0; i < NODE_NUM; i++) {
		graph[i].visited = 0;
		graph[i].link = NULL;
	}

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
	DFS(0); //V1부터 DFS 순회를 하시오

}