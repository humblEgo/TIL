### Quick Sort

퀵정렬은 분할정복법을 통해 정렬하는 방법이다. 따라서 아래 과정대로 정렬된다.
 - 분할: 배열을 다음과 같은 조건을 만족하도록 두 부분으로 나눈다.
   - 조건: elements in lower parts <= elements in upper parts
 - 정복: 각 부분을 순환적으로 정렬한다.
 - 합병: nothing to do

퀵정렬은 배열을 크기별로 나누는 기준인 'pivot 값'이 해당 배열의 가장 큰 값이나 가장 작은 값일 경우가 최악의 경우로써, 시간복잡도 o(N^2)를 가진다.
보통 배열의 가장 마지막 값을 pivot으로 적용하므로, '이미 정렬된 입력 데이터'에 퀵정렬을 적용하는 경우 가장 큰 시간복잡도를 가지게 되는 것이다.

한편, 운이 좋아서 항상 절반으로 분할되는 경우는 최선의 경우로써, 시간복잡도 O(nlogn)을 가진다.


C로는 아래와 같이 구현가능하다.

```C
#include <stdio.h>

int partition(int Array[], int p, int r) {  
    
    int i = p-1;    //pivot보다 작은 값들 중 마지막 값
    int j = p;    // 지금 검사하려는 값
    int pivotData = Array[r];        

    int temp = 0;

    for (i = 0; i < r; i++) {
        if (Array[i] >= pivotData) {
            j += 1;
        }
        else {
            i += 1;            
            temp = Array[i];
            Array[i] = Array[j];
            Array[j] = temp;
            j += 1;
        }
    }    
    temp = Array[i + 1];
    Array[i + 1] = Array[j];
    Array[j] = temp;

    return i+1;
}

void quickSort(int Array[], int p, int r) { // A[p...r]을 정렬한다.
    if (p < r) {
        int q = partition(Array, p, r); //분할
        quickSort(Array, p, q - 1); //왼쪽 부분배열 정렬
        quickSort(Array, q + 1, r); //오른쪽 부분배열 정렬
    }
}
```
