BFS 구현
---



DFS 구현
---
* visit 표시를 NODE 구조체 안에.
* stack은 NODE 구조체 포인터를 저장하는 배열.

* `error: invalid conversion from ‘void*’ to ‘NODE*’`
  > 명시적 형변환 필요한 오류 (앞에 (struct NODE*) 추가)
  > https://try2explore.com/questions/12206972
  

** 너무 하드코딩 한 것 같다.. 문제가 뭘까..

* 쉘에 띄어쓰기로 알맞은 depth 만큼씩 tree 출력하기 위해..
  > stack의 스택포인터가 각 노드의 depth 나타내줌 -> 그만큼 반복해서 공백 출력?!