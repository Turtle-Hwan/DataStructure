#### 더미 트리
```
      10
     /   \
    5     20
  /  \     \
 4    3     15
```



BFS 구현
---
* 큐 사용.


DFS 구현
---
* 스택 사용

* visit 표시를 NODE 구조체 안에.
* stack은 NODE 구조체 포인터를 저장하는 배열.

* `error: invalid conversion from ‘void*’ to ‘NODE*’`
  > 명시적 형변환 필요한 오류 (앞에 (struct NODE*) 추가)
  > https://try2explore.com/questions/12206972
  

** 너무 하드코딩 한 것 같다.. 

* 쉘에 띄어쓰기로 알맞은 depth 만큼씩 tree 출력하기 위해..
  > stack의 스택포인터가 각 노드의 depth 나타내줌 -> 그만큼 반복해서 공백 출력?! -> 실패..
  
```
DFS 원하는 출력 결과..

10 ->  5 ->  4  
         ->  3  
   -> 20  
         -> 15
```
