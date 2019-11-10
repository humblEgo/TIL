### Linked_list
----
 1. 기본적 연결 리스트
  - 노드들의 연결로 구성되어있고, 각 노드는 Data와 link로 이루어져있다.
  - 연결 리스트는 제일 첫 노드인 Head, 제일 끝 노드인 Tail, 노드의 수인 number of nodes로 이루어지는게 보통이다.
  - 우선, 비어있는 Linked_List는 아래와 같이 구현될 수 있다.
  <pre>
  class Node:
      def __init__(self, item):
          self.data = item
          self.next = None
  
  class LinkedList:
      def __init__(self):
          self.nodeCount = 0
          self.head = None
          self.tail = NonE
  </pre>
  
  - head의 인덱스를 0 이 아닌, 1로 지정하면 리스트를 확장하는데 용이하다.
  
  - n번째 node를 찾아가는 코드는 아래와 같이 구현될 수 있다.
  <pre>
  class LinkedList의 메서드 getAt
  def getAt(self, pos):
      if pos <=0 or pos > self.nodeCount:
          return None      
      i = 1
      current = self.head
      while i < pos:
          current = current.next
          i += 1
      return current
  </pre>
  
  - ||Array|Linked_List
    |:---|:---|:------
    저장공간|연속한 위치|임의의 위치
    특정 원소 지칭|매우 간편|선형탐색과 유사
    시간복잡도|O(1)|O(n)
  
  - head에서 모든 노드를 방문하는 "리스트 순회"의 경우 아래와 같이 구현할 수 있다.
  <pre>
  def traverse(self):
      answer = []
      current = self.head
      while current != None:
          answer.append(current.data)
          current = curr.next
      return answer
  </pre>
  
  - "원소의 삽입"은 아래와 같이 구현할 수 있다.
  <pre>
  def insertAt(self, pos, newNode):                
      if pos < 1 or pos > self.nodeCount + 1: #pos 범위조건 확인
          return False        
      if pos == 1:                             #pos == 1인 경우에는 head 뒤에 새 node 삽입
          newNode.next = self.head
          self.head = newNode
      else:
          prev = self.getAt(pos-1) # pos번째 노드의 이전 노드를 prev 노드라고 가르킴
          newNode.next = prev.next # newNode가 pos번째 노드를 가르키도록 함.
          prev.next = newNode # pos -1 번째 노드가 newNode를 가르키도록 함.
      if pos == self.nodeCount + 1:            #pos가 nodeCount + 1인 겨우에는 prev는 tail
          self.tail = newNode
      
      self.nodeCount += 1 #nodeCount를 1개 늘림.
      return True
----    
 2. Dummy node를 활용한 연결리스트
  - 기존에는 n번째에 노드를 insert할 때 getAt 메서드로 처음부터 n번째까지 노드를 순차적으로 확인해야하므로 삽입과 삭제가 유연하다는 연결리스트의 특징이 반감된다. 이에 특정 노드의 뒤에 삽입 혹은 삭제하는 메서드를 insertAfter(prev, newNode), popAfter(prev)작성하는 방법을 고려하였다.
  - 이 때 insertAfter(prev, newNode)와 popAfter(prev) 메서드를 '맨 앞에 위치한 노드'에도 무리없이 적용할 수 있도록 하기 위해, linkedList의 첫번째 노드에 DummyNode를 삽입해보면 아래와 같다.
  <pre>
  class LinkedList:
      def __init__(self):
          self.nodeCount = 0
          self.head = Node(None)
          self.tail = None
          self.head.next = self.tail
         
      def traverse(self):
          result = []
          curr = self.head
          while curr.next:
              curr = curr.next
              result.append(curr.data)
          return result
          
      def getAt(self, pos):
          if pos < 1 or pos > self.nodeCount:
              return None
          i = 0
          curr = self.head
          while i < pos:
              curr = curr.next
              i += 1
          return curr
  
      def insertAfter(self, prev, newNode): #메서드 정의:prev가 가리키는 node의 다음에 newNode를 삽입하고, 성공/실패에 따라 True/False를 리턴
          newNode.next = prev.next
          if prev.next is None:
              self.tail = newNode
          preve.next = newNode
          self.nodeCount += 1
          return True
          
      def insertAt(self, pos, newNode):
          if pos < 1 or pos > self.nodeCount +1:
              return False
              
          if pos != 1 and pos == self.nodeCount + 1:
              prev = self.tail
          else:
              prev = self.getAt(pos-1)
          return self.insertAfter(prev,newNode)    
      
      def concat(self, L):
          self.tail.next = L.head.next
          if L.tail:
              self.tail = L.tail
          self.nodeCount += L.nodeCount
          
      def popAfter(self, prev): #prev의 다음 node를 삭제하고, 그 node의 data를 리턴
          curr = prev.next 
         if curr == None: #prev가 마지막 node일 때, prev.next == None 일 때 return NOne
            return None   
         if curr == self.tail: #리스트의 맨 끝이 node를 삭제할 때 tail 조정.
            self.tail == prev
         prev.next = curr.next
         return curr.data
   </pre>
  
