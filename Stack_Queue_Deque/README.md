Stack, Queue, Deque 구현
---

Stack 구현
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
  * shell에서 문자열을 입력받기 위해서, C++의 <string> 라이브러리 사용.  
  * string으로 선언한 변수는 scanf()로는 입력받지 못하고, cin >> var; 으로 받아야 함.
	