### 큐?
----
선입선출 방식으로 자료를 저장.

배열로는 아래와 같이 구현할 수 있다.
```Python
class ArrayQueue:
    
    def __init__(self):
        self.data = []
        
    def size(self):    
        return len(self.data)
        
    def isEmpty(self):
        return self.size() == 0
        
    def enqueue(self, item):
        self.data.append(item)
        
    def dequeue(self):
        return self.data.pop(0)
        
    def peek(self):
        return self.data[0]
</pre>
위 내용처럼 배열로 큐를 구현할 경우, dequeue()는 0(n) 복잡도를, 나머지는 상수 시간 복잡도를 가진다. dequeue 연산의 시간복잡도는 이중연결리스트를 이용하여 구현하면 개선된다.

이중연결리스트로는 아래와 같이 구현할 수 있다.
<pre>
class Node:

    def __init__(self, item):
        self.data = item
        self.prev = None
        self.next = None


class DoublyLinkedList:

    def __init__(self):
        self.nodeCount = 0
        self.head = Node(None)
        self.tail = Node(None)
        self.head.prev = None
        self.head.next = self.tail
        self.tail.prev = self.head
        self.tail.next = None


    def __repr__(self):
        if self.nodeCount == 0:
            return 'LinkedList: empty'

        s = ''
        curr = self.head
        while curr.next.next:
            curr = curr.next
            s += repr(curr.data)
            if curr.next.next is not None:
                s += ' -> '
        return s


    def getLength(self):
        return self.nodeCount


    def traverse(self):
        result = []
        curr = self.head
        while curr.next.next:
            curr = curr.next
            result.append(curr.data)
        return result


    def reverse(self):
        result = []
        curr = self.tail
        while curr.prev.prev:
            curr = curr.prev
            result.append(curr.data)
        return result


    def getAt(self, pos):
        if pos < 0 or pos > self.nodeCount:
            return None

        if pos > self.nodeCount // 2:
            i = 0
            curr = self.tail
            while i < self.nodeCount - pos + 1:
                curr = curr.prev
                i += 1
        else:
            i = 0
            curr = self.head
            while i < pos:
                curr = curr.next
                i += 1

        return curr


    def insertAfter(self, prev, newNode):
        next = prev.next
        newNode.prev = prev
        newNode.next = next
        prev.next = newNode
        next.prev = newNode
        self.nodeCount += 1
        return True


    def insertAt(self, pos, newNode):
        if pos < 1 or pos > self.nodeCount + 1:
            return False

        prev = self.getAt(pos - 1)
        return self.insertAfter(prev, newNode)


    def popAfter(self, prev):
        curr = prev.next
        next = curr.next
        prev.next = next
        next.prev = prev
        self.nodeCount -= 1
        return curr.data


    def popAt(self, pos):
        if pos < 1 or pos > self.nodeCount:
            raise IndexError('Index out of range')

        prev = self.getAt(pos - 1)
        return self.popAfter(prev)


    def concat(self, L):
        self.tail.prev.next = L.head.next
        L.head.next.prev = self.tail.prev
        self.tail = L.tail

        self.nodeCount += L.nodeCount
        
class LinkedListQueue:

    def __init__(self):
        self.data = DoublyLinkedList() 
        
    def size(self):
        return self.data.getLength()
    
    def isEmpty(self):
        return self.data.getLength() == 0
        
    def enqueue(self, item):
        node = Node(item)
        self.data.insertAfter(self.data.tail.prev, node)
    
    def dequeue(self):
        return self.data.popAt(1)
        
    def peek(self):
        return self.data.getAt(1).data



```

물론 기본 라이브러리에서 큐를 가져와서 쓸 수 도 있다.


----

C로는 아래처럼 구현해보았다.

 - 삽입이 일어나는 쪽을 rear, 삭제가 일어나는 쪽을 front라고 부름.(front가 삽입과 삭제가 용이하고, rear는 삽입만 용이하므로 이를 고려해서 생성.)

 - 아래 내용대로 만듦
   - enqueue: 큐의 rear에 새로운 원소를 삽입
   - dequeue: 큐의 front에 있는 원소를 큐로부터 삭제하고 반환
   - peek: 큐의 front에 있는 원소를 제거하지 않고 반환하는 연산
   - is_empty: 큐가 비었는지 검사



```C
#ifndef QUEUEADT_H
#define QUEUEADT_H

#include <stdbool.h> /* C99 only*/

typedef int Item;
typedef struct queue_type* Queue;

Queue create();
void destroy(Queue q);
void make_empty(Queue q);
bool is_empty(Queue q);
void enqueue(Queue q, Item i);
Item dequeue(Queue q);
Item peek(Queue q);
int get_size(Queue q);

#endif

#include <stdio.h>
#include <stdlib.h>

struct node {
	Item data;
	struct node* next;
};

struct queue_type {
	struct node* front;
	struct node* rear;
	int size;
};

void terminate(const char* message) {
	printf("%s\n", message);
	exit(EXIT_FAILURE); // 비정상 종료쓰..
}

int get_size(Queue q) {
	return q->size;
}

Queue create() {
	Queue q = (Queue)malloc(sizeof(struct queue_type));
	if (q == NULL) {
		terminate("Error in create: queue coulud not be created.");
	}
	q->front = NULL;
	q->rear = NULL;
	q->size = 0;
	return q;
}

void destroy(Queue q) {
	make_empty(q);
	free(q);
}

void make_empty(Queue q) {
	while (!is_empty(q)) {
		dequeue(q);
	}
	q->size = 0;
}

bool is_empty(Queue q) {
	return q->size == 0;
}

void enqueue(Queue q, Item i) {
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	if (newNode == NULL) { //newNode만드는 것 실패하면, 오류메세지내고 종료
		terminate("Error in push: queue is full.");
	}

	newNode->data = i;
	newNode->next = NULL;
	if (q->front == NULL) {
		q->front = newNode;
		q->rear = newNode;
	}
	else {
		q->rear->next = newNode;
		q->rear = newNode;
	}
	q->size++;
}
Item dequeue(Queue q) {
	struct node* oldFront;
	Item i;
	if (is_empty(q)) {
		terminate("Error in dequeue: queue is empty.");
	}
	oldFront = q->front;
	i = oldFront->data;
	q->front = oldFront->next;
	if (q->front == NULL) {
		q->rear = NULL;
	}
	free(oldFront);
	q->size--;
	return i;
}

Item peek(Queue q) {
	if (is_empty(q)) {
		terminate("Error in peek: queue is_empty.");
	}
	return q->front->data;
}
```
