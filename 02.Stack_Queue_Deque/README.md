Stack, Queue, Deque 구현
---

* .cpp 파일은 gcc로 컴파일 시 뒤에 `-lstdc++` 옵션을 붙여주어야 한다.  
  * `gcc -o Stack Stack.cpp -lstdc++`  

---
Stack
--
* 기능
  > void Push(int data) : 입력받은 data를 stack에 집어넣기  
  > int Pop() : stack의 규칙에 따라 값 하나를 뽑고, 스택에서 삭제하고, 그 값을 return  
  > Print() : stack에 들어있는 모든 값 순서대로 출력  
  
* 구현
  > 배열 Stack[]과, 스택 마지막 index를 가리키는 스택 포인터 StackP를 선언.
  > Push하면 `Stack[StackP] = data; StackP++;`  
  > Pop 하면 `StackP--; return Stack[StackP];`  

* 새롭게 알게 된 점  
  * shell에서 문자열을 입력받기 위해서, C++의 <string> 헤더 사용.  
  * string으로 선언한 변수는 scanf()로는 입력받지 못하고, cin >> var; 으로 받아야 함.
  
Queue
--


* 절댓값 추가 (찾아봤으나 안 씀..)
c++에서 정수 절댓값 abs() 함수는 <cstdlib> 헤더에 있음.
[참고](https://blockdmask.tistory.com/335)

* 원형 큐를 구현하기 위해 사용한 트릭
tail이 head보다 작은 경우 (tail만 index를 넘어감) : tail + MAX_LEN(배열 길이)를 인덱스처럼 사용 (마치 MAX_LEN 길이 배열이 두 개 붙은 크기의 배열처럼.)  
Print()할 때는 다시 (tail + MAX_LEN) % MAX_LEN 사용 (나머지로 원래 index에 접근)  

조금 복잡하게 구현한 것 같다... 더 좋은 방법이 있으려나
	