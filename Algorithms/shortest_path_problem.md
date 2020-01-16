### shortest_path_problem?


<가정>
최단경로는 가중치 (방향) 그래프 G =( V, E)를 가정한다. 
이 때 경로 p의 길이는 경로상의 모든 에지의 가중치의 합을 뜻한다.
노드 u에서 v까지의 최단경로의 길이를 라고 표시해본다.

문제는 네가지 유형이 있다.
 - Single-source: 하나의 출발 노드 s로부터 다른 모든 노드까지의 최단 경로를 찾아라.
 - Single-destination: 모든 노드로부터 하나의 목적지 노드까지의 최단 경로를 찾아라.
 - Single-pair: 주어진 하나의 출발 노드 s로부터 하나의 목적지 노드 t까지의 최단 경로를 찾아라. 최악의 경우 시간복잡도에서 Single-source 문제보다 나은 알고리즘이 없어서 잘 언급되진 않는다. 
 - All-pairs: 모든 노드 쌍에 대해서 최단 경로를 찾아라.
 
알고리즘에 따라 음수 가중치가 있어도 작동하는 경우도 있고 그렇지 않은 경우도 있다. 그러나 음수 싸이클이 있으면 최단 경로를 찾을 수 없다.

최단 경로의 기본 특성
 - 최단 경로의 어떤 부분 경로도 역시 최단 경로이다.
 - 최단 경로는 사이클을 포함하지 않는다.(음수 사이클이 없다는 가정하에서)


#### Single-source 최단경로문제

입력: 음수 사이클이 없는 가중치 방향그래프 G=(V,E)와 출발 노드 S∈V

목적: 각 노드 v∈V에 대해서 다음을 계산한다.
 - d[v]: 현재까지 찾은 경로 중 최선 경로의 길이
   - 처음에는 d[s] = 0, d[v]=무한대로 시작한다.
   - 알고리즘이 진행됨에 따라 감소해간다. 하지만 항상 d[v]>=∂(s,v)를 유지한다.
   - 최종적으로는 d[v]=∂(s,v)가 된다.
 - pi[v]: s에서 v까지의 최단경로상에서 v의 직전 노드(predecessor)
   - 그런 노드가 없는 경우 pi[v]=NIL


구현: 대부분의 Single-source 최단경로 알고리즘의 기본 구조는 아래와 같다.
 1. 초기화: d[s] = 0, 노드 v!=s에 대해서 d[v]=무한대, pi[v]=NIL
 2. 엣지들에 대한 반복적인 relaxation
 (알고리즘들 간의 차이는 어떤 엣지에 대해서, 어떤 순서로 'relaxation'을 하느냐에 있음)

```
Relaxation(u, v, w){ // 특정 노드로 가는 길이를 알게된 가장 짧은 길이로 업데이트 하는 것.
    if d[v] > d[u] + w(u, v)
        then d[v] <- d[u] + w(u,v)
        pi[v] <- u
}

Generic-Single-Source(G,w,s){ // 기본적인 single-source 최단경로 알고리즘
    INITIALISE-SINGLE-SOURCE(G,s)
    repeat
        for each edge (u,v) ∈ E
            RELAX(u, v, w)
    until there is no change
}

BELLMAN-FORD(G, w, s){
    INITIALIZE-SINGLE-SOURCE(G,s)
    for i <- 1 to |V[G]|-1 //기본적인 알고리즘과 달리 n-1번만 반복하도록 fix해둠.
        do for each edge(u, v) ∈ E[G]
            do RELAX(u,v,w)
            
    for each edge (u, v)
        do if d[v] > d[u] + w(u, v) // 만약 이게 TRUE면 음수 사이클이 존재한다는 의미
            then return FALSE
    return TRUE 
}
```


벨만포드 알고리즘은 RELAX가 연산될 때마다 모든 노드들을 업데이트하므로 시간복잡도 면에서 비효율이 존재한다.
이를 Dijkstra 알고리즘을 통해 고려할 수 있다.

다익스트라 알고리즘은 아래 가정을 따른다.
 - 음수 가중치가 없다고 가정
 - s로부터의 최단경로의 길이를 이미 알아낸 노드들의 집합 S를 유지, 맨 처음엔 S = 공집합
 - Loop invariant:
   - u !∈ S인 각 노드 u에 대해서 d(u)는 이미 S에 속한 노드들만 거쳐서 S부터 u까지 가는 최단 경로의 길이.

이는 'd(u) =min<sub>v!∈S</sub> d(v)인 노드 u에 대해서, d(u)는 s에서 u까지의 최단경로의 길이이다.'는 정리에 기반한다.

수도코드로는 아래처럼 구현 가능하다.
```
DIJKSTRA(G, w, s)
    for each u ∈ V do
        d[u] <- 무한대
        pi[u] <- NIL
    S <- 공집합
    d[s] <- 0
    while |S| < n DO //while문은 n-1번 반복
        find u !∈ S with the minimum d[u] value; //d[u]는 u까지 가는 최소거리 값. 최소우선순위 큐로 개선 가능!
        S <- S ∪ {u}
        for each v !∈ S adjacent to u do // degree(u) = O(n)
            if d[v] > d[u] + w(u,v) then
                d[v] <- d[u] + w(u,v)
                pi[v] <- u
            end.
        end.
     end.
 end.
 }    
```

