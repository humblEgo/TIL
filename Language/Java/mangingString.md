
### 생성방법에 따른 String 객체

```java
String s1 = "Java";
String s2 = "Java";
String s3 = s2;
String s4 = new String("Java");
String s5 = new String("Java).intern();
```
위 코드에서 s1, s2, s3은 모두 같은 하나의 객체를 가리키고 있다. 
--> .java 파일을 컴파일 하게 되면 .class 파일이 만들어지는데, 이 때 s1에서 선언 및 정의된 "Java"라는 문자열은 상수화되어 .class파일의 "String pool"에 들어가게 된다.
s2에서 선언 및 정의된 값도 이미 "String pool"에 들어간 값과 같으므로 이 상수를 가리키게 된다.
s2가 가리키고 있는 것을 가리키게 된다.

한편 s4는 s1, s2, s3와 다른 객체를 가리킨다. s4의 양식대로 선언 및 정의하면 메모리 Heap 영역에 "Java"를 가지는 객체가 새롭게 생기는 것이다.

만약 s5처럼 intern() 메소드를 활용한다면, 새롭게 만들어진 String 객체도 상수화할 수 있다. 만들어진 Stirng 객체가 이미 상수로 만들어진 문자열이라면, 이를 버리고 상수를 가리키게 하는 것이다.
따라서 intern() 메소드를 이용해서 heap 메모리를 아낄 수 있다. 단, intern() 메소드를 이용하면 좀 더 시간이 걸린다는 단점이 있다.
