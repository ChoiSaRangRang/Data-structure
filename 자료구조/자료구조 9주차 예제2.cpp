#include <iostream>
#include <stack> //���� ���� �Լ�/��ü ����

using namespace std;



void main() {
	//�ý��� ���� ���� �̿�
	//������ ���ڴµ� �� �̸� s�̴�. ���� ������ ���� ���ÿ� �׾Ƶΰڴ�
	stack<int> s;

	s.push(10);
	s.push(20);
	cout << s.top() << endl; //���� �����ִ� �� ���

	s.pop();
	s.push(30);
	s.push(40);
	s.push(50);
	s.pop();
}