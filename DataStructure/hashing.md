### hashing?

해쉬 테이블은 dynamic set을 구현하는 효과적인 방법의 하나이다. 적절한 가정하에서 평균 탐색, 삽입, 삭제시간은 O(1)이고, 보통 최악의 경우에는 O(n)의 시간복잡도를 가진다.

해쉬 함수(hash function)은 h를 사용하여 키 k를 T[h(k)]에 저장하게된다. 이 때 각 키에 대한 해쉬함수값을 그 키를 저장할 배열 인덱스로 사용하게 된다.
 - h: U -> {0,1,...,m-1}   여기서 m은 테이블의 크기, U는 모든 가능한 키들의 집합을 뜻함.
 - 키 k가 h(k)로 해슁되었다고 말한다.

일반적으로 |U|>>m이므로, 두 개 이상의 키가 동일한 위치로 해슁되는 경우가 발생가능하고, 이 때 '충돌' 이슈가 생긴다.
충돌에 대처하기 위해서는 대표적으로 아래 두가지 방법이 고려된다.
 - chaining
   : 평균시간복잡도는 키들이 여러 슬롯에 얼마나 잘 분배되느냐에 의해서 결정된다.
   - 키의 삽입: 키 k를 리스트 T[h(k)]의 맨 앞에 삽입하는 경우엔 시간복잡도가 O(1)이다. 만약 중복된 키가 들어올 수 있고, 중복저장이 허용되지 않는다면 삽입시 리스트를 검색해야 하므로 이 때 시간복잡도는 리스트의 길이에 비례한다.
   - 키의 검색: 리스트 T[h(k)]에서 순차검색하는 형태이고, 시간복잡도는 키가 저장된 리스트의 길이에 비례한다.
   - 키의 삭제: 리스트 T[h(k)]로부터 키를 검색한 후 삭제한다. 일단 키를 검색해서 찾은 후에는 O(1)시간에 삭제 가능하다.
 - open addressing
   : 모든 키를 해쉬 테이블 자체에 저장, 테이블의 각 칸에는 1개의 키만 저장. 아래 세가지 기법 등으로 세분화된다.
   
   - 키의 삽입 & 검색
     - Linear probing
   
     : 충돌이 일어날 경우, h(k), h(k)+1, h(k)+2.. 순서로 검사하여 처음으로 빈 슬롯에 저장. 테이블의 끝에 도달하면 다시 처음으로 circular하게 돌아간다.
   키에 의해서 채워진 연속된 슬롯(primary cluster)가 한번 생성되면 점점 더 커지는 경향이 생긴다는 단점이 생긴다.
     
     - Quadratic probing
   
     : 충돌이 발생할 경우, h(k), h(k)+1^2, h(k)+2^2, h(k)+3^2,...순서로 시도하는 것. linear probing의 단점이 다소 개선된다.
   
     - Double hashing   
     : 서로 다른 두 해쉬 함수 h1과 h2를 이용하여 `h(k,i) = (h<sub>1</sub>(k) + i*h<sub>2</sub>(k)) mod m` 수식으로 i값을 올리며 순서대로 시도한다. 이러면 key값에 따라 offset이 바뀐다. linear probing의 단점이 다소 개선된다.
   
   - 키의 삭제   
   : 키를 삭제할 때 값을 삭제하고, 연속된 키 값을 끌어와서 삭제된 키로 옮기는 등의 연산이 필요하다.
   
      
현실에서는 키들이 랜덤하지 않고, 키들의 통계적 분포에 대해 알고 있다면 이를 이용하여 해쉬 함수를 고안하는 것이 가능하겠지만, 현실적으로 어렵다.
해슁의 성능을 높이기 위해 키들이 균등한 크기로 골고루 분포하도록 하는 것이 바람직하다. 
또한 키 중복을 줄이기 위해 해쉬함수의 키 값을 값의 특정부분(ex 데이터의 끝부분)으로만 결정되지 않도록 하는 것이 바람직하다.





