### 파일디스크립터 (출처: https://dev-ahn.tistory.com/m/96)

 - 시스템으로부터 할당 받은 파일을 대표하는 음이 아닌 정수 값
 - 프로세스에서 열린 파일의 목록을 관리하는 테이블의 인덱스
 
유닉스 시스템에서는 모든 객체들(Regular file, directory, socket, pipe, 블록 디바이스, 캐릭터 디바이스 등등)은 파일로써 관리된다. 유닉스 시스템에서 프로세스가 이 파일들을 접근할 때에 파일 디스크립터라는 개념을 이용한다.

프로세스가 실행 중에 파일을 Open 하면 커널은 해당 프로세스의 파일 디스크립터 숫자 중에 사용하지 않는 가장 작은 값을 할당해준다. 
이후 파일 디스크립터 숫자(이하 fd값)를 통해 파일을 지칭할 수 있다. 

프로그램이 프로세스로 메모리에서 실행을 시작할 때, 기본적으로 할당되는 파일 디스크립터가 있다. 
바로 표준 입력, 표준 출력, 표준 에러이며 각각 0, 1, 2라는 정수가 할당된다. 
POSIX 표준에서는 STDIN_FILENO, STDOUT_FILENO, STDERR_FILENO로 참조되며 <unistd.h> 헤더 파일에서 찾아볼 수 있다.
파일 디스크립터는 0 ~ OPEN_MAX 까지의 값을 가질 수 있으며, OPEN_MAX 값은 플랫폼에 따라 다르다.

커널 구조체 중에 struct files_struct에는 struct file fd_array라는 배열이 있는데, 이 구조체 배열의 index가 open을 통해 얻는 파일 디스크립터(fd)이다.

fd로 파일을 제어할 때는, fd번째 원소인 fd_array[fd]는 **'Offset, 동작제어 flag, 접근 모드, i/o 관련 설정, 파일의 inode 객체를 가리키는 레퍼런스'**로 이루어진 `dentry` 구조체 배열인 File table의 원소를 가르키고, 
이 구조체가 가르키는 inode에 접근하는 과정을 거친다. 이 때 dentry는 directory entry를 의미하며 리눅스에서 디렉토리에 접근을 빠르게 하기 위한 구조체로 사용한다고 한다, 

한편 inode는 파일 종류(일반파일, 소켓, fifo)와 권한, lock 목록 포인터, 여러 파일 오퍼레이션과 다양한 파일 속성(크기, 파일스탬프 등)을 가지고 있다.

즉, open 함수로 파일을 호출하면, 해당 파일에 대한 dentry를 생성하고, inode를 생성(또는 읽음) 후에 해당 프로세스의 open 파일 관리 구조체인 files_struct의 fd_array 의 비어있는 위치에 생성한 dentry를 포인팅하고 그 index를 반환하게 되는 것이다.

fd로 파일에 접근해서 여러번 read하면, 이전에 읽은 byte부터 이어서 파일을 읽는게 신기했는데, 앞선 read 과정에서 fd_array[fd]안에 있는 offset이 변경되었기 때문인 것을 알게 되었다.
