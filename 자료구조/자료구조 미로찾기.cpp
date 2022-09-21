#include <iostream>
using namespace std;

#define element int
const int MAX_STACK_SIZE = 100;
const int MAZE_SIZE = 6;

typedef struct {
    short r;
    short c;
} element;

typedef struct {
    element stack[MAX_STACK_SIZE];
    int top;
} StackType;

void init(StackType* s) {
    s->top = -1;
}

int is_empty(StackType* s) {
    return s->top == -1;
}

int is_full(StackType* s) {
    return s->top == MAX_STACK_SIZE - 1;
}

void push(StackType* s, element item) {
    if (is_full(s)) {
        exit(1);
    }
    s->stack[++(s->top)] = item;
}

element pop(StackType* s) {
    if (is_empty(s)) {
        exit(1);
    }
    return s->stack[(s->top)--];
}

element peek(StackType* s) {
    if (is_empty(s)) {
        exit(1);
    }
    return s->stack[s->top];
}

element here = { 1,0 };
element entry = { 1,0 };

char maze[MAZE_SIZE][MAZE_SIZE] = {
    {'1','1','1','1','1','1'},
    {'e','0','1','0','0','1'},
    {'1','0','0','0','1','1'},
    {'1','0','1','0','1','1'},
    {'1','0','1','0','0','x'},
    {'1','1','1','1','1','1'}
};

void push_loc(StackType* s, int r, int c) {
    // �迭 ������ ��� r,c�� �����Ѵ�.
    if (r < 0 || c < 0 || r > MAZE_SIZE || c > MAZE_SIZE) return;
    // ��(1)�� �ƴϰ�, �̹� �Դ� ��(.)�� �ƴϴ� = �� �� �ִ�
    if (maze[r][c] != '1' && maze[r][c] != '.') {
        element tmp;
        tmp.r = r;
        tmp.c = c;
        push(s, tmp);
    }
}

void print() {
    int i, j;
    for (i = 0; i < MAZE_SIZE; i++) {
        for (j = 0; j < MAZE_SIZE; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int r, c;
    StackType s;

    init(&s);
    here = entry; // entry�� �̶� �ѹ��� ���ȴ�
    while (maze[here.r][here.c] != 'x') {
        r = here.r;
        c = here.c;
        maze[r][c] = '.';

        print();
        printf("------------\n");

        // ������ ���� �������� ���� ���� ���� ���� �̾��ش�
        // �׷��Ƿ� ��-��-��-�� ������ ������
        // ��-��-��-�� �� ������ ������ �ȴ�
        push_loc(&s, r - 1, c); // north
        push_loc(&s, r + 1, c); // south
        push_loc(&s, r, c - 1); // west
        push_loc(&s, r, c + 1); // east

        if (is_empty(&s)) {
            printf("����\n");
            exit(1);
        }
        else {
            here = pop(&s);
        }
    }
    printf("����\n");
    return 0;
}
element here = { 1.0 };
element entry = { 1.0 };

class Stack {
public:
	element stack[MAX_STACK_SIZE];
	element stack[MAZE_SIZE];


	Stack() { //������ �Լ��� �ʱ�ȭ
		top = -1;
	}


	bool is_empty_stack() {
		return(top == -1);
	}

	bool is_stack_full() {
		return(top == MAX_STACK_SIZE - 1);
	}

	void push(int value) {
		if (is_stack_full()) {
			cout << "ERROR : Stack Overflow" << endl;
			exit(1); //���α׷� ��ü�� ����
		}
		else {
			stack[++top] = value; //���ٷ� ���� ����(top�� ���� ������Ű�� stack�� ����ϱ�
		}

	}

	int pop() {
		if (is_empty_stack()) {
			cout << "ERROR : Stack Underflow" << endl;
			exit(1);
		}
		else {
			return stack[top--]; //���ٷ� ���� ����(���� stack ���� �����ϰ� top�� ���Ŀ� �ٿ���
		}
	}

	int peek() {
		if (is_empty_stack()) {
			cout << "ERRPR : Stack Empty" << endl;
		}
		else {
			return stack[top];
		}
	}

	char maze[MAZE_SIZE][MAZE_SIZE] = {
		{'1', '1', '1', '1', '1', '1'},
		{'e', '0', '1', '0', '0', '1'},
		{'1', '0', '0', '0', '1', '1'},
		{'1', '0', '1', '0', '1', '1'},
		{'1', '0', '1', '0', '0', 'x'},
		{'1', '1', '1', '1', '1', '1'}
	};

	void push_loc(int r, int c) {
		if (r < 0 || c < 0 || r > MAZE_SIZE || c > MAZE_SIZE) {
			return;
		}
		else if (maze[r][c] != '1' && maze[r][c] != '.') {
			r = r;
			c = c;
			push(r);
		}
	}

	void print_stack() {
		int i, j;
		for (i = 0; i < MAZE_SIZE; i++) {
			for (j = 0; j < MAZE_SIZE; j++) {
				cout << maze[i][j];
			}
			cout << '\n';
		}
	}
};

void main() {
	int r, c;


}