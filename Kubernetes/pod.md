# 파드(Pod)

파드는 하나 이상의 컨테이너 그룹이다. 또한 다음 개념들로 표현할 수 있다.

- *파드*는 쿠버네티스 애플리케이션의 기본 실행 단위
- 쿠버네티스 객체 모델 중 만들고 배포할 수 있는 가장 작고 간단한 단위
- 클러스터에서의 Running 프로세스

쿠버네티스 클러스터 내부의 파드는 주로 두 가지 방법으로 사용된다.

1. 단일 컨테이너만 동작하는 파드
   - 이 경우 한 개의 파드가 단일 컨테이너를 감싸고 있다고 생각할 수 있다. 이를 통해, 쿠버네티스는 컨테이너가 아닌 파드를 직접 관리한다.
2. 함께 동작하는 작업이 필요한 다중 컨테이너가 동작하는 파드

## 어떻게 파드가 다중 컨테이너를 관리하는가

파드는 서비스를 형성하는 다중 협력 프로세스(컨테이너)를 지원하도록 디자인되었다.

파드는 같은 파드 안에 속한 컨테이너에게 두 가지 공유 리소스를 제공한다. *네트워킹*과 _저장소_ !

### 네트워킹

각각의 파드는 각 주소 패밀리의 고유한 IP 주소를 할당 받는다. 같은 클러스터에 있어도 유니크한 IP주소를 받는다는 말이다. 한편 **한 파드 내부의 모든 컨테이너는 네트워크 네임스페이스와 IP주소 및 네트워크 포트를 공유한다.** 파드 안에 있는 컨테이너는 다른 컨테이너와 `localhost`를 통해서 통신할 수 있다. 특정 파드 안에 있는 컨테이너가 파드 밖의 요소들과 통신하기 위해서는, 네트워크 리소스를 어떻게 쓰고 있는지 공유해야한다(예를 들어 포트 등).

### 저장소

- 파드는 공유 저장소 집합인 Volumes를 명시할 수 있다.
- 파드 내부의 모든 컨테이너는 공유 볼륨에 접근할 수 있고, 그 컨테이너끼리 데이터를 공유하는 것을 허용한다.
- 볼륨은 컨테이너가 재시작될 때도 파드 안의 데이터가 영구적으로 유지될 수 있게 한다.

## 파드 작업

파드는 상대적으로 수명이 짧고 일시적이라서 개별 파드를 만들 일이 거의 없다. 파드는 직접 만들거나, *컨트롤러*에 의해 간접적으로 만들어진다. 이후 고유한 ID(UID)가 할당되고, 클러스터의 노드에서 동작한다.

이 때 파드는 아래 4가지 상황이 발생하지 않는한 노드에 남아있다.

- 프로세스가 종료되는 경우
  - 파드 안의 컨테이너를 재실행하는 것과 파드를 재시작하는 것은 구분되어야한다. 파드는 프로세스가 아니라 컨테이너를 실행하는 환경이다.
- 파드 오브젝트가 삭제되는 경우
- 파드가 리소스 부족으로 축출(eviction)되는 경우
- 노드에 장애가 생기는 경우

노드에 장애가 생길 때 파드는 self-heal되는게 아니라 삭제된다.

### 파드와 컨트롤러

워크로드 리소스를 사용해서 여러 파드를 생성하고 관리할 수 있다. 리소스 컨트롤러는 파드 장애 발생 시 복제, 롤아웃, 자동 복구르 처리한다.

스케쥴러는 교체용 파드를 정상적인 노드에 배치한다.

## 파드 템플릿

워크로드 리소스에 대한 컨트롤러는 파드 템플릿으로 파드를 생성하고 사용자를 대신해서 이러한 파드를 관리한다.

파드 템플릿은 파드를 생성하기 위한 명세이며 **디플로이먼트, 잡,** 그리고 **데몬셋**과 같은 워크로드 리소스에 포함되어 있다. 아래는 예시이다.

```
apiVersion: batch/v1
kind: Job
metadata:
  name: hello
  template:
    # 요기부터 파드 템플릿이다.
    spec:
      containers:
      - name: hello
        image: busybox
        command: ['sh', '-c', 'echo "Hello, Kubernetes!" && sleep 3600']
      restartPolicy: OnFailure
    # 여기까지가 파드 템플릿이다.
```

파드 템플릿을 수정하거나 새 파드 템플릿으로 전환해도 이미 존재하는 파드에는 영향을 미치지 않는다. 대신 수정된 파드 템플릿과 일치하는 새 파드가 생성될 뿐이다.

예를들어 디플로이먼트 컨트롤러는 실행 중인 파드가 현재 파드 템플릿과 일치하는지 확인하고 템플릿이 업데이트되면 기존 파드를 제거하고 업데이트된 템플릿을 기반으로 파드가 새로 생성한다.
