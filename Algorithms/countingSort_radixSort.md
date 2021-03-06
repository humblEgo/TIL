### Counting sort?

시간복잡도가 O(n+k)으로, 선형시간 정렬알고리즘이다. (만약 k가 O(n)이면 O(n)으로 표현 가능)
Comparison Sort의 최소 시간복잡도인 O(nlogn)보다 작은 시간복잡도를 가진다. 즉, Non-comparison Sort 중 하나이다.

**n개의 정렬의 데이터 값의 범위(ex 0~k사이의 정수값)를 아는 경우에 적용 가능**하며, 빠른 대신 많은 메모리를 소비한다.
k가 클 경우 비실용적이라고 할 수 있다.

'입력에 동일한 값이 있을 때 입력에 먼저 나오는 값이 출력에서도 먼저 나온다'는 Stable 정렬 특성도 가지고 있다.

C언어로는 아래와 같이 구현 가능하다.
```C
// 0으로 초기화 -> 카운팅 -> 누적합 구하기 -> 끝에서부터 처음 방향으로 살펴보면서 값을 인덱스에 저장 

```

### Radix sort?

n개의 d자리 정수를 정렬하는 알고리즘이다. 
(사실 'd자리 정수'라고 했으나 꼭 정수가 아니라 문자열이라도 개수가 정해져있다면 활용 가능하긴 하다.)

가장 낮은 자리수의 숫자부터 마지막 숫자까지 stable sort로 정렬하면 된다.

시간복잡도는 O(d(n+k))이다. 

C언어로는 아래와 같이 구현 가능하다.

```C
Radix-sort(A, d)// n개의 배열 A와 각 배열 요소의 자리수 d를 인수로 받음.
    for i <- 1 to d
        do use a sstable sort to sort array A on digit i
```


