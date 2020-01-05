### Quick Sort

퀵정렬은 분할정복법을 통해 정렬하는 방법이다. 따라서 아래 과정대로 정렬된다.
 - 분할: 배열을 다음과 같은 조건을 만족하도록 두 부분으로 나눈다.
   - 조건: elements in lower parts <= elements in upper parts
 - 정복: 각 부분을 순환적으로 정렬한다.
 - 합병: nothing to do

C로는 아래와 같이 구현가능하다.

```C
