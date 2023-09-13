#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  int pid = fork();
  if (pid != 0) {
      wait(NULL);
      printf("\n\nIn Parent process\n");
      printf("The Parent process id = %d\nThe Child process id = %d",getppid(),getpid());
      }
  if (pid == 0) {
      printf("\n\nIn Child process\n");
      printf("The Parent process id = %d\nThe Child process id = %d",getppid(),getpid());
  }
  return 0;
}
