## 전송 매체(trnasmission media)

네트워크 상에서 데이터 송수신을 위한 전송 통로이다. 유선과 무선으로 나눌 수 있다.

### 유선 전송매체

트위스트 페어 케이블, 광케이블 등이 있다.

- 광케이블
- 트위스트 페어 케이블(twisted pair cable, 랜 케이블)

랜 케이블은 양쪽 끝에 RJ-45라는 커넥터가 있다.
랜 케이블은 실드 여부에 따라 UTP, STP 케이블로 나누어진다.

- UTP 케이블 (Unshielded Twist Pair cable): 구리선 여덟개를 두개씩 꼬아 만든 네쌍의 전선, 실드로 보호되지 않아서 외부에서 발생하는 노이즈의 영향을 받기 쉽지만 저렴하여 일반적으로 많이 사용됨.
  - UTP 케이블은 전송품질에 따라 Cat3~7까지 분류할 수 있다. 목적에 따라 선택이 필요하다.
- STP 케이블 (Shielded Twist Pair cable): 실드로 선을 보호하여 노이즈의 영향을 상대적으로 덜 받지만 비싸서 일반적으로 사용되지는 않음.

또한 연결 방식에 따라 다이렉트 케이블과 크로스 케이블로도 나누어진다.

- 다이렉트 케이블: 컴퓨터와 스위치를 연결할 때 사용.
- 크로스 케이블: 컴퓨터 간에 직접 랜 케이블로 연결할 때 사용. 양 컴퓨터 모두 1,2번 선은 데이터 수신, 3, 6번 선은 데이터 송신하는 식으로 동작하더라도 구조적으로 케이블에 정보가 충돌되지 않도록 설계되어있다.

### 무선 전송매체

- 라디오파
- 마이크로파
- 적외선 등등

### MAC 주소 (Media Access Control Address)

랜 카드에는 랜카드가 제조할 때 새겨지는 '물리 주소'가 있다. MAC 주소는 48비트 숫자로 구성되어있고 앞쪽 24비트는 랜 카드를 만든 제조사 번호고, 뒷쪽 24비트는 제조사가 랜 카드에 붙인 일련번호가 있다. 이를 통해 각 랜 카드는 '전 세계에서 유일한 번호'를 MAC 주소로 할당받는다.

MAC주소는 48비트이다보니 구분하기 쉽도록 16진수를 사용하여 표시한다.
