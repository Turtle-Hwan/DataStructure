#include <stdio.h> 
#include <stdlib.h>
#include <iostream>
#include <string>

//이진 트리
struct NODE {
	int data;
	struct NODE *right;
	struct NODE *left;
	bool visit = false;
};
struct NODE *rootP;	//더미 head 노드 전역 변수로 선언 : Search 시작점으로 사용하기 위해.

void DummyTree() {
	//더미 트리
	struct NODE *root = (struct NODE*)malloc(sizeof(struct NODE));
	rootP = root;
	struct NODE *Level1_Left = (struct NODE*)malloc(sizeof(struct NODE));
	struct NODE *Level1_Right = (struct NODE*)malloc(sizeof(struct NODE));
	
	struct NODE *Level2_LLeft = (struct NODE*)malloc(sizeof(struct NODE));
	struct NODE *Level2_LRight = (struct NODE*)malloc(sizeof(struct NODE));
	struct NODE *Level2_RRight = (struct NODE*)malloc(sizeof(struct NODE));
	
	root->data = 10;
	root->left = Level1_Left;
	root->right = Level1_Right;
	
	Level1_Left->data = 5;
	Level1_Left->left = Level2_LLeft;
	Level1_Left->right = Level2_LRight;
	
	Level2_LLeft->data = 4;
	Level2_LLeft->left = NULL;
	Level2_LLeft->right = NULL;
	
	Level2_LRight->data = 3;
	Level2_LRight->left = NULL;
	Level2_LRight->right = NULL;
	
	Level1_Right->data = 20;
	Level1_Right->left = NULL;
	Level1_Right->right = Level2_RRight;
	
	Level2_RRight->data = 15;
	Level2_RRight->left = NULL;
	Level2_RRight->right = NULL;
}

#define MAX_LEN 10000
class StackClass {
	struct NODE* Stack[MAX_LEN];
public:
	int StackP = 0;
	
public:
	void push(struct NODE* node) {
		if (StackP != MAX_LEN) {
			Stack[StackP] = node;
			StackP += 1;
		}
	}
	void pop() {
		if (StackP != 0) {
			StackP -= 1;
		}
	}
	struct NODE* top() {
		if (StackP != 0) {
			return Stack[StackP-1];
		}
		else return NULL;
	}
	int isEmpty() {
		if (StackP == 0) {
			return 1;
		}
		else {
			return 0;
		}
	}
};



void Print() { // tree 전체 모양 print
	
}

void DFS (struct NODE* root) {	// dfs 규칙대로 노드 하나씩 print
	struct NODE *cursor = root;
	
	StackClass stack;
	stack.push(cursor);
	cursor->visit = true;
	printf("| %d |", cursor->data);
	
	
	//스택이 빌 때까지 반복
	while (stack.isEmpty() == false) { 
		//스택 맨 위 노드의 자식 노드 확인. 자식 없으면 스택 맨 위 노드 꺼내기.
		
		if (cursor->left == NULL && cursor->right == NULL) {
			//printf(" > end\n      ");
		}
		
		if (cursor->left != NULL && cursor->left->visit == false) {
			//왼쪽 자식 노드 스택에 집어넣기
			printf(" --> ");
			
			cursor = cursor->left;
			stack.push(cursor);
			cursor->visit = true;
			printf("| %2d |", cursor->data);
		}
		else if (cursor->right != NULL && cursor->right->visit == false) {
			//오른쪽 자식 노드 스택에 집어넣기
			printf(" --> ");
			
			cursor = cursor->right;
			stack.push(cursor);
			cursor->visit = true;
			printf("| %2d |", cursor->data);
		}
		else {
			//자식노드 없으므로 스택에서 꺼내기.
			printf(" back ");
			stack.pop();
			cursor = stack.top();
		}
	}
}


class QueueClass {
	struct NODE* Queue[MAX_LEN];
	int head = 0;	//큐는 head에서 pop 되고, tail에서 push된다.
	int tail = 0;
	bool full = false;
	
public:
	void push(struct NODE* data) {
		if (head == tail && full == true) {
		}
		else {
			Queue[tail] = data;
			tail += 1;
			
			if (tail == MAX_LEN) {tail = 0;}
			if (tail == head) {full = true;}
		}
	}

	void pop() {
		if (head == tail && full == false) {
		}
		else {
			int popDataIndex = head;
			head += 1;
			if (head == MAX_LEN) {
				head = 0;
			}
		}
	}
	
	struct NODE* top() {
		return Queue[head];
	}
	
	bool isEmpty() {
		if (head == tail && full == false) {
			return true;
		}
		else {
			return false;
		}
	}
};

void BFS(struct NODE *root) {
	struct NODE* cursor = root;
	
	QueueClass queue;
	queue.push(cursor);
	
	while(queue.isEmpty() == false) {
		//queue에서 하나 pop 하고, 출력하고, 꺼낸 노드의 자식들 push하기.		
		queue.pop();
		printf("| %2d |\n", cursor->data);
		if (cursor->left != NULL) {
			queue.push(cursor->left);
		}
		if (cursor->right != NULL) {
			queue.push(cursor->right);
		}
		
		cursor = queue.top();
	}
	
	
}

int main() {
	DummyTree();
	

	std::string command;
	while(1) {
		printf("\n\n print / dfs / bfs / q(quit) 입력\n");
		std::cin >> command;

		if (!command.compare("print")) {
			Print();
		}
		else if (!command.compare("dfs")) {
			DFS(rootP);
		}
		else if (!command.compare("bfs")) {
			BFS(rootP);
		}
		else if (!command.compare("q")) {
			exit(0);
		}
		else {
			printf("???");
		}
	}
}