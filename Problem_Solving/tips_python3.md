# Tips for Problem Solving with python3

문제 풀며 얻은 팁을 정리합니다.

- [stack_and_queue]

#### stack_and_queue

stack과 queue를 따로 구현할 필요없이 list로 해결해버리자!

- Stack
  - push: append() 메소드 활용
  ```python
  >>> list = [1, 2]
  >>> list.append(3)
  >>> list
  [1, 2, 3]
  ```
  - pop: pop() 메소드 활용
  ```python
  >>> list = [1, 2, 3]
  >>> list.pop()
  >>> list
  [1, 2]
  ```
- Queue
  - push: append() 메소드 활용
  - pop: pop(0) 메소드 활용
  ```python
  >>> list = [1, 2, 3]
  >>> list.pop()
  >>> list
  [2, 3]
  ```
