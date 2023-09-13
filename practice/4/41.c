#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
int main() {
  int n = fork();
  int a = 5, b = 10;
  if (n != 0) {
      wait(NULL);
      a -= 1;
      b -= 1;
      printf("a=%d , b=%d\n", a, b);
  }
  if (n == 0) {
    a += 1;
    b += 1;
    printf("a=%d , b=%d\n", a, b);
  }
}
