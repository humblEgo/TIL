# git의 원리
----

### git의 세 가지 구성요소
 - Working Directory: 작업할 파일이 있는 디렉토리
 - Stageing Area: 커밋을 수행할 파일들이 올라가는 영역
 - Git Directory: git 프로젝트의 메타 데이터와 데이터 정보가 저장되는 디렉토리
 
 ※ Repository: repo라고도 부르며, 소스코드와 커밋 내역 등의 모든 작업 이력이 담겨있는 공간을 의미함. 각종 데이터와 해시 값 등이 담김.
### 동작과정
Working Directory / Staging Area / Local Repository / Remote Repository

수정한 내역을 원격지 저장소에 반영하려면, `git add`(Working Directory --> Staging Area), `git commit`(Staging Area --> Local Repository), `git push`(Local Repository-->Remote Repository)의 과정을 거친다.

원격지 저장소로부터 수정된 내역을 받을 때에는 `git fetch`(Remote Repository->Local Repository)를 수행하고, 컴퓨터에 있는 소스코드를 이와 맞추려면 `git merge`(Local Repository-->Working Directory)를 수행한다. `git pull`은 git fetch와 git merge를 한 번에 사용하는 명령어이다.

