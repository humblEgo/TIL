# 뉴턴법/뉴턴-랩슨법

## Newton's method?

- 뉴턴법은 뉴턴-랩슨법(Newton-Raphson method)라고도 불리는데, 방정식 **`f(x) = 0`의 해를 근사적으로 찾을 때** 유용하게 사용되는 방법이다.

- 원리는 현재 x값에서 접선을 그리고, 그 접선이 x축과 만나는 지점으로 x를 이동시켜 가면서 점진적으로 해(f(x) = 0이 되는 x 값)를 찾는 식이다.

### 뉴턴법의 특징 및 제약 사항
- f(x)가 연속이고 미분가능해야 한다.
- f(x)에 해가 존재해야한다.
- 적절한 초기값을 주는 것이 포인트이다.
  - 초기값에 따라 해를 구하는데 시간이 너무 오래걸리거나 아예 해를 찾지 못할 수도 있다.
  - f(x) = 0인 해가 여러개 있다면, 뉴턴법은 그 중 하나의 해만 찾아줄 뿐이며, 초기값 x를 어떤 값으로 주느냐에 따라 구해지는 해가 달라질 수 있다. 