#include <pthread.h> // Include the pthread header
#include <stdio.h>

#define NUM_THREADS 3

int je, jo, evensum = 0, sumn = 0, oddsum = 0, evenarr[50], oddarr[50];

void *Even() {
  int i, n;
  je = 0;

  for (i = 1; i <= n; i++) {
    if (i % 2 == 0) {
      evenarr[je] = i;
      evensum = evensum + i;
      je++;
    }
  }
  pthread_exit(NULL); // Terminate the thread
}

void *Odd() {
  int i, n;
  jo = 0;

  for (i = 1; i <= n; i++) {
    if (i % 2 != 0) {
      oddsum = oddsum + i;
      oddarr[jo] = i;
      jo++;
    }
  }
  pthread_exit(NULL); // Terminate the thread
}

void *SumN() {
  int i, n;

  for (i = 1; i <= n; i++) {
    sumn = sumn + i;
  }
  pthread_exit(NULL); // Terminate the thread
}

int main() {
  pthread_t threads[NUM_THREADS];
  int i, t;

  printf("Enter a number: ");
  scanf("%d", &t);

  // Create threads to call the Even, Odd, and SumN functions
  pthread_create(&threads[0], NULL, Even, NULL);
  pthread_create(&threads[1], NULL, Odd, NULL);
  pthread_create(&threads[2], NULL, SumN, NULL);

  for (i = 0; i < NUM_THREADS; i++) {
    pthread_join(threads[i], NULL); // Wait for each thread to finish
  }

  // Display the results
  printf("The sum of first %d natural numbers is %d\n", t, sumn);
  printf("The sum of first %d even numbers is %d\n", t, evensum);
  printf("The sum of first %d odd numbers is %d\n", t, oddsum);

  printf("The first %d Even numbers are:\n", t);
  for (i = 0; i < je; i++) {
    printf("%d ", evenarr[i]);
  }
  printf("\n");

  printf("The first %d Odd numbers are:\n", t);
  for (i = 0; i < jo; i++) {
    printf("%d ", oddarr[i]);
  }
  printf("\n");

  pthread_exit(NULL); // Terminate the main thread
}

