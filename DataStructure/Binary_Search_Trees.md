### 이진 탐색 트리(Binary Search)
----
데이터를 단순배열에 저장했을 때와 비교하면 아래의 장점을 가진다.
 - 장점
   - 데이터를 검색할 때 전수조사하는 것보다 짧은 소요시간을 가진다. 평균적으로 O(log(n))
   - 데이터 원소의 추가, 삭제가 용이하다.
 - 단점
   - left, right 정보를 추가로 기록해야하므로 공간 소요가 크다.
----
연산 정의
 - insert(key, data): 트리에 주어진 데이터 원소를 추가
 - remove(key): 특정 원소를 트리로부터 삭제
 - lookup(key): 특정 원소를 검색
 - inorder(): 키의 순서대로 데이터 원소를 나열
 - min(), max(): 최소 키, 최대 키를 가지는 원소를 각각 탐색
 - remove(): 찾은 노드를 제거하고, 이진 탐색 트리 성질을 만족하도록 트리의 구조를 정리
 
 
 <pre>
 class Node:
     def __init__(self, key, data):
         self.key = key
         self.data = data
         self.left = None
         self.right = None
         
     def inorder(self):
         traversal = []
         if self.left:
             traversal += self.left.inorder()
         traversal.append(self)
         if self.right:
             traversal += self.right.inorder()
         return traversal
     
     def lookup(self, key, parent=None):
         if key < self.key:
             if self.left:
                 return self.left.lookup(key, self)
             else:
                 return None, None
         elif key > self.key:
             if self.right:
                 return self.right.lookup(key, self)
             else:
                 return None, None
         else:
             return self, parent
     
     def insert(self, key, data):
         if key < self.key:
             if self.left:
                 self.left.insert(key, data)
             else:
                 self.left = Node(key, data)
         elif key > self.key:
             if self.right:
                 self.right.insert(key, data)
             else:
                 self.right = Node(key, data)                  
         else:
             raise KeyError('...') #같은 값은 없다고 가정했으므로 keyError 발생시킴
             
      def countChildren(self):
          count = 0
          if self.left:
              count += 1
          if self.right:
              count += 1
          return count           
          
     
 class BinSearchTree:
     def __init__(self):
         self.root = None
         
     def inorder(self):
         if self.root:
             return self.root.inorder()
         else:
             return []
             
     def min(self):
         if self.left:
             return self.left.min()
         else:
             return self
             
     def lookup(self, key, parent=None):
         if self.root:
             return self.root.lookup(key)
         else:
             return None, None
         
     def insert(self, key, data):
         if self.root:
             self.root.insert(key, data)
         else:
             self.root = Node(key, data)
         
     def remove(self, key):
         node, parent = self.lookup(key)
         if node:
             nChildren = node.countChildren()
             # The simplest case of no children
             if nChildren == 0:
                 # 만약 parent 가 있으면
                 # node 가 왼쪽 자식인지 오른쪽 자식인지 판단하여
                 # parent.left 또는 parent.right 를 None 으로 하여
                 # leaf node 였던 자식을 트리에서 끊어내어 없앱니다.
                 if parent:
                     if parent.left == node:
                         parent.left = None
                     if parent.right == node:
                         parent.right = None
                 # 만약 parent 가 없으면 (node 는 root 인 경우)
                 # self.root 를 None 으로 하여 빈 트리로 만듭니다.
                 else:
                     self.root = None
             # When the node has only one child
             elif nChildren == 1:
                 # 하나 있는 자식이 왼쪽인지 오른쪽인지를 판단하여
                 # 그 자식을 어떤 변수가 가리키도록 합니다.
                 if node.left:
                     nodeChild = node.left
                 if node.right:
                     nodeChild = node.right
                 # 만약 parent 가 있으면
                 # node 가 왼쪽 자식인지 오른쪽 자식인지 판단하여
                 # 위에서 가리킨 자식을 대신 node 의 자리에 넣습니다.
                 if parent:
                     if parent.left == node:
                         parent.left = nodeChild
                     if parent.right == node:
                         parent.right = nodeChild
                 # 만약 parent 가 없으면 (node 는 root 인 경우)
                 # self.root 에 위에서 가리킨 자식을 대신 넣습니다.
                 else:
                     self.root = nodeChild
             # When the node has both left and right children
             else:
                 parent = node
                 successor = node.right
                 # parent 는 node 를 가리키고 있고,
                 # successor 는 node 의 오른쪽 자식을 가리키고 있으므로
                 # successor 로부터 왼쪽 자식의 링크를 반복하여 따라감으로써
                 # 순환문이 종료할 때 successor 는 바로 다음 키를 가진 노드를,
                 # 그리고 parent 는 그 노드의 부모 노드를 가리키도록 찾아냅니다.
                 while successor.left:
                     parent = successor
                     successor = successor.left                    
                 # 삭제하려는 노드인 node 에 successor 의 key 와 data 를 대입합니다.
                 node.key = successor.key
                 node.data = successor.data
                 # 이제, successor 가 parent 의 왼쪽 자식인지 오른쪽 자식인지를 판단하여
                 # 그에 따라 parent.left 또는 parent.right 를
                 # successor 가 가지고 있던 (없을 수도 있지만) 자식을 가리키도록 합니다.
                 if parent.left == successor:
                     if successor.countChildren() == 0:
                         parent.left = None
                     else:
                         parent.left = successor.right
                 elif parent.right == successor:
                     if successor.countChildren() == 0:
                         successor.parent.right = None
                     else:
                         successor.parent.right = successor.right                                   
 
             return True  

         else:
             return False
         
         
