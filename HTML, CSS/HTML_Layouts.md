## HTML Layouts

1. 배치

- display(block, inline, inline-block)
  - block: 위에서 아래로 쌓임.
  - inline: 오른쪽으로 흐름. (block 하위 개념임. 문장안에서 하용하는 태그에 주로 기본값으로 설정되어 있으며 span, a, strong 태그는 display:inline속성을 default로 가짐)
  - inline-block: inline 속성처럼 한 줄에 표현하면서도, margin, width, height 속성을 정의할 수 있음. (default로 좌우에 5px 가량의 margin이 발생함.)
- position(static, absolute, relative, fixed)
  - static: 그냥 왼쪽,위쪽에서 순서대로 배치됨. 모든 태그들은 default로 position:static 상태임.
  - absolute: 기준점에 따라서 특별한 위치에 위치함. 이 때 기준점은 상위 엘리먼트로 단계적으로 찾아가는데, static이 아닌, position이 기준점임.
  - relative: 원래 기존에 static이었을 때의 위치를 기준으로 이동함. top/left/right/bottom으로 설정가능.
  - fixed: viewport(전체화면)좌측, 맨위를 기준으로 동작함.
- float(left, right)
  - 기존의 배치에서 예외적으로 배치됨.

2. 사이즈

- 엘리먼트의 크기는 기본적으로 부모의 크기가 기준임.
- box-sizing:border-box; 값을 줘서 box-size를 고정해야 패딩 등 값을 조정했을 때 box크기가 조정되는 현상을 막을 수 있음.

---

# 결론적으로 Layout 구현방법은?

- 전체 레이아웃은 float를 잘 사용해서, 2단, 3단 컬럼 배치를 구현함. 브라우저 지원범위에 따라 [CSS-gird](#CSS-grid)나 flex 속성 등 layout을 위한 속성을 사용할 필요 있음.
- 특별한 위치에 배치하기 위해서는 position absolute를 사용하고, 기준점을 relative로 설정함.
- 네비게이션과 같은 엘리먼트는 block 엘리먼트를 inline-block으로 변경해서 가로로 배치하기도 함.
- 엘리먼트안의 텍스트의 간격과, 다른 엘리먼트간의 간격은 padding과 margin 속성을 활용해서 위치시킴.

# CSS-gird: flexbox는 기본값이 가로이므로 **1차원적**이라는 한계가 있음. 반면 grid는 선언시 row값과 column 값을 줘서 트랙을 생성하고 이 트랙에 의해서 생긴 셀에 아이템을 배치함. **2차원적**으로 layout 구성이 가능해진다는 것.
