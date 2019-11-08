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
  def insertArt(self, pos, newNode):
      if pos < 1 or pos > self.nodeCount + 1:
          return False
      if pos == 1:
          newNode.next = self.head
          self.head = newNode
      else:
          prev = self.getAt(pos-1) # pos번째 노드의 이전 노드를 prev 노드라고 가르킴
          newNode.next = prev.next # newNode가 pos번째 노드를 가르키도록 함.
          prev.next = newNode # pos -1 번째 노드가 newNode를 가르키도록 함.
      if pos == self.nodeCount + 1:
          self.tail = newNode
      
      self.nodeCount += 1 #nodeCount를 1개 늘림.
      return True
      
