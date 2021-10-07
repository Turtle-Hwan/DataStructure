구름 IDE를 사용해봤다.  
구름 IDE는 작은 리눅스 서버를 무료로 빌려주고, 그 안에서 프로젝트 생성 + 코드 작성 등이 가능함.

C/C++ 으로 컨테이너를 생성했더니, git과 gcc, g++ 등이 미리 깔려있음.

---
git 연동을 일반적인 방법으로 쉘에서 할 수도 있지만, GUI로도 제공함.

처음 컨테이너 생성 시 SCM에 github을 추가하거나, 
후에 왼쪽 바의 Git 메뉴에서 컨테이너 내부에 생성한(git init) git 폴더를 잡아주면 된다.


---
git push 시 github id / password 입력이 계속 뜨는데, 미리 저장해놓고 안 뜨게 하고 싶었다. => 구름에서 제공하는 git GUI를 이용하면 자동 저장된다고 나오지만, 그래도 계속 뜨는 문제.

* [참고] password 란에는 github password가 아니라, github에서 Personal Access Token을 발급받은 후, 이 토큰값을 입력해 주어야 한다!!

=>  
분명 local git repogitorty 내의 .git 안에 config 파일은 존재하는데, `git config (--global, --local)` 명령어로 쉘에서 볼 수가 없었다...

그리고 `git config credential.password {비밀번호}` 명령어도 작동을 안 했다.

=>  [해결책]  
1. 먼저, `git config credential.helper store` 명령어를 실행한다.

2. .git 폴더 내의 config 파일에 [credential] 란이 생겼는지 확인한다.

3. `git config credential.username {github 아이디}` 명령어를 입력하고, config 파일에 username 항목이 생겼는지 확인한다.

4. `git config credential.Password {personal access token 값}` 명령어를 입력하고, config 파일 확인한다.  

  [주의!] 여기서 password가 아니라 대문자 P 임에 주의.(대문자로 해야 잘 되더라..)

5. `git push` 시 아이디 / 비밀번호 확인 창 없이 잘 되는지 확인!! 끝!!  

---
