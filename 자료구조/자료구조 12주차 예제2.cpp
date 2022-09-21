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

int eval(TNode* root) {
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

void preorder(TNode* root) {
	//루트 먼저 처리 후, L&R 서브트리 순회
	if (root == NULL) {
		return;
	}
	if (root->data >= '0' && root->data <= 9) {
		cout << " " << root->data << " "; //V
	}
	else {
		cout << " " << (char) (root->data) << " "; //V
	}
	preorder(root->left); //L
	preorder(root->right); //R
}

void postorder(TNode* root) {
	//L&R 서브트리 순회 후 루트처리

	if (root == NULL) {
		return;
	}

	preorder(root->left); //L
	preorder(root->right); //R

	if (root->data >= '0' && root->data <= 9) {
		cout << " " << root->data << " "; //V
	}
	else {
		cout << " " << (char)(root->data) << " "; //V
	}
}

void inorder(TNode* root) {
	//L 서브트리 순회 후 루트처리, R서브 트리 순회

	if (root == NULL) {
		return;
	}

	preorder(root->left); //L

	if (root->data >= '0' && root->data <= 9) {
		cout << " " << root->data << " "; //V
	}
	else {
		cout << " " << (char)(root->data) << " "; //V
	}

	preorder(root->right); //R
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

	//수식트리를 순회
	 
	//1전위순회 preorder(root);
	//2후위순회
	postorder(root);
}