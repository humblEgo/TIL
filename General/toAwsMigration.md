### AWS Migration Case – MUSINSA

: 기존에는 89개에 달하는 Physical Machine을 서버로 활용했으나, 비즈니스 확장 에 대응할 수 없었음. 이를 해결해야하는 상황에서 ‘Money, Time, Human’ 제약 을 고려하여 AWS를 선택하여 아래 전략으로 Migration함.

----

#### 1. Lift & Shift but Cloud oriented
  -  pets에서 cattle 모델로 전환
  - ‘hosts’와 IP 의존성 제거
  - CMS 도입
  - 산재된 모니터링 서비스를 통합
  - 서버 및 서비스 상태 저장을 위한 Time-series DB
  - 통합 대시보드
  - 로그 관리 및 처리 방식 전환
  - 보안을 위한 내부 RPM repository
  - OS major version upgrade
  - Java Applications
    
#### 2. 빠른 이전
  - 개발부채 최소화와 팀원들의 피로도 증가를 막기 위해 상황 설명 및 타임라인 전달하여 설득부터 진행함.
  
#### 3. 혼란 최소화
  - Physical Server 환경하에 개발된 서비스를 AWS 환경 위에서 오류없이 돌리기 위해, 레플리카를 만들어서 AWS 환경을 참조하게 함. 이후 본 서비스와 레플리카 서비스 모두 함께 베포/테스트를 진행하여 ‘테스트 되지 않은 코드가 없도록’ 함.
  
#### 4. 이전 후 클라우드형 튜닝
  - Database: SQL DB의 한계를 느껴서 NoSQL로 Spread Out함.
  - Aurora – MySQL: 비싼 리소스여서 Scale Up/Out에 한계가 존재함. Maximum optimizing 대상으로 둚.
  - DocumentDB: History성 Data 등 변경이 없는 데이터를 이전함.
  - DynamoDB: Main DB에서 Divide & Conquer 전략으로 분리 중.
  - MSA : 조직이 커지고 도메인이 구분되면 자연적으로 변화함.
  - CQRS(or 비동기처리): Event queuing  및 Buffering으로 peak 부하 분산 
  - BI & Data Lake: 전통적 환경에 비해 탁월한 경쟁력이며, ‘Forecast’와 같은 예측을 통한 자동화 개발 예정
  - 개인화 전시: Personalize를 활용한 Seg기반 개인화 전시 서비스 개발
