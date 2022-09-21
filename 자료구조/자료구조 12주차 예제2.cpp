#include <iostream>
using namespace std;

//���� Ʈ���� ����Ʈ�� ����
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
	else if (root->left == NULL && root->right == NULL) { //�ڽ� ��尡 ���� �����
		return (root->data);
	}
	else { //��ܸ� ����
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
	//��Ʈ ���� ó�� ��, L&R ����Ʈ�� ��ȸ
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
	//L&R ����Ʈ�� ��ȸ �� ��Ʈó��

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
	//L ����Ʈ�� ��ȸ �� ��Ʈó��, R���� Ʈ�� ��ȸ

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
	//���� Ʈ���� ������
	//     +
	//  *     +
	// 3  2  5  6
	TNode* n1, * n2, * n3, * n4, * n5, * n6, * n7;
	TNode* root;

	//�����ڵ��� ��� �� ���ִ�(NULL�� ���� ����ؾ��ϴϱ�)
	n1 = new TNode(3, NULL, NULL);
	n2 = new TNode(2, NULL, NULL);
	n3 = new TNode('*', n1, n2);
	n4 = new TNode(5, NULL, NULL);
	n5 = new TNode(6, NULL, NULL);
	n6 = new TNode('+', n4, n5);
	root = n7 = new TNode('+', n3, n6);

	//����Ʈ���� ��ȸ
	 
	//1������ȸ preorder(root);
	//2������ȸ
	postorder(root);
}