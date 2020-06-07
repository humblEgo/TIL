# bitmap file?

[cub3D project](https://github.com/humblEgo/42_cursus/tree/master/cub3D)를 진행하며 `--save` 옵션이 입력되면 화면을 bmp파일로 따로 저장하는 요구사항을 처리해야했다. 이를 위해 bmp를 학습하였다.

BMP 파일 포맷은 비트맵 디지털 그림을 저장하는데 쓰이는 그림 파일 포맷이다.
다른 그림 파일 형식과 달리 파일압축 자체를 하지 않아s서 파일 크기가 크다. 인터넷 익스플로어를 제외한 웹 브라우저에서는 이미지로 인식하지 않는 경우가 많아서 자주 쓰이진 않는다.
압축을 하지 않는다는 특징 때문에 압축관리에 추가로 컴퓨팅 자원이 쓰이지 않고, 파일을 읽는 속도가 빠르다. 이 때문에 raw 방면에서는 어느정도 사용되고 있다.

![비트맵 파일 구조](https://user-images.githubusercontent.com/54612343/83354309-c7270f80-a392-11ea-8614-7cdec4bbff46.png)

- 참고 1) [Bitmap-wikipedia](https://en.wikipedia.org/wiki/Bitmap)
- 참고 2) [C언어 코딩도장](https://dojang.io/mod/page/view.php?id=702)
