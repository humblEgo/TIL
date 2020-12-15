> 레일즈 구현시 '필요한 기능을 떠올리고 찾아쓸 수 있는 상태가 되는 것'을 목표로 루비 개념을 훑습니다.

# Why Ruby?

개인적으로 '갈증'을 느낀 다음 학습을 시작하는 것을 선호합니다. 갈증을 해소하기 위한 학습은 즐겁고, 효율적으로 필요한 만큼 공부하기 좋기 때문입니다.

마침 아래 두 요인 덕에 루비에 대한 갈증이 최고조네요ㅎㅎ 굳이 다른 언어를 놔두고 루비를 학습하는 이유!

1. 42seoul 의 마지막 공통써클 프로젝트인 `ft_trancendence`. 이 프로젝트는 루비온레일즈로 게임서버를 만드는 프로젝트입니다. 루비 공부가 필수입니다.

2. 스타트업들이 초기 생산성을 위해 루비온레일즈를 아직도 많이들 채택한다는 점에서 관심이 갔습니다.
   국내에서는 이런 경향이 적어서 아쉽지만, 제가 애용하는 당근마켓도 초기에는 루비온레일즈로 만들었다고 합니다. CTO님 피셜에 의하면, 자신은 파이썬 장고파였는데 다른 팀원의 적극적인 어필로 '생산성의 루비온레일즈'를 택했고, 실제로 생산성 덕을 봤다고 하시더군요. 저도 이것저것 빠르게 만들어보고 싶다보니 기대됩니다.

# 퍼펙트 루비 책 요약 / 2.0~2.7.1 release note

> 개인학습차 책 내용을 메모했습니다. 굳이 정리 안해도 후에 찾아보면 무방할 챕터, 내용은 생략했습니다.

[1장. 루비 개요](https://github.com/humblEgo/TIL/blob/master/Language/Ruby/ruby.md#1%EC%9E%A5-%EB%A3%A8%EB%B9%84-%EA%B0%9C%EC%9A%94)

[2장. 루비 언어 규격](https://github.com/humblEgo/TIL/blob/master/Language/Ruby/ruby.md#2%EC%9E%A5-%EB%A3%A8%EB%B9%84-%EA%B8%B0%EC%B4%88)

[3장. 제어구조/메소드/내장함수](https://github.com/humblEgo/TIL/blob/master/Language/Ruby/ruby.md#3%EC%9E%A5-%EC%A0%9C%EC%96%B4%EA%B5%AC%EC%A1%B0%EB%A9%94%EC%86%8C%EB%93%9C%EB%82%B4%EC%9E%A5-%ED%95%A8%EC%88%98)

[4장. 클래스와 모듈](https://github.com/humblEgo/TIL/blob/master/Language/Ruby/ruby.md#4%EC%9E%A5-%ED%81%B4%EB%9E%98%EC%8A%A4%EC%99%80-%EB%AA%A8%EB%93%88)

[5장. 주요 내장 클래스/모듈](https://github.com/humblEgo/TIL/blob/master/Language/Ruby/ruby.md#5%EC%9E%A5-%EC%A3%BC%EC%9A%94-%EB%82%B4%EC%9E%A5-%ED%81%B4%EB%9E%98%EC%8A%A4%EB%AA%A8%EB%93%88)

[6장. 루비의 클래스 객체](https://github.com/humblEgo/TIL/blob/master/Language/Ruby/ruby.md#6%EC%9E%A5-%EB%A3%A8%EB%B9%84%EC%9D%98-%ED%81%B4%EB%9E%98%EC%8A%A4-%EA%B0%9D%EC%B2%B4)

[7장 동적 프로그래밍](https://github.com/humblEgo/TIL/blob/master/Language/Ruby/ruby.md#7%EC%9E%A5-%EB%8F%99%EC%A0%81%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D)

[8장 Proc 객체](https://github.com/humblEgo/TIL/blob/master/Language/Ruby/ruby.md#8%EC%9E%A5-proc-%EA%B0%9D%EC%B2%B4)

[9장 Method 클래스](https://github.com/humblEgo/TIL/blob/master/Language/Ruby/ruby.md#9%EC%9E%A5-method-%ED%81%B4%EB%9E%98%EC%8A%A4)

10. 루비의 리플렉션 프로그래밍

11. 라이브러리

12. 내장 툴

13. gem 패키지 작성법

14. 자주 사용되는 외부 툴

15. 커맨드라인 애플리케이션 개발

16. 웹 애플리케이션 개발

> 책은 ruby 2.0 version 을 기준으로 기술되어있지만 저는 레일즈 6.x.x. 버전을 써야합니다. 그래서 2.7.1 버전까지의 변경점을 추가로 확인했습니다.

[+) ruby 2.0~2.7.1 release note]()

# 1장 루비 개요

### 모든 것이 객체

루비는 순수 객체지향 프로그래밍 언어이다. 즉, C 계열 언어들과 달리 원시형에 해당되는 자료형이 없고 모든 것이 그야말로 '객체'이다.

그래서 아래처럼 int나 bool 값에도 메소드를 호출할 수 있다.

```ruby
ㅁp 1.t_s 							# "1"을 출력
p true.to_s						# "true"를 출력
p nil.class 					# NilClass 출력
p nilClass.ancestors 	# [NilClass, Object, Kernel, BasicObject] 출력. 호출한 클래스의 상속관계를 나타낸다.
```

### 루비는 여러 종류가 있다.

마츠모토씨가 만든 루비를 MRI(Matz' Ruby Implementation)이나 CRuby(주로 C언어로 개발됨)이라 부른다. 그 외 루비들 중 대표적인 것은 아래와 같다.

- JRuby: 자바로 개발된 루비. 자바 라이브러리도 이용할 수 있다.
- MacRuby: 맥의 코코아 프레임워크 등을 바로 사용할 수 있도록 개조한 루비
- Rubinius: 루비 자신을 이용해서 개발된 루비
- ruby: 임베디드용 경량판 루비

## 코딩스타일

루비를 쓰는(썼던) 기업들을 참고하자!

- [Ruby style guide by github](https://github.com/github/rubocop-github/blob/master/STYLEGUIDE.md)
- [Ruby style guide by Airbnb](https://github.com/airbnb/ruby#whitespace)

#### 네이밍

- 클래스, 모듈
  - 대문자로 시작 + 카멜케이스 사용
- 메소드명
  - 영문 소문자 및 구분자 '\_'를 이용해서 스네이크 케이스로 작성
- boolrean 값을 반환하는 메소드명
  - 메소드명 뒤에 물음표(?)를 붙여서 기술한다.
  - `ex) Object#nil?`
- 변수명
  - 메소드명과 동일하게 영문 소문자 + 스네이크 케이스
- 코드 블록 방침
  - 여러 줄에 걸쳐 기술할 경우: `do...end`를 사용한다.
  - 한 줄에 모두 작성할 때는 `{...}`을 사용한다.
  - 단, 처리 우선순위가 달라지는 경우가 있으므로 잘 구별해서 사용하자.

# 2장 루비 기초

#### 메소드 정의

메소드 정의는 def 키워드를 이용해서 기술한다. 마치 python.

```ruby
def 메소드명(인수 ...)... end
```

문자열은 큰따옴표 `""`나 작은따옴표 `''` 모두 쓸 수 있다. 그러나 큰 따옴표의 경우 `#{...}`로 감싸는 루비 코드를 포함시킬 수 있다. 이를 '식 전개'라고 한다.

```ruby
"result: #{2+2}"는 "result:4" 이라는 문자열이 된다.
```

#### 메소드 호출과 블록

메소드 호출은 아래 형식으로 한다.

```
리시버(receiver).메소드명
```

한편 블록은 처리를 하나의 단위로 묶은 것으로, 메소드 호출 시 한 번만 지정할 수 있는 인수의 일종이다. 이런 메소드의 호출을 '블록 메소드 호출'이라고 한다. 블록을 전달받은 메소드는 임의의 시점에 블록을 실행할 수 있다. each 메소드는 배열의 요소 수만큼 블록을 실행한다.

아래 예시를 보자.

```ruby
names.each do |name|
    puts "HELLO, #{name.upcase}"
end
```

- 변수 names를 리시버로 해서 each라는 이름의 메소드를 호출하고 있다.
- 메소드 호출 직후에 코드 블록을 `메소드명(실인수...) do |변수명| ...end` 로 표현한다.

블록은 다음과 같이 '{}'로 감싸서 표현할 수 도 있다.

```ruby
names.each {|name|
	puts "HELLO, #{name.upcase}"
}
```

### 톱 레벨

클래스 정의와 모듈 정의에서 쓰는 정의식 외에는 '톱 레벨' 이라고 부른다. 톱 레벨로 정의된 메소드는 전역 서브 루틴처럼 사용할 수 있으며 다음과 같은 특징을 가진다.

- 메소드 호출 시 리시버를 기술하지 않는다.
- 함수처럼 어디서든(전역) 호출할 수 있다.(극히 일부는 제외)

리시버를 기술하지 않는 경우에도 메소드 호출 시 암묵적인 리시버가 존재한다.

### 메소드 정의와 반환 값

메소드 반환 값은 해당 메소드 내에서 마지막으로 평가되는 식의 결과 값이다. 떄문에 return을 기술하지 않아도 된다.

```ruby
def add(a, b)
	a + b
end

add(1, 1)    # => 2
```

한편 처리 도중에 메소드를 호출한 곳으로 돌아가려면 return을 기술한다. return 값을 부여한 경우에는 그 값이 반환 값이 된다.

### 줄

식과 식은 줄바꿈으로 구분한다. 하지만 여러 식을 한 줄에 기술하고 싶은 경우에는 세미콜론으로 구분한다. 물론 보통은 줄바꿈으로 구분하는 식으로 작성한다.

### 멀티바이트를 포함하는 코드

코드가 한글 등 멀티바이트 문자열을 포함할 떄는 서두에 스크립트 인코딩을 지정한다. //TODO: 2.7버전에서도 이런지 확인해볼 것.

파일 읽기나 정규 표현 인코딩시에는 이 스크립트 인코딩이 사용된다.

```ruby
#!/bin/bash                # <== 요래 shebang(유닉스에서 해석기를 지정해주는 문구)이 있는 경우에는 그 다음 줄에 기술한다.
# coding: utf-8            # <== 여러 형식으로 적을 수 있다. encoding: utf-8  ,  -*- coding: utf-8  ,  vim: set fileencoding=utf-8:
```

### 변수와 상수

변수는 스코프에 따라 구분할 수 있다. 변수 종류에 따라 명명 규칙이 다르므로, 이름만 보고서도 어떤 종류의 변수인지 판별할 수 있다.

- 지역변수

  - 첫 글자를 소문자 영어 또는 언더바(\_)를 사용해야한다. `ex) ruby _ruby`
  - 블록, 메소드 정의, 클래스/모듈 정의, 톱 레벨을 스코프로 가진다.
  - 당연하게도 블록 안이라면 블록 밖에서 정의된 지역 변수를 참조할 수 있다. 반대로 블록 안에서는 블록 밖에서 참조할 수 없다.

- 전역변수

  - 전역변수명은 `$`로 시작해야 한다.
  - 존재하지 않는 전역 변수를 참조하면 `nil`이 반환된다.
  - 역시나 원활한 관리를 위해 가능하면 사용을 자제하자.

- 상수

  - 상수명은 영문 대문자로 시작해야한다.

  - 상수는 대입식을 이용해서 정의한다.

    ```ruby
    FOO_BAR = 'bar'

    puts FOO_BAR   # "bar"를 출력
    ```

  - 상수 대입은 한 번만 해야 하지만, 정의가 완료된 상수에 다시 대입하는 것이 가능하긴하다. 대신 경고문이 뜨므로 가급적 피하자.

  - 메소드 안에서 상수를 정의할 수는 없다. syntax error가 발생한다.

    ```ruby
    def set_foo
    	FOO_BAR = 'bar' # dynamic constant assignment (SyntaxError)
    End
    ```

### 조건 분기와 진리값

루비에서는 `false`와 `nil` 이외의 모든 값은 참으로 취급한다. **즉, 0도 참이 된다.**

### 식

루비 프로그램의 대부분은 어떤 값을 반환하는 식으로 이루어진다. 변수 대입은 오른쪽 값을 반환하고, if는 마지막으로 평가한 값을 반환한다. 심지어 'Hello'나 '1234' 등도 문자나 값을 반환하는 식이다.

### 클래스

class 키워드를 사용하고 클래스명은 영문 대문자로 시작해야 한다.

```ruby
class 클래스명
end
```

클래스로부터 인스턴스는 new 구문으로 생성한다. `클래스명.new`

### 인스턴스 변수

- 인스턴스 내에서만 참조할 수 있는 변수를 뜻한다.
- 이를 통해 객체의 상태를 저장할 수 있다.
- 인스턴스 변수는 '@length'처럼 @으로 시작하는 이름을 사용한다.

```ruby
class Ruler
	def length=(val)		# 루비에서는 인스턴스 변수에 대입하는 메소드 이름 끝에 등호 '='를 붙인다. C++의 연산자오버로딩마냥.
		@length = val
	end

	def length
		@length
	end
end

ruler = Ruler.new

ruler.length = 30
ruler.length  				# => 30
```

일반적으로는 인스턴스 변수에 접근하기 위한 메소드로 `attr_accessor`를 이용한다. C++로 치면 자동으로 getter, setter가 만들어지는 느낌이다.

```ruby
class Ruler
	attr_accessor :length
end
```

### self

메소드 내부에서는 해당 메소드가 있는 인스턴스를 `self`라는 이름의 유사 변수를 이용해서 참조할 수 있다. python과 동일하군, C++로 치면 `this` 같은 느낌!

그리고 역시나 메소드 내부에서 리시버를 생략한 메소드를 호출할 때는 암묵적으로 `self`가 리시버가 된다.

**리시버를 생략할 수 있을 때는 그렇게 하는 것이 일반적이다.**

단, `Ruler#length=` 같은 메소드 호출의 self는 생략할 수 없다. 이를 생략하면 메소드 호출이 아닌 지역변수 대입으로 처리되기 때문이다.

### 초기화

생성자를 `initialize` 메소드를 정의해서 구현한다. `new`의 인수로 전달한 값이 `initialize` 메소드에 인수로 전달된다.

### 클래스 메소드

모든 값은 객체로 취급된다. 고로 클래스도 물론 객체다. 따라서 클래스를 대상으로 메소드를 호출할 수 있다. 이처럼 클래스를 대상으로 호출할 수 있는 메소드를 **클래스 메소드**라고 한다.

클래스 메소드는 메소드명 앞에 self를 붙여서 정의한다. 아래처럼!

```ruby
class Ruler
	attr_accessor :length

	def self.pair
		[Ruler.new, Ruler.new]				# 리시버를 생략해서 [new, new]로 기술할 수도 있다.
	end
end
```

### 클래스 변수

클래스와 해당 인스턴스를 스코프로 하는 변수를 클래스 변수라고 한다.

클래스 변수는 `@@`를 이름 앞에 붙여서 표기한다.

클래스 변수는 클래스 정의 안이나 클래스 메소드에서 참조할 수 있다.

```ruby
class MyClass
	@@cvar = "Hello!"

	def cvar_in_method
		puts @@cvar
	end

	def self.cvar_in_class_method
		puts @@cvar
	end
end
```

### 상속

루비는 단일 상속을 지원한다.

클래스를 상속하려면 클래스 정의시 `<` 로 슈퍼 클래스를 지정한다.

```ruby
class 서브 클래스명 < 슈퍼 클래스명
end
```

그 외엔 뭐.. C++이랑 비슷하다.

- 서브 클래스에는 슈퍼 클래스에서 정의한 메소드가 상속된다.

- 서브 클래스의 인스턴스에서 슈퍼 클래스의 인스턴스 메소드를 호출할 수 있다.

- 서브 클래스에 새로운 메소드를 정의할 수도 있다.

- 슈퍼 클래스에서 이미 정의된 메소드를 서브 클래스에서 다시 정의하는 식으로 오버라이드도 가능하다.

아무것도 상속하지 않은 클래스를 정의할 수는 없다. 클래스 정의시에 슈퍼 클래스를 지정하지 않으면, Object 클래스를 상속한 클래스가 정의된다. 이 Object 클래스에는 객체의 기본적인 동작이 정의되어 있다.

### 모듈

루비에는 모듈이라는 클래스와 비슷한 구조가 있다. **모듈은 '인스턴스화 할 수 없는 클래스 같은 것'이라고 이해하면 된다.**

모듈은 module 키워드를 사용해서 정의한다.

```ruby
module ahebfaud
end
```

모듈 정의 안에는 다른 모듈이나 클래스 정의를 기술할 수 있어서 네임스페이스로 이용할 수 있다. C++처럼 `::` 을 이용해서 참조할 수 있다.

모듈 정의 내에서도 메소드를 정의할 수 있으나, 클래스에 정의한 메소드와는 다른 세가지 용도로 사용된다.

- 특정 메소드를 인스턴스 메소드로 포함
- 특정 객체의 메소드로 포함
- 모듈 함수로 사용

자세한건 4-2장을 참고하자.

### 주요 내장 클래스

루비가 표준으로 가지고 있는 대표적인 클래스를 확인해보자.

- 수치

  - Numeric 클래스를 상속한 몇 가지 서브 클래스(Fixnum, Bignum, Float)에 수치 표기방법이 정의되어있다.
    - 부동소수점 수는 e 뒤에 지수부를 기술할 수 있다.
    - 2진수(0b), 8진수(0 or 0o), 16진수(0x)를 표기할 수 있다.
    - `1_000_000` 큰 수치에 세 자리마다 구분해서 가독성을 높일 수 있다. `1__00`처럼 연달하 기술하거나 수치 값의 맨 앞이나 0x 등 접두사 바로 뒤에 기술할 수는 없다.

- 문자열

  - 여러 줄의 문자열을 표현하려면 `<< 식별자`를 사용해서 히어 도큐먼트(heredoc)로 만들면 된다.

  - 히어 도큐먼트 시작 식별자를 작은 따옴표로 감싸면 식 전개나 백슬래시 기법을 무효화할 수 있다.

    ```ruby
    str = << 'EOS'
    #{foo}\t#{bar}\t#{baz}
    EOS

    # 식전개를 하지 않고 백슬래시 기법도 무시된다.
    puts str    # => "#{foo}\t#{bar}\t#{baz}" 출력됨
    ```

  - 그 외에 문자열 내에서 따옴표를 많이 사용해야하는 경우에는 `%d(It's rainy)`처럼 기술하면 일일이 백슬래시를 붙이지 않아도 된다. 이를 퍼센티지(%) 기법이라고 한다.

### 심볼

앞에 콜론(:)을 붙인 문자열을 심볼(symbol)이라고 한다.

음.. 문자열과 뭐가 다른거지? 식별자나 키워드로 활용할 때 더 빠르고 간편하다고는 하는데 왜 그런걸까?
책 설명이 빈약하여 [Ruby의 심볼(SYMBOL)과 문자열(STRING)은 서로 어떻게 다른가?](http://guruble.com/루비-온-레일스ruby-on-rails-면접에는-어떤-질문들이-나올까/)를 참고해보았다.

- 심볼은 문자열과 달리 '변경이 불가능(immutable)'한 객체이다. 즉, 심볼은 한번 값이 assign 되고나면 값을 변경하는 것이 불가능하다 . 또한 Java에서 final 선언된 변수와 달리 덮어쓰기는 할 수 있다는 의미이다.

- 문자열은 mutable 하기 때문에, 루비 인터프리터는 실제 문자열이 어떤 값을 가지고 있는지 실행시점까지 알 수가 없다. 이것은 다시말해, 우리가 보기에는 동일한 문자열도 서로 다른 메모리 공간에 할당되어있다는 의미이다.

- 반면, 심볼은 Immutable 하기 때문에 한번 heap 메모리상에 생성되고 나면 해당 심볼은 동일한 객체로 재사용이 가능하다. 좀 더 자세히 알아보면, 루비에서 심볼은 단순히 동일한 heap 메모리를 재사용할 뿐만 아니라, `Symbol dictionary`를 통해 관리된다. irb에서 아래처럼 명령어를 실행하면 `Symbol dictionary`에 존재하는 심볼 목록을 확인할 수 있다.

  ```ruby
  > symbol.all_symbols.inspect
  ```

- 이런 특징 때문에 루비에서 대부분의 경우 심볼을 사용하는 것이 문자열을 사용하는 것보다 **메모리 효율성이나 성능 측면에서 유리**하며, hash의 키 등으로 문자열을 사용하는 것보다 심볼을 사용하는 것이 좋다.

심볼에는 상수나 변수, 메소드 이름으로 이용할 수 있는 글자를 사용 가능하다. 그 외의 문자열은 `:'foo-bar'`처럼 따옴표로 감싸 주어야한다.

### 배열

배열은 다수의 객체를 순서대로 나열한 컨테이너 객체이다.

C++과 달리 하나의 배열에 형이 다른 객체를 넣을 수 있다.

배열안에 배열을 넣어서 다차원 배열도 만들 수 있다. 마치 파이썬!

요소가 존재하지 않는 인덱스를 지정한 경우에는 'nil'이 반환된다.

인덱스로 마이너스 값을 지정하면 뒤에서부터 역순으로 세서 요소를 반환한다. 마치 파이썬!

문자열이나 심볼 배열은 퍼센티지 기법을 사용하면 간단하게 기술할 수 있다.

```ruby
%w(Alice bob carol)  #=> ["Alice", "bob", "carol"]
%i(red green blue)   #=> [:red, :green, :blue] # 루비 2.0 이후에 유효
```

요소가 공백을 포함할 때는 백슬래시로 이스케이프 처리를 해줘야한다.

```ruby
%w(foo\ bar hoge\ piyo)		# => ["foo bar", "hoge piyo"]
```

### 해시

연상 배열이라고도 한다. 첨자로 문자열이나 심볼 등 임의 객체를 사용할 수 있따.

해시 첨자는 키(key)라고도 불린다.

```ruby
{키 => 요소}
```

`colors['blue']`와 같이 키를 지정한다. 존재하지 않는 키를 지정하면 nil이 반환된다.

키가 심볼이면 다음과 같이 간단하게 기술할 수 있다.

```ruby
{red: 'ff000', green: '00ff00', blue: '0000ff'}
```

### 범위

루비에는 범위를 표현하는 범위 객체가 존재한다.

범위 구문은 두 객체 사이에 마침표를 배열해서 표현하며, 마침표 수에 따라 마지막 값을 범위에 포함할지가 결정된다.

`1..5` : 마지막 5를 범위에 포함함.

`1...5` : 마지막 5를 포함하지 않는다.

날짜나 문자열 범위 예제는 아래와 같다.

```ruby
vacation = Time.at(1343746800)..Time.at(1346425199)
```

### 정규 표현

문자열에서 특정 패턴과 일치하는 부분을 찾아내거나 유무를 확인한다. 형식은 아래와 같다.

```ruby
#  /pattern/ 기본형식이다.


pattern = /[0-9]+/

# 일치 여부를 진릿값으로 반환
pattern === 'HAL 9000'   		# => true
pattern === 'Hello world'  	# => false

# 최초로 일치한 위치를 정수로 반환
pattern =~ 'HAL 9000'				# => 4
pattern =~ 'Hello world'		# => nil
```

### 퍼센티지 기법의 괄호

퍼센티지 기법에 사용하는 괄호는 다른 괄호 종류나 기호를 사용해도 된다. 문자열이나 정규 표현 등에는 '()'을 자주 사용하기 때문에 '{}' 등의 다른 괄호를 사용해야 할 때가 있다.

```ruby
%q{paren(and paren)}		# => "paren(and paren)"
%r{/usr/(bin|lib)/}			# => /\/usr\/(bin|lib)\//
```

'{}' 이외의 괄호 종류도 사용할 수 있다. 임의의 기호를 이용할 수 있으며, 이때는 양쪽 단에 같은 기호를 사용한다.

```ruby
# 괄호 종류
%q<content>
%q[content]

# 임의의 기호
%q |content|
%q!content!
%q*content*
```

### 블록 객체

블록 객체(Proc)는 함수를 객체로 표현한 것이다. 참고로 Proc은 절차, Procedure의 줄임말이다.

Proc.new에 블록을 지정하면 블록 객체를 생성할 수 있다. Proc.new 메서드는 블록으로 절차(루비 표현식들)를 넘겨 받는다. 가인수는 '|name|'처럼 파이프 기호를 이용해 기술한다.

```ruby
greeter = Proc.new {|name|
	puts "Hello, #{name}!"
}
```

`Kernel#proc` 메서드도 있다. 이 메서드는 `Proc.new`와 같다.

```ruby
p = proc { puts 'Hello, world!'}
p.call() 			# Hello, world!
```

Proc#call을 호출하면 처리가 실행된다. call에 지정한 인수는 블록의 가인수에 대입된다.

```ruby
greeter.call 'Proc'     # "Hello, Proc!" 출력
```

Proc#call의 반환 값은 블록 내에서 마지막으로 평가된 값이다.

```ruby
format = Proc.new {|name|
	name = name.capitalize

	"Hello, #{name}!"
}

format.call('alice')				# => "Hello, Alice!"
```

흥미롭고 혼란스럽게도 블록 객체는 proc 메소드나 lambda 메소드를 사용해서도 기술할 수 있다. 또한 `->`가 자주 사용된다. 이 기법에서는 가인수가 있는 경우에는 `->(name)`처럼 기술한다.

```ruby
by_proc    = proc {|name| puts "Hello, #{name}!" }
by_lambda  = lambda {|name| puts "Hello, #{name}!" }
by_literal = ->(name) { puts "Hello, #{name}!" }
```

후.. 비슷한게 너무 많다. 헷갈리지 않는가? [블록 vs 블록 객체 (Proc 객체) vs lambda](https://www.44bits.io/ko/post/ruby-proc-and-lambda) 글에 잘 정리되어있다! 정독 추천!

### 다중 대입

파이썬처럼 다중 대입이 가능하다.

```ruby
a, b = 1, 2

a, b = [1, 2, 3]			# 배열을 사용한 다중 대입(오른쪽에 남은 3은 무시된다.)

a, b, c = [1, 2]			# 대응하는 요소가 없는 c에는 nil이 대입된다.

a, *b = [1, 2, 3]     # *가 있는 b는 오른쪽에서 남은 요소를 배열로 인식해서 대입한다.

a # => 1
b # => [2, 3]
```

### 예외

`begin~rescue` 절로 처리한다.

```ruby
begin
	1 / 0
rescue ZeroDivisionError
	puts "어떤 문제가 발생했다."

	# 예외 처리
end
```

### 외부 파일 읽기

다른 파일에 있는 프로그램을 읽으려면 require를 이용한다. require는 지정된 파일을 읽어서 실행한다.

require에는 상대경로도 사용 가능하다. 상대 경로를 지정하면 내장 함수가 `$LOAD_PATH`에 등록된 디렉터리에서 파일을 찾는다.

경로가 `./`나 `../`로 시작하는 경우 루비가 실행되고 있는 디렉터리를 기점으로 파일을 찾는다. 또한 파일 확장자는 생략할 수 있다.

### 예약어

루비에는 41개의 키워드가 있다. 이 키워드들은 변수의 이름이나 톱 레벨 상수명으로 사용할 수 없다.

인스턴스 변수, 클래스 변수, 전역 변수에는 각각 @, @@, $ 등의 접두사가 붙는데, 이 경우에는 예약어를 명칭으로 사용할 수 있다. 하지만 혼란을 초래할 수 있으므로 일부러 사용하지는 말자.

### 내장 변수 및 상수

#### 유사 변수(pseudo variable)

- true, false, nil 이외의 유사 변수는 위치나 구문에 따라 참조하는 값이 달라진다.
- 유사 변수에는 값을 대입할 수 없다.
- 유사 변수 목록은 아래와 같다.
  - `self`: 자신을 가리킨다. 리시버 없이 메소드를 호출할 때는 self가 리시버가 된다.
  - `true`: TrueClass의 유일 인스턴스
  - `false`: FalseClass의 유일 인스턴스
  - `nil`: NilClass의 유일 인스턴스
  - `__FILE__`: 현재 실행 중인 소스 파일
  - `__LINE__`: 현재 실행 중인 행 번호
  - `__ENCODING__`: 현재 소스의 스크립트 인코딩

#### 내장변수

내장 변수는 어디에서든 참조할 수 있지만 실제 스코프가 매우 좁고 참조 위치에 따라서 다른 값을 참조하는 경우가 있다.

아래는 대표적인 루비 내장 변수

- 전역내장변수
  - `$stdout, $>` : 표준 출력. 초기값은 STDOUT
  - `$stderr`: 표준 에러 출력, 초깃값은 STDERR
  - `$stdin`: 표준 입력. 초깃값은 STDIN
  - `$*`: 루비 스크립트에 부여된 인수의 배열 ARGV와 같음.
  - `$/, $-0`: 기본 입력의 줄바꿈 구분을 나타내는 문자열. 기본 값은 \n
  - `$:, $LOAD_PATH, $-I`: 라이브러리를 읽어올 때 탐색 대상이 되는 경로의 배열
  - `$DEBUG`: 해석기가 -d 옵션으로 실행됐고 디버그 모드라면 참 값
  - `$VERBOSE`: 이중화 메시지 플래그. nil이면 경고를 출력하지 않는다. false면 중요 경고만 출력하고 true면 모든 경고를 출력
  - `$PROGRAM_NAME`: 실행 중인 스크립트명
  - `$<`: 루비 스크립트에 부여된 인수 또는 표준 입력으로 구성된 가상 파일. ARGFdhk ehddlf
  - `$FILENAME`: 가상 파일 ARGF의 파일명
- 지역내장변수
  - `$SAFE`: 현재 스레드의 세이프 레벨을 표시하는 정수
  - `$!`: 마지막에 발생한 예외 객체
  - `$@`: 마지막에 발생한 예외의 Backtrace를 표시하는 배열
  - `$$`: 실행 중인 루비 프로세스의 프로세스 아이디
  - `$?`: 마지막으로 종료된 프로세스의 종료 상태
  - `$~`: 마지막으로 성공한 정규 표현 일치에 관한 정보(MatchData 객체)
  - `$1, $2, $n ...`: 마지막으로 성공한 정규 표현 일치에서 n번째 괄호에 있는 일치하는 값(n은 양의 정수)
  - `$+`: 마지막으로 성공한 정규 표현 일치에서 마지막 괄호에 일치하는 값

## 심볼

심볼은 앞에 :이 붙은 문자열이다. 심볼은 문자열과 비슷하지만 문자열보다 좀 더 빠른 작성과 실행이 가능하다.

문자열은 작성할 때마다 새로운 문자열을 생성하는 반면, 심볼은 이미 사용한 심볼은 재생성하지 않고 기존의 심볼을 가져와 사용하기 때문이다.

때문에 해시의 키 값으로 자주 사용된다.

```ruby
# hash_1 : 문자열 key, 문자열 value
hash_1 = {"ruby" => "rails", "python" => "Django"}

# hash_2 : 심볼 key, 문자열 value
hash_2 = {:ruby => "rails", :python => "Django"}

# hash_3 : 심볼 key, 문자열 value 축약형
hash_3 = {ruby: "rails", python: "Django"}

# hash_4 : 심볼 key, 심볼 value
hash_4 = {ruby: :rails, python: :Django}
```

보통 3번, 4번 스타일로 만든 해시를 주로 사용한다고 한다.

# 3장 제어구조/메소드/내장 함수

### 메소드로 정의된 연산자

```ruby
| ^ & <=> == === =~ > >= < <= << >> +@ -@
+ - * / % ** ~ [] []= ` ! != !~
```

메소드로 정의된 연산자는 자체적으로 정의할 수도 있다. 연산자 오버로딩!

단항 연산자의 메소드를 정의하려면 `def +@`처럼 연산자명 뒤에 @를 붙인다.

### ==연산자와 객체의 동치성

== 연산자는 대부분의 클래스에서 **동치성을 판단**하기 위해 정의된 메소드이다. 서로 다른 인스턴스라도 값이 같으면 true를 반환한다는 소리. **동일성**, 즉 같은 인스턴스인지 여부를 확인하려면 `equal?` 메소드를 사용하자.

비교 시에 type casting이 자동으로 이루어지는 경우는 거의 없다. 단, 정수와 부동소수점 수를 ==로 비교할 때는 type casiting이 자동으로 이루어져서 `42 == 42.0`은 true가 된다.

### 조건 분기

`if, elsie, else` 는 뭐 C++의 `if, else if, else`와 동일하게 쓰면 된다. 재밌게도 `unless` 라는 조건식이 있다.

```ruby
n = 1

unless n.zero?
	puts 'not zero'
else
	puts 'It's zero'
end									# 'not zero' 출력
```

`unless`는 `if`와 반대로 동작한다. 즉, 지정된 조건식이 false면 처리가 실행된다. `else`도 기술할 수 있지만 `elsif`에 해당하는 것은 없다.

if나 unless는 마지막에 평가된 값을 평가한다. 이 반환 값을 대입이나 메소드 호출의 인수로 사용할 수도 있다.

```ruby
platform =
	if /darwin/ =~ RUBY_PLATFORM
		'Mac'
	else
		'Others'
	end

puts platform										# 'Mac' 또는 'Others' 출력
```

조건식 뒤에는 임의로 `then` 을 기술할 수 있지만 보통 생략한다. 이를 생략하지 않으면 한줄로도 쓸 수 있는데 권장되진 않는다. 차라리 삼항연산자를 쓰자. 삼항연산자는 C, C++과 동일한 방식으로 작성된다.

```ruby
if n.zero? then puts '0이다' else puts '0이 아니다' end   # 추천되는 방법은 아님

result = n.zero? ? '0이다' : '0이 아니다'									# 추천되는 방법.
```

else 절에 분기가 없는 경우에는 후위 if나 후위 unless를 사용하자. 이는 if 수식자 또는 unless 수식자라고도 불린다. 진짜 사람이 자연스레 말하는 것 같은 형태이다.

```ruby
puts '0이다' if n.zero?
puts '0이 아니다' unless n.zero?
```

하나의 비교 대상에 대해 조건식이 여러 개면 case를 이용해서 깔끔하게 기술하자.

```ruby
stone = 'ruby'

case stone
when 'ruby'												# case절의 값과 when절의 값을 리시버로하여 === 연산자로 비교된다.
	puts '7'
when 'peridot', 'sardonyx'				# 복수의 값을 비교하며 하나라도 true면 실행된다.
	puts '8'
when /'diamond'|'crystal'/				# 정규표현으로도 분기를 지정할 수 있다.
else
	puts 'unknown'
end
```

=== 메소드는 ==과 기본적으로 같은 동작을 하지만, 몇 가지 클래스에서는 예외적으로 다른 동작을 한다.

- `Range`: 인수가 자신의 범위 내에 있으면 true를 반환
- `Regexp`: 인수의 문자열이 일치하는 경우는 true를 반환
- `Proc`: 오른쪽을 인수로 해서 블록 객체를 실행한 결과를 반환
- `Module, Class`: 인수가 자신 또는 자신의 서브 클래스 인스턴스면 true 반환

case도 마지막으로 평가된 값을 반환하기 때문에 대입이나 메소드 인수로 사용할 수 있다.

그 외에 when 절 뒤에 then을 써서 한줄로 표현하거나 case에 식을 지정하지 않고 사용하는 방법도 있다.

### 반복

while은 지정한 조건식이 true인 동안 처리식을 반복 실행한다.

재밌는건 until. unitl은 while과 반대로 동작한다. 즉, 지정한 조건식이 false인 동안 계속 실행된다.

```ruby
languages = %w(Perl Python Ruby)
i = languages.length - 1

until i < 0
	puts "hello, #{languages[i]}"
	i -= 1
end											# 문자열이 역순으로 출력된다.
```

while과 until은 식 뒤에 기술할 수도 있다. 이것을 각각 후위 while, 후위 until(또는 while 수식자, until 수식자)라고 한다.

```ruby
sleep 1 while processing?

sleep 1 until prepared?
```

여러 식을 사용하려면 `begin...end` 를 이용하면 된다. 이것과 while, until을 조합하자.

```ruby
# 처음에 반드시 begin 내부가 실행된다. c의 do~while 느낌.
begin
	process1
	process2
end while needed?
```

배열이나 해시 등 each 메소드를 가지고 있는 객체는 for를 사용해서 각 요소에 대한 처리를 할 수 있다.

```ruby
for name in %w(Alice Bob Carol)
	puts name					# 배열 요소를 순서대로 출력
end

# 놀랍게도 루프 내에 정의된 변수를 참조할 수 있다.
puts name						# 'Carol' 출력
```

each에서는 반복 처리를 블록으로 기술했지만, for에 전달하는 식은 블록이 아니다. 루프 안과 밖에서 스코프가 바뀌지 않기 때문에 for 안에서 사용한 변수 name은 for 밖에서도 참조할 수 있다.

해시를 for로 반복 실행할 때도 직관적으로(!) 사용하면 된다.

```ruby
for val in {a: 1, b: 2}
	puts val[0]			# key 출력
	puts val[1]			# value 출력
end

for key, val in {a: 1, b: 2}
	puts key
	puts val
end
```

한편 루비에는 이 외에도 사용하기 쉬운 다양한 반복 메소드가 존재한다. 이런 이유로 지금까지 등장한 제어 구조를 통해 반복 처리를 하는 경우는 드물다고한다. 예를들어, 배열 반복에는 each를 주로 사용한다. 단순한 무한 반복에는 `Kernal.#loop`를 사용하는 편이 더 간단하고 의도도 명확해진다. n회 반복하고 싶으면 Integer 클래스가 제공하고 있는 times 메소드를 이용하자.

```ruby
loop do									# 무한반복
	puts 'infinity loop!'
end

2.times do							# 2회 반복
	puts 'loop 2 times'
end
```

- each
  - 배열에 내장되어있는 반복자이다. 파이프 사이에 선언한 변수에 배열의 값을 하나씩 담아서 실행한다.
  - ex) `arr.each {|a| puts a}`
- collect
  - 역시 배열에 내장된 반복자이다. 파이프 사이에 선언한 변수에 각 배열 값을 사용하여 새로운 배열을 생성할 수 있다.
  - ex) `b = a.collect{|x| x*10}`

루비에서는 배열과 해시를 collections라고 부른다. 그만큼 비슷하다는 뜻!

### 점프 구문

`break` : 루프 처리를 중단한다. `break`에 전달하는 값은 반복 구문이나 메소드의 반환 값이 된다.

`next`: 루프 안에서 next를 호출하면 다음 반복으로 넘어간다. 마치 C/C++의 continue 문!

`redo`: 다시 한번 해당 반복을 수행한다.

### 프로그램 끝을 명시

파일 내에서 프로그램 끝을 명시하려면 `__END__` 키워드를 사용한다. `__END__` 이후에 작성된 것은 루비 프로그램으로 실행되지않고, `DATA`라는 상수에 `FILE` 객체로 저장되어 실행 시에 참조할 수 있다.

`__END__` 키워드가 없으면 상수 `DATA`는 생성되지 않는다.

### 예외 처리

다른 언어처럼, 루비도 예외가 발생하면 보완 처리된 때까지 콜 스택을 거슬러 올라간다. 어디에도 보완처리가 되어있지 않으면 인터프리터가 예외 메세지를 출력하고 이상 종료를 하게 된다.

예외를 발생시키려면 `Kernel.#raise` 를 사용한다.

```ruby
raise 'error!'											# RuntimeError: error!  문자열을 던지는 경우다.
raise StandardError, 'error!'				# StandardError: error! 에러 객체를 던질 수도 있다. 두 번째 인자로 예외메세지를 지정한다.
```

C++의 try~catch 문처럼 `begin~rescue` 구문을 사용하자.

```ruby
begin
	do_process				# 예외가 발생할 가능성이 있는 처리
rescue => e					# 예외처리한 예외객체가 변수 e에 대입된다. 직전에 발생한 예외는 내장 변수 $!를 통해 취득할 수도 있다.
	puts "Error occurred (#{e.class})"
end
```

예외 객체에는 예외 관련 정보를 취득하기 위한 몇 가지 메소드가 있다.

```ruby
e.class				# => StandardError
e.message			# => "예외가 발생했다."
e.backtrace		# => ["sample.rb:4:in 'meth'", "sample.rb:9:in '<main>'"]	예외발생한 시점의 콜 스택을 배열로 반환한다. 파일명:행번호:in '메소드명'
```

캬 backtrace 가 너무 꿀이라 취한다..

`rescue` 절에서 예외 클래스를 특별히 지정하지 않으면 StandardError와 그 서브 클래스로 예외 처리를 한다. 반면, 예외 클래스를 지정하면 지정한 클래스와 서브 클래스로 예외 처리를 한다.

```ruby
# 하나의 begin...end에 대해 여러 번의 예외 처리가 필요한 경우
begin
	do_process
rescue LoadError => e
	# deal with exception
rescue ArgumentError => e
	# deal with exception
rescue CalculateError, ParseError => e				# 하나의 rescue 절에 예외 클래스를 복수 지정할 수도 있다.
  # deal with exception
end
```

`rescue` 절에 인수를 지정하지 않고 `raise`를 호출하면 해당 `rescue`에서 받은 예외를 다시 발생시킨다. 로그처리할 때 편리하다.

```ruby
begin
	raise StandardError, 'hi'
rescue => e
	logger.error e.messgae

	raise									# 받은 예외를 다시 발생시킨다.
end
```

`ensure` 절에 예외 유무와 상관없이 마지막에 반드시 실행하고 싶은 처리를 기술할 수 있다. `else` 절로 예외가 없을 경우 실행시킬 처리를 기술할 수도 있다.

```ruby
begin
	file = File.open('whatever.txt')

	do_process file
rescue
	puts 'something wrong'
else
	puts '무사히 실행을 마쳤다. 굿굿!'
ensure
	file.close if file
end
```

한편 `begin` 절, `rescue`절 또는 `else`절에서 마지막으로 평가된 값은 `begin`절의 반환 값이 된다. `ensure`절에서 나오는 값은 반환 값으로 사용되지 않는다.

`rescue`절 내에서 `retry`를 호출하면 `begin`절이나 메소드를 처음부터 다시 처리할 수 있다.

```ruby
begin
	failed ||= 0
	puts 'trying...'

	process
rescue
	failed += 1

	retry if failed < 5
end
```

다중 내포 관계에 있는 처리에서 한번에 탈출해서 큰 처리의 흐름을 중단하고 싶은 경우가 있따. 이 때 사용하는 것이 대역 탈출이다.

대역 탈출 수단으로 `catch/throw` 를 제공한다. `throw`를 호출하면 지정된 이름의 `catch` 블록을 중단하고 `catch`를 호출한 위치로 돌아간다.

```ruby
catch :entire do
	catch :process do
		throw :entire			# :entire 블록 중단
	end
end
```

`throw` 두 번째 인수에는 `catch` 반환 값을 지정할 수 있다. 두 번째 인수를 지정하지 않으면 `catch`는 `nil`을 반환한다.

루비에서는 메소드 내에서 마지막으로 평가된 식의 값이 해당 메소드의 반환 값이 된다. `return`이 명시될 때는 `return` 에 지지정한 값이 반환 값이 된다.

### 메소드 가인수, 가변인수, 배열전개

메소드의 가인수에는 기본 값으로 사용할 수 있는 임의의 식을 지정할 수 있다. 아래처럼!

```ruby
def greet(naem, message = 'Hi')
	"#{message}, #{name}"
end
```

가인수의 앞에 \*을 붙이면 여러 인수를 배열로 받을 수 있다.

```ruby
def greet(naem, *messages)
	messages.each do |message|
		puts "#{message}, #{name}"
	end
end
```

\*는 단순히 인수를 무시하고 싶은 경우에도 사용할 수 있다.

```ruby
def greet(name, *)
	puts "Hello, #{name}."
end

greet 'Ruby', '안녕', 'foo'				# 'Hello, Ruby.' 출력
```

실인수 앞에 \*를 붙이면 복수의 인수를 배열로 지정할 수 있다.

```ruby
def greet_twice(name, first, second)
	puts '#{first}, #{name}'
	puts '#{second}, #{name}'
end

greetings = %w(Hello Hola)

greet_twice 'Ruby', *greetings # "Hello, Ruby." "Hola, Ruby."를 순서대로 출력.
```

### 메소드와 블록

메소드는 블록을 받을 수 있다. 메소드는 받은 블록을 임의의 시점에 임의의 횟수만큼 실행할 수 있다. 배열의 each 메소드는블록을 요소 수만큼 실행한다.

```ruby
%w(Alice Bob Charlie).each do |name|
	puts "Hello, #{name}."
end
```

이렇게 받은 블록을 실행할 수 있는 메소드를 정의해보자.

- yield

  메소드 안에서 yield를 호출하면 받은 블록을 실행한다.
  블록을 지정하지 않으면 예외가 발생한다. 블록이 지정된 경우에만 실행시키려면 `block_given?` 메소드를 이용하자.

  ```ruby
  def block_sample
  	puts 'stand up'
  	yield	if block_given?
  	puts 'sit down'
  end

  block_sample do
  	puts 'walk'
  end								# 'stand up' 'walk' 'sit down'를 순서대로 출력
  ```

  참고로 `File.open` 같은 경우엔 블록 유무에 따라 메소드 처리가 다르다.

  ```ruby
  # 블록을 사용하지 않고 파일에 문자열을 기록하는 처리
  file = File.open('without_block.txt', 'w')
  file.puts 'write something'
  file.close

  # 블록을 사용한 처리(파일이 자동으로 닫힌다.)
  File.open 'with_block.txt', 'w' do |file|
  	file.puts 'with_block'
  end
  ```

- 블록 반환 값

  - yield는 블록의 반환값을 반환한다. 역시나 마지막으로 평가된 식의 값이 반환 값이다.
  - 블록 안에서 next를 호출하면 처리는 'yield 호출 위치'로 돌아간다.
  - 블록 안에서 break를 호출하면 처리는 '메소드 호출 위치'로 돌아간다.

- 블록 인수

  - yield 호출 시에 전달한 값은 블록의 인수가 된다.

  - 블록은 메소드와 비교해서 인수의 수에 관대하다. 실제 인수가 블록 인수보다 많거나 적어도 에러가 발생하지 않는다.

  - 메소드의 가인수처럼 블록 인수에도 기본 값과 가변 인수를 지정할 수 있다.

    ```ruby
    def default_arg_for_block
    	yield
    end

    def default_arg_for_block do |val = 'Hi'|
    	puts val
    end				# 'Hi'

    def flexible_args_for_block
    	yield 1, 2, 3
    end

    def flexible_args_for_block do |*params|
    	puts params.inspect
    end				# '[1, 2, 3]' 출력
    ```

- 가인수를 블록을 받기
  받은 블록을 실행하지 않고 다른 메소드로 전달하는 경우가 있다. 이 때는 블록을 가인수로 취급한다.
  가인수 앞에 `&`를 붙이면 메소드에 전달된 블록을 가인수로 받을 수 있다. 이렇게 `&`를 사용한 가인수는 하나의 메소드에 하나만 지정할 수 있다.

  ```ruby
  def block_sample(&block) 	  # 블록이 Proc 객체로 대입된다.
  	puts 'stand up'
  	block.call if block				# Proc#call 메소드로 블록을 호출한다.
  	puts 'sit down'
  end

  block_sample do
  	puts 'walk'
  end				# 'stand up' 'walk' 'sit down' 순서대로 출력
  ```

- 객체를 블록으로 전달
  메소드를 호출할 때 실인수 앞에 `&`를 붙이면 Proc 객체를 블록으로 지정할 수 있다.
  Proc 객체를 Array#each에 전달한 예제!

  ```ruby
  people = %w(Alice Bob Charlie)
  block = Proc.new {|name| puts name}

  people.each &block # 'Alice' 'Bob' 'Charlie'를 순서대로 출력
  ```

  만약 Proc 객체 이외의 실인수에도 `&`를 붙인 경우엔 인수에 대해 `to_proc`메소드를 호출한 결과를 메소드에 전달한다. 마치 형변환.

- 반복 처리 이외의 블록용도

  블록은 each 같은 루프 처리뿐 아니라 '준비 -> 본질적인 처리 -> 정리'처럼 전후 처리를 공통화할 수 있는 패턴을 추상화하여 처리할 때 유용하다. 책에 나온 응용패턴은 아래와 같다.

  - 파일 열기/닫기
  - DB 접속/절단
  - 트랜잭션 시작/종료
  - 잠금과 해제

  파일 time.txt에 현재 시간을 기록하는 프로그램을 참고해보자.

  ```ruby
  def write_with_lock
  	File.open 'time.txt', 'w' do |f|
  		f.flock File::LOCK_EX

  		yield f

  		f.flock File::LOCK_UN
  	end
  end

  write_with_lock do |f|
  	f.puts Time.now
  end
  ```

- 블록 기법
  메소드 호출로 블록을 지정할 때는 `do...end`를 사용하는 방법과 `{...}`를 사용하는 방법이 있다. 둘은 결합 우선순위가 다르며, 보통 다음 기준으로 나누어 사용한다고 한다.

  - 블록 내 처리를 한 줄로 기술할 때: `{...}`, 여러줄일 때 `do...end`
  - 값을 반환하는 식으로 블록을 작성할 때: `{...}`, 일련의 처리를 실행할 땐 `do...end`

  저자는 후자를 주로 쓴다고 한다.

- 블록 지역변수

  블록 내의 변수와 이름이 같은 지역 변수가 블록 바깥에 존재하지 않으면, 해당 변수는 블록의 지역 변수로 간주된다. 이를 블록 지역 변수라고 한다. 블록 밖에 같은 이름의 지역 변수가 있다고 해도 블록 인수는 항상 블록 지역변수로 간주된다. 블록 지역 변수는 블록 밖에서 접근할 수 없다.

### 유사 키워드 인수

키워드 인수란 이름을 가지고 있는 인수를 일컫는다. 실인수를 전달할 때 다음과 같이 인수 이름을 지정해서 전달할 수 있다.

```ruby
keywords(key: value)
```

메소드 호출 시에 인수로 해시 값을 지정할 떄는 해시 구문의 괄호를 생략할 수 있다. 이것을 이용해서 키워드 인수와 비슷한 처리를 할 수 있다. 이런 인수를 유사 키워드라고 한다.

```ruby
def keywords(hash = {})
	hash
end

# Hash의 괄호 '{}'를 생략할 수 있다.
keywords(alice: '앨리스', bob: '밥')				# {:alice=>'앨리스', :bob=>'밥'}

# 메소드 호출 시에도 괄호를 생략할 수 있다.
keywords alice: '앨리스', bob: '밥'
```

유사 키워드 인수에서는 매소드 내에서 기본 값을 설정해야 한다. 즉, 메소드 내에서 기본 값 해시를 가인수의 해시로 덮어쓰기하면 설정할 수 있다.

```ruby
def keywords(hash = {})
	defaults = {alice: '앨리스', bob: '밥'} # 기본 값 해시
	hash = defaults.merge(hash)

	hash
end

keywords bob: '밥' # => {:alice=>"앨리스", :bob=>"밥"}
```

### 키워드 인수

다음과 같이 가인수로 키워드를 지정하는 것도 가능하다.

```ruby
def keywords(alice: nil, bob: nil)
	{alice: alice, bob: bob}
end

keywords alice: '앨리스', bob: '밥' #=> {:alice=>'앨리스', :bob=>'밥'}
```

유사 키워드 인수에서 가인수는 단지 해시를 받을 수 있는 하나의 인수로 취급됐다. 하지만 키워드 인수를 이용하면 메소드 정의 가인수에 키워드를 직접 기술할 수 있다. 또한 키워드로 존재하지 않는 인수가 전달되면 예외 ArgumentError가 발생한다.

키워드 인수에는 기본 값을 지정해줘야한다. 이는 가인수에 직접 지정한다.

키워드 인수를 이용하면서 이와 별도로 옵션 해시를 받고 싶다면, `**`를 가인수 앞에 붙인다.

```ruby
def keywords(alice: nil, bob: nil, **others)
	{alice: alice, bob: bob, others: others}
end

# 키워드 인수로 존재하지 않는 것은 other에 전달한다.
keywords alice: '앨리스', bob: '밥', charlie: '찰리' # => {:alice=>'앨리스', :bob=>'밥', :others=>{:chalie=>'찰리'}}

# 인수의 순서를 바꿀 수 있다.
keywords charlie: '찰리', alice: '앨리스', bob: '밥' # => {:alice=>'앨리스', :bob=>'밥', :others=>{:chalie=>'찰리'}}

# **가 붙은 가인수(others)에는 빈 해시가 기본 값으로 들어간다.
keywords alice: '앨리스', bob: '밥' #=> {:alice=>'앨리스', :bob=>'밥', :others=>{}}
```

### 가인수의 순서

가인수가 여러 개인 경우는 가인수의 나열 순서에 제한이 있따. 예를 들어 가변 인수 뒤에는 일반 인수를 쓸 수 없으며, 복수의 가인수는 다음과 같은 순서로 나열할 필요가 있다.

1. 일반 인수/생략 가능 인수
2. \*로 지정할 수 있는 가변 인수
3. 키워드 인수
4. \*\*로 지정할 수 있는 해시 인수
5. &로 지정할 수 있는 블록 인수

### ::을 사용한 메소드 호출

메소드 호출에는 마침표(.)이 아닌 `::`을 사용할 수도 있다. `::`은 상수 참조 시에 많이 사용되지만 메소드 호출시에는 그다지 사용되지 않는다. 혹시 레거시 코드에 있으면 보고 메소드 호출을 눈치챌 용도로 알아두자!

### 메소드 정의 취소

`undef`를 이용하면 메소드 정의를 취소할 수 있다.

```ruby
def greet
	puts 'hi'
end

undef greet, puts
greet 						# NameError
puts 'hi'					# NoMethodError
```

대환장 파티가 일어날 수 있으므로 사용에 주의하자.

### 메소드에 별명 붙이기

`alias`로 기존 메소드에 별명을 붙일 수 있다. 재밌는건 A 메소드에 별명을 B라고 붙이고 A 메소드를 `undef` 하더라도 별명 B로 함수를 호출할 수 있다는 것이다.

### 기본적인 내장 함수

puts처럼 리시버를 생략하고 호출하는 내장 메소드는 서브 루틴처럼 호출할 수 있어서 '내장 함수'라고 부른다. 대표적인 것을 훑어보자.

#### 문자열 입출력

- `Kernel#puts`: 문자열 끝에 개행이 없으면 개행 추가, 개행이 있으면 그대로 출력.
- `Kernel#print`: 개행 문자를 삽입하지 않는다.
- `Kernel#spritnf`: 지정한 형식으로 문자열을 출력한다. 기본적으로 C 언어의 `sprintf`와 같다. 내장함수는 아니지만 `String#%` 연산자는 이 `sprintf`를 간략화 시킨 것이다.
- `Kernel.#p`: 객체를 사람이 이해하기 쉬운 문자열로 출력해준다. 디버그로 좋다. 지정한 인수가 문자열이 아니면 `inspect`메소드의 반환 값을 출력시킨다.
- `Kernel.#warn`: 부여된 인수를 $stderr로 출력한다.
- `Kernel.#gets`: 상수 ARGF에서 한 줄을 읽어서 반환한다. ARGF는 스크립트 인수(ARGV)가 부여된 경우에는 그것을 파일명으로 간주하는데, 인수가 여러 개인 경우에는 그것을 하나로 묶어서 하나의 파일로 간주한다.

#### 외부 명령어 실행

- Kernel.#` : 외부명령 실행시키고 그 결과로 반환된 표준출력을 문자열로 취득하는 경우. 외부 명령어가 종료되기까지 처리를 동기화해서 대기한다.
- `Kernel.#system`: 인수로 지정한 외부명령 실행시키고 성공여부만 확인하는 경우. 외부 명령어가 종료되기까지 처리를 동기화해서 대기한다.
- `Kernel.#exec`: 인수로 지정한 외부 명령어를 실행시킨다. exec로 외부 명령어를 실행하면 실행 중인 루비 프로세스가 외부 명령어의 프로세스로 바뀌며 외부 명령어 실행이 종료되어도 제어권이 루비로 돌아오지 않은 채 프로세스가 종료된다.
- `Kernel.#spawn`: 외부 명령어 종료를 기다리지 않고 바로 자식 프로세스의 PID를 반환한다.

`system/exec/spawn` 메소드에서는 첫 번째 인수로 해시를 지정할 수 있고 이를 통해 외부 명령어 프로세스의 환경 변수를 덮어쓰거나 새롭게 추가하는 것이 가능하다.

#### 외부 파일 읽기

- `Kernel.#require`: 인수에 파일명을 지정해서 해당 파일을 읽는다. 상대경로 사용가능. 루비의 표준 환경 라이브러리나 gem 패키지를 읽을 때도 사용된다. 한번 require된 파일의 경로는 내장 변수 `$LOADED_FEATURES($)`에 추가된다. 동일 인수로 몇 번이고 require되어도 동일 경로의 파일은 한 번만 읽는다.

#### 인터럽트 처리기를 정의한다.

- `Kernel.#trap` : signl handler를 등록하는 용도다. `:EXIT`를 signal handler에 등록시켜두면 프로그램이 종료되기 전에 실행된다.

# 4장 클래스와 모듈

클래스 정의식에 지정하는 클래스명은 영문 대문자로 시작해야하며, 파스칼 케이스로 명명하는 것이 관례다.

new 메서드로 인스턴스를 생성한다. 이 때 클래스 내에 정의해둔 initialize 메서드로 초기화 가능하다.

메서드 네이밍이 흥미로운데 boolean을 리턴하는 메서드는 끝에 물음표를, 주의를 기울여야하는 메서드는 끝에 느낌표를 붙이는게 관례다.

```ruby
str = 'abc'

str.reverse # => 'cba'
str					# => 'abc'

# 원본을 바꿔버리는 '파괴적인' 메서드라서 느낌표가 붙었다.
str.reverse!  # => 'cba'
str						# => 'cba'

user.save			# 실패하면 false 반환
user.save!		# 실패하면 예외를 발생시킨다.
```

이제 getter, setter를 귀찮게 만들 필요가 없다. `attr_accessor`에 인스턴스 변수 이름만 지정해 주면, 접근자가 자동으로 정의된다.

한편 `attr_reader`는 인스턴스 변수를 참조하기 위한 메소드만 정의한다.

`attr_write`는 인스턴스 변수를 대입하기 위한 메소드만 정의한다.

### 클래스 메소드

클래스도 객체의 하나이므로 클래스에 대한 메소드 호출이 가능하다. 클래스에 대해서 호출이 가능한 메소드를 클래스 메소드라 한다. 클래스 메소드는 C++의 static 메소드 같은 것이다.

클래스 메소드를 정의하려면 클래스 정의 내에서 메소드를 정의할 때 메소드명 이름에 `self.`을 붙인다.

```ruby
class Ruler
	attr_accessor :length

	def self.pari
		[new, new]
	end
end

Ruler.pair 			# Ruler 객체 두 개를 배열로 반환한다.
```

한편 클래스 메소드는 '싱글톤 클래스(singleton class)'라 불리는 형태로 정의할 수도 있다.

```ruby
class Ruler
	attr_accessor :length

	class << self
		def pari
			[new, new]
		end

		def trio
			[new, new, new]
		end
	end
end
```

이렇게 정의하면 1) 클래스 메소드를 모아서 정의할 수 있다는 이점과 2) 내포 관계로 정의해서 인스턴스 메소드와 구별할 수 있다는 이점이 있다.

### 메소드 호출 제한

`public, private, protected` 가 쓰인다. 메소드 정의 직후에 아래처럼 기술하면 된다.

```ruby
private :private_method_name
```

`protected` 메소드는 자바나 C++와는 의미가 다르다. 흠.. 쓸일이 별로 없다고 적혀있으니 다음에 쓸 때 자세히 알아보자.

### 클래스 상속

루비는 단일 상속을 지원한다.

서브 클래스는 슈퍼 클래스의 인스턴스 메소드, 클래스 메소드를 상속하지만, 인스턴스 변수에 대한 정보는 상속하지 않는다. 단, 상속한 메소드 내에 인스턴스 변수가 정의돼 있으면 결과적으로 슈퍼 클래스와 같은 이름의 인스턴스 변수가 상속된다.

서브 클래스는 슈퍼 클래스의 정수 및 상수도 상속한다. 서브클래스에서 상수를 재정의하는 것도 가능하다.

### 메소드 오버라이드

메소드 내에서 s uper를 호출하면 슈퍼 클래스에 정의된 동명의 메소드를 호출할 수 있고, 서브 클래스 메소드 호출 시에 지정된 인수가 슈퍼 클래스 메소드에 자동으로 전달된다. 서브 클래스에서 받은 인수와 다른 값을 전달하고 싶으면 super에 인수를 지정하면 된다. 또한 인수를 일절 사용하고 싶지 않은 경우에는 `super()`와 같이 괄호를 기술해서 인수가 없다는 것을 명시하면 된다.

### 싱글톤 메소드

객체는 클래스에 정의한 메소드 외에도 해당 객체 고유의 메소드를 가질 수 있다. 이것을 싱글톤 메소드라고 한다.

```ruby
class Foo
	def override_me
		puts "in foo class"
	end
end

bar = foo.new
def bar.sigleton_method					# bar 객체만 쓸 수 있는 싱글톤 메서드를 정의한다.
  puts 'singleton!'
end

def bar.override_me							# bar 객체만 오버라이드하도록 할 수도 있다.
	super

	puts 'in singleton method'
end

bar.singleton_method			# 'singleton!'
bar.override_me						# 'in foo class' 'in singleton method'
```

### 모듈

루비에는 클래스와 매우 닮은 모듈이라는 기능이 있다. 클래스와 다른 몇가지 특징이 있다.

- 인스턴스를 생성할 수 없다.
- 상속할 수 없다.

모듈은 주로 다음과 같은 용도로 사용할 수 있다.

- 네임스페이스를 만든다.
- 모듈의 메소드를 특정 클래스의 인스턴스 메소드로 추가한다.
- 모듈의 메소드를 특정 객체의 싱글톤 메소드로 추가한다.
- 모듈 함수를 정의해서 사용한다.

아래는 모듈을 싱글톤 메소드를 정의해서 사용하는 예제다.

```ruby
module Sweet
	def self.lot								# 모듈에서 메소드 명 앞에 self.을 붙여서 정의하면 싱글톤 메소드가 된다.
		%w(a b c d).sample				# Array#sample은 요소를 랜덤으로 반환한다.
	end
end

Sweet.lot											# 'a'
Sweet.lot											# 'b'
```

특정 네임스페이스의 클래스나 모듈을 참조할 때는 `::` 연산자를 사용하자. 동일한 처리를 내포 클래스로 구현할 수 있지만 인스턴스 생성이 필요없을 땐 모듈을 이용하는 것이 좋다고 한다. (왜 좋지? 인스턴스가 없는 것이 보장되기 때문일까?)

### 믹스인(Mix-in)

모듈에 정의된 메소드를 클래스의 인스턴스 메소드로 추가할 수 있다. 이것을 믹스인(Mix-in)이라고 한다.

인스턴스 메소드로 모듈 메소드를 추가하려면 `include`를 이용한다. 모듈의 `include`는 몇 번이고 가능하다.

```ruby
module Greetable
	def greet_to(name)
		puts 'Hello, #{name}. My name is #{self.class}.'
	end
end

class Alice
	include Greetable
end

alice = Alice.new
allice.greet_to 'Bob'		# 'Hello, Bob. My name is Alice.' 출력
```

모듈은 클래스를 상속할 수 없지만, 다른 모듈을 include할 수는 있다.

### 메소드를 객체에 추가

모듈에 정의한 메소드는 객체의 싱글톤 메소드로 추가할 수도 있다. 객체에 모듈의 메소드를 추가하려면 extend를 이용한다.

```ruby
module Greetable
	def greet_to(name)
		puts 'Hello, #{name}. I'm a #{self.class}'
	end
end

o = Object.new
o.extend Greetable

o.greet_to 'World'					# 'Hello, world. I'm a Object.
```

클래스도 객체의 일종이므로 모듈을 extend할 수 있다. include와의 차이점은 이 [링크](https://www.geeksforgeeks.org/include-v-s-extend-in-ruby/#:~:text=In simple words%2C the difference,but not to its instance.)를 참고하자.

### 클래스나 모듈을 자동으로 읽기

require에 긴 시간이 걸리거나 리소스가 많이 소모되는 경우가 있다. 매번 읽어 들일 필요가 없는 외부 파일은 autoload를 적용해보자.

autoload는 인수에 지정한 클래스명/모듈명이 처음 참조됐을 때 외부 파일을 자동으로 require한다. 인수에 지정한 클래스명/모듈명이 참조되기 전까지는 require가 라이브러리를 읽지 않는다.

```ruby
# 첫 번째 인수에는 클래스명/모듈명을 문자열이나 심볼로 지정하고, 두 번째 인수에는 require할 파일명을 지정한다.
autoload :MySweets, 'my_library/my_sweets'

MySweets # 여기서 require 된다.
```

### 객체

모든 클래스는 BasicObject를 상속하고 있으며, BasicObject만 상속받는 일부 클래스를 제외하고 대부분의 클래스는 Object 클래스에서 파생된 서브 클래스다. 슈퍼클래스를 지정하지 않으면 자동으로 Object 클래스를 상속한다.

Object 클래스의 기본동작을 보자.

```ruby
o = Object.new

# 자신에 대한 정보를 반환한다.
o.class
o.is_a?(Object)
o.object_id
o.nil?
o.frozen?

# 자신을 블록 인수로 해서 블록을 실행하고 자신을 반환한다.
o.tap {|v| puts v}
```

아, `Object#!=`은 오버라이드 안해도 `Object#==`의 결과를 논리 부정해서 반환한다.

`Object#freeze`를 호출하면 리시버에 대한 파괴적인 조작(객체 상태를 변경하는 조작)을 금지할 수 있다. freeze된 객체를 변경하려고 하면 RuntimeError가 발생한다. **한 번 freeze된 객체는 절대로 변경할 수 없다.**

객체를 복사하려면 `Object#dup`이나 `Object#clone`을 이용한다. 양쪽 모두 오염 상태를 포함해서 객체를 복사한다. 후자는 자신ㅇ ㅣfreeze됐는지 여부와 싱글톤 메소드 정보를 포함해서 복사한다.

둘 모두 얕은 복사(shallow copy)를 한다. 양쪽 모두 자신을 복사해서 반환하지만, 자신을 참조하고 있는 타 객체는 복사하지 않는다. 예를 들어, 배열을 복사하면 배열의 요소는 복사되지 않는다.

### 오염된 객체

루비에는 세이프 레벨(safe level)이라는 기능이 있어서 외부 입력을 통해 위험한 처리가 발생하는 것을 미연에 방지한다.

| 레벨 | 개요                                                                                                         |
| ---- | ------------------------------------------------------------------------------------------------------------ |
| 0    | 기본 세이프 레벨. IO나 환경변수, 커맨드라인 인수에서 얻은 문자열에는 오염마크가 붙는다.                      |
| 1    | 오염 마크가 붙는 대상은 0과 같다. 오염된 객체를 인수로 한 파일 조작, 명령어 실행, 시그널 트랩 등이 금지된다. |
| 2    | 오염 마크가 붙는 대상은 0과 같다. 1의 금지 항목에 추가로 프로세스 관련 조작도 금지된다.                      |
| 3    | 이 레벨에서 생성된 객체에는 모두 오염마크가 붙는다. 2의 금지 항목에 추가로 오염 삭제 등이 금지된다.          |
| 4    | 오염 마크가 붙는 대상은 3과 같다. 전역 변수나 오염되지 않은 객체의 변경, 메소드 재정의 등이 금지된다.        |

세이프 레벨을 적절히 설정하면 오염된 객체로 인해 위험해진 처리를 막을 수 있다.

객체의 오염 여부는 `Object#tainted?`로 확인할 수 있다.

# 5장 주요 내장 클래스/모듈

루비 자체에 포함되어있는 내장 클래스/모듈은 require할 필요 없이 바로 사용할 수 있다.

주요 내장 클래스/모듈을 간단 정리해보자.

### Numeric

- 술어 메소드: 자신이 어떤 값을 가지고 있는지 판별할 수 있다.

  ```ruby
  0.zero? 		#=> true
  3.zero? 		#=> false
  0.nonzero? 	#=> nil
  3.nonzero? 	#=> 3

  356.integer?	#=> true
  3.real?				#=> true
  Complex(1, 2).real?		#=> false

  1.odd?			#=> true
  2.even?			#=> true
  2.next	#=>3
  2.succ	#=>3
  2.pred	#=>1
  ```

- `<=>`: 우주선 연산자 또는 스페이스십 연산자라고도 불리는데 주로 정렬 처리에 이용된다. 왼쪽 값이 오른쪽보다 작으면 음수, 같으면 0, 크면 양수를 반환한다.

  ```ruby
  1 <=> 2	#=> -1
  1 <=> 1	#=> 0
  1 <=> 0 #=> 1
  ```

- `Enumerable#sort` : 블록으로 정렬 방법을 변경할 수 있다. 블록은 우주선 연산자와 같은 조건으로 반환 값을 반환한다.

  ```ruby
  %w(Alice Bob Charlie).sort {|a, b| a.length <=> b.length }	#=> {"Bob", "Alice", "Charlie"}
  ```

- `Numeric#step`: 반복 처리 메소드. 시작 값이 수치 자신이며 종료 값이 첫번째 인수이다.

  ```ruby
  3.step 5 do |num|
  	puts num
  end					# "3" "4" "5"를 순서대로 출력

  1.2.step 2.0, 0.2 do |num|		# 두번째 인수로 증가분을 설정할 수도 있다.
    puts num
  end					# 1.2 1.4 1.6 1.8 2.0 순서대로 출력.
  ```

### Rational

`Kernel.#Rational` 는 유리수를 표현한다. 첫 번째 인수에는 분자, 두 번째 인수에는 분모를 지정한다.

```ruby
r = Rational(1, 3)	#=> (1/3)

r.denominator				#=> 3		분모를 취득
r.numerator					#=> 1		분자를 추득
r.to_f							#=> 0.33333333333		부동소수점으로 변환
```

나눗셈을 할 때 `/`가 아닌 `Numeric#quo` 메소드를 사용하면, 반환 값을 Rational 객체로 취득할 수 있다.

```ruby
r = 3.quo(10)			#=> (3/10)
```

### Complex

`Kernel.#Complex`는 복소수를 표현한다. 첫 번째 인수는 실수부를, 두 번째 인수는 허수부를 지정한다. 두 번째 인수를 생략하면 0이 사용된다. 첫번째 인수로 문자열이 주어지면 복소수를 표현한 문자로 해석된다.

```ruby
c = Complex(2, 3)
c.real			# => 2
c.imaginary	#	=> 3

Complex(2)			#=> (2+0i)
Complex('2+2i')	#=> (2+2i)
```

### String

핵 유용할 예정이다. 메소드를 훑자~!

- `empty?`: 비었는지 여부
- `length`: 길이
- `bytesize`: 문자열의 바이트 수
- `include`: 인수에 지정한 문자열을 포함하고 있는가?
- `start_with`: 지정한 문자열로 시작하는가?

문자열은 수정이 가능한 객체라 `<<`을 사용하면 '파괴적으로' 변경할 수 있다.

```ruby
str = 'Pine'
str << 'apple'	#=> 'Pineapple'
str							#=> 'Pineapple'
```

- `slice` : 문자열의 특정 부분만 취득. 정규표현으로 지정 가능.

- `[]`: slice의 간단 구문

  ```ruby
  str = 'The Answer to life, the universe, and everything: 42'
  str[4..9]		#=> 'Answer'
  ```

- `strip`: 문자열 전후의 공백문자를 제거. `rstrip`, ` lstrip` 도 있다.

- `chop`: 문자 종류에 상관없이 문자열 끝에 있는 문자 하나를 제거

- `shomp`: 문자열 끝에 있는 줄바꿈 코드를 하나만 제거

- `squeeze`: 문자열 내 중복문자를 하나로 모은다. 첫 번째 인수에 모을 대상이 되는 문자를 지정할 수도 있다.

- `downcase`, `upcase`, `swapcase`, `capitalize` : 문자열내 대소문자 변환처리

- `sub`: 특정 패턴에 일치한 첫 번째 문자열을 변환. 첫 번째 인수는 정규 표현으로 지정, 두 번째 인수는 치환대상

  ```ruby
  '24-1-365'.sub(/[0-9]+/, 'x') #=> 'x-1-365'
  ```

- `gsub`: 일치하는 패턴 다 바꾸려면 이걸 사용하자.

원본을 변경하고 싶으면 `!`를 붙여보자.

```ruby
str = ' hi '
str.strip!			#=> 'hi'
```

- `split`: 문자열 안의 특정 문자를 구분자로 분할해서 배열로 변경.

  ```ruby
  '42seoul'.split(//)			#=> ['4', '2', 's', 'e', 'o', 'u', 'l']
  '42seoul'.each_char.to_a			#=> ['4', '2', 's', 'e', 'o', 'u', 'l']
  ```

반복처리에는 메소드명이 each로 시작하는 메소드를 사용한다.

- `each_char`: 문자 단위 반복
- `each_btyes`: 바이트 단위 반복
- `each_line`: 행 단위 반복. 줄바꿈 문자열을 따로 지정하는 것도 가능하다.

모든 문자열은 인코딩 정보를 가지고 있으며, 이를 변경할 수 있다.

- `encoding` : 인코딩 정보를 Encoding 객체로 반환한다. 무슨 인코딩인지 확인할 때 사용.
- `encode`: 문자열을 특정 인코딩으로 변환.

### Enumerable 객체

Array, Hash, Range 등 객체 집합을 표현하는 클래스에는 Enumerable이 include 되어 있다. 객체 집합을 조작할 때 세상편해진다.

```ruby
#반복과 함께 값이 증가
%w(A B C).each_with_index do |num, index|
	puts '#{index}: #{name}'
end		# '0: A' '1: B' '2: C'

# 뒤에서부터 역순으로 반복
(1..3).reverse_each do |val|
	puts val
end		# '3' '2' '1' 순서대로 출력

# 요소를 n회씩 나누어 반복
(1..5).each_slice 2 do |a, b|
	p [a, b]
end	# '[1, 2]' '[3, 4]' '[5, nil]' 순서대로 출력

# n개로 연결된 요소를 하나씩 물려서 반복
(1..4)each_cons 2 do |a, b|
	p [a, b]
end	# '[1,2]' '[2,3]' '[3,4]'

# 리시버 요소를 처음부터 끝까지 무한 반복
(1..3).cycle do |n|
  	puts n
end		# '1', '2', '3' ... 계속 출력
```

참고로 Timer 객체나 Float 객체 등과 같이 such 메소드가 없는 객체를 사용해서 범위 객체를 정의했을 때는 반복 처리를 할 수 없다.

요소가 특정 조건을 만족하는지 판별할 수 있다. 아래 요소들은 블록이랑 같이 처리하는 것도 가능하다.

- `all?`: 모든 요소가 참인지 판별
- `none?`: 모든 요소가 거짓인지 판별
- `any?`: 하나라도 참이 있는지 판별
- `one?`: 하나만 참인지 판별

```ruby
[4, 4, 2, 3].all? {|v| v.is_a?(Integer)}	#=> true
```

부분요소를 가져올 수도 있다.

- `grep`: 특정 조건을 만족하는 요소를 `===`로 비교해서 true가 되는 요소의 배열을 반환한다.
- `detect`: 반환 값이 처음으로 true 가 되는 요소를 반환
- `select`: 블록의 각 요소에 대해 실행해서 블록 반환 값이 true인 모든 요소를 반환
- `take`: 앞에서부터 지정한 수만큼의 요소를 배열로 반환
- `take_while`: 블록이 처음으로 false를 반환할 때까지의 요소를 배열로 반환
- `drop_while`: 블록이 청므으로 false를 반환한 후 요소를 배열로 반환

복합연산도 간단하게 처리 가능하다.

- `inject` : 리시버에 대한 복합 연산을 수행한다.

  ```ruby
  # 초기값 설정이 가능하다.
  [4, 4, 2, 3].inject(0) {|result, num|
  	result += num
  }	#=> 13

  # 초기값 생략시 가장 첫번째 요소가 초깃값으로 설정됨.
  [4, 4, 2, 3].inject {|result, num|
    result += num
  }	#=> 13
  ```

- `each_with_object` : 요소를 반복하며 객체를 갱신해 가는 처리에 적합하다. `each_with_object` 인수에는 초깃값이 되는 객체를 지정한다. 이 객체는 반복 때마다 블록 인수로 사용되며 최종적으로는 반환 값이 된다.

  ```ruby
  %w(Alice Bob Charlie).each_with_object({}) {|name, result|
  	result[name] = name.length
  }	#=> {'Alice'=>5, 'Bob'=>3, 'Charlie'=>7}
  ```

- `group_by`, `partition`: 특정 조건으로 요소를 그루핑

- `max`, `min`, `minmax` : 각 요소를 <=> 연산자로 비교하여 최솟값, 최댓값을 얻는다.

sort는 비교할 때마다 두 개 요소의 메소드를 호출해야한다. 반면, sort_by는 메소드 호출은 요소 단위로 한 번만 하면 된다. 따라서 요소별 메소드 실행 시간이 길면 sort 쪽이 실행에 많은 시간이 걸린다.

### Array

꽤 신선한데 쓸만해보이는 메소드를 정리해보자.

- `compact`: 배열 요소에서 nil을 제거한 새로운 배열을 반환한다.

- `uniq`: 중복 요소를 제거한 새로운 배열을 반환한다. 중복여소는 `eql?` 메소드로 판별한다.

- `flatten`: 배열의 배열(다차원 배열)을 일차언으로 변경한 새로운 배열을 반환한다.

- `tranpose`: 배열을 행과열로 간주해서 둘을 서로 바꾸어 새로운 배열을 반환한다.

- `zip`: 자신과 인수에 지정한 배열을 결합해서 다차원 배열을 생성한다.

  ```ruby
  array = [1, 'a']
  array.zip([2, 'b'], [3, 'c']) #=> [[1,2,3], ['a','b','c']]
  ```

- `join`: 배열의 요소들을 모두 연결해서 문자열을 반환한다.

  ```ruby
  array = [24, 1, 365]
  array.join 			#=> '241365'
  array.join('-')	#=>	'24-1-365'
  ```

### Hash

파괴적 조작에 의해 해시 값이 변경될 가능성이 있는 객체는 키로 적합하지 않은데, 키가 되는 객체의 해시 값이 변경되면 키와 값을 연결할 수 없기 때문이다. 문자열 객체도 변경 가능한 객체지만, 편리성을 위해 예외를 두고 있다. 문자열을 해시 키로 사용하는 경우는 문자열을 복사해서 이용하므로 원 객체가 변경되어도 영향을 받지 않는다.

하단은 메소드 메모!

- `merge`: 해시 두 개를 하나로 모아서 새로운 해시를 반환한다. 키가 중복된 경우에는 인수에 지정한 해시가 우선시되어 덮어쓰기 한다.
- `invert`: 키와 값을 뒤바꾼다.
- `has_key?`: 키가 있는지 확인한다.
- `has_value?`: 값이 있는지 확인한다.
- `keys`, `values`: 각각 모든 키와 값을 배열로 반환한다.
- `new`: 첫번째 인수로 초깃값을 지정할 수 있다. 그럼 존재하지 않는 키를 참조했을 때 nil 대신 이 초기값을 반환한다.

### Enumerator

- `lazy`: 매우 큰 배열이나 무한 요소를 가진 객체 집합을 손쉽게 처리한다.

  ```ruby
  (0..Float::INFINITY).map { |n| n.succ }.select {|n| n.odd? }.take(3) # 결과가 반환되지 않음.

  (0..Float::INFINITY).lazy.map { |n| n.succ }.select {|n| n.odd? }.take(3)
  odd_numbers.force #=> [1,3,5]
  ```

  이처럼 요소 반복 시마다 필요한 부분만 실행된다.

# 6장 루비의 클래스 객체

클래스에서 사용할 수 있는 대부분의 메소드는 Module 클래스에 정의되어있는 것이다. Module과 Class의 차이는 아래 두 가지 뿐이다.

1. Class는 인스턴스를 작성할 수 있다.
2. Class는 상속하거나 상속될 수 있다.

### class 정의식과 Class.new

둘은 스코프에서 차이가 있다.

```ruby
external_scope = 1

class ExpDefineClass
	puts external_scope	# NameError 발생
end

NewDefineClass = Class.new do
	puts external_scope # 1을 출력
end
```

즉, Class.new는 클래스를 블록으로 정의하기 때문에 바깥쪽 스코프를 참조할 수 있다. 동적으로 클래스를 정의해야할 때 유용하다.

### 싱글톤 클래스

루비에는 싱글톤 클래스 외에도 '싱글톤'이라는 명칭이 붙는 기능이 있는데, 이것이 바로 싱글톤 메소드다. 싱글톤 메소드 또한 특정 객체와 연계되는 메소드다. 싱글톤 클래스는 사실 싱글톤 메소드를 정의할 때 해당 싱글톤 메소드가 정의되는 클래스이다.

일반 클래스와 싱글톤 클래스의 차이는 이 [싱글톤 패턴을 쓰는 이유와 문제점](https://jeong-pro.tistory.com/86)을 참고해보자.

싱글톤 메소드 호출시에는 싱글톤 클래스에 정의된 메소드를 먼저 탐색하고 서브클래스에 정의된 메소드, 슈퍼클래스에 정의된 메소드 순으로 탐색한다.

그 외 메소드들 간단 정리

- `prepend`: include 된 여러 모듈, 클래스가 있더라도 prepend에 있는 것이 먼저 호출된다. 모듈 내에서 사용하는 변수 등을 초기화해야할 때 써먹기 좋다.

# 7장 동적프로그래밍

### eval family

루비의 eval family는 네 가지 메소드가 있다.

| 메소드명                  | 동작                                                                           |
| ------------------------- | ------------------------------------------------------------------------------ |
| Kernel.#eval              | self가 호출된 위치를 식으로 평가. 인수에 지정한 문자열을 식으로 인식해서 처리. |
| Module#class_eval         | 리시버 클래스를 self로 해서 식을 평가                                          |
| Module#module_eval        | 리시버 모듈을 self로 해서 식을 평가                                            |
| BasicObject#instance_eval | 리시버 객체를 self로 해서 식을 평가                                            |

### eval과 Binding 객체

Binding 객체는 특정 구문으로 정의된 변수나 메소드를 모아 둔 객체이다.

Binding 객체를 사용하면 식을 평가할 때 `Kernel.#eval`로 사용할 구문을 지정할 수 있다. `Kernel.#eval`의 두 번째 인수에 Binding 객체를 지정하면, 식이 Binding 객체의 스코프로 평가된다.

흠.. 아래 예시를 보자!

```ruby
class EvalTarget
	def initialize
		@instance_val = 'instance valiable'
	end

	def instance_binding
		local_val = 'local valiable'
		binding
	end

	private
	def private_method
		'private method'
	end
end

el = EvalTarget.new
binding_obj = el.instance_binding

eval '@instance_val', binding_obj     #=> 'instance valiable'
eval 'local_val', binding_obj					#=> 'local valiable'
eval 'private_method', binding_obj		#=> 'private method'

# Binding 객체에도 eval 메소드가 정의되어 있어서 아래처럼 사용해도 동일한 처리가 가능하다.
binding_obj.eval '@instance_val'		#=> 'instance valiable'
binding_obj.eval 'local_val'				#=>	'local valiable'
binding_obj.eval 'private_method'		#=> 'private method'
```

이거쓰면 유지보수하기 힘들어질 것만 같아서 찾아보니 장단점이 있다. [링크](https://hashcode.co.kr/questions/2756/ruby에서-eval의-정확한-역할이-뭔가요-그리고-쓰면-안좋다는데-정말-그런가요)안의 링크들도 한번 읽어보면 안쓰는게 나을듯.

- 장점: 동적 구문 생성, 바인딩, 실행으로 메타프로그래밍에 유용
- 단점: 느림, 스코프를 넘어선 자원 접근, 보안 취약 유발

# 8장 Proc 객체

블록을 사용하면 메소드 호출 측에서 작성한 처리를 메소드에 전달할 수가 있지만, 블록은 메소드 하나당 하나만 지정할 수 있다. 또한, 객체가 아니므로 변수에 저장해서 반복 사용할 수 있다.

블록의 이런 특성 및 한계를 벗어나 특정 처리를 객체로 추상화한 것이 Proc객체이다. 구체적으로 아래 상황에서 쓰인다.

- 메소드에 복수의 블록을 지정하고 싶을 때
- 블록을 객체로 사용하고 싶을 때

Proc 클래스는 블록을 객체로 만드는 클래스다. 아래처럼 쓴다.

```ruby
proc_obj = Proc.new {|a| a } #=> #<Proc:0x007f97d8ade2e8@(irb):1>
```

Proc 객체를 생성한 후, 객체 생성 시에 사용한 블록에 인수를 전달하려면 `Proc#call` 메소드에 인수를 지정하면 된다.

`Proc.new` 메소드의 인수에 블록을 지정하지 않으면, `Proc.new` 메소드를 호출한 메소드에 지정된 블록이 사용된다.

블록이 없는 `Proc.new`를 호출한 메소드에도 블록이 없으면 ArgumentError가 발생한다.

`Kernel.#proc` 메소드로 Proc 객체를 생성할 수도 있다.

Proc 객체의 === 메소드는 다른 객체의 === 메소드와 달리 Proc 객체를 실행한다.

### Proc 객체와 블록

루비의 메소드는 블록을 지정해서 `yield` 메소드로 평가할 수 있으며, 메소드에 지정된 블록을 Proc 객체로 받을 수도 있다.

블록을 Proc 객체로 받으려면 메소드 인수에 블록 인수를 지정한다. 블록 인수를 이용하면 메소드 호출 시에 지정한 블록을 Proc 객체로 처리할 수 있다.

```ruby
# coding: utf-8

def convert_proc(&block)
	block
end

proc_obj = convert_proc { 1 }
proc_obj.call #-> 1
```

### Proc#curry

'x'와 'y'같이 복수의 인수를 사용하는 함수에 'x'만 특정 값을 설정해 두고 'y'는 인수로 사용하는 새로운 함수를 만들 수 있는데, 이것을 커리(curry)화라고 한다.

Proc#curry라는 메소드로 커리화가 가능하다.

```ruby
# coding: utf-8

add = Proc.new {|x, y| x + y}
inc = add.curry.(1)

inc.(2)

append_prefix_atmark = add.curry.('@')
append_prefix_atmark.('takkanm')			#=> '@takkanm'
```

### Kernel.#lambda

```ruby
lambda_obj = lambda { 1 }

lambda_obj.class 	#=> Proc
lambda_obj.call		#=> 1
```

요걸 간단히 기술하려면 `->`을 사용하면 된다. `->`가 람다 기호랑 비슷해서 만들어졌다고 한다ㅎㅎ

```ruby
# -> (가인수 리스트) {처리}
inc = ->(x) {x + 1}

inc.(1) #=> 2
```

### Proc.new / Kernel.#proc / Kernel.lambda

Proc 객체를 중간에 처리중단할 때 차이점이 있다.

| 차이점 | Proc.new             | Kernel.#proc         | Kernel.#lambda     |
| ------ | -------------------- | -------------------- | ------------------ |
| return | 메소드를 빠져나간다. | 메소드를 빠져나간다. | 제어를 빠져나간다. |
| break  | 예외가 발생한다.     | 예외가 발생한다.     | 제어를 빠져나간다. |

`return`과 `break`를 구별해서 쓰기 헷갈리지 않는가. 그래서 Proc이나 lambda 내에서 처리를 중단하고 싶을 때는 걍 블록 처리 중단과 마찬가지로 `next`를 사용하는 것도 좋다.

한편 인수 개수에 따라서도 동작이 다르다.

`Proc.new` 로 작성한 객체의 인수는 다음과 같이 동작한다.

- 가인수의 수보다 많은 인수가 전달되면 무시한다.
- 인수 수가 부족하면 부족한 인수에는 nil이 전달된다.
- 복수의 가인수가 정의되어 있을 때, 배열이 하나만 전달되면 가인수에 맞추어 전개된다.

반면 `Kernel.#lambda`로 작성한 객체는 일반 메소드와 마찬가지로 ArgumentError가 발생한다.

이런 차이가 있다보니 `Proc#call`을 사용해서 Proc 객체를 실행할 때는 차이가 있다는 것을 확실히 의식할 필요가 있다. `Proc#lambda?` 같은 메소드로 lambda인지 여부를 확인하고 쓰는 것도 한 방법이다.

### 루비의 클로저

클로저(Closure)란, 인수 이외에도 함수 정의 시에 포함되는 변수 등의 정보를 가지는 함수 객체를 말한다.

루비에서는 Proc 객체가 클로저처럼 동작할 수 있다. Proc 객체도 Proc 객체가 만들어진 구문의 객체를 보유하고 있어서, 해당 객체를 반복해서 사용할 수 있다.

```ruby
def create_proc
	str = 'from create_proc'
	Proc.new {str}
end

proc_obj = create_proc

str = 'from toplevel'
# proc_obj 내에서 호출된 str은 create_proc	내의 str을 참조하고 있다.
proc_obj.call #=> 'from create_proc'
```

또한 proc_obj 내에서 참조하고 있는 객체 상태가 Proc 객체 정의 후에 변경되면, 실행 시점의 객체 상태가 참조된다.

```ruby
str = 'from toplevel'
top_level_proc = Proc.new { str }
to_level_proc.call #=> 'from toplevel'

# top_level_proc 내의 str이 참조하고 있는 객체를 변경하면 call 결과도 바뀐다.
str += ' append strings'
top_level_proc.call #=> 'from toplevel append strings'
```

# 9장 Method 클래스

루비에서는 객체가 가지는 메소드도 객체로 취급할 수 있다. 바로 Method 객체다. 아래처럼 객체가 가지고 있는 메소드를 구체화할 수 있다.

```ruby
array = [1,2,3,4,5]
array_shift = array.method(:shift)

array_shift.call # => 1
```

관련 메소드로 인수의 정보나 메소드 소유자/이름/리시버를 취득할 수 있다.

### Method 객체와 Proc 객체

둘 중에서는 클로저로 활용할 수 있는 Proc 객체를 사용하는 경우가 많다.

반면, Method 객체는 특정 처리와 그것을 적용할 객체가 고정되어있으므로 해당 처리를 반복해서 호출할 필요가 있을 때 유용하다.

---

# ruby 2.0~2.7.1 release note

책에 기술된 Ruby의 버전은 2.0버전이다. 2020년 현재 2.7.1버전까지 버전업되며 달라진 부분들을 훑었다. 다행히 막 특기할만한 내용은 없는듯하다.

- [2.1.0 release note](https://www.ruby-lang.org/ko/news/2013/12/25/ruby-2-1-0-is-released/)
- [2.2.0 release note](https://www-ruby-lang.herokuapp.com/ko/news/2014/12/25/ruby-2-2-0-released/)
- [2.3.0 release note](https://www.ruby-lang.org/ko/news/2015/12/25/ruby-2-3-0-released/)
- [2.4.0 release note](https://www.ruby-lang.org/ko/news/2016/12/25/ruby-2-4-0-released/)
- [2.5.0 release note](https://www.ruby-lang.org/ko/news/2017/12/25/ruby-2-5-0-released/)
  - ~~`Object#yield_self` 메서드 추가~~
- [2.6.0 release note]()
  - [루비 2.6 릴리즈 및 주요 문법 변경사항 소개 by 44bits](https://www.44bits.io/ko/post/ruby-2-6-0-released-and-changes)
  - 키워드 인자의 키 객체로 심볼이 아닌 값을 사용할 수 없도록 변경됨.
  - 해시 만들 때 `map` 호출할 필요없이 `to_h` 메서드로 한방에 처리 가능.
  - `Object#yield_self`가 `then`으로 이름 바뀜.
  - `Hash#merge`가 여러 개 인자를 받도록 변경.
  - `split`에 블록 받을 수 있음.
- [2.7.0 release note](https://www.ruby-lang.org/ko/news/2019/12/25/ruby-2-7-0-released/)
  - [루비 2.7 릴리즈 및 주요 문법 변경사항 소개 by 44bits](https://www.44bits.io/ko/post/news--ruby-2-7-released)
  - 패턴 매칭 기능
