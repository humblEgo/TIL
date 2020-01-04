### 트리?
----
 - 정점(node)와 정점들을 서로 잇는 간선(edge)을 이용하여 데이터 배치 형태를 추상화한 자료구조
 - 순환하는 길이 없는 그래프(graph)로도 정의하기도 함.
 
 - node의 위치에 따른 구분
  - root node: 최초의 node
  - leaf node: 트리의 가장 바깥쪽 node(child node가 없는 node)
  - internal node: root node와 leaf node를 제외한 node
  
  - node의 연결관계에 따른 구분
   - parent node: 직접 연결되어있는 두 node 중 root 쪽에 더 가까운 node
   - chlid node: 직접 연결되어있는 두 node 중 root 쪽으로부터 더 먼 node
   - sibling node: 같은 parent node를 가진 chlid node간의 관계
   - uncles node: parent node의 sibling node
   - ancestor node: parent node 이후 root node까지 이르는 연결관계에 있는 모든 node
   - descendant node: child node 이후 leaf node까지 이르는 연결관계에 있는 모든 node
   
 - node's level: root node의 level을 0으로 정의할 경우, 이후에 이어서 해당 node에 도달하는데 필요한 엣지의 개수를 말한다.
 - 이 경우, tree's Height는 최대 수준(level) + 1 을 뜻한다. (tree's depth라고도 한다.)
 - node's degree(차수): 자식(서브트리)의 수
  
 ### 여러 형태의 트리
 ----
 여러가지 이슈를 해결하고자 다양한 형태의 트리들이 고안되었다. 그 중 3가지는 아래와 같다.
  1) 이진 트리(Binary Trees): 모든 노드의 degree가 2이하인 트리. 재귀적으로 정의하자면, '빈 트리(empty tree)이거나 루트 노드 + 왼쪽 서브트리 + 오른쪽 서브트리, (단, 이 때 왼쪽과 올느쪽 서브트리 또한 이진 트리)' 라고 정의할 수 있다.
  2) 포화 이진 트리(full binary trees): 모든 레벨에서 노드들이 모두 채워져 있는 이진 트리
  3) 완전 이진 트리(complete binary trees): '높이 k인 완전 이진 트리'라고 부르는데, 이는 k-2 높이까지는 완전 이진 트리로 구성되어있고, k-1부터는 왼쪽에서 부터 순차적으로 노드가 채워져 있는 이진트리를 뜻한다.
  
  
 ### 이진트리 구현
 연산 정의
  - size(): 현재 트리에 포함되어 있는 노드의 수를 구함
  - depth(): 현재 트리의 깊이 (또는 높이; hegith)를 구함
  - traversal
    - 깊이 우선 순회 (depth first traversal)
      - 중위 순회(in-order traversal)
      - 전위 순회(pre-order traversal)
      - 후외 순회(post-order traversal)
    
    - 넓이 우선 순회(Breadth Frist Traversal): level이 낮은 노드를 우선으로 방문, 같은 level의 노드들 사이에서는, 부모 노드의 방문 순서에 따라 방문하고, 왼쪽 자식 노드를 오른쪽 자식보다 먼저 방문.
 
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
 
 class Node:
 
     def __init__(self, item):
         self.data = item
         self.left = None
         self.right = None
          
     def size(self):
         leftSubtreeSize = self.left.size() if self.left else 0
         rightSubtreeSize = self.right.size() if self.right else 0
         return leftSubtreeSize + rightSubtreeSize + 1
     
     def depth(self):
         leftSubtreeDepth = self.left.depth()
         rightSubtreeDepth = self.rightdepth()
         
         if leftSubtreeDepth >= rightSubtreeDepth:
             return leftSubtreeDepth + 1
         else
             retunr rightSubtreeDepth + 1
             
     def inorder(self):
         traversal = []
         if self.left:
             traversal += self.left.inorder()
         traversal.append(self.data)
         if self.right:
             traversal += self.right.inorder()
         return traversal
         
       
     
 class BianryTree:
     
     def __init_-(self, r):
         self.root = r
         
     def size(self):
         if self.root:
             return self.root.size()
         else:
             return 0
     
     def depth(self):
         if self.root:
             return self.root.depth()
         else:
             return 0
             
     def inorder(self):
         if self.root:
             return self.root.inorder()
         else:
             return []
             
     def breadthFirstTraversal(self):
         traversal = []
         q = ArrayQueue()
         
         if self.root:
             q.enqueue(self.root)
             
             while not q.isEmpty():
                 mov = q.dequeue()
                 traversal.append(mov.data)
                 if mov.left:
                     q.enqueue(mov.left)
                 if mov.right:
                     q.enqueue(mov.right)
         else:
             return []
         return traversal
```

