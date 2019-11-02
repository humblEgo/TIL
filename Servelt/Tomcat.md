#### 톰캣은 버전마다 JSP Spec, EL Spec, JASPIC Spec, Supported Java versions, Servlet Spec이 다르다.

이에 찾아본 각 용어별 정보
- JSP(JavaServer Pages): HTML 내에 자바 코드를 삽입하여 웹 서버에서 동적으로 웹 페이지를 생성하여 웹 브라우저에 돌려주는 언어. 실행시에는 자바 서블릿으로 변환된 후 실행되므로 서블릿과 거의 유사하지만, 서블릿과 달리 HTML 표준에 따라 작성되어 웹 디자인에 용이한 이점이 있다고 함.(ex: 서블릿을 활용하면 문구 출력할 때 Java 언어를 써서 sysoutpritnln을 써야해서 불편한데, JSP를 쓰면 HTML로 작성한 문구도 서블릿으로 알아서 변환되므로 편하다고 함.)
- EL(Expression Language): JSP 2.0 Spec에 추가된 개념이라고하며, JSP에서 자바코드와 JSP 스크립트 코드를 더욱 더 간결하게 하기 위해 등장함. EL을 사용하면 Java 코드를 더욱 간결하게 표현가능(ex 자료형 설정안해도 되는 등).
- JASPIC(Java Authentication SPI for Containers): 써드파티 보안 제공자가 웹 애플리케이션으로 예정된 응답 메시지 및 HTTP 요청의 Java EE(Java Platform, Enterprise Edition) 인증을 처리할 수 있게 함. 

- Servlet
: 자바를 사용하여 웹페이지를 동적으로 생성하는 서버측 프로그램 혹은 그 사양. 쉽게말해 URL 요청을 처리하는 프로그램임. WAS에서 동작하는 Java 클래스이기도 함.
: HttpServlet 클래스를 상속받아야한다.
: 서블릿과 JSP로부터 최상의 결과를 얻으려면, 웹 페이지를 개발할 때 이 두가지(JSP, 서블릿)를 조화롭게 사용해야 한다.
EX) 웹 페이지를 구성하는 화면(HTML)은 JSP로 표현하고, 복잡한 프로그래밍은 서블릿으로 구현

 - Servlet Lifecycle 
  서블릿 요청을 받으면 WAS는 해당 서블릿이 메모리에 있는지 확인 하고, 
  <br> 메모리에 없으면 해당 서블릿 클래스를 메모리에 올리고 init 메소드를 실행함. 이어서 service 메소드를 실행함. 
  <br> 만약 메모리에 있으면, service 메소드를 바로 실행함.
	WAS가 종료되거나, 웹 어플리케이션이 새롭게 갱신될 경우, destroy 메서드가 실행됨.
  

