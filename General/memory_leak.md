# Memory leak

Memory leak은 크게 두가지 의미로 쓰인다.

1. Memory was allocated and was not subsequently freed before the program terminated.

   - memory leack의 엄격한 정의이다.
   - 많은 개발자들은 이 정의에 해당하는 케이스 중 동적할당된 메모리 주소를 잃어버리지 않은 경우(still reachable memory)엔 'memory leak'으로 생각할 필요없다고 한다.
   - 'still reachable'한 메모리는 OS가 프로세스 종료시 회수해가므로 힙 고갈(heap depletion)의 위험이 없기 때문이다.
   - valgrind로 체크했을 때 report에 'still reachable' 카테고리가 보인다면 이 케이스에 해당하는 것이다. ![image](https://user-images.githubusercontent.com/54612343/83583565-a2dc5600-a57f-11ea-96b0-fd4b3bc35f13.png)

2. Memory was allocated and _cannot_ be subsequently freed because the program no longer has any pointers to the allocated.
   - 일반적으로 유효하게 쓰이는 'memory leak' 정의이다. valgrind에서는 이를 'memory leak'정의로 채택하고 있다.
   - 이 경우 memory를 free하려고 해도 주소를 잃어버려서 free할 수가 없다.
   - 결과적으로 상당한 힙 고갈(heap depletion)을 유발할 수 있다.

# Memory leak 예시

```C
int foo(void)
{
    static char *working_buf = NULL;
    char *temp_buf;
    if (!working_buf) {
         working_buf = (char *) malloc(16 * 1024);
    }
    temp_buf = (char *) malloc(5 * 1024);

    ....
    ....
    ....

}
```

위 예시 코드 이후에 별도의 free가 없는채로 함수가 종료되었다고 가정하면 아래 memory leak이 발생한다.

- working_buf: global이나 static 변수에 malloc된 경우 메모리 주소를 원한다면 찾을 수 있다. 1번 정의의 memory leak이다.
- temp_buf: 지역변수이므로 메모리주소를 잃어버린다. 2번 정의의 memory leak으로 심각한 문제를 일으킬 수 있다.

참고

- [Valgrind Frequently Asked Questions](https://www.valgrind.org/docs/manual/faq.html)
- [Still Reachable Leak detected by Valgrind](https://stackoverflow.com/questions/3840582/still-reachable-leak-detected-by-valgrind)
