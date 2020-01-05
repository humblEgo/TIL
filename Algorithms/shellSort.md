### 셸 정렬

단순 삽입정렬의 '이미 정렬을 마쳤거나 정렬에 마친 상태에 가까우면 정렬 속도가 매우 빨라진다'는 장점을 살리고, '삽입할 위치가 멀리 떨어져 있으면 이동(대입)해야 하는 횟수가 만항진다.'는 단점을 보완한 정렬 알고리즘이다.
도널드 셸이 고안해서 셸 정렬이라고 명명되었으며, 퀵 정렬이 고안되기 전까지는 가장 빠른 알고리즘으로 알려져 있었다고 한다.

 - 과정
   1. 정렬해야할 리스트를 일정한 기준에 따라 분류
   2. 연속적이지 않은 여러 개의 부분 리스트를 생성
   3. 각 부분 리스트를 삽입 정렬을 이용하여 정렬
   4. 모든 부분 리스트가 정렬되면 다시 전체 리스트를 더 적은 개수의 부분 리스트로 만든 후에 알고리즘을 반복
   5. 위의 과정을 부분 리스트의 개수가 1이 될 때까지 반복
   
 C로 구현한 것은 다음과 같다.
 ```C
 # include <stdio.h>
 # define MAX_SIZE 10
 
 
 //gap만큼 떨어진 요소들을, first에서 last까지를 범위로 하여, 삽입정렬 수행한다.
 void inc_insertion_sort(int list[], int first, int last, int gap){ 
     int i, j, key;
     
     for( i = first + gap; i <= last; i= i+ gap){
         key = list[i]; //현재 삽입될 숫자인 i번째 정수를 key 변수로 복사함.
     }
     
     // 현재 정렬된 배열은 i-gap까지이므로 i-gap번째부터 역순으로 조사한다.
     // j 값은 first 이상이어야 하고
     // key 값보다 정렬된 배열에 있는 값이 크면 j번째를 j + gap번째로 이동
     for( j = i -gap; j >= first && list[j]> key; j = j-gap) {
         list[j+gap] = list[j]; // 레코드를 gap만큼 오른쪽으로 이동
     }
     
     list[j+gap] = key;
 }
 
void shell_sort(int list[], int n) {
    int i, gap;
    
    for(gap = n/2; gap>0; gap =gap/2){
        
        if((gap%2)==0){ //gap이 짝수면 홀수로 만든다.
        gap++;
        }
        
        for(i=0; i<gap; i++{
            inc_insertion_sort(list, i, n-1, gap);
        }
    }
}
```


