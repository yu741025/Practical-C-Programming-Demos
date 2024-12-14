/*
 * This program demonstrates the use of threads, mutex locks, and condition variables 
 * to implement a barrier synchronization in a multithreaded environment.
 *
 * 1. Import Necessary Header Files and Define Constants:
 *    - `pthread.h`: POSIX threads library header, used for multithreading.
 *    - `stdio.h` and `stdlib.h`: Provide standard input/output and utility functions.
 *    - `NUM_THREADS`: Defines the number of threads to create, set to 5.
 *
 * 2. Define Synchronization Primitives:
 *    - A mutex lock (`mutex`) is used to control access to shared resources, preventing race conditions.
 *    - A condition variable (`cond`) is used for signaling between threads.
 *    - `count`: Tracks the number of threads that have reached the barrier.
 *    - `flag`: Indicates whether all threads have reached the barrier.
 *
 * 3. `pthread_barrier_wait_` Function:
 *    - Simulates a barrier:
 *        - A thread calls this function, locks the mutex, and increments `count`.
 *        - If `count` reaches the total number of threads, it sets `flag` and signals all waiting threads.
 *        - If `count` hasn't reached the total number of threads, the thread waits on the condition variable.
 *        - The mutex is released after these operations.
 *
 * 4. `do_work` Function:
 *    - The function executed by each thread:
 *        - Calls `pthread_barrier_wait_` to wait for other threads at the barrier.
 *        - Once all threads reach the barrier, it retrieves its thread ID and prints a message indicating the thread is running.
 *
 * 5. `main` Function:
 *    - Defines an array of `pthread_t` named `threads`, sized by `NUM_THREADS`, to store thread IDs.
 *
 * 6. Create Threads:
 *    - For each thread:
 *        - Prints a message ("Starting thread i").
 *        - Calls `pthread_create` to create a new thread with the following parameters:
 *            - `&threads[i]`: Pointer to the thread ID.
 *            - `NULL`: Default thread attributes.
 *            - `do_work`: Function the thread will execute.
 *            - `NULL`: No arguments passed to `do_work`.
 *        - If `pthread_create` returns a non-zero value, it indicates thread creation failed, and an error message is printed before exiting.
 *    - Uses `pthread_join` in a loop to ensure the main thread waits for all child threads to complete before continuing execution.
 *
 * 7. Cleanup Resources:
 *    - `pthread_mutex_destroy`: Destroys the initialized mutex lock.
 *    - `pthread_cond_destroy`: Destroys the condition variable.
 *
 * Screenshot of Result:
 *    - The output demonstrates barrier synchronization and ensures all threads coordinate before proceeding.
 */#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 5

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int count = 0;
int flag = 0;

void pthread_barrier_wait_() {
  pthread_mutex_lock(&mutex);
  count++;
  if (count == NUM_THREADS) {
    flag = 1;
    pthread_cond_broadcast(&cond);
  } else {
    while (!flag) {
      pthread_cond_wait(&cond, &mutex);
    }
  }
  pthread_mutex_unlock(&mutex);
}

void *do_work(void *arg) {
  pthread_barrier_wait_();
  pthread_t thread_id = pthread_self();
  printf("Thread %lu running\n", (unsigned long)thread_id);

  return NULL;
}

int main(int argc, char *argv[]) {
  pthread_t threads[NUM_THREADS];

  for (int i = 0; i < NUM_THREADS; i++) {
    printf("Starting thread %d\n", i);
    if (pthread_create(&threads[i], NULL, do_work, NULL) != 0) {
      perror("pthread_create error");
      exit(1);
    }
  }

  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  pthread_mutex_destroy(&mutex);
  pthread_cond_destroy(&cond);

  return 0;
}