### 환형 큐?
----
**정해진 개수**의 저장공간을 빙 돌려가며 이용. 기본 배열로 큐를 구현하면 삽입과 삭제를 몇번 반복했을 경우 앞쪽 공간이 낭비될 수 있으므로, 대안으로 쓰이곤한다.

연산의 정의
 - size(): 현재 큐에 들어 있는 데이터 원소의 수를 구함
 - isEmpty(): 현재 큐가 비어 있는지를 판단 
 - isFull(): 큐에 데이터 원소가 꽉 차 있는지를 판단
 - enqueue(x): 데이터 원소 x를 큐에 추가
 - dequeue(): 큐의 맨 앞에 저장된 데이터 원소를 제거 (또한, 반환)
 - peek(): 큐의 맨 앞에 저장된 데이터 원소를 반환 (제거하지 않음)
 
파이썬 배열로 구현할 경우, 아래처럼 구현하는 것이 가능하다ㅏ.
```Python
class CircularQueue:
    
    def __init__(self, n):
        self.maxCount = n
        self.data = [Noun] * n
        self.count = 0
        self.front = -1
        self.rear = -1
    
    def size(self):
        return self.count
        
    def isEmtpy(self):
        return self.count == 0
    
    def isFull(self):
        return self.count == self.maxCount
        
    def enqueue(self, x):
        if self.isFull():
            raise IndexError('Queue is full')
        self.rear = (self.rear+1)%self.maxCount
        self.data[self.rear] = x
        self.count += 1
        
    def dequeue(self):
        if self.isEmpty():
            raise IndexError('Queue empty')
        self.front = (self.front + 1)%self.maxCount
        x = self.data[self.front]
        self.count -= 1
        return x
        
    def peek(self):
        if self.isEmpty():
            rasie IndexError('Queue empty')
        return self.data[(self.front+1)%self.maxCount]
```


C언어로는 동적으로 크기가 조정되는 '동적원형배열 큐'를 구현해보았다.

```C
#include <stdio.h>
#include <stdlib.h>

struct DynArrayQueue {
	int front, rear;
	int capacity;
	int* array;
};

struct DynArrayQueue* CreateDynQueue() {
	struct DynArrayQueue* Q = (struct DynArrayQueue*)malloc(sizeof(struct DynArrayQueue));
	if (!Q) {
		return NULL;
	}
	Q->capacity = 1;
	Q->front = -1;
	Q->rear = -1;
	Q->array = (int*)malloc(sizeof(int));
	if (!Q->array) {
		return NULL;
	}
	return Q;
}

int IsEmptyQueue(struct DynArrayQueue* Q) {
	return (Q->front == -1);
}

int IsFullQueue(struct DynArrayQueue* Q) {
	return (Q->front == ((Q->rear + 1) % Q->capacity));
}

int QueueSize(struct DynArrayQueue* Q) {
	return(Q->capacity - Q->front + Q->rear + 1) & Q->capacity;
}

void ResizeQueue(struct DynArrayQueue* Q) {
	int size = Q->capacity;
	Q->capacity = Q->capacity * 2;
	Q->array = realloc(Q->array, Q->capacity); //재할당도 잊지말자.
	if (!Q->array) {
		printf("Memory Error");
		return;
	}
	if (Q->front > Q->rear) {   //큐 사이즈가 커지는 것 반영하여 조정
		for (int i = 0; i < Q->front; i++) {
			Q->array[i + size] = Q->array[i];
		}
		Q->rear = Q->rear + size;
	}
}

void EnQueue(struct DynArrayQueue* Q, int data) {
	if (IsFullQueue(Q)) {
		ResizeQueue(Q);
	}
	Q->rear = (Q->rear + 1) % Q->capacity;
	Q->array[Q->rear] = data;
	if (Q->front == -1) {
		Q->front = Q->rear;
	}
}

int DeQueue(struct DynArrayQueue* Q) {
	int data = 0;
	if (IsEmptyQueue(Q)) {
		printf("Queue is Empty");
		return 0;
	}
	else {
		data = Q->array[Q->front];
		if (Q->front == Q->rear) {
			Q->front = -1;
			Q->rear = -1;
		}
		else {
			Q->front = (Q->front + 1) % Q->capacity;
		}
		return data;
	}
}

void DeleteQueue(struct DynArrayQueue* Q) {
	if (Q) {
		if (Q->array) {
			free(Q->array);
		}
		free(Q);
	}
}
```



