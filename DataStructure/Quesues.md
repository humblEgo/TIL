### 큐?
----
선입선출 방식으로 자료를 저장.

배열로는 아래와 같이 구현할 수 있다.
<pre>
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


</pre>

물론 기본 라이브러리에서 큐를 가져와서 쓸 수 도 있다.
