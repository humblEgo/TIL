## JDBC

- JDBC란?
  - Java DataBase Connectivity의 약자이며, Java와 DB가 통신할 수 있게 해주는 API
  - 적절한 JDBC 드라이버만 있으면, DB의 종류와 상관없이 하나의 JDBC API로 DB에 접근할 수 있다.
- JDBC API가 나오게 된 이유는?
  - JDBC API가 없었던 시절에는 각각의 데이터베이스(oracle, mySQL 등등)마다 다른 SQL 문을 사용하였다. 개발자들의 불편은 이루말할 수 없었고 이 문제를 해결하기 위해 일부 function, structure, global variable 등을 통합하였다. 이 통합한 문법을 JDBC API에 명세하여 적절한 JDBC 드라이버만 있으면, DB의 종류와 상관없이 하나의 JDBC API로 DB에 접근할 수 있게 만든 것이다.

* eclipse에서도 Oracle의 API를 이용하기 위해서 Oracle LIB을 eclipse에 복사한다.
  _eclipse의 Java library 경로는 references->Java->Build Path->Classpath Variables에서 JRE_LIB 항목에서 확인할 수 있다. 외부라이브러리는 lib폴더의 ext폴더 내에 설치해서 쓰면 된다_
* JDBC 실행 순서

  1. Driver loading : OracleDriver 로딩

  ```Java
  Class.forName(driver);
  ```

  2. Connection : Java와 Oracle 연결 _여기부터는 인터넷 상황에 따라 오류가 생기기 쉬우므로 try, catch문으로 예외처리해주자._

  ```Java
  con = DriverManager.getConnection(url, id, pw); // finally 문으로 if(con != null) con.close(); 해주자.
  ```

  3. Statement : query 전송 객체

  ```Java
  stmt = con.createStatement(); // finally 문으로 if(stmt != null) stmt.close(); 해주자.
  ```

  4. Query : query 작성

  ```Java
  String sql = "SELECT * FROM book";
  ```

  5. Run : query 전송

  ```Java
  res = stmt.executeQuery(sql);
  ```

* SELECT vs 그 외 DB조작 명령어

  - SELECT 문을 쓸 때는 ResultSet 객체를 만들어서 값을 query 명령문을 Statement 객체에 executeQuery()메서드를 통해 결과값을 `ResultSet result`에 저장한다.
  - INSERT 등 DB값을 조작하는 작업을 할 때는 query 명령문을 Statement 객체에 executeUpdate() 메서드를 통해 결과값을 `int result`에 저장한다.

- PreparedStatement

  - 위 JDBC 실행순서에서 Statement 후에 query를 작성하면 코드가 너무 번잡해지는 문제를 해결하기 위한 방법이다. 적용하면 아래 순서로 JDBC가 실행된다.

  1. Driver loading

  ```Java
  Class.forName(driver);
  ```

  2. Connection

  ```Java
  con = DriverManager.getConnection(url, id, pw); // finally 문으로 if(con != null) con.close(); 해주자.
  ```

  3. query : 쿼리를 먼저 만든다.

  ```Java
  String sql = 'UPDATE book SET book_loc = ? WHERE book_name = ?",
  ```

  4. PreparedStatement

  ```Java
  pstmt = con.prepareStatement(sql);
  pstmt.setString(1, "001-00007123");
  pstmt.setString(2, "book7");
  ```

  5. Run

  ```Java
  int n = pstmt.executeUpdate();
  ```
