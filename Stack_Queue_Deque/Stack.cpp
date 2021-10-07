#include <stdio.h>
#include <iostream>
#include <string>

#define MAX_LEN 10000
int Stack[MAX_LEN];
int StackP = 0;

void Push(int data) {
	if (StackP == MAX_LEN) {
		printf("stack이 꽉 차있습니다.\n");
	}
	else {
		Stack[StackP] = data;
		StackP += 1;
		printf("stack에 데이터를 넣었습니다.\n현재 %d개 들어있음.", StackP);
	}
}

int Pop() {
	if (StackP == 0) {
		printf("스택이 비었습니다.\n");
		return -1;
	}
	else {
		StackP -= 1;
		printf("스택의 마지막 data를 반환합니다.\n현재 %d 개 들어있음.\n", StackP);
		return Stack[StackP];
	}
}

void Print() {
	if (StackP == 0) {
		printf("스택이 비었습니다.\n");
	}
	else {
		for (int i = 0; i < StackP; i++) {
			printf("| Stack[%d] : %d | -> ", i, Stack[i]);
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