## C언어에 대해 알게된 내용 기록

목차
 - [자료형](#자료형)
 - [표준 입/출력 도구](#표준-입출력-도구)
 - [연산자](#연산자)
 - [배열](#배열)
 - [함수](#함수)
 - [포인터](#포인터)
 - [함수 응용](#함수-응용)
 - [구조체와 공용체](#구조체와-공용체)
 - [전처리기](#전처리기)
 - [파일입출력](#파일입출력)
 - [함수에 대한 고급 이론](#함수에-대한-고급-이론)
 - [라이브러리 정리용](#라이브러리-정리용)


----
### 자료형
 - 정의: **일정 크기(길이)의 메모리**에 저장된 정보를 **해석하는 방법**
   - 자료형의 유무가 B언어와 C언어간의 승패를 갈랐다고 합니다.
   - 자료형이 붙으면 컴파일러는 자료형에 해당하는 데이터를 저장할 공간을 할당하게 된다.
   - 할당된 공간에는 쓰레기값이 들어가 있으므로, 원치않은 동작을 방지하기 위해 가능하면 초기화하고 사용하자.
   
 - size_t란?
   - size_t는 부호 없는 정수형(unsigned integer)으로 sizeof, alignof, offsetof의 return 값이다. *unsigned int 타입이 아니다!*
   - 이론상 해당 시스템에서 어떤 값 객체가 차지할 수 있는 이론적인 최대 크기를 표현하는 자료형이다. 즉, 32bit, 64bit 등 시스템에 따라 각각 '부호없는 32bit 정수' 크기를 가지거나 '부호없는 64bit 정수' 크기를 가지는 식으로 크기가 변화한다. *이 점이 unsigned int와 다르다, unsigned int는 64bit OS라고해서 꼭 64bit 정수는 아닐 수 있다.*
   - 1바이트로 만들 수 있는 최대 크기의 array라든지, 하나의 값이 가질 수 있는 최대의 크기를 범위로 하는 값을 다룰 때 필요하다.
   - c에서는 stddef.h / stdio.h / stdlib.h / string.h / time.h / uchar.h / wcahr.h에 정의되어있다.


#### 상수의 종류
 - 리터럴 상수
   - 문자 상수: 영문자나 특수문자를 기술한 상수
   - 문자열 상수: 문자 상수들의 연속된 집합체를 표현한 상수. 다른  상수들과 달리 여러 개가 한 덩어리를 이룬 배열이며 '주소'로 식별될 수 있음.
   - 정수 상수
   - 실수 상수
 - 심볼릭 상수
   - 형한정: const 형한정어를 이용해 선언 및 정의되는 상수
   - 전처리기: #define 전처리기로 선언 및 정의되는 상수
   
 
 #### 보수를 이용한 뺄셈 연산과정
  - 8비트의 표현 범위를 이용하여, 보수를 더하는 방식으로 감산함.
  EX) 4에서 2를 뺄 경우, 00000100<sub>(2)</sub> 에 2의 '2의 보수'인 11111110<sub>(2)</sub>를 더한다. '2의 보수'는 보수를 구하려고 하는 정수를 각 자리수를 0은 1로, 1은 0으로 바꾸어 '1의 보수'를 구하고, 1을 더하여 구한다.
 
 
#### 부동소수점
실수형식은 근본적으로 근사값 처리로 인한 **오차**를 가지고 있다.
 - float: 32비트 단정도 형식, **유효 자릿수는 소수점 이하 6자리**, 정확도가 떨어지므로 메모리 이슈 없으면 웬만하면 실수표현할 때 double쓰는게 나음. 
 - double: 64비트 배정도 형식 **유효 자릿수는 소수점 이하 15자리**
 - long double: 특수정도 형식, 지원 안하는 컴파일러가 많음. 정확성이 많이 요구될 때, 80비트로 구현됨.
 
 
#### 문자열
문자열의 본질은 배열이다. 즉, 문자열 == (상수화된) 문자(배)열.
 - 초기화하면 마지막 null 값까지 포함하여 메모리에 저장된다.--> 문자열 크기를 12로 선언했으면, 11개까지 써야한다. 만약 12개를 넘기면 Buffer Overflow 문제가 발생하고, 프로그램 Crash가 나면 Buffer Overrun 문제가 발생할 수 있다. 이를 막기 위해 **'경계검사'**를 꼭 해야한다.

한편 `char str[] = "Hello";` 이나 `char *str = "hello";`로 문자열을 생성할 수 있으나, 전자는 문자열 값을 수정할 수 있지만, 후자는 문자열 값을 수정이 불가하며 **string literal**이라고 따로 부르는 명칭이 있다는 점에서 차이가 있다. 

#### 메모리에 대한 기본 이론
 1. 32비트 플랫폼에서 주소의 길이는 32비트이며, 16진수로 표시한다. 그리고 주소의 범위는 0x00000000번지부터 0xFFFFFFFF번지까지이며, 모두 연이어져 있는 선형 메모리이다.
 2. 자료형은 일정 크기의 메모리를 해석하는 방법이고, 변수는 해서갛ㄹ 대상 메모리에 붙인 이름이다.
 3. 0번지~64kb 영역의 메모리는 운영체제가 사용하고 있다.
 4. 스택이든, 힙이든, 실행 코드 영역이든 모두 선형 메모리 위에 일렬로 존재한다.

#### C언어 코딩 컨벤션
헝가리안 표기법은 찾아보니 구시대의 유물이라는 의견이 많은듯 하여, [링크 블로그를 참고하여 개발할 예정](https://tttsss77.tistory.com/64)

----
### 표준 입출력 도구

 - 특기할 내용
   - 레이어별로 하드웨어(H/W), 커널(Kernel), 유저(User)로 나누었을 때, 입출력은 항상 **커널에서** 이루어진다.
   - 커널<-->하드웨어간에는 '드라이버'로, 유저<-->커널간에는 유저모드에서 접근할 수 있도록 추상화된 'File'로 정보를 주고 받는다. 이 때 정보는 규칙(Protocol)에 입각하여 작성된다.
   ex) 커널의 프로토콜인터페이스와 정보를 주고받는 파일은 'Socket'이다
   - Buffer는 Memory이며, 미리 자료를 복사 받아서 자료를 주고받는 것이 끊기는 등의 충격을 완화하는 역할을 한다. 만약 버퍼를 거치지 않는 경우 DMA를 한다고하며 버퍼를 통하는 것보다 빠르다. 참고로 getchar()나 scanf(), gets() 같은 함수는 Buffered I/O를 한다. 각각 정보를 가져온다는 점에서 동일하고, getchar()는 한글자씩, gets()는 한줄씩, scanf()는 내용을 출력타입에 맞게 변환하여 가져오는 차이가 있다. 단, gets()는 심각한 보안결함이 있어서, gets_S()를 써야한다.

   - 입력가변 길이 처리할 경우, UI단계에서 길이 제한을 하거나 연결리스트 등 가변가능한 자료구조를 써서 대응하는게 좋음. 

----
### 연산자

#### 연산의 우선순위
 - 식이 있을 때, 연산 우선순위에 따라 먼저 계산되는 값은 임시저장 된다(메모리에 저장된다) 이후 계산이 진행되며 값이 구해지면 임시저장된 값은 삭제된다. 즉, 당연하지만 필요하다면 유실전에 따로 저장해야한다.

#### 단순대입
<pre>
int a;
a = 10;
</pre>
위와 같은 코드가 있다면, a는 l-value(left + location value)이고, 10은 r-value(right value)이다. l-value에는 원래 쓰레기값이 있고, 이후 r-value가 copy & overwrite가 진행된다.

#### 이형자료 간의 연산 및 형승격
'표현 범위'가 큰 형식을 따라간다. 즉, `printf("%f",5/2)` 요런 코드를 소수점 아래까지 표시하려면, 5나 2 중 하나를 double로 형변환 해줘야한다.
 

#### Sizeof() 연산자
sizeof(자료형)으로 쓰고, CPU가 아닌 **컴파일러**가 수행하는 연산이다. 따라서, 많이 이용한다고 해도 CPU의 부하가 증가하지 않는다(성능에 영향을 주지 않는다). 단, 컴파일러마다 크기가 달라지는 자료형도 있어서 값이 달라질 수 있다.

#### 실수의 연산
결론부터 말하자면 실수는 **상등이나 부등 연산을 수행하면 안된다.** 부동소수점의 근사처리로 인한 오차가 이슈가 되어 상등이 아닌데 상등이라고 나오거나 부등이 아닌데 부등이라고 나오는 경우가 왕왕생긴다. 대신 비교연산은 수행해도 된다.

--> 이런 특성은 switch case 구문 작성시 case 다음에 실수가 아니라 정수를 적는 것으로 이어진다. case 구문 내에서 상등연산이 이뤄지는데, 실수는 상등연산시 오류가 발생할 수 있기 때문이다.

#### if문 관리
다중 if문의 경우, 경우에 따라 논리적으로 단순명쾌할 수 있지만 불필요한 연산이 수행된다는 점에서 성능하락 이슈가 있다. 따라서 결과값을 내기까지 판단해야하는 조건을 최소화하는 것이 성능향상에 좋으며, 그런 의미에서 다중 if문과 머신차원에서 거의 동일한 연산이 수행되는 switch-case도 가급적 없애는게 좋다. 왠만하면 2분할 방식으로 논리구조를 짜고, 고성능을 요하는 상황에서는 lookup-table을 이용하는 것도 고려하자.

#### goto문 관리
goto문은 스파게티 코드를 만드는 주범으로 사용이 지양되고 있지만, error 처리할 때는 쓰이곤 한다.

#### continue문 관리
소스코드 정적분석 했을 때, knot이 늘어나서 코드가 복잡해지므로, 가급적 쓰지 않는 것이 좋음.

----
### 배열
배열은 여러 인스턴스가 모여 한 덩어리를 이룬 것이다. 

#### 배열의 이름
배열의 이름은 그 자체로 주소를 뜻하며 정의하자면 **여러 요소를 대표하는 첫 번째 요소의 메모리 주소에 부여하는 식별자**이다. 즉, 0번째의 메모리 주소에 이름을 넣기 마련이다. 
한편 문자열의 경우, (상수화된)문자(배)열 이므로 본질은 배열인데 이름이 없다. 때문에 문자열은 이름이 아닌 주소로 식별하게 되어있다. 
배열은 여러 인스턴스가 모여 한 덩어리를 이룬 것이므로, 배열의 이름(식별자)이 하나라고 한개의 변수 다루듯 다루면 에러가 나게 쉽다.

#### 문자열의 성격
문자열은 '가변'길이가 되는 경우가 많고, 배열은 기본적으로 '고정'길이이다. 문자열의 가장 마지막 단어 이후엔 null 이 들어가서 '사용된 영역'과 '사용되지 않은 영역'간의 구분자가 되어준다.

#### 다차원 배열
배열의 배열을 뜻하며, 메모리의 실제모습과 상관없이 논리구조가 2차원 혹은 3차원인 배열을 뜻한다. 즉, ㅈ료의 접근방법에 한정되는 것이다.

예를 들어 `char aData[3][4]`면 논리적으로 따지면 aData 이름의 배열이 3행 4열 형태로 있다고 말할 수 있다. 물론 컴퓨터의 메모리는 1차원적으로 되어있으므로, 엄밀히 따지자면 char[4] 배열을 요소로 3개 가지고 있는 배열의 구조로 되어있다. 때문에 인덱스를 `aData[0][4]`처럼 범위를 넘게 입력하면, `aData[0][0]`을 기준으로 4인덱스 만큼 떨어져 있는 'aData[1][0]'을 참조하는 오류가 발생한다.

----
### 함수
무엇을 함수로 만들 것인가? 아래 대원칙에 따라 만드는게 보통임.
 - UI와 내부기능을 분리한다.
   - 웬만하면 입력값 유효성 검사는 입력단에서 처리하는 것이 효율성 측면에서 좋음.
 - 하나의 단위기능으로 규정할 수 있는 대상은 함수로 만든다.
 
함수 이름은 그 함수에 대한 포인터라고 생각해도 무방하다.

----
### 포인터
변수의 본질은 메모리이며 모든 메모리는 자신의 위치를 식별하기 위한 근거로 고유번호(일련번호)를 갖는데, 이 번호를 메모리의 주소라 한다. 한편, 이 때 말하는 메모리는 Virtual Memory(가상메모리)이다.

윈도우의 경우, 윈도우7부터는 메모리해킹을 방지하기 위해 ASLR(Address Space Layout Randomization)이 지원된다.

#### 함수가 여러개로 나뉘었을 때 배열 등을 다른 함수로 전달
지역변수로 선언된 배열을 매개변수로 가져갈 수 있도록 하기 위해 매개변수에 해당 배열 포인터형을 입력할 수 있다. 배열의 이름이 주소이므로, 포인터 변수에 저장할 수 있는 것이다.

#### 메모리의 종류
메모리는 **용도**에 따라 아래와 같이 나누어진다. 
 - Stack: 자동변수이고 지역변수인 변수가 사용하는 메모리 영역이며, 임시 메모리의 성격을 가진다. 크기가 작고(최대 1MB 수준) 관리(할당 및 반환)가 자동으로 이루어지는 장점이 있다.
 - Heap: 동적 할당할 수 있는 자유 메모리 영역이며, 개발자가 직접 수동관리해야한다. 32비트 응용프로그램의 경우, 대략 1.xGB 정도를 사용할 수 있다. 따라서 대량의 메모리가 필요하거나 필요한 메모리의 크기를 미리 알 수 없을 때 사용한다.
 - PE image(실행파일)
   - Text Section: C언어의 소스코드가 번역된 기계어가 저장된 메모리 영역이다. 기본적으로 읽기전용 메모리이며, 변조될 경우 해킹이다.
   - Data Section
     - Read Only: 상수 형태로 기술하는 문자열이 저장된 메모리 영역이며, 읽기는 가능하지만 쓰기는 허용되지 않는다.
     - Read/Write: 정적변수나 전역변수들이 사용하는 메모리 영역이며, 별도로 초기화 하지 않아도 0으로 초기화된다. 관리는 자동이라서 힙 영역 메모리처럼 할당 및 해제를 신경 쓸 필요는 없다.
     
#### 메모리 동적할당 및 관리
메모리는 OS가 관리하는데, Heap영역을 통해 동적할당할 경우 OS에 요청한 용량만큼을 **허가**해준다. 이후 **반환의 의무**가 따른다. 할당은 받았으나 반환하지 않은 메모리는 사용할 수 없다. 즉, 메모리가 사용할 수 없는 상태가 되는 경우 메모리 누수(memory leak) 오류로 이어진다.

아래 함수를 통해 메모리 동적 할당 및 해제한다. 
malloc(), calloc() 쓸 때는 `<stdlib.h>`헤더를, memset()함수 쓸 때는 `<string.h>`헤더를 include할 것.
 - `void *malloc(size_t size);`
   - 인자: size 할당 받을 메모리의 바이트 단위 크기(byte 단위)
   - 반환값: 힙 영역에 할당된 메모리 덩어리 중 첫 번째 바이트 메모리의 주소, 에러가 발생하면 Null 반환
   - 설명: 할당 받은 메모리의 시작주소를 반환한다. 반드시 free()함수를 이용하여 반환해야 하며, 메모리를 초기화하려면 memset()함수를 이용해야 한다. 
 - `void free(void *memblock);`
   - 인자: memblock 반환할 메모리의 주소
   - 반환값: 없음
   - 설명: 동적으로 할당받은 메모리를 운영체제에 반환하는 함수
   
메모리 동적할당시에는 여러 오류가 발생할 수 있고, 해킹의 빌미를 제공할 수 있다; [이 링크](https://bpsecblog.wordpress.com/2016/10/06/heap_vuln/)를 참고할 것.

#### 메모리 복사
배열의 이름은 식별자이지만 변수가 아니라 '주소상수'에 부여된 식별자이므로 l-value가 되지 못한다. 

단순히 주소만 복사하는 경우(Shallow copy)와 내용을 복사하는 경우(Deep copy)를 혼동하면 안된다.
 - 주소만 복사하는 경우: a배열에 동적할당 후 b배열을 shallow copy하는 경우엔, 스택 메모리가 깨지고, 후에 free()함수를 a배열에 대해 쓰더라도 b배열 주소에 대해서 free() 함수가 적용되므로 결과적으로 메모리누수까지 생긴다.
 - 내용을 복하는 경우: 행렬값을 다른 이름의 행렬에 복사해서 넣으려면 각 배열의 요소만큼 반복문을 수행하여 요소별로 일일이 단순 대입 연산을 수행해줘야 한다. 그러나 memcpy()함수를 이용하면 귀찮은 반복을 함수가 대신해준다.
 
#### 포인터의 배열과 다중 포인터
포인터도  변수이고, 모든 변수는 주소를 가졌다. 다중 포인터는 포인터가 포인터 변수를 가리킬 경우이다. 다중 포인터가 등장하는 흔한 이유는 '포인터의 배열' 때문이다. 가령 char* 포인터의 배열은 논리적으로 보자면 1차원 구조의 자료형 두 종류(포인터 배열과 문자 배열)이 묶여서 논리적인 2차원 구조가 만들어진다.

#### 다차원 배열에 대한 포인터
예를 들어서 **char[3][16] 배열은 char[16]가 요소이고 개수가 3인 배열**이다. 이 배열의 식별자인 주소를 담을 수 있는 포인터 변수는 `char[16]*`이라고 할 수 있지만, 이대로 쓰면 문법 오류이다. `char(*변수이름)[12]`와 같이 써야한다. 영상처리시 자주 사용할 예정.


#### 변수와 메모리
변수의 본질은 메모리이고, 주기억장치 메모리를 의미한다. 그 중 우리가 쓰는 메모리는 **스택, 힙, 텍스트, 데이터 영역의 메모리**이다. 지역변수는 스택 영역이며, 관리가 자동으로 이루어진다. 원래 변수를 선언할 때는 어떤 메모리를 쓸 것인지 명시해야하는데, **아무런 언급이 없는 지역변수는 컴파일러가 알아서 모두 자동변수로 처리**한다. 메모리 종류는 기억부류(storage-class)라고 하며, 변수를 선언할 때 자료형 앞에 기억부류를 명시하는 예약어를 기억부류 지정자(storage-class specifier)라고 한다.

C언어의 기억부류 지정자로 기술할 수 있는 예약어는 extern, auto, static, register 등이 있는데, 각각 외부, 자동, 정적, 레지스터라고 부른다.

#### static storage-class specifier
전역변수 혹은 정적변수가 사용하는 데이터 영역 메모리는 프로그램이 시작될 때 확보되어 종료될 때까지 그대로 유지된다. 때문에 기술적으로 전역변수나 정적변수는 모두 동시성(concurrency)를 지원하기 어렵다는 문제가 있다. 멀티쓰레드로 돌려도 성능향상이 되지 않는 이슈가 생길 수 있다는 것.

#### register storage-class specifier
주기억장치 성능이 좋지 않던 시절에 속도위해 쓰던 건데, 임베디드할거 아니면 크게 쓸 일 없다. 다만, 레지스터 변수는 CPU의 일부이므로 별도로 주소가 없다. 즉, 일반 메모리와 달리 주소가 아니라 고유명사로 식별된다는 것이다. 때문에 레지스터 변수에 대해서는 일반 변수처럼 주소연산을 수행할 수 없다.

----
### 함수 응용

#### Call by address vs Call by reference
피호출 함수가 호출 함수의 변수에 영향을 미치는 경우를 주로 call by reference라고 하곤 한다. 그러나 엄밀히 말하면 C언어에는 call by reference가 없고, call by address만 있으며 call by address도 뜯어보면 call by value를 이용한 것이라고 할 수 있다.

call by address는 피호출 함수에 호출 함수에 포함된 실질 매개변수(임의로 a라고 가정)의 주소를 **복사**해서 형식 매개변수(임의로 b라고 가정)로 넘겨주고, 피호출함수에서는 b로 전달받은 a의 주소로 접근하여 값을 변경하는 식으로 작동한다. 즉, 피호출 함수에서 호출 함수의 변수를 변경한 것은 맞으나, 이 또한 값을 **복사**한 매개변수(여기선 주소값)를 함수에 넘겨준 것이기 때문에 call by value를 사용한 것이다. 이 과정에서 실질 매개변수와 형식 매개변수 두 값에 대해 메모리를 따로 사용한다.

반면 call by reference는 변수를 추가로 사용하여 메모리를 사용하지 않고, C++의 기능 중 하나인 '참조자 &'라는 것을 이용하여 오직 실질 매개변수만으로 호출한다.

#### 재귀함수 장단점
 - 장점: 함수가 함수를 호출하는 과정에 이미 스택 프레임이 존재하므로, 별도로 구현하지 않고 이를 활용할 수 있다. 비선형 자료구조인 트리를 다룰 때 잘 활용된다.
 - 단점: 스택에는 자동변수나 매개변수 말고도 스택 프레임을 관리하기 위한 여러 정보들이 포함되며, 함수호출에 의해 프로그램의 흐름도 변경되고, 매개변수를 복사하는 연산도 수행해야하므로 반복문에 비해 훨씬 더 많은 연산이 수행된다. 또한, 중단점을 잘못 설정하면 1MB 정도에 불과한 스택 메모리를 순식간에 대량으로 소모할 가능성이 높다.

#### 유니코드 문자열
C언어에서 문자열은 1) MBCS(Multi-bytes Charater Sets) 문자열과 2) 유니코드(UNICODE) 문자열 두 종류로 나누어진다. MBCS와 달리 유니코드는 영문, 한글에 상관없이 필요한 메모리의 크기가 '(문자열의 길이 + 1)\*sizeof(wchar_t)'로 통일된다. 유니코드 사용시에는 유니코드 문자열 전용함수를 사용해서 처리한다.

#### 유틸리티 함수
자주 쓸 것 같은 함수인데, 우선 적어둔다.
 - atoi() 함수: 정수 문자열을 실제 정수로 변환하는 함수
 - atol() 함수: long형 숫자 문자열을 실제 long 숫자로 변환하는 함수
 - atof() 함수: 실수 문자열을 실제 실수로 변환하는 함수

----
### 구조체와 공용체
구조체는 **서로 같거나 다른 형식들의 연속된 '집합체'**이다. 또한 사용자가 구조를 설계한 자료형이므로, 메모리를 해석하는 방법이라고 볼 수 있다.
공용체는 **한 형식에 여러 해석방법을 부여하는 문법**이다.
참고로 배열은 동일 형식(자료형)의 연속(연접)된 '집합체'이다.

아래는 기억해둘 팁들
 - 구조체는 자료형도 되므로, 구조체 변수를 배열로 선언할 수도 있다.
 - 구조체 변수를 매개변수나 반환 자료형식으로 사용할 수 있으나, 복사해야할 정보의 양이 기본 자료형에 비해 크기 때문에 비효율적이다. 따라서 구조체가 매개변수나 반환형이 될 때는 Call by address 형식으로 처리하는 것이 효율성 측면에서 바람직하다. 
 
#### 구조체 멤버 맞춤
각 요소가 연접해있는 배열과 달리 구조체는 연접할 수도 있고, 그렇지 않을 수도 있다. 즉 두 멤버 사이에 일정 크기의 공백이 껴들어 갈 수 있다. 이는 구조체 멤버 맞춤 때문이다. 혹시 두 멤버간에 위치가 1바이트로 맞춰져야하는 상황이라면, Visual Studio 설정상에서 1로 값을 바꾸거나, `#pragrma pack` 전처리기를 이용해서 특정 구조체만 멤버를 1바이트 멤버 맞춤하도록 바꿀 수 있다.

#### 비트필드
비트필드는 구조체 멤버가 바이트 단위가 아닌 비트 단위 데이터를 다루는 멤버로 선언되는 구조체이다. 이를 통해 8비트 정보를 쉽게 원하는 크기만큼 잘라서 사용할 수 있다. 임베디드할 때 쓰인다고함.

----
### 변수와 상수 고급이론

#### 형한정어
형한정어는 const, volatile가 있다.(분류상 typedef도 포함되긴 한다.) 변수에 비해 상수가 코드 복잡도가 낮아질 가능성이 높다.
한편 volatile의 경우, 이를 적용해서 변수를 선언하면, 변수와 관련된 모든 연산에 대해 컴파일러가 '최적화'규칙을 적용하지 않는다. 

#### extern 외부변수 선언
작성할 때 원형 선언과 정의를 분리할 수 있는 것처럼, 변수도 외부변수 선언과 정의로 구분할 수 있다. 외부변수라는 말의 의미는 변수의 정의가 현재 파일이 아니라 다른 파일(외부파일)에 존재한다는 의미이다. 따라서 일단 obj로 컴파일 과정에서는 변수 선언만 있어도 다른 obj 파일에 정의가 있을거라 가정하고 오류 없이 처리되지만, 링크 과정에서 다른 외부 obj 파일에서 실체를 찾지 못하면 링크 오류가 반환된다.

#### 형식 재선언
생산성을 위해 쓰일 수 있으나, 구조체나 열거형 상수와 연계해서 형식 재선언이 필요한 경우가 있으나, 혼란을 막기위해 특히나 기본 형식을 재선언하는 일은 사용을 자제하는 것이 좋다.

#### 열거형 상수
열거형 상수는 #define 전처리기처럼 심볼릭 상수를 정의하는 것과 같다. 하지만 하나가 아니라 **여러 개의 심볼릭 상수를 한꺼번에 정의**하고 구조체처럼 새로운 **사용자 정의 자료형**으로 활용하는 것도 가능하다. switch-case문 등을 이용할 때, 이해가 쉽도록 상수를 지정하는 식으로 활용할 수 있다.


----
### 전처리기
컴파일러가 소스코드를 컴파일하기에 앞서 선행 처리하는 구문이다. 이는 코드를 '변형'하는 역할을 한다는 것을 뜻한다.

#### 매크로
함수가 스택을 너무 잡아먹는 등의 성능이슈가 있어서 보완하기 위해 매크로가 고안되었다. 매크로는 외형상으로는 함수의 모습을 하고 있으나, **실제로는 함수가 아니라 한 행 혹은 여러 행으로 기술할 수 있는 구문(혹은 항)**이다. 함수를 call하는 과정없이 매크로 설정값을 바로 push한다는 점에서 효율성을 높일 수 있다.

하지만 매크로는 함수가 아닌데 함수인 것처럼 보이며, 매개변수의 자료형이 없다는 큰 단점이 있어서 예기치 못한 오류가 발생할 가능성이 크므로, 가능하면 최대한 매크로를 자제하고 `__inline` 함수를 이용하되 매크로를 이용해야만 하는 상황에만 매크로를 이용하는 것이 바람직하다. 물론 설정상으로 `__inline` 함수 확장 기능을 설정해두면 컴파일러가 적용가능한 함수에는 자동으로 `__inline`함수를 적용해버린다.

#### 매크로 특수화 연산자 \#, \##
\#은 인수가 무엇이든 '문자열'로 만들어주는 연산자이다. \##은 두 매개변수를 한 덩어리로 묶어 코드를 만들어 주는 연산자이다. 코드 자동화 구현할 때 도움될 듯.


----
### 함수에 대한 고급 이론
함수의 이름도 주소상수에 부여한 식별자이다. 성능 향상을 위해서는 메모리를 덜 쓰면 된다. 

최적화의 주체는 컴파일러이고, 이를 돕는 코드가 성능 향상에 좋은 코드이다.

#### 함수 호출 규칙
호출자 함수가피호출자 함수를호출하는과정에서 **매개변수를 전달하는 순서 및 매개변수가 사용한 메모리 관리방법 등에 관한 규칙**이다. 대표적으로 `__cdecl`, `__stdcall`, `__fastcall` 등 세 가지 정도가 있다. C/C++ 컴파일러의 기본 함수 호출 규칙은 `__cdecl`이다.
 - `__cdecl`: 매개변수를 오른쪽부터 스택에 push, 매개변수로 인해 증가한 스택을 호출자 함수가 본래 크기로 줄임.
 - `__stdcall` : 매개변수를 오른쪽부터 스택에 push, 매개변수로 인해 증가한 스택은 피호출자 함수가 정리.
 - `__fastcall` : 매개변수를 오른쪽부터 스택에 push, 피호출자 함수가 스택을 정리함. 단, 매개변수가 여러 개면 가장 나중에 Push되어야 할 왼쪽 첫 번쨰, 두 번째 매개변수는 스택 대신 CPU의 레지스터(EDX, ECS)를 이용해 전달함.

#### 함수 포인터
`반환 자료형 ( 호출 규칙 *변수이름)(매개변수)`형식으로 표현된다. 이는 동적 연결 라이브러리(DLL, Dynamic Linking Library)를 활용하는 경우나 역호출(call back) 구조를 구현하는 경우에 필요하다.

#### 함수 포인터 + Lookup 배열
함수 포인터와 lookup 배열을 응용하면 switch 와 case 문을 완벽하게 대처하면서 고성능으로 코드 제작이 가능하다.

<pre>
#include <stdio.h>

void testFunc1(int nParam)
{
    puts("testFunc1");
}
void testFunc2(int nParam)
{
    puts("testFunc2");
}
void testFunc3(int nParam)
{
    puts("testFunc3");
}

int main(void)
{
    void(\*pfList[3])(int) = { //함수 포인터의 배열
        testFunc1, testFunc2, testFunc3
    };
    
    int nInput;
    scanf_s("%d", &nInput);

    if(nInput >= 0 && nInput <= 2)
    {
        pfList[nInput](10);
    }

return 0;
}
</pre>


----

### 파일입출력

UNIX 운영체제에서는 모든 입출력이 파일을 읽고 쓰는 것으로 행해지는데, 그 이유는 키보드와 스크린을 포함해 모든 주변장치들이 파일 시스템상의 파일처럼 취급되기 때문이다. 이러한 개념은 프로그램과 주변장치 간의 인터페이스 방법을 한 가지로 통일함으로써 단순성을 부여해 준다. 대부분의 경우 파일을 읽고 쓰기 위해 아래 단계를 따른다.
  1. open

   - 대부분의 경우 파일을 읽고쓰기 전에 시스템에게 반드시 '파일을 열게' 해야한다. 이 경우 시스템은 파일이 존재하는지, 사용자가 그 파일에 대한 사용권한을 가지고 있는지를 판별하여, 이상이 없을 때에는 프로그램에 파일 설명자(file descriptor)라고 하는 양의 정수 값을 보내 준다. 이 file descriptor 가 파일 입출력시 식별자로 사용된다. '열린 파일'은 시스템에 의해서만 관리되고, 사용자의 프로그램에서는 단지 파일 설명자만 사용가능하다. 단, 키보드와 스크린에 대한 입출력은 매우 빈번히 일어나므로 특별한 배려가 되어 있다. 프로그램이 실행되면 명령어 해석기인 shell이 standard input, standard output, standard error를 각각 0, 1, 2로 할당해주는데, 이와 같은 표준 입출력장치 0, 1, 2는 파일을 오픈할 필요 없이 사용이 가능하다.
   - 한편 프로그램 사용자는 파일의 입출력을 '<'이나 '>' 같은 기호를 이용하여 방향전환을 시킬 수 있다. `prog <infile >outfile` 이런 식으로 작성하면 shell은 표준 입출력 filde discriptor 0과 1을 키보드와 모니터 대신 주어진 파일 이름으로 대치한다.
    
  2. read/write
  
   - read와 write함수는 호출 때마다 '전송된 바이트 수'를 리턴한다. read 시에는 요청된 개수보다 적은 바이트 수가 리턴되어올 때도 있다. 리턴된 값이 0일 때는 파일의 끝을 나타내며, -1일 때는 에러가 발생했음을 뜻한다. (파일에 쓸 경우에 리턴된 값은 전송된 바이트 수를 나타내며, 이 값이 요청된 값과 다를 경우에는 에러가 발생한다.)
   - 입력과 출력은 보통 순차적으로 수행된다. 즉, read와 write가 한 번 수행될 때마다, 그 전에 수행된 자리에서 바로 오른쪽으로 한 자리 이동되면서 입출력이 행해진다. 물론 필요하다면 system call 함수 lseek를 사용하여 파일 내를 마음대로 돌아다니면서 read와 write를 수행할 수도 있다.
  3. close
   - 동시에 사용할 수 있는 파일의 한계는 20여 개 정도이므로 많은 파일을 동시에 다루어야될 프로그램은 file descriptor를 재사용할 수 있도록 고려해 주어야 한다. close 함수는 파일 설명자와 열린 파일 간의 연결을 끊어 버리고 파일 설명자를 다른 파일이 다시 사용할 수 잇도록 만들어 준다.

### 라이브러리 정리
썼거나 쓸만한 라이브러리 정리하며 숙지해두는 용도 for 구글링

#### string.h 라이브러리
 - strcpy: 문자열 복사
 - strlen: 문자열 길이
 - strcat: 문자열 합치기
 - strcmp: 문자열 비교
 - strdup: 동적할당 후, strcpy를 활용하여 문자열 주소 복사 후 배열의 주소를 반환.

