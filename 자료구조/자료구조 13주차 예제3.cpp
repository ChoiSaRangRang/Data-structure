#include <iostream>
using namespace std;
typedef int element;

#define  8 NODE_NUM// 노드의 개수

int adj[NODE_NUM][NODE_NUM] =
{ 0, 1, 1, 0, 0, 0, 0, 0,
1, 0, 0, 1, 1, 0, 0, 0,
1, 0, 0, 0, 0, 1, 1, 0,
0, 1, 0, 0, 0, 0, 0, 1,
0, 1, 0, 0, 0, 0, 0, 1,
0, 0, 1, 0, 0, 0, 0, 1,
0, 0, 1, 0, 0, 0, 0, 1,
0, 0, 0, 1, 1, 1, 1, 0 };

string name[NODE_NUM] = { "v1", "v2", "v3", "v4", "v5", "v6", "v7", "v8" };

bool visited[NODE_NUM] = { 0 };

void print_node(int v)
{
	cout << name[v] << endl;
}

void DFS(int v) {

	if (visited[v] != 0) return;
	else visited[v] = 1;

	print_node(v);

	for (int w = 0; w <= NODE_NUM; w++)
	{
		if (adj[v][w] == 0) continue;
		// adj[v][w]이 1임.
		if (visited[w] != 0) continue;
		else DFS(w);
	}
}

void main()
{
	DFS(0);
}
