### minimum_spanning_tree?
----

최소비용신장트리(MST). 무방향 가중치 그래프 G =(V,E)에 대하여 각 엣지에 가중치가 w(u,v) 형태로 부과되어있을 때, 
 1. Tree에 속한 에지들에 의해 그래프의 모든 정점들이 서로 연결되고
 2. 가중치의 합이 최소가 되는 케이스를 찾는 문제이다.

참고로 '싸이클이 없는 연결된 무방향 그래프'를 트리라고 부르며, MST의 답은 트리형태를 띌 수 밖에 없다. 
싸이클이 생기면 노드를 연결하는데 필요없는 엣지가 적어도 하나가 생기기 때문!


MST 관련하여 두 가지 알고리즘-Kruskal의 알고리즘과 Prim의 알고리즘이 유명하다. 
둘 모두 공통적으로 '엣지가 특정 부분집합에 안전하다'는 개념을 활용한다. 이는 어떤 MST의 부분집합 A에 대해서 AU{u, v}도 역시 어떤 MST의 부분 집합이 될 경우 **엣지 (u,v)는 A에 대해서 안전하다(safe)**고 하는 것을 뜻한다.

#### Generic MST 알고리즘
   1. 처음에는 'A = 공집합'이다.
   2. 집합 A에 대해서 **안전한** 엣지를 하나 찾은 후 이것을 A에 더한다.
   3. 엣지의 개수가 n-1개가 될 때까지 2번을 반복한다.

이 때 어떻게 '안전한' 엣지를 찾는지가 이슈가 된다. 이는 아래 정리를 통해 찾는다.
 - 그래프의 정점들을 두 개의 집합 S와 V-S로 분할한 것을 **컷(cut) (S, V-S)**라고 부른다.
 - 엣지 (u, v)에 대해서 u는 집합 S에 속하고, v는 집합 V-S에 속할 경우, 엣지 (u,v)는 컷(S, V-S)를 **cross**한다고 말한다.
 - 엣지들의 부분집합 A에 속한 어떤 엣지로도 컷 (S, V-S)를 cross하지 않을 때 컷 (S, V-S)는 A를 **존중한다(respect)**고 말한다.
 
--> A가 어떤 MST의 부분집합이고, (S, V-S)는 A를 존중하는 컷이라고 하자. 이 컷을 cross하는 엣지들 중 가장 가중치가 작은 엣지 (u, v)는 A에 대해서 안전하다.

 
#### Kruskal의 알고리즘
   1. 엣지들을 가중치의 오름차순으로 정렬한다.
   2. 엣지들을 그 순서대로 하나씩 선택해간다. 단, 이미 선택된 엣지들과 사이클을 형성하면 선택하지 않는다.
     - 사이클 형성 여부는, 각 노드를 원소로하는 집합을 만든 뒤, 엣지로 연결될 때 합집합하는 식으로 정리하고, 연결되는 노드가 이미 집합에 있는지 여부를 검사하여 싸이클 여부를 확인한다.
   3. n-1개의 엣지가 선택되면 종료한다.
 

 
 - kruskal의 알고리즘 구현 
   - 서로소인 집합들의 표현: 우선 각 집합을 하나의 **트리**로 표현한다. 집합의 각 원소들이 트리의 노드가 되기만 하면 되며, 노드는 자식노드가 아니라 부모 노드의 주소를 가진다.(부모가 없으면 자기자신을 부모로 가르키도록 함) 복잡해보이지만 모든 트리를 하나의 배열로 표현이 가능하다.(모든 부모는 유일하기 때문)
   ```
   // 노드 x가 집합에 있는지 확인하는 함수 FIND-SET(x)는 자신이 속한 트리의 루트를 찾도록 설계.
   FIND-SET(x) {
       if x != p[x]
           then p[x] <- FIND-SET[X]
       return p[x]
   }
   
   // 한 트리의 루트를 다르 트리의 루트의 자식 노드로 만드는 union(u, v). 트리의 높이에 시간복잡도가 결정되므로 weighted Union을 쓰면, 시간복잡도를 개선할 수 있다.
   union(u, v) {
       x <- FIND-SET(u);
       y <- FIND-SET(v);
       p[x] <- y;
   }
   
   // kruskal 알고리즘 수도코드
   MST-KRUSKAL(G,w){
       A <- 공집합
       for each vertex v ∈ V[G] // 각자의 노드를 유일한 원소로 가지는 집합 생성
           do MAKE-SET(v)
       sort the edges of E into nondecreasing order by weight w
       for each edge(u,v) ∈ E, taken in nondecreasing order by weight
           do if FIND-SET(u) != FIND-SET(v)
               then A <- A ∪ {(u, v)}
                   UNION(u, v)
       return A     
       }        
   ```

#### Prim의 알고리즘
 1. 임의의 노드를 출발노드로 선택
 2. 출발 노드를 포함하는 트리를 점점 키워 감.
 3. 매 단계에서 이미 트리에 포함된 노드와 포함되지 않은 노드를 연결하는 엣지들 중 가장 가중치가 작은 엣지를 선택

 - Prim의 알고리즘 구현
   - V<sub>A</sub>: 이미 트리에 포함된 노드들
   - V<sub>A</sub>: 아직 속하지 않은 각 노드 v에 대해서 다음과 같은 값을 유지
     - key(v): 이미 V<sub>A</sub>에 속한 노드와 자신을 연결하는 엣지들 중 가중치가 최소인 엣지 (u, v)의 가중치
     - pi(v): 그 엣지 (u, v)의 끝점 u
   
   --> key값이 최소인 노드를 찾는다. 새로 노드를 이을 때마다, 새로 추가된 노드와 인접한 노드들의 key값을 비교하여 적절하게 업데이트한다.
   
 ```
 MST-Prim(G, w, r){ //r은 출발점
     for each u ∈ V do{
         key[u] <- 무한대
         pi[u] <- NIL
     }
     V<sub>A</sub> <- {r}
     key[r] <- 0
     while |V<sub>A></sub>|<n do{
         find u !∈ V<sub>A</sub> with the minimum key value; // 노드들을 최소 우선순위 큐에 넣고 시작하면 개선 가능!
         V<sub>A</sub> <- V<sub>A</sub> ∪ {u}
         for each v !∈ V<sub>A</sub> adjacent to u do{
             if key[v] > w(u, v) then
                 key[v] <- w(u, v)
                 pi[v] <- u
         }       
     }
 }
 ```
 

