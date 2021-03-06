## 선형 배열
----
배열은 원소들을 순서대로 늘어놓은 것이며, 선형 배열은 데이터들이 line처럼 일렬로 늘어선 형태를 말한다.
순서가 있으므로, 값마다 index가 부여된다.

파이썬에서는 list를 통해 배열을 구현할 수 있고, Java 등과 달리 **'동일하지 않은 데이터타입'**의 값으로 리스트를 구현할 수도 있다.

아래 두 연산은 리스트 끝에 대해서 적용되므로, 리스트 길이에 무관한 **상수시간**이 소요되며, **O(1)의 시간복잡도**를 가진다. 
 1. 원소 꺼내기 (끝에 value가 삽입되어 리스트의 길이가 길어짐.)
  <pre>List.append(value)</pre>
 2. 끝에서 꺼내기 (끝에서 나오며 리스트에서도 삭제됨.)
  <pre>List.pop()</pre>
 
아래 두 연산은 리스트 길이에 따라 소요시간이 바뀌는 대표적인 연산이다. 리스트의 길이에 비례하므로 **선형시간**이 걸린다고 표현하며, **O(n)의 시간복잡도**를 가진다고 표현한다.
 1. 원소 삽입
 2. 원소 삭제
