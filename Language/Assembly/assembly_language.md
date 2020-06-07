# Assembly_language

어셈블리어(Assembler language)는 [기계어]()와 1:1 대응이 되는 컴퓨터 프로그래밍의 저급언어(low-level programming language)이다.
컴퓨터 구조에 따라 사용하는 기계어가 달라지므로, 1:1 대응이 되는 어셈블리어도 각각 다르게 된다.

어셈블리 언어는 오래된 언어이고 잘 쓰이지 않을 것 같지만 두 가지 관점에서 여전히 살아있는 언어이다. 첫째는 보안이라는 관점에서 볼 때 소스가 공개되지 않는 프로그램을 바이너리수준에서 분석하고 이해해야 한다면 디스어셈블 된 코드를 읽어야 하는데, 이때 어셈블리 언어에 대한 이해가 없다면 불가능하다. 둘째는 하드웨어를 직접 제어 하는 부분(드라이버나 운영체제 커널의 특별한 모듈)은 여전히 그 간결성과 편의성 때문에 어셈블리 언어로 코딩을 할 수밖에 없다. 예를 들어 운영체제 소스를 분석해 보면 여전히 소스 중 일정비율은 어셈블리 언어로 코딩되어 있다.

어셈블리 언어는 정해진 표준이 없다. AT&T 방식과 Intel 방식이 대표적으로 쓰인다. 둘 모두 opcode(명령어)와 operand(인자값, 피연산자)로 이루어져있다는 공통점이 있다. 차이점은 아래 표와 같으며 서로 호환되지 않는다.
|항목|AT&T|Intel|
|----|----|----|
|접두사 규칙|레지스터는 `%`, 값은 `$`|16진수 데이터는 `h`, 2진수 데이터는 `b`|
|operands 위치 차이|destination operands가 뒤, source operands가 앞|dest operands가 앞, src operands가 뒤|
|memory operands|`(`와 `)` 사이에 놓음|`[`와 `]` 사이에 놓음|
|접미사 규칙|operands size 등 고유의미가진 접미사 존재|접미사 사용않고 의미있는 문장을 그대로 사용함.|

## 개념

#### 어셈블러

어셈블러(assembler)는 [니모닉 기호(mnemonics)]()를 opcode로 변환하고 메모리 위치와 기타 존재물에 따라 식별자를 다시 분석함으로써 목적 코드를 만들어낸다.

#### 니모닉 기호(mnemonic)

mnemonic의 사전적 의미는 **어떤 것을 기억하는 데 쉽게 하도록 도움을 주는 것, 또는 쉽게 기억되는 성질**이다. 그 어원은 아래와 같다.

> mnemonic 의 어원은 그리스 신화의 기억의 여신 므네모시네(Mnemosyne) 에서 유래 되었습니다. 므네모시네의 자녀인 뮤즈(Muses)는 올림포스 산의 신들의 축제에서 아폴론을 도와 음악을 연주 하였는데, 악보가 없는 세계라 기억력에 의존하여 연주할 수 있었다고 합니다.

어원에서 알 수 있듯이 mnemonic 자체는 꼭 어셈블리어에 대해서가 아니라 기억하기 어려운 것을 기억하기 쉽도록 만드는 모든 개념을 뜻한 것이라고 할 수 있다. 어셈블리어를 설명할 때 쓰이는 mnemonic 기호는 기계어로된 일련의 숫자를 인간이 알아보기 쉽게 영어로 바꾸어준 것을 뜻한다.

#### 패스의 수

어셈블러에는 두 가지 종류가 있다. 실행 프로그램을 만들기 위해 얼마나 많은 패스가 소스를 거치는지에 따라 다르다.

- 1패스(one-pass) 어셈블러: 소스 코드를 한번만 거친다.
- 다중 패스(multi-pass) 어셈블러: 처음 패스들에서 모든 기호와 관련 값들이 포함된 테이블 하나를 만들고 나중 패스들에서 테이블을 이용하여 코드를 만들어낸다.

#### 기계어

기계어는 특별한 변환 과정 없이 컴퓨터가 직접 처리할 수 있는 유일한 언어이다.
아래는 n번째 피보나치 수를 계산하는 32비트 x86 기계어를 표현한 16진 기능의 예이다.

```C
8B542408 83FA0077 06B80000 0000C383
FA027706 B8010000 00C353BB 01000000
C9010000 008D0419 83FA0376 078BD98B
B84AEBF1 5BC3
```

#### 레지스터(Register)

레지스터는 CPU 바로 안에 있는 고속 저장 장소이며 일반 메모리보다 훨씬 빠른 속도로 접근할 수 있다. 프로그램이 실행되면 실행 파일이 메모리에 상주하면서 동작에 필요한 일부 데이터들이 CPU로 전달되게 되는데, 이 때 그 데이터들이 저장되는 곳이 레지스터이다.

기본적인 프로그램 실행 레지스터는 8개의 범용 레지스터와 6개의 세그먼트 레지스터, 프로세서 상태 플래그 레지스터와 명령어 포인터가 있다.

- 참고
  - [어셈블리어-위키피디아](<https://ko.wikipedia.org/wiki/%EC%96%B4%EC%85%88%EB%B8%94%EB%A6%AC%EC%96%B4#:~:text=%EC%96%B4%EC%85%88%EB%B8%94%EB%A6%AC%EC%96%B4(%EC%98%81%EC%96%B4%3A%20assembly%20language),%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D%EC%9D%98%20%EC%A0%80%EA%B8%89%20%EC%96%B8%EC%96%B4%EC%9D%B4%EB%8B%A4.>)
  - [저급 프로그래밍 언어-위키피디아](https://ko.wikipedia.org/wiki/%EC%A0%80%EA%B8%89_%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D_%EC%96%B8%EC%96%B4)
  - [mnemonic이란 by henry kang](https://medium.com/hexlant/mnemonic-%EC%9D%B4%EB%9E%80-7fb48106bd77))
  - [Intel과 AT&T의 차이점](https://hardner.tistory.com/22)
  - [리버싱과 시스템 해킹을 공부하려면 꼭 알아야하는 어셈블리어의 기초-어셈블리어](https://www.youtube.com/watch?v=yf7yFJHTif8)
  - [태초의 프로그래밍 언어 어셈블리](https://github.com/gurugio/book_assembly_8086_ko/blob/master/README.md)
  - [레지스터의 종류와 특징](https://beomnaegol.tistory.com/entry/Assembly-%EB%A0%88%EC%A7%80%EC%8A%A4%ED%84%B0%EC%9D%98-%EC%A2%85%EB%A5%98%EC%99%80-%ED%8A%B9%EC%A7%95)
  - [어셈블리어 튜토리얼](https://note.heyo.me/asm-tutorial-0/)
  - [Introduction to x64 Assembly](https://software.intel.com/content/www/us/en/develop/articles/introduction-to-x64-assembly.html)
  - [NASM tutorial](https://cs.lmu.edu/~ray/notes/nasmtutorial/)
  - [Assembly on the Mas](https://stackoverrun.com/ko/q/4687127)
