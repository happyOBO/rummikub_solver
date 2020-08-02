#include <stdio.h>
int main(int argc, char **argv) { 
    for (int i = 0; i < 110; ++i) {
     // \033[스타일_번호m 스타일 시작 
     printf("%3d --> \033[%dm%s\033[0m\n", i, i, "Text");
      // \033[0m 스타일 끝. 스타일을 끝내지 않으면 이후의 출력들도 앞서 지정한 스타일로 출력된다. 
      } return 0; }
