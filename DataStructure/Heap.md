### 힙(Heap)?
----
이진 트리의 한 종류이며, 이진 힙(binary heap) 이라고도 불린다.
힙에서는 아래 세가지 성질을 가지고 있다.
 - 루트 노드가 언제나 최댓값 또는 최솟값을 가짐
 - 완전 이진 트리이다.
 - 최대 힙 내의 임의의 노드를 루트로 하는 서브트리 또는 최대 힙이다.
----
이진 탐색 트리와의 비교하면 아래와 같은 특징을 갖는다.

이진탐색트리|힙
--------|--------
원소들이 완전히 크기 순으로 정렬되어 있음.|원소들이 완전히 크기 순으로 정렬되어있지 않음.
특정 키 값을 가지는 원소를 빠르게 검색할 수 있음.|특정 키 값을 가지는 원소를 빠르게 검색할 수 없음.
다른 부가적인 제약 조건은 없음 | 이진 탐색트리에 비해 완전이진트리여야 한다는 부가제약조건이 있음.

부가 제약 조건인 완전 이진 트리여야한다는 제약 때문에 n개의 노드로 이루어진 최대 힙의 높이가 log(n)+1(에서 소수 부분은 버림)으로 정해진다는 것이다.
때문에 최대 힙은 원소 삽입을 할 경우, 부모 노드와의 대소 비교를 하며 원소 삽입하므로, 대소 비교의 최대 회수가 log<sub>2</sub>n이며, 
최악 복잡도가 O(logn)의 삽입 연산이라는 장점이 있다.

----
최대 힙(Max Heap)의 추상적 자료구조

연산의 정의를 아래와 같이 두면,
 - __init__(): 빈 최대 힙을 생성
 - insert(item): 새로운 원소를 삽입
 - remove(): 최대 원소(root node)를 반환, 동시에 이 노드를 삭제
 - insert(): 완전 이진 트리이므로, 트리의 마지막 자리에 새로운 원소를 임시로 저장하고, 부모 노드와 키 값을 비교하여 위로 이동시킴.
아래와 같이 구현할 수 있다.
<pre>
class MaxHeap:
    def __init__(self):
        self.data = [None]
    
    def insert(self, item):
        self.data.append(item)
        pos = len(self.data) - 1 #Last Index
        
        while pos > 1: #root로 올 때까지 부모와 비교하여 더 작으면 바꾸는 작업을 반복한다.
        parentPos = pos // 2
            if self.data[pos] > self.data[parentPos]:
                self.data[pos], self.data[parentPos] = self.data[parentPos], self.data[pos]
                pos = parentPos
            else:
                break        
    
    def remove(self):
        if len(self.data) > 1:
            self.data[1], self.data[-1] = self.data[-1], self.data[1]
            data = self.data.pop(-1)
            self.maxHeapify(1)        
        else:
            data = None
        return data
    
    def maxHeapify(self, i):
        left = i * 2
        right = i*2 + 1
        greatest = i
        
        if left <= len(self.data)-1 > self.data[left] > self.data[greatest]:
            greatest = left
        if right <= len(self.data)-1 > self.data[right] > self.data[greatest]:
            greatest = right
            
        if smallest != i:
            self.data[i], self.data[greatest] = self.data[greatest], self.data[i]
            self.maxHeapify(greatest)
        
