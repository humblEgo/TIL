### 스택?

스택은 일종의 리스트이다.
단, 데이터의 삽입과 삭제가 한쪽 끝에서만 이루어지며 LIFO(Last In First Out)으로 작동한다.
삽입/삭제가 일어나는 쪽을 스택의 top이라고 부른다.

 - 구현해본 기본 기능
   - push: 스택에 새로운 원소를 삽입하는 연산
   - pop: 스택의 top에 있는 원소를 스택에서 제거하고 반환
   - peek: 스택 top의 원소를 제거하지 않고 반환
   - empty: 스택이 비었는지 검사

```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sNode{
   
};
