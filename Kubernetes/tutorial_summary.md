# Kubernetes tutorial flow

[쿠버네티스 공식 튜토리얼](https://kubernetes.io/docs/tutorials/kubernetes-basics/)을 진행하며 학습한 내용을 간략하게 정리한다.

1. minikube 설치
2. kubectl 설치
3. `kubectl get nodes` 하면 노드가 잡히게 설정
4. `kubectl create deployment` 로 디플로이먼트 생성
   1. the full repository url for images hosted outside Docker hub 을 포함해야함.
   2. 예시
      `kubectl create deployment kubernetes-bootcamp --image=gcr.io/google-samples/kubernetes-bootcamp:v1`
   3. `kubectl get deployments`하면 노드안의 컨테이너에서 돌고 있는 디플로이먼트가 보여야함.
5. 파드 노출시키기
   - Kubectl proxy
     - 기본적으로 파드는 같은 클러스터에서는 볼 수 있지만, 그 밖에서는 볼 수 없다.
     - kubectl 은 API endpoint로 app과 통신을 주고 받는다.
     - kubectl proxy로 proxy를 만들자. [proxy란](https://brownbears.tistory.com/191)
     - `curl <http://localhost:8001/version`> 요런 명령어를 쳤을 때 응답되어야한다?
     - API 서버는 파드 이름에 따라 파드마다 endpoint를 만들어주는데 이것도 proxy처럼 접근가능하다.
     - 아래 명령어로 환경변수에 파드이름을 저장해두자.
       `export POD_NAME=$(kubectl get pods -o go-template --template '{{range .items}}{{.metadata.name}}{{"\\n"}}{{end}}') echo Name of the Pod: $POD_NAME`
   - Kubectl service
     - `kubectl get services`로 서비스 목록을 본다.
     - `kubectl expose deployment/kubernetes-bootcamp --type="NodePort" --port 8080` 로 8080포트를 노출시키자.
     - `kubectl get servcies` 다시 이 커맨드를 치면 kubernetes-bootcamp가 서비스로 새로 생긴다.
     - `export NODE_PORT=$(kubectl get services/kubernetes-bootcamp -o go-template='{{(index .spec.ports 0).nodePort}}') echo NODE_PORT=$NODE_PORT` 로 NODE_PORT 환경변수에 NodePort값을 찾아와서 넣어준다.
     - `curl $(minikube ip):$NODE_PORT` 명령어로 잘 노출되었는지 확인할 수 있다.
     - 참고로 이 노출된 NodePort의 경우, 쿠버네티스에서 오픈되었을 때 30000~32767 사이의 범위에서 자동으로 생성된다. 오픈할 때마다 값이 바뀐다.
6. 라벨 써보기
   - 디플로이먼트는 자동으로 라벨을 생성한다. `kubectl describe deployment`를 실행해보면, label 항목확인 가능하다.
   - get pods, get services 같은 커맨드에 `-l`옵션을 주고 인자로 라벨을 넣으면 해당 라벨에 해당하는 파드, 서비스를 조회가능하다.
   - 환경변수 POD_NAME에 파드이름을 넣고 `export POD_NAME=$(kubectl get pods -o go-template --template '{{range .items}}{{.metadata.name}}{{"\\n"}}{{end}}') echo Name of the Pod: $POD_NAME`
   - `kubectl label pod $POD_NAME app=v1` 커맨드로 그 파드에 app=v1 라벨을 추가할 수 있다.
   - `kubectl describe pods $POD_NAME` 하면 파드의 라벨을 확인할 수 있다.
   - `kubectl delete service -l run=kubernetes-bootcamp` 커맨드로 특정 라벨의 서비스를 삭제해버릴 수도 있다.
7. Scale up/down
   - 1개에서 4개로 Scale up 하는 경우
   - `kubectl scale deployments/kubernetes-bootcamp --replicas=4` 커맨드로 레플리카셋을 4개로 만들 수 있다.
     - `kubectl get deployments` 의 available column의 값이 4로 바뀌었으면 성공
     - `kubectl get pods -o wide`로 각 파드 정보를 가져와보면 파드도 4개로 바뀌었을 것이다.
   - `kubectl scale deployments/kubernetes-bootcamp --replicas=2`커맨드로 2개로 Scale down도 가능하다.
8. Rolling update
   - Rolling update는 24시간 서비스를 끊김없이 돌리면서 서비스를 업데이트하기 위한 기술이다. _달리는 자동차의 바퀴를 갈아끼우는 작업!_ 이를 위해 적어도 2개 이상의 파드가 돌아가고 있어야한다.
   - `kubectl describe pods` 커맨드의 image 란을 보면 현재 이미지를 알 수 있다.
   - `kubectl set image deployments/kubernetes-bootcamp kubernetes-bootcamp=jocatalin/kubernetes-bootcamp:v2` 커맨드로 바꿀 이미지 버전을 적어주자.
   - `kubectl rollout status deployments/kubernetes-bootcamp` 커맨드로 잘 rolled out 되었는지 확인할 수 있다.
   - `kubectl rollout undo deployments/kubernetes-bootcamp` 하면 update를 편하게 되돌릴 수 있다.

그 외 조작 팁

1. `kubectl describe pods` 로 파드안에 있는 컨테이너를 볼 수 있다.
2. `kubectl exec $POD_NAME env` 으로 파드 환경변수 리스트를 볼 수 있다.
3. `kubectl exec -ti $POD_NAME bash`로 직접 컨테이너 안에 들어갈 수 도 있다.
