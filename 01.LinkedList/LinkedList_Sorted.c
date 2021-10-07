#include <stdio.h>
#include <stdlib.h>

struct NODE {
	int data;
	struct NODE *next;
};
struct NODE *headP;	//더미 head 노드 전역 변수로 선언 : Search 시작점으로 사용하기 위해.


void Create_Sorted(int inputData) //새 노드 생성 및 맨 마지막에 연결
{
	struct NODE *newNode = malloc(sizeof(struct NODE));
	newNode->data = inputData;
	newNode->next = NULL;
	
	struct NODE *searchNode = headP;	//탐색하기 위한 노드 생성
	while (1) { 
		if (searchNode->next == NULL) {	//마지막에 노드를 붙이게 될 때.
			searchNode->next = newNode;
			break;
		}
		else if (searchNode->next->data >= inputData) {	//다음 노드의 데이터가 더 크다면, 현재 노드와 다음 노드 사이에 넣어야 함.
			newNode->next = searchNode->next;
			searchNode->next = newNode;
			break;
		}
		else {
			searchNode = searchNode->next;	//NULL을 찾을 때까지 이동
		}
	}	
	printf("새 노드를 연결하였습니다.");
}

int Search(int inputData) //원하는 inputData 값이 있으면 1 반환 | 없으면 0 반환
{
	//처음부터 끝까지 포인터 따라서 이동하며 탐색 후, 있으면 변수에 1 대입
	int exist = 0;	
	int idx = 1;
	
	struct NODE *searchNode = headP;	//탐색하기 위한 노드 생성
	while (1) { 
		if (searchNode->data == inputData) {	//data 비교
			exist = 1;
			break;
		}
		else if (searchNode->next == NULL) {	//만약 다음 주소가 없다면(NULL), 종료
			break;
		}
		else {
			searchNode = searchNode->next;	//다음 주소가 있다면, 다음 주소로 이동
			idx += 1;
		}
	}
	
	
	if (exist) {
		printf("%d 번째 노드에 %d 값이 존재합니다.", idx, inputData);
		return 1;
	}
	else {
		printf("%d 값을 찾을 수 없습니다.", inputData);
		return 0;
	}
}


int Delete(int inputData) //원하는 inputData 값이 있으면 삭제하고 1 반환 | 없으면 삭제 안되고 0 반환
{
	
	//inputData 존재 여부 : exist
	int exist = 0;
	int idx = 1;
	
	struct NODE *searchNode = headP;	//탐색하기 위한 노드 생성
	while (1) { 

		if (searchNode->next == NULL) {	//만약 다음 주소가 없다면(NULL), 종료
			break;
		}
		else if (searchNode->next->data == inputData) {	//data 비교		
			//해당 노드(searchNode 다음 노드) 삭제
			free(searchNode->next);
			searchNode->next = searchNode->next->next;
			exist = 1;
			break;
		}
		else {
			searchNode = searchNode->next;	//다음 주소가 있다면, 다음 주소로 이동
			idx += 1;
		}
	}
	
	if (exist) {
		//노드 삭제 코드
		
		printf("%d 번째 노드인 %d 가 Delete 되었습니다!", idx, inputData);
		return 1;
	}
	else {
		printf("원하는 값이 없어서 Delete 불가!");
		return 0;
	}
}

void Print() // 들어 있는 모든 값 console에 출력
{
	struct NODE *searchNode = headP;	//탐색하기 위한 노드 생성
	while (1) { 
		printf("%d | -> | ", searchNode->data);
		if (searchNode->next == NULL) {	//만약 다음 주소가 없다면(NULL), 종료
			printf("NULL (이전 값이 마지막 노드 입니다.)");
			break;
		}
		else {
			searchNode = searchNode->next;	//다음 주소가 있다면, 다음 주소로 이동
		}
	}
}


void main() {
	headP = malloc(sizeof(struct NODE));
	headP->data = -100000;
	headP->next = NULL;
	
	char command;
	
	while(1) {
		printf("\n\nc(create) / d(delete) / s(search) / p(print) / q(quit) 입력\n");
		scanf(" %c", &command);

		if (command == 'c') {
			int data;
			printf("추가할 데이터\n");
			scanf("%d", &data);
			
			Create_Sorted(data);
		}
		else if (command == 'd') {
			int data;
			printf("삭제할 데이터\n");
			scanf("%d", &data);
			
			Delete(data);
		}
		else if (command == 's') {
			int data;
			printf("찾을 데이터\n");
			scanf("%d", &data);

			Search(data);
		}
		else if (command == 'p') {
			Print();
		}
		else if (command == 'q') {
			exit(0);
		}
		else {
			printf("???");
		}
		//printf("%c", command);
	}

}