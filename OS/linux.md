### 리눅스 도움말 보는 법


**위치**
 - .   : 현재 디렉토리
 - ..  : 부모 디렉토리
 - /   : 최상위 root 디렉토리
 - ~   : Home 디렉토리

명령어 'echo $PATH'를 입력했을 때 안에 포함되어 있는 것은 바로 실행할 수 있다. 
아니라면 경로를 일일이 입려해줘야 실행할 수 있다.


**리눅스 도움말 형식**
 - 명령어   [option]    ... 
 - []   ▶ 생략가능
 - ...  ▶ 중복허용

**도움말 호출**
 - man  명령어 
 - info  명령어
 - 명령어  --help

**파일 다루기**

리눅스는 모든 것을 파일로 간주한다. 따라서 디렉토리도 파일로 간주한다.
 - 생성  ▶  mkdir, vi, cat, touch
 - 복사  ▶  cp
 - 삭제  ▶  rm 
 - 이동  ▶  mv
 - 이름바꾸기 ▶  rename
 
 자주 쓰이는 옵션 3가지
 - '-r': recursive, 하위 디렉터리 포함이라는 의미
 - '-i': interactive, 대화형 모드(뭔가 하기 전에 물어보게끔 하는 것)
 - '-f': force, 강제
 
 
 **파일 분류하기**
  - 일반
    - text: 우리가 읽을 수 있는 파일
    - binary: 컴퓨터가 읽어서 실행하는 파일
  - 특수
    - directory
    - 장치(device)
      - block: 저장장치(HDD, CDR..)
      - char: 키보드 등..
 
 - 일반파일
 d 디렉터리
 l 심볼릭 링크
 c character
 b block
 s socket
 p named pipe
      
      
 
 Link file
   - Hard link: c++언어의 레퍼런스 변수와 같은 개념(a 파일의 다른 이름을 b라고도 칭한다.)
   - Soft link(Symbolic link): c++언어의 포인터 변수와 같은 개념 (a 파일의 주소를 c라고 한다.)
 
----

### 홈 디렉토리




shell: 명령어 해석기! user와 kunnel을 이어주는 역할을 한다.
리눅스에서는 default로 bash shell을 제일 많이 씀.

키면 최초에 아래 순서대로 구동된다.
 1. ~/.bash_profile : 설정 파일
 2. ~/.bashrc : alias 등 설정은 이 파일로 함.
 3. /etc/bashrc : 모든 사용자에게 적용되는 파일, root만 설정할 수 있는 고유권한이다.


----

명령어
 tr '변경대상 문자' '수정내용'
 sed 's/변경대상 문자/수정내용/g' : g는 여러라인으로 들어오는 모든 stdin값에 대해 적용시키는 옵션
 awk '"조건" {실행}'




----
 
 ### vi 에디터
 
 vi 에디터 기본 모드(esc 키 눌러서 진입)
  - 명령모드: 입력모드에서 명령모드로 가려면 esc누르면 됨.
  - 실행모드: 명령모드에서 콜론(:)을 찍고 명령을 내린다.
  - 입력모드: i, a, o 누르면 명령모드에서 입력모드로 이어짐.
 
 실행모드 명령
 :w 저장
 :q 종료
 :wq 저장 후 종료
 :!wq 강제 저장 후 종료
 :w 다른이름 다른 이름으로 저장
 
 dd 라인 단위로 잘라내기
 yy 라인 단위로 복사하기
 dw 문자 단위로 잘라내기
 yw 문자 단위로 복사하기
 p 붙여넣기
 x 삭제하기
 
 상 k
 하 j
 좌 h
 우 l
 
 ----
 [ubuntu에서 valgrind로 memory leak 검사하기](https://rosagigantea.tistory.com/488)
 
 
 
 
 
 
