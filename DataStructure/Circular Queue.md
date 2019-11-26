### 환형 큐?
----
**정해진 개수**의 저장공간을 빙 돌려가며 이용

연산의 정의
 - size(): 현재 큐에 들어 있는 데이터 원소의 수를 구함
 - isEmpty(): 현재 큐가 비어 있는지를 판단 
 - isFull(): 큐에 데이터 원소가 꽉 차 있는지를 판단
 - enqueue(x): 데이터 원소 x를 큐에 추가
 - dequeue(): 큐의 맨 앞에 저장된 데이터 원소를 제거 (또한, 반환)
 - peek(): 큐의 맨 앞에 저장된 데이터 원소를 반환 (제거하지 않음)
 
배열로 구현할 경우, 아래와 같다.
<pre>
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
  </pre>
