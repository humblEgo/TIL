# Closer란?

클로저는 함수를 둘러싼 환경(지역 변수, 코드 등)을 계속 유지하다가, 함수를 호출할 때 다시 꺼내서 사용하는 함수를 뜻한다.

- 클로저 사용하기

  - 아래와 같이 사용한다.

  ```python
  def calc():
      a = 3
      b = 5
      def mul_add(x):
          return a * x + b
  ```

  ```python
  c = calc()
  print(c(1), c(2), c(3)) # 8, 11, 14
  ```

  - 이처럼 클로저를 사용하면 프로그램의 흐름을 변수에 저장할 수 있어서 지역 변수와 코드를 묶어서 사용할 수 있다. 또한 클로저에 속한 지역 변수는 바깥에서 직접 접근할 수 없으므로 데이터를 숨기고 싶을 때 활용할 수 있다.

- lambda로 클로저 만들기
  - 클로저는 다음과 같이 lambda로도 만들 수 있다.
  ```python
  def calc():
      a = 3
      b = 5
      return lambda x: a * x + b
  ```
  ```python
  c = calc()
  print(c(1), c(2), c(3)) # 8, 11, 14
  ```
- 클로저의 지역 변수 변경하기

  - 클로저의 지역변수를 변경하고 싶다면 `nonlocal`을 아래와 같이 사용하면 된다.
  - _`nonlocal`을 변수명에 선언하면 가장 가까운 바깥쪽에 있는 지역변수를 사용할 수 있게 된다._

  ```python
  def calc():
      a = 3
      b = 5
      total = 0
      def mul_add(x):
          nonlocal total
          total = total + a * x + b
          print(total)
      return mul_add

  c = calc()
  c(1) #8
  c(2) #19
  c(3) #33
  ```

출처: [코딩도장](https://dojang.io/mod/page/view.php?id=2366)
