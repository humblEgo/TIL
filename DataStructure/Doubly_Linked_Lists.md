### Node를 양방향으로 연결시킨 Linked Lists
----
 - Node를 생성할 때 양방향을 고려하여 생성한다.
 <pre>
 class Node:
     def __init__(self, item):
         self.data = item
         self.prev = None
         self.next = None
 </pre>
 
 - 양방향 모두에 Dummy node를 생성하여 편의를 도모해보았다. 이 경우, 아래와 같이 구현할 수 있다.
 <pre>
 class DoublyLinkedList:
     def __init__(self,item):
         self.nodeCount = 0
         self.head = Node(None)
         self.tail = Node(None)
         self.head.prev = None
         self.head.next = self.tail
         self.tail.prev = self.head
         self.tail.next = None
         
     def traverse(self):     #이중연결리스트를 head에서 tail까지 순회하며 리스트로 값을 반환
         result = []
         curr = self.head
         while curr.next.next:
             curr = curr.next
             result.append(curr.data)
         return result
         
     def reverse(self):      #이중연결리스트를 tail에서 head 방향으로 순회하며 리스트로 값을 반환
         result = []
         curr = self.tail
         while curr.prev.prev:
             curr = curr.prev
             result.append(curr.data)
         return result
         
     def insertAfter(self, prev, newNode): #특정 노드 바로 뒤에 새로운 노드를 삽입
         next = prev.next
         newNode.prev = prev
         newNode.next = next
         prev.next = newNode
         next.prev = newNode
         self.nodeCount += 1
         return True
         
     def getAt(self, pos):                 #head로부터 pos번째에 위치한 노드를 불러옴
         if pos < 0 or pos > self.nodeCount:
             return None
         
         i = 0
         if pos > self.nodeCount//2:                 #pos 값에 따라 값 검색 방향 설정하여 조금 더 효율화
             curr = self.tail
             while i < self.nodeCount - pos + 1:
                 curr = curr.prev
                 i += 1
         else:
             curr = self.head
             while i < pos:
                 curr = curr.next
                 i += 1
             return curr
         
     def insertAt(self, pos, newNode):   #pos번째에 노드를 삽입
         if pos < 1 or pos > self.nodeCount + 1:
             return False
         
         prev = self.getAt(pos-1)
         return self.insertAfter(prev,newNode)
         
     def insertBefore(self, enxt, newNode)
     
     def popAfter(self, prev): #특정 값 다음에 위치한 노드를 삭제하며 값을 반환
         if prev == self.tail or prev == self.tail.prev:
             return False
         curr = prev.next
         curr.next.prev = prev
         prev.next = curr.next
         self.nodeCount -= 1
         return curr.data

     def popBefore(self, next):
         if next == self.head or next == self.head.next:
             return False
         curr = next.prev
         curr.prev.next = next
         next.prev = curr.prev
         self.nodeCount -= 1
         return curr.data
      
      def popAt(self, pos)
          if pos < 1 or pos > self.nodeCount:
              raise IndexError
          prev = self.getAt(pos-1)
          return self.popAfter(prev)
          
      def concat(self, L)
          ALastNode = self.tail.prev
          BFirstNode = L.head.next
        
          ALastNode.next = BFirstNode
          BFirstNode.prev = ALastNode
          self.tail = L.tail
          L.head = self.head
          self.nodeCount += L.nodeCount    
     </pre>   


----
### C언어로 구현한 경우


```C

#include <stdio.h>
#include <stdlib.h> //malloc과 free 함수를 사용하기 위해 include

typedef struct listNode {
	int Data;
	struct listNode* Next;  //다음 노드를 연결하는 포인터를 작성
	struct listNode* Prev;  //이전 노드를 연결하는 포인터를 작성
} Node;

Node* createNode(int data) { // 노드 생성 기능 구현(데이터 주면 노드 만들어서 만든 노드 포인터를 리턴함)

	Node* newNode = (Node*)malloc(sizeof(Node)); // 노드 사이즈만큼 메모리 할당

	// varaibles initalization
	newNode->Data = data;
	newNode->Next = NULL;
	newNode->Prev = NULL;

	return newNode;
}

void deleteNode(Node* Node) { // 노드 삭제
	free(Node);
}

Node* getNodeAt(Node* head, int index) { //index에 있는 node를 반환
	Node* traverse = head;
	int count = 0;

	while (traverse != NULL) {
		if (count++ == index){
			return traverse;
			}
		traverse = traverse->Next;
	}
	return NULL;
}

int countNode(Node* head){ //시작점 받으면 리스트에 노드 몇 개인지 반환
	Node* traverse = head;
	int count = 0;
	
	while ( traverse != NULL ) {
		traverse = traverse->Next;
		count++;
	}
	return count;
}

void appendNode(Node** head, Node* newNode) { //새 노드를 리스트 제일 마지막에 추가
    
	if ((*head) == NULL) {                        // no list exists
		*head = newNode;
	}	
	else {                                        // list exists
		Node* traverse = *head;

		while (traverse->Next != NULL) {
			traverse = traverse->Next;
		}

		traverse->Next = newNode;
		newNode->Prev = traverse;
	}	
}

void insertAfter(Node* Current, Node* newNode) {
	//Current가 head라면,
	if (Current->Prev == NULL && Current->Next == NULL) {
		Current->Next = newNode;
		newNode->Prev = Current;
	}
	//Currnet가 not head라면,
	if (Current->Next == NULL) { //Current가 tail일 경우
		Current->Next = newNode;
		newNode->Prev = Current;
	}
	else { //Current가 tail이 아닐 경우
		Current->Next->Prev = newNode;
		newNode->Next = Current->Next;
		Current->Next = newNode;
		newNode->Prev = Current;
	}
}

void removeNode(Node** head, Node* remove){
		//remove node만 하나 있을 때.
		if (remove == *head) {
			*head = remove->Next;
		}
		// remove node의 next가 NULL이 아닐 때
		if(remove->Next != NULL){
			remove->Next->Prev = remove->Prev;			
		}
		// remove node의 prve가 NULL이 아닐 떄,
		if (remove->Prev != NULL) {
			remove->Prev->Next = remove->Next;
		}

		deleteNode(remove);
}
