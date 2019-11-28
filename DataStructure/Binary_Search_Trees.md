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
         
         
