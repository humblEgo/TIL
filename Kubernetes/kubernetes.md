# 쿠버네티스

### Why Kubernetes?

큰 기업들은 대규모의 서비스를 운영하고 있기 떄문에 최대한 자원을 효율적으로 써야 비용적으로 유리하다.
이에 자원을 잘게 쪼개어 쓸 수 있게 해주는 가상화기술이 필요하다.

예시) A, B, C의 서비스를 사용하는 기업이 있다. 그리고 A 서비스의 피크타임은 아침, B는 점심, C는 저녁처럼 피크타임이 다르다고 가정하자. 이 경우 적절한 서버자원할당이 이슈가 된다. 쿠버네티스는 Auto scaling으로 피크시간에 따라 자원할당을 하고, 터진 서버가 있으면 자동으로 healing이 되도록 지원한다.

### 가상화 기술의 간략한 발전역사

가상화 기술은 아래 순서대로 같이 발전했다.

1. linux의 자원격리기술

   - 이슈: 쓰기어려워서 일반인은 잘 쓰지 못함.

2. VM 가상화기술

   - openstack이라는 서비스가 많이 쓰임.
   - 이슈: 자동화는 되는데, VM을 위해 OS를 띄워야하므로 시스템효율이 낮음.

3. Container 가상화기술

   - 서비스 간의 자원격리를 하는데 OS를 별도로 안띄워도 되니까 자동화시에 빠르고 자원 효율도 높음.
   - docker라는 서비스가 많이 쓰임.
   - 이슈: docker는 하나의 서비스를 컨테이너로 가상화시켜서 배포를 할 뿐 엄청 많은 서비스들을 운영할 때 일일이 배포하고 운영하는 역할을 해주진 않음.
   - 해결책: **컨테이너 오케스트레이터**로 여러 컨테이너들을 관리해주는 솔루션.

쿠버네티스는 현재 가장 많이 사용하는 컨테이너 오케스트레이터로, 표준으로 자리잡아가고 있다.
