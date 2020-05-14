### flexbox
 - css는 float 외에 flex나 grid로도 요소 배치를 조정할 수 있다. 
 - IE에서 오류가 아직 있는 편이라 PC용 서비스에 바로 도입하긴 어렵지만, 모바일 환경은 거의 대부분 지원하므로 적용하기 쉽다. [참고: Can I use](https://caniuse.com/#search=flex)
 
----
#### flexbox의 구성

 - flexbox는 복수의 자식 요소인 flex item과 그 상위 부모 요소인 flex container로 구성된다. 각 요소별로 아래 속성들을 적용할 수 있다.
   - flex container 속성: flex-direction, flex-wrap, justify-content, align-items, align-content
   - flex item 속성: flex, flex-grow, flex-shrink, flex-basis, order
   
각각 설명은 아래와 같다. 

----
#### flex container 속성
 - flex-direction: flex item에 작용하는 주축을 조정한다. 디폴트값은 row
 - flex-wrap: 컨테이너가 아이템의 폭보다 줄어들었을 경우 요소동작을 결정한다. 디폴트값은 nowrap
 - justify-content: main axis 축 방향으로 아이템을 어떻게 정렬할지 결정한다. 
 
    *비유하자면 아이템을 어묵, main axis는 어묵을 꽂은 나무꼬치라고 하고 어묵을 움직인다고 생각!*
 - align-items: 아이템이 한 줄(sigle-row)일 때, main axis 축의 수직방향(cross axis)으로 아이템을 어떻게 정렬할지 결정한다.
 - align-content: 아이템이 여러줄(multi-row)일 때, 각 row line간의 정렬관계를 결정한다.
----
#### flex item 속성
 - flex-basis: 아이템이 점유하는 기본너비 설정
 - flex-grow: 아이템의 증가너비 비율을 설정. 아이템을 배치하고 남아있는 **여백**을 작성한 설정비만큼 아이템 크기에 더해줌. 따라서 각 아이템의 flex-basis를 0으로 설정하면, 각 아이템이 점유하는 공간을 0으로 인식해서, 
 아이템의 크기를 각각 작성한 설정비에 맞게 설정해줌.
 - flex-shrink: 아이템의 감소너비 비율을 설정.
 - flex: `flex-grow`와 `flex-shrink` 그리고 `flex-basis: 0;`을 합친 것과 동일(단축 속성)하게 작용되어 아이템간의 크기 비율을 설정할 때 사용.
 
 *참고: 아이템 1, 2가 한 화면에 있고 아이템 1은 크기를 고정하지만 아이템 2는 가로축 화면너비에 자동으로 맞추도록 하려면, 아이템 1의 width를 지정하고, 아이템 2는 `flex: 1`을 설정하면 간편하게 구현되더라.*
 - align-self: 아이템 각각의 컨테이너 내에서의 정렬을 결정.
 - order: 아이템간의 순서를 결정.
 
   
