#include <stdio.h>
#include <iostream>
#include <string>
#include <cstdlib>

#define MAX_LEN 3
int Queue[MAX_LEN];
int head = 0;	//큐는 head에서 pop 되고, tail에서 push된다.
int tail = 0;
bool full = false;	//꽉 찬 상태 표기 위함 : 원형 큐에서는 꽉 찬 상태와 빈 상태 모두 head == tail

//배열 이용, 원형으로 구현.
void Push(int data) {
	if (head == tail && full == true) {
		printf("queue가 꽉 차있습니다. push 불가!\n");
	}
	else {
		Queue[tail] = data;
		tail += 1;
		
		//원형 큐를 만들기 위한 코드 추가 : tail이 index를 벗어나면 0으로 되돌리기
		if (tail == MAX_LEN) {
			tail = 0;
		}
		
		//꽉 찼는지 검사
		if (tail == head) {
			full = true;
		}
		
		//현재 data 개수를 세기 위한 코드
		int nowDataCount;
		if (tail - head > 0) {
			nowDataCount = tail - head;
		}
		else {
			nowDataCount = tail - head + MAX_LEN;
		}
		printf("queue에 데이터를 넣었습니다.\n현재 %d개 들어있음.", nowDataCount);
	}
}

int Pop() {
	if (head == tail && full == false) {
		printf("queue가 비었습니다. pop 불가!\n");
		return -1;
	}
	else {
		int popDataIndex = head;
		head += 1;
		if (head == MAX_LEN) {
			head = 0;
		}
		
		//현재 data 개수를 세기 위한 코드
		int nowDataCount;
		if (tail - head > 0) {
			nowDataCount = tail - head;
		}
		else {
			nowDataCount = tail - head + MAX_LEN;
		}
		printf("queue의 마지막 data를 반환합니다.\n현재 %d 개 들어있음.\n", nowDataCount);
		return Queue[popDataIndex];
	}
}

void Print() {
	if (head == tail && full == false) {
		printf("queue가 비었습니다.\n");
	}
	else {
		//head가 작은 경우 == tail이 index 안 벗어난 경우
		if (head < tail) {
			for (int i = head; i < tail; i++) {
				printf("| Queue[%d] : %d | -> ", i, Queue[i]);
			}
		}
		else {
			for (int i = head; i < tail + MAX_LEN; i++) {
				printf("| Queue[%d] : %d | -> ", i % MAX_LEN, Queue[i % MAX_LEN]);
			}
		}
	}
}


int main() {
	std::string command;
	while(1) {
		printf("\n\n push / pop / print / q(quit) 입력\n");
		std::cin >> command;

		if (!command.compare("push")) {
			int data;
			printf("추가할 데이터 : ");
			std::cin >> data;
			
			Push(data);
		}
		else if (!command.compare("pop")) {
			int popData = Pop();
			printf("pop된 데이터 : %d", popData);
		}
		else if (!command.compare("print")) {
			Print();
		}
		else if (!command.compare("q")) {
			exit(0);
		}
		else {
			printf("???");
		}
	}
}