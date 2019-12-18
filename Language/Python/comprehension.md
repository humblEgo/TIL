## Comprehension(지능형리스트)
----
Java와 달리 파이썬에는 comprehension이라는 편리한 문법이 있다. 정리해보자면 하단 내용과 같다.
>### 1. for 문을 한줄에 작성하는 경우
----
특정 list의 값을 2배로 하는 경우, 
<pre> 
temp = list([2,3,4,5])
temp_new = list()

for i in temp:
  temp_new.append(i*2)
print(temp_new)

out> [4,6,8,10]
</pre>

위 내용을 한줄로 요약하면, 아래와 같다.
<pre>
temp_new = list([i*2 for i in temp])
</pre>

>### 2. if문을 추가하는 경우
----
if문을 추가하는 것도 가능하다. 위의 temp 리스트에서 3보다 큰 경우에는 2를 곱하고, 3보다 작은 경우에는 그냥 list를 넣는다고 가정해보자. 
아래와 같이 작성이 가능하다.
<pre>
temp = list([2,3,4,5])
temp_new = list()

for i in temp:
  if i>3:
      temp_new.append(i*2)
  else:
      temp_new.append(i)
</pre>

위 구문을 한 줄로 작성하면 아래와 같다.
<pre>
list([i*2 if i>3 else i for i in temp])
</pre>

만약 else를 제외하고 작성하려면 아래와 같이 **if를 뒤로 뺀다.**
<pre>
list([i*2 for i in temp if i>3])
</pre>

코드를 간결하게 작성할 때 매우 편리하다.
