#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  int sum = 0;
  int i;
  printf("Enter the value of n :");
  int n;
  scanf("%d", &n);
  int pid = fork();
  if (pid == 0) {
    i = 1;
    while(i<=n){
      sum = sum + i;
      i = i + 2;
    }
    printf("Sum of odd number up to %d : %d\n", n, sum);
  }
  if (pid != 0) {
    wait(NULL);
    i = 2;
    while(i<=n){
      sum = sum + i;
      i = i + 2;
    }
    printf("Sum of even number up to %d : %d\n",n, sum);
  }
  return 0;
}
