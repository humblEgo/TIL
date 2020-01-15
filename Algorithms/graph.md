### Graph?


 - (무방향) 그래프 G = (V,E) 로 표현하고 '그래프 G는 V와 E에 의해 정의된다'고 한다.
   - V: 노드 혹은 정점(vertex)의 집합
   - E: 노드쌍을 연결하는 '엣지' 혹은 '링크'의 집합
   - 개체(object)들 간의 이진관계를 표현
   - 정점의 개수 n = |V|, 엣지의 개수 m = |E|
 
 - 방향 그래프(Directed Graph) G = (V,E)
   - 엣지 (u,v)는 u로부터 v로의 방향을 가짐
 
 - 가중치 그래프(Weighted Graph)
   - 보통 엣지마다 가중치를 지정
   
 
#### 그래프의 표현

여러가지 방법이 있지만, 보통은 아래 두 가지 방법으로 표현한다.
 - 인접행렬(adjacency matrix)
   - nxn 행렬 A = (a<sub>ij</sub>), a<sub>ij</sub>의 인접행렬이 있으면 1, 없으면 0으로 표시
   - 저장 공간은 O(n^2)이고, 어떤 노드 v에 인접한 모든 노드를 찾는데 O(n)시간, 어떤 에지(u,v)가 존재하는지 검사하는데 O(1) 시간복잡도를 가진다.
   - 무방향 그래프면 대칭적으로, 방향 그래프면 비대칭적으로 표현된다.
   - 가중치 그래프를 표현할 때는 보통 엣지의 존재를 나타내는 값으로 1대신 엣지의 가중치를 저장하는 방식이 쓰인다.
   
 - 인접리스트(adjacency list)
   - 정점 집합을 표현하는 하나의 배열과 각 정점마다 인접한 정점들의 연결 리스트
   - 무방향 그래프의 노드의 개수는 2m개이고, 저장 공간은 O(n+m)이며, 어떤 노드 v에 인접한 모든 노드를 찾는데 O(degree(V)), 어떤 엣지 (u,v)가 존재하는지 검사하는데는 O(degree(u)) 시간복잡도가 걸릴 수 있다.
   - 방향 그래프면 노드의 개수는 m이 된다.

무방향 그래프에서 G = (V,E)에서 노드 u와 노드 v를 연결하는 경로(path)가 존재하면 u와 v는 서로 연결되어있다고 말한다.
모든 노드 쌍들이 서로 연결되어있는 그래프를 '연결된 그래프'라고 한다.

#### 그래프 순회(Graph Traversal)

대표적으로 두 가지 방법이 쓰인다.
 - BFS(Breadth-First Search, 너비우선순회)
   - 기준 노드로부터 거리가 동일한 노드부터 탐색하는 방법으로, 일종의 동심원 형태로 순회하게 된다.
   - 보통 큐를 이용해서 구현
   - BFS를 하면서 지나온 엣지 개수로 각 노드에 대해서 최단 경로의 길이를 구할 수 있다.
   
   - 장점: 출발노드에서 목표노드까지의 최단 길이 경로를 보장한다.
   - 단점: 경로가 매우 길 경우에는 탐색 가지가 급격히 증가하여 보다 많은 기억 공간을 필요로 하게 된다. 해가 존재하지 않는다면 모든 그래프를 탐색한 후 실패로 끝난다.
   
 - DFS(Depth-First Search, 깊이우선순회)
   - 재귀적인 방법으로 구현할 수 있다.
   
   - 장점: 현 경로상의 노드들만 기억하면 되므로 저장공간의 수요가 비교적 적음. 목표노드가 깊으면 해를 빨리 구할 수도 있음.
   - 단점: 해가 없는 경로에 깊이 빠질 가능성이 있다.(이를 완화하기 위해 깊이 제한을 하기도함.) 얻어진 해가 최단 경로가 된다는 보장이 불가하다.
   
#### DAG(Directed Acyclic Graph)

방향 사이클(엣지 화살표를 따라가다보면 자신에게 돌아오는 경우)이 없는 방향 그래프. 
'작업들의 우선순위'가 DAG 형태를 띄는 경우가 많다. DAG에서 노드들의 순서화하기 위해 '위상정렬(topological ordering)'을 한다.

위상정렬 알고리즘은 아래 두 가지 방법이 대표적이다.

 1. 다른 노드에서 자신에게 향하는 엣지의 개수, 즉 indegree의 개수가 없는 노드를 찾아서 출력하고, 해당 노드를 그래프에서 지우는 것을 반복한다.
 ```
 topologicalSort1(G) // 시간복잡도 고려 않은 수도코드
 {
     for <- 1 to n {
         indegree가 0인 임의의 정점 u를 선택한다;     
         A[i] <- u;
         정점 u와 u의 진출간선을 모두 제거한다;
     }
     배열 A[1...n]에는 정점들이 위상정렬되어있다.
 }
 ```
 
 2. 
 ```
 topologicalSort2(G)
 {
     for each V에 있는 v{
         visited[v] <- NO;         
     }
     make an empty linked list R;
     for each V에 있는 v{ // 정점의 순서는 상관없음
         if (visited[v] = NO) THEN
             DFS-TS(X, R);
     }
 }
 
 DFS-TS(V, R)
 {
      visited[V] <- YES;
      for each x adjacent to v do{
          if (visited[x] = NO) then
              DFS-TS(x, R) ;
          }
      add V at the front of the liked list R;
 }
```






