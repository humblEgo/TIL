### 하노이의 탑

Q) 세 개의 막대와 여기에 쌓여질 서로 다른 크기의 원반들이 있다. 퍼즐이 시작될 떄는 원반들이 한 막대에 크기가 작은 것부터 큰 순서로, 제일 위에 제일 작은 원반이 있는 원뿔 형태로 쌓여 있다. 
전체 원반을 다른 막대로 다음의 규칙을 지키면서 옮겨야한다.
 - 한 번에 하나의 원반만 옮길 수 있다.
 - 옮길 때마다 한 막대의 맨 위의 원반을 다른 막대에 이미 놓여 있는 원반 위로 옮기게 된다.
 - 자기보다 작은 원반 위로는 옮길 수 없다.
 
 
A) 아래 내용처럼 재귀적으로 풀 수 있다.
```C
void TowersOfHanoi(int n, char frompeg, char topeg, char auxpeg) {
    //원반이 하나면 옮기고 리턴한다.
    if(n==1) {
        pritnf("원반 1을 막대 &c로부터 막대 &c로 옮긴다.",frompeg, topeg);
        return;
        }
    //위의 n-1개 원반을 C를 보조탑으로 이용해서 A에서 B로 옮긴다.
    TowersOfHanoi(n-1, frompeg, auxpeg, topeg);
    
    //나머지 원반을 A에서 C로 옮긴다.
    printf("\n원반 &d를 막대 %c로부터 막대 %c로 옮긴다.", n, frompeg, topeg);
    
    // n-1개 원반을 A를 보조탑으로 이용해서 B에서 C로 옮긴다.
    TowersOfHanoi(n -1, auxpeg, topeg, frompeg);
    }
 ```
