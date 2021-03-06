## OSI 모델의 전체 흐름

아래처럼 구성된 네트워크가 있다고 가정해보자.

> 컴퓨터-스위치A-라우터A - 라우터B-스위치B-웹 서버

3-way 핸드셰이크가 완료된 상태라고 가정하고, 컴퓨터가 웹 브라우저에 URL을 입력해서 접속하는 경우를 보면, 아래 예시 과정을 거친다.

#### 컴퓨터 -> 스위치 A

1. 컴퓨터 -> 응용 계층

   - `GET /index.html HTTP/1.1` 요청

2. 응용 계층 -> 전송 계층

   - 출발지 포트번호(1025번 이상인 번호 중 무작위로 선택), 목적지 포트번호(80번)을 포함한 TCP 헤더가 붙어서 세그먼트가 됨.

3. 전송계층 -> 네트워크 계층

   - 출발지 IP 주소, 목적지 IP 주소 등으로 구성된 IP 헤더를 붙여서 IP 패킷을 생성

4. 네트워크 계층 -> 데이터 링크 계층

   - 이더넷 헤더와 트레일러를 붙여서 이더넷 프레임 생성

5. 데이터 링크 계층 -> 물리 계층

   - 데이터가 전기 신호로 변환되어 컴퓨터에서 스위치A로 전송된다.

#### 스위치 A -> 라우터A

1. 물리 계층 -> 데이터 링크 계층
   - 전기신호를 변환하여 플러딩, 메모리 주소 필터링 등의 과정을 거친다.
2. 데이터 링크 -> 물리 계층
   - 데이터를 전기 신호로 변환하여 라우터로 전송한다.

#### 라우터A -> 라우터B

1. 물리 계층 -> 데이터 링크 계층
   - 전기신호를 데이터로 변환
2. 데이터 링크 계층 -> 네트워크 계층
   - 데이터(이 시점엔 이더넷 프레임)의 목적지 MAC 주소와 자신의 MAC 주소를 비교하여 같으면 역캡슐화를 수행하고 네트워크 계층으로 전달한다.
3. 네트워크 계층 -> 데이터 링크 계층

   - 라우팅 테이블과 목적지 IP 주소를 비교한다. 이후 라우팅을 한다. 따라서 이 시점에 **출발지 IP 주소를 라우터A의 외부 IP 주소로 변경**한다.

4. 데이터 링크 계층 -> 물리 계층
   - 이더넷 헤더와 트레일러를 붙인 후에 물리 계층에서 전기신호로 바꾸어 네트워크로 전달한다.

#### 라우터B -> 스위치B

1. 물리 계층 -> 데이터 링크 계층
   - 전기신호를 데이터로 변환
2. 데이터 링크 계층 -> 네트워크 계층
   - 데이터(이 시점엔 이더넷 프레임)의 목적지 MAC 주소와 자신의 MAC 주소를 비교하여 같으면 역캡슐화를 수행하고 네트워크 계층으로 전달한다.
3. 네트워크 계층 -> 데이터 링크 계층

   - 라우팅 테이블과 목적지 IP 주소를 비교한다. 이후 라우팅을 한다. 따라서 이 시점에 **출발지 IP 주소를 라우터B의 내부 IP 주소로 변경**한다.

4. 데이터 링크 계층 -> 물리 계층
   - 이더넷 헤더와 트레일러를 그대로 다시 붙인 후에 물리 계층에서 전기신호로 바꾸어 네트워크로 전달한다.

#### 스위치B -> 웹 서버

1. 물리 계층 -> 데이터 링크 계층
   - 역캡슐화 진행!
2. 데이터 링크 계층 -> 네트워크 계층
   - 역캡슐화 진행!
3. 네트워크 계층 -> 전송 계층
   - 역캡슐화 진행!
4. 전송 계층 -> 응용 계층
   - 드디어 응용 계층 도착.. 이제 응답을 이전의 과정을 거슬러올라 컴퓨터 쪽으로 보낸다.
