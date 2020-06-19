# Minikube

Minikube는 쿠버네티스를 로컬에서 쉽게 실행하는 도구이다. Minikube는 매일 쿠버네티스를 사용하거나 개발하려는 사용자들을 위해 가상 머신(VM) 이나 노트북에서 단일 노드 쿠버네티스 클러스터를 실행한다.

Minikube는 다음과 같은 쿠버네티스의 기능을 제공한다.

- DNS
- 노드 포트
- Config map과 Secret
- 대시보드
- 컨테이너 런타임: Docker, CRI-O와 containerd
- CNI(Conatiner Network Interface) 사용
- 인그레스

###

1. minikube 설치
2. kubectl 설치
3. kubectl get nodes 커맨드로 가용자원을 확인한다.
   쿠버네티스가 어플리케이션을 어떤 노드로 배포할지는 이 노드의 정보에 따라 결정한다.
4. kubectl create deployment로 배포한다. 도커허브에 없는 이미지는 이미지 경로까지 인자로 넣어줘야한다.
   kubectl create deployment kubernetes-bootcamp --image=gcr.io/google-samples/kubernetes-bootcamp:v1
5. kubectl get deployments로 잘 배포되었는지 확인한다.
6. pods는 같은 클러스터내의 앱끼리는 볼 수 있지만, 클러스터 바깥에서는 접근이 불가하다.
   kubectl을 사용하면 API endpoint를 사용해서 앱과 상호소통할 수 있다.
   kubectl 커맨드로 'proxy'를 만들면 호스트와 쿠버네티스간에 연결이 된다. 이걸로 (앱이 아니라 쿠버네티스의)API를 직접 사용할 수 있게된다.
7. POD_NAME을 추출해서 환경변수에 저장해주기
   `xport POD_NAME=$(kubectl get pods -o go-template --template '{{range .items}}{{.metadata.name}}{{"\n"}}{{end}}')`
   6,7 단계는 proxy가 running하고 있을 때 접근 가능하다.

### End point?

- 클라우드에 공개된 API를 실행하기 위해 접속하는 연결 접점
- 엔드포인트는 FQDN으로 표현되는데 API의 접점으로 일종의 게이트웨이 역할을 한다.
- 클라우드 환경에서는 인프라 컴포넌트를 제어하기 위해 엔드포인트에 접속한다.
- 엔드포인트는 주로 IP주소가 아닌 도메인으로 접속한다.
  - 도메인을 씀으로써 IP주소를 은폐할 수 있다.
  - IP주소가 바뀔때 자동으로 바뀐 IP주소로 접속하도록 할 수 있다.

[참고](https://jungwoon.github.io/infra,%20api,%20cloud/2019/01/31/Api-Summary/)
