## Servlet, JSP tip

#### 한글처리

- post 방식일 경우: servlet마다 `request.setCharacterEncoding("UTF-8");`
- get 방식일 경우: server.xml에 <Connector URIEncoding="UTF-8"/> 추가
- Filter
  - 클라이언트와 서버 간에 request, response를 진행할 때 filter를 두고, 해당 filter에 인코딩을 넣어서 한글을 처리할 수 있다.
  - chain 기법을 이용한 방법이다.
