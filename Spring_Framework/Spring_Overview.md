## Spring Framework?

- 자바 플랫폼을 위한 오픈소스 애플리케이션 플레임워크
- 동적인 웹 사이트를 개발하기 위한 여러가지 서비스를 제공한다. 주요기능은 아래와 같다.
  - DI
  - AOP
  - MVC
  - JDBC

스프링 모듈은 대표적으로 아래 모듈들이 있다. 이 모듈을 이용하려면 개발자가 개발 프로젝트에 XML 파일 등으로 직접 모듈에 대한 의존설정을 해주면 된다.

| 스프링 모듈   | 기능                                                                        |
| ------------- | --------------------------------------------------------------------------- |
| spring-core   | 스프링의 핵심인 DI(Dependency Injection)와 IoC(Inversion of Control)을 제공 |
| spring-aop    | AOP구현 기능 제공                                                           |
| spring-jdbc   | DB를 적은 양의 코드로 다룰 수 있는 기능 제공                                |
| spring-tx     | 스프링에서 제공하는 트랜잭션 관련 기능 제공                                 |
| spring-webmvc | 스프링에서 제공하는 컨트롤러와 뷰를 이용한 스프링 MVC 구현 기능 제공        |

- 스프링 컨테이너 (IoC)
  - Container: 스프링에서 객체를 생성하고 조립하는 것
  - Bean: 컨테이너를 통해 생성된 객체

## Spring Framework 특징

- 종속 객체를 생성해주고, 조립할 수 있다.
- 자바 SE로 된 자바 객체(POJO, Plain Old Java Object)를 자바 EE에 의존적이지 않게 연결해준다.

## Spring Project 생성

스프링은 프로젝트를 생성하는데 2~3가지 방법이 있다.

- maven 이용시

  - pom.xml: 스프링 모듈을 가져오기 위한 설정파일이다. 아래처럼 설정을 적어준다.

  ```java
  <dependencies>
    <dependency>
      <groupId>org.springframework</groupId>
      <artifactId>spring-context</artifactId>
      <version>4.1.0.RELEASE</version>
    </dependency>
  </dependencies>
  ```

  ```java
  <build>
    <plugins>
        <plugin>
        <artifactId>maven-compiler-plugin</artifactId>
        <version>3.1</version>
        <configuration>
          <source>1.8</source>
          <target>1.8</target>
          <encoding>utf-8</encoding>
        </configuration>
      </plugin>
    </plugins>
  </build>
  ```

## Spring 폴더 구조

maven으로 스프링 프로젝트를 생성하는 기본 원리는 1) 폴더 구조와 2) pom파일의 역할을 알면 된다.

```
├── src
│   ├── main
│   │   ├── java        // 애플리케이션 기능 구현하는 폴더
│   │   └── resources   // 자원을 관리하는 폴더로 스프링설정파일(XML) 또는 property 파일 등이 관리됨.
├── target
├── .settings
├── .classpath
├── .project
└── pom.xml
```

pom.xml 파일은 메이븐 설정파일로 메이븐은 라이브러리를 연결해주고, 빌드를 위한 플랫폼이다.

spring에서는 java 코드만이 아니라 resource를 이용해서 객체를 생성하는 방법을 주로 쓴다.
