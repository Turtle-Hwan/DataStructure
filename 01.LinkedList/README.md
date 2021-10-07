LinkedList 구현
---

* 기능  
  > Create : 입력한 값이 든 새 노드 생성 및 맨 마지막에 연결  
  > Search : 원하는 data 값 찾기 (return 0/1)  
  > Delete : 원하는 data 값 삭제  
  > Print : 들어 있는 모든 값 출력  

* [추가 구현]  
  LinkedList_Sorted : 노드가 추가, 삭제될 때 항상 정렬된 상태를 유지하는 LinkedList  
  > Create_Sorted : 입력한 값이 든 새 노드 생성 및 정렬된 알맞은 위치에 연결  


* 새롭게 알게 된 점  
  * C에서 구조체 포인터 변수 내부의 값에 접근할 때, `(*struct).data | struct->data` 이렇게 쓰는데, data도 구조체를 나타내는 포인터 변수일 경우, `struct->data->data` 로 써도 문제없이 작동한다는 것을 알게 되었다!!
  * 동적 할당 시 size를 주는 이유는 딱 구조체에 사용될 만큼의 메모리를 할당하기 위해서이다. (sizeof(struct))