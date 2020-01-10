### 힙정렬?

힙은 1) complete binary tree이면서 2) heap property(부모노드는 자식노드보다 크다)를 만족해야한다.
힙정렬은 최악의 경우에도 시간복잡도가 O(nlogn)이고, 추가 배열이 불필요한 정렬이다. 이진 힙 자료구조를 사용한다.


힙을 1차원 배열로 표현할 경우엔 다음처럼 표현가능하다.
  - A[1...n] 배열에서 루트노드는 A[1]
  - A[i]의 부모 = A[i/2]
  - A[i]의 왼쪽 자식 = A[2i]
  - A[i]의 오른쪽 자식 = A[2i+1]
  
재귀적으로는 아래와 같이 구현할 수 있다.
```C
//루트를 제외한 루트의 왼쪽 자식노드와 오른쪽 자식노드가 루트가 되는 각각의 트리가 heap property를 만족하는 상황에서, 힙으로 만들어주는 연산.
MAX-HEAPIFY(a, i){
    A[i]가 자식이 없으면
        return;
    k <- index of the biggest child of i;
    if A[i] >= A[k]
        return;
    exchange A[i] and A[k];
    MAX-HEAPIFY(A, k);
    
    while A[i]가 자식노드가 있는 동안,
        k는 i의 가장 큰 자식노드의 index;
        if A[i] >= A[k]
            return;
        exchange A[i] and A[k];
        i = k;
    end.
}

// complete binary tree를 heap으로 만드는 함수
BUILD-MAX-HEAP(a){
   heap-size = length.[A];
   for i <- length[A]/2 downto 1
       do MAX_HEAPIFY(A,i);
}

```


### 우선순위 큐?

insert(x)랑 extact_max(): 최대값을 삭제하고 반환. 하는 걸 가짐.

```C
MAX-HEAP-INSERT(A,key){
    heap_size = heap_size +1;
    A[heap_size] = key;
    i = heap_size;
    while (i > 1 and A[PARENT(i)] < A[i]) {
        exchange A[i] and A[PARENT(i)];
        i = PARENT(i);
    }
}
EXTRACT_MAX(){
    if heap-size[A] <1
        then error "heap underflow"
    max = A[1]
    A[1] = A[heap-size[A]]    
    max-heapify(A, 1)    
    heap_size = heap_size - 1;
}

```

