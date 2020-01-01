### 스택?

스택은 일종의 리스트이다.
단, 데이터의 삽입과 삭제가 한쪽 끝에서만 이루어지며 LIFO(Last In First Out)으로 작동한다.
삽입/삭제가 일어나는 쪽을 스택의 top이라고 부른다.



1. 배열로 구현한 경우
```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Item; // 지금은 int형 데이터를 넣는 stack을 구현했으나, 다른 데이터형 쓸 떈 이것만 바꿔쓰자. 

typedef struct stack_type* Stack;

Stack create();
void deleteStack(Stack s);
void make_empty(Stack s);
bool is_empty(Stack s);
void reallocate(Stack s); //스택이 꽉 찼을 때 배열으 크기를 두배로 만드
void push(Stack s, Item i);
Item pop(Stack s);
Item peek(Stack s);

#define INIT_CAPACITY 100

struct stack_type {   //하나의 스택에 들어가야하는 요소 정의.
    Item* contents; //안에 들어있는 배열의 이름이 contents
    int top; 
    int size; // 스택의 역할을 하는 배열의 크기
};


static void terminate(const char* message) { //프로그램 종료 기능
    printf("%s\n", message);
    exit(1); //프로그램 종료
}

Stack create() { //스택을 만들고 만들어진 스택을 반환.
    Stack s = (Stack)malloc(sizeof(struct stack_type));  //스택자체를 stack_type의 포인터로 정의해뒀으므로, 걍 Stack 입력.
    
    if (s == NULL) {
        terminate("Error in create: stack could not be created.");
    }
    s->contents = (Item*)malloc(INIT_CAPACITY * sizeof(Item));
    
    if (s->contents == NULL) {
        free(s);
	terminate("Error in create: stack could not be created.");
    }
    s->top = -1;
    s->size = INIT_CAPACITY;
    return s;
}

void deleteStack(Stack s) {
    free(s->contents);
    free(s);
}

void reallocate(Stack s){
    Item* tmp = (Item*)malloc(2 * s->szie * sizeof(Item));
    if (tmp == NULL){ //malloc 실패했을 경우
        terminate("Error in create: stack could not be created.");
    }
    for(int i= 0; i<(s->size); i++){
        temp[i] = s->contetns[i];
    }
    free(s->contents);
    s->contents = tmp;
    s->size *= 2;
}


void make_empty(Stack s){
    s->top = -1;
}

bool is_empty(Stack s){
    return s->top == -1;
}


void push(Stack s, Item i){
    if(is_full(s)){  //stack이 가득찼는지 확인
        reallocate(s);  //stack이 가득찼다면 배열크기 두배로 증가시킴.
    }
    s->top++;
    s->contents[s->top] = i;	
}

Item pop(Stack s) {
    if(is_empty(s)){
        terminate("Erro in pop: stack is empty.");
    }
    s->top--;
    return s->contents[s->top+1];
}

Item peek(Stack s){
    if(is_empty(s)){
        terminate("Error in peek: stack is empty.");	
    }
    return s->contents[s->top];   
}
```

----


2. 연결리스트로 구현한 경우
 - 구현해본 기본 기능
   - createStack: stack을 생성하고 메모리 할당
   - deleteNode: stack을 삭제하고 메모리 반환
   - createNode: Node를 생성하고 메모리 할당
   - deleteNode: Node를 삭제하고 메모리 반환   
   - pushNode: Stack에 새로운 Node를 삽입
   - popNode: Stack의 top에 있는 Node를 Stack에서 제거하고 반환 (메모리 반환은 고려 x)
   - peek: Stack의 top에 있는 Node를 제거하지 않고 data값 반환   



```C

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
