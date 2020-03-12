## 응용 계층(Application layer)

세션 계층과 표현 계층을 포함하며, 애플리케이션과 데이터를 주고받기 위해 필요하다.
서비스를 요청하는 측을 클라이언트, 서비스를 제공하는 측을 서버라고 하는데, 응용 계층에서 클라이언트의 요청을 전달하기 위해 서버 등의 통신대상이 이해할 수 있는 메시지(데이터)로 변환하고 전송 계층으로 전달하는 역할을 수행한다.

응용 계층에서는 다양한 프로토콜이 사용된다.
|프로토콜|내용|
|----|----|
|HTTP (HyperText Trnasfer Protocol)|웹 사이트 접속|
|DNS (Domain Name System)|이름 해석 <br> (네트워크 이름을 기반으로 IP주소를 알아내는 것)|
|FTP (File Trnasfer Protocol)|파일 전송|
|SMTP (Simple Mail Transfer Protocol)|메일 송신|
|POP3 (Post Office Protocol version|메일 수신|

#### ping 명령

목적지 컴퓨터와의 통신이 정상적으로 되고 있는지를 확인하기 위해 ping 명령을 이용한다. 이는 ICMP(Internet Control Message Protocol)라는 프로토콜을 사용하여 목적지 컴퓨터에 ICMP 패킷을 전송하고 패킷에 대한 응답이 제대로 오는지 확인하는 명령이다.
