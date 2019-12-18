### getter&setter?
----
클래스 내의 변수를 관리하기 위하여, private로 선언된 변수를 외부에서 **읽을 수 있도록**하기 위해서 **getter** 컨셉의 메소드를 만들고, **값을 수정할 수 있도록**하기 위해서 **setter** 컨셉의 메소드를 만들 수 있다.
setter안에 유효성 검사를 넣어두면 입력되는 변수값을 통제할 수 있다!


하단은 예시코드이다.
<pre>
public class SimpleLocation
{
  private double latitude;
  private double longitude;
  
  public SimpleLocation(double lat, double lon)
  {
    this.latitude = lat;
    this.longitude = lon;
  }
  
  //getter
  public double getLatitude()
  {
     return this.latitude;
  }
  
  public double setLatitude(double latitudeValue)
  {
      this.latitude = latitudeValue;
  }
 
  
  // more code here (defines the method distance, etc.)
  // ...
  
  public static void main(String[] args)
  {
  // more code here 
  // ...
  }
}
</pre>


### Memory Models With Objects
객체를 생성하면, 힙 영역 메모리를 할당하여 해당 객체가 배치된다. 
세부적인 동작은 아래 예시와 같다. 
  1. `wiz`라는 객체를 만들어서, Java가 임의로 `@42`라는 힙 주소에 객체를 생성했다고 가정하면
  2. `wiz`라는 객체에 모든 객체정보를 저장하는 것이 아니라, reference로 불리는 객체의 위치를 저장한다. 이 경우엔 `@42`가 reference이다.
이런 원리 때문에, 임의의 객체 'aObject'와 'bObject'를 생성하고, `aObject = bObject`와 같이 코드를 작성하면, bObject에 저장된 reference(힙 영역 주소)가 aObject에 복사되어 덮어써진다고 볼 수 있다.
※ 메모리 모델을 그릴 때 주의할 점이 있는데, **java의 매개 변수는 항상 참조가 아니라 값으로 전달**된다는 것이다.
