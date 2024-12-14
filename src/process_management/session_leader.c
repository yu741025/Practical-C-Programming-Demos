/*
 * This program creates a child process, establishes a new session, and demonstrates the child's detachment from the controlling terminal.
 *
 * 1. Fork a New Child Process:
 *    - The program uses `fork()` to create a child process.
 *    - If `fork()` fails, it prints an error message.
 *    - When `pid == 0`, it indicates the child process, which executes the corresponding code block.
 *
 * 2. Create a New Session in the Child Process:
 *    - The child process calls `setsid()` to create a new session.
 *    - If `setsid()` fails, it prints an error message.
 *
 * 3. Verify Process Group Leader and Controlling Terminal:
 *    - Before `setsid()`:
 *      - Retrieve and print the current terminal process group ID (TPGID), along with the child process's PID and process group ID (PGRP).
 *    - After `setsid()`:
 *      - Retrieve and print the updated TPGID, PID, and PGRP to verify changes.
 *      - Execute the `ps` command to observe the child process status.
 *
 * 4. Output Analysis:
 *    - PID (Process ID): A unique identifier for the process.
 *    - PGRP (Process Group ID): The identifier for the process group.
 *    - TPGID (Terminal Process Group ID): The ID of the foreground process group associated with the terminal.
 *    - Explanation:
 *      - When the child process calls `setsid()`:
 *        - The child process becomes the leader of a new session.
 *        - The PGRP is set to the child process's PID.
 *        - The child process detaches from its controlling terminal, resulting in a TPGID of `-1`.
 *      - Observations:
 *        - After `setsid()`, the child's STDIN is detached (TPGID = -1), indicating no controlling terminal.
 *        - However, STDOUT remains associated with the original terminal, inherited from the parent process, allowing output messages to be displayed normally.
 */


#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  pid_t pid;

  if ((pid = fork()) == -1) {
    perror("fork error");
    exit(1);
  } else if (pid == 0) {
    pid_t tpgid = tcgetpgrp(STDIN_FILENO);
    printf("Before setsid() Child PID: %d PGRP: %d TPGID: %d\n", getpid(),
           getpgrp(), tpgid);
    if (setsid() == -1) {
      perror("session error");
      exit(1);
    }
    tpgid = tcgetpgrp(STDIN_FILENO);
    printf("After setsid() Child PID: %d PGRP: %d TPGID: %d\n", getpid(),
           getpgrp(), tpgid);

    char cmd[50] = {0};
    snprintf(cmd, sizeof(cmd), "ps -o pid,pgid,tpgid,comm -p %d", getpid());
    system(cmd);
    return 1;
  } else {
    wait(NULL);
  }

  return 0;
}