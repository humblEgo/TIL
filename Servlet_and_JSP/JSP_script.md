## JSP 주요 스크립트

- 선언 태그

  - JSP 페이지에서 Java의 멤버변수 또는 메서드를 선언

  ```java
  <%!
    int num = 10;
    String str = "jsp";
    ArrayList<String> list = new ArrayList<String>();

    public void jspMethod() {
      System.out.println("---jspMethod()---");
    }
  %>
  ```

- 주석 태그
  - jsp 주석은 jsp 파일이 서블릿 파일로 변환될 때 제외된다.
- 스크립트릿 태그

  - JSP 페이지에서 Java 코드를 넣기 위한 태그

  ```java
  <%
    if (num > 0) {
  %>
    <p> num >0 </p>
  <%
    } else {
  %>
    <p> num <- 0 </p>
  <%
    }
  %>
  ```

_이처럼 JSP는 Java코드와 html코드가 뒤섞이므로, 주로 view를 구현하는데 쓰인다._

- 표현식 태그
  - Java의 변수 및 메서드의 반환값을 출력하는 태그
  ```java
  num is <%= num %>
  ```
- 지시어

  - 서버에서 JSP 페이지를 처리하는 방법에 대한 정의

  1. page: 페이지 기본 설정 -> <% page 속성="속성 값">

  ```java
  <%@ page language="java" contentType="text/html; charset=EUC-KR" pageEncoding="EUC-KR"%>
  ```

  2. include: include file 설정 -> <% include file="파일명">

  ```java
  <%@ include file= "header.jsp"%>
  ```

  3. taglib: 외부라이브러리 태그 설정 -> <% taglib uri="uri" prefix="네임스페이스명">

  ```java
  <%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
  ```
