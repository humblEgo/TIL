#### list?
----
 - 여러 값을 한꺼번에 모을 수 있음
 - 순서가 있어서 index로 데이터 활용 가능
 - 값 변경, 정렬 가능
   - 값 추가시
     * append(value) : 리스트 맨 뒤에 값 추가 <pre>ex) list.append(5)
     * list.insert(index, value) : 인덱스번째에 value 추가 <pre>ex) list.insert(4,2)    
   - 값 제거시
     * remove(value) : 리스트에 포함된 value를 삭제. 여러값이 있다면, 가장 처음 것만 삭제 <pre>ex) list.remove(2)
     * pop() : 맨 뒤의 값을 return하고 삭제함.
   - 값 정렬시 
     * sort() : value를 오름차순으로 정렬
     * sort(reverse=True): 내림차순으로 정렬
     * reverse() : value를 역정렬
     * sorted(list) : 오름차순 정렬한 값을 보여주기만 하고 값을 변화시키지는 않음. <pre>ex) print(sorted(list1))
 - 값을 확인할 경우
   - if value in list : if문을 이용하여 value를 확인하는 방법. <pre>ex) if 5 in list1
   - list.index(value) : value가 있는 가장 처음 인덱스 값을 알려줌. <pre>ex) print(list1.index(5))
 - 리스트 간에는 더하기, 빼기도 가능하다.

 
 
