### Dynamic programming
----


재귀호출로 계산하는 경우, TOP-DOWN방식으로 계산할 경우 불필요한 중복계산이 많다. 
이를 피하기 위한 대표적인 방법으로 아래 두가지가 있다.
 1. Memorization : top-down방식으로 계산하되 실제로 필요한 subproblem만을 풀고, 이미 계산한 값은 따로 저장해서 해당 값이 필요할 때마다 꺼내어 쓰는 방법
 2. BOTTOM-UP 방식: bottom-up방식이며, recursion에 수반되는 overhead가 없다.


memorization의 예시
```C
int fib(int n) {
    if (n==1 || n==2){
        return 1;
        }
    else if (f[n] > -1){ //배열 f가 -1로 초기화되어있는 것 가정했을 때, 이미 계산된 값이라는 의미.
        return f[n];
        }
    else {
        f[n] = fib(n-2) + fib(n-1); // 중간 계산 결과를 caching
        return f[n];
        }
    }
```


Recursion BOTTOM-UP의 예시
```C
int fib(int n) {
    f[1] = 1;
    f[2] = 1;
    for (int i = 0; i <= n; i++) {
        f[i] = f[i-1] + f[i-2];             
        }
    return f[n];    
    }
```

#### Optimal Substructure

동적 계획법은 일반적으로 최적화 문제나 카운팅 문제에 적용된다. 
주어진 문제에 대해 순환식을 정의하고, 이를 memorization이나 bottom-up 방식으로 푸는 것이다.
이 때 그 문제의 최적해가 그것의 sub-problem들의 최적해로부터 효율적으로 구해질 수 있는 지 여부-즉, optimal structure를 가지는지 확인하는 것이 필요하다.

> 최적해의 일부분이 그 부분에 대한 최적해인가?
 


탐욕 알고리즘과의 차이점
 - 탐욕 선택: 하위 문제를 풀기 전에 선택을 한다. 항상 하나의 문제만을 고려한다.
 - 동적 프로그래밍: 하위 문제를 풀고 나서 선택을 한다. 동시에 여러 개의 하위 문제를 고려한다.
 



