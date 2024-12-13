/*
 * This program demonstrates the creation of a zombie process by forking a child process, allowing the parent to observe the child’s status before cleaning it up.
 *
 * Included Header Files:
 *  - `sys/types.h` and `unistd.h`: Provide the prototype for the `fork()` function and other UNIX system services.
 *  - `stdlib.h`: Contains various utility functions, such as `exit`.
 *  - `stdio.h`: Provides functions for input and output handling.
 *
 * Variable Declarations:
 *  - A `pid_t` variable named `pid` is declared to store the process ID returned by the `fork()` function.
 *  - A character array `cmd[50]` is declared to store the command to be executed. It is initialized to all zeros using `{0}`.
 *
 * Forking a Child Process:
 *  - The `fork()` function is called to create a child process.
 *  - If `fork()` returns a value less than 0, it indicates that process creation has failed. 
 *    - In this case, the program prints an error message using `perror` and exits with `exit(1)`.
 *
 * Child Process Execution:
 *  - If `fork()` returns 0, it indicates that the code is running in the child process.
 *  - The child process will immediately terminate using `exit(0)`.
 *  - Before the parent process retrieves the child process's exit status using `wait()` or `waitpid()`, the child process exists as a zombie process.
 *
 * Parent Process Execution:
 *  - If `fork()` returns a value greater than 0, the code is running in the parent process.
 *  - The parent process prints the child process's PID.
 *  - The `snprintf` function is used to format a string and store it in the `cmd` array.
 *    - This string contains the `ps` command, which queries the child process information.
 *  - The `sleep(2)` function makes the parent process sleep for 2 seconds to ensure the child process becomes a zombie process.
 *  - The `system(cmd)` function executes the command stored in the `cmd` array, running the `ps` command to display information about the child process.
 *
 * Result Explanation:
 *  - The result shows the child process's PID as 38388. From the output of the `ps` command:
 *    - `STAT` is `Z+`, indicating that the process has terminated but remains in the system's process table.
 *      - This happens because the parent process has not yet retrieved the child process's exit status, making it a zombie process.
 *    - `COMMAND` is `<defunct>`, further confirming that the process has terminated but has not been removed from the process table.
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {

  pid_t pid;
  char cmd[50] = {0};

  if ((pid = fork()) < 0) {
    perror("fork");
    exit(1);
  }

  if (pid == 0) {
    exit(0);
  }

  if (pid > 0) {
    printf("The child PID is %d\n\n", pid);
    snprintf(cmd, sizeof(cmd), "ps -p %d", pid);
    sleep(2);
    system(cmd);
    exit(0);
  }
}
