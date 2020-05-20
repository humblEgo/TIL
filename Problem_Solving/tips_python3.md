# Tips for Problem Solving with python3

문제 풀며 얻은 팁을 정리합니다.

- [stack_queue]

### stack_queue

stack과 queue를 따로 구현할 필요없이 list로 해결해버릴 수 있다.

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
  - peek: slice 활용
  ```python
  >>> list = [1,2,3]
  >>> list[-1]
  3
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
  - peek: index사용

[참고: python v3.1.5 documentatoin](https://docs.python.org/3.1/tutorial/datastructures.html)
