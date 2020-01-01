### 스택?

스택은 일종의 리스트이다.
단, 데이터의 삽입과 삭제가 한쪽 끝에서만 이루어지며 LIFO(Last In First Out)으로 작동한다.
삽입/삭제가 일어나는 쪽을 스택의 top이라고 부른다.

 - 구현해본 기본 기능
   - createStack: stack을 생성하고 메모리 할당
   - deleteNode: stack을 삭제하고 메모리 반환
   - createNode: Node를 생성하고 메모리 할당
   - deleteNode: Node를 삭제하고 메모리 반환   
   - pushNode: Stack에 새로운 Node를 삽입
   - popNode: Stack의 top에 있는 Node를 Stack에서 제거하고 반환 (메모리 반환은 고려 x)
   - peek: Stack의 top에 있는 Node를 제거하지 않고 data값 반환   

```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sNode {
	char* data;
	struct sNode* next;
} Node;

typedef struct listStack {
	Node* top;
	int size;
} listStack;

void createStack(listStack** Stack) { //stack을 생성

	(*Stack) = (listStack*)malloc(sizeof(listStack));
	(*Stack)->top = NULL;
	(*Stack)->size = 0;
}

Node* createNode(char* newChar) {

	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = (char*)malloc(strlen(newChar) + 1); // 끝에 NULL 값을 넣어주기 위한 메모리 할당

	strcpy(newNode->data, newChar);		
	newNode->next = NULL; // newNode의 next를 NULL로 초기화
}

void deleteNode(Node* removeNode) {  //node 삭제하며 할당한 메모리 반환
	free(removeNode->data);
	free(removeNode);
}

Node* popNode(listStack* stackList) {	//stackList 마지막 값 삭제하며 top값 반환
	Node* tempNode;

	//node가 하나도 없었을 경우
	if (stackList->size == 0) {
		printf("stack is empty!!");
		tempNode = NULL;
	}
	else {
		//node가 하나 이상 있었을 경우		
		tempNode = stackList->top;
		stackList->top = stackList->top->next;
		stackList->size--;
	}
	return tempNode;
}


void deleteStack(listStack* stackList) { //stackList 삭제하며 할당한 메모리 반환
	int count = stackList->size;
	int i;
	Node* tempNode;

	for (i = 0; i < count; i++) {
		tempNode = popNode(stackList);
		deleteNode(tempNode);
	}
	free(stackList);
}

void pushNode(listStack* stackList, Node* newNode) { //stackList 마지막에 node 추가	
		newNode->next = stackList->top;
		stackList->top = newNode;	
	    stackList->size++; 
}


char* peek(listStack* stackList) { //stackList의 top값 확인(삭제하지 않음)
	if (stackList->size == 0) {
		return NULL;
	}
	return stackList->top->data;
}
```
