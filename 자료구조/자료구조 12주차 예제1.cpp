#include <iostream>
using namespace std;

//수식 트리를 포인트로 진행
class TNode {
public:
	int data;
	TNode* left;
	TNode* right;

	TNode(int x, TNode* llink, TNode* rlink) {
		data = x;
		left = llink;
		right = rlink;
	}
};

int eval(TNode *root) {
	if (root == NULL) {
		return 0;
	}
	else if (root->left == NULL && root->right == NULL) { //자식 노드가 없는 노드라면
		return (root->data);
	}
	else { //비단말 노드면
		int op1 = eval(root->left);
		int op2 = eval(root->right);

		if (root->data == '+') {
			return (op1 + op2);
		}
		else if (root->data == '*') {
			return(op1 * op2);
		}
		else if (root->data == '-') {
			return(op1 - op2);
		}
		else if (root->data == '/') {
			return(op1 / op2);
		}
	}
}

void main() {
	//수식 트리를 만들자
	//     +
	//  *     +
	// 3  2  5  6
	TNode* n1, * n2, * n3, * n4, * n5, * n6, * n7;
	TNode* root;

	//연산자들은 모두 꽉 차있다(NULL이 없음 계산해야하니까)
	n1 = new TNode(3, NULL, NULL);
	n2 = new TNode(2, NULL, NULL);
	n3 = new TNode('*', n1, n2);
	n4 = new TNode(5, NULL, NULL);
	n5 = new TNode(6, NULL, NULL);
	n6 = new TNode('+', n4, n5);
	root = n7 = new TNode('+', n3, n6);

	//수식을 계산하여 출력하자
	cout << "수식 트리 계산 값 = " << eval(root) << endl;
}