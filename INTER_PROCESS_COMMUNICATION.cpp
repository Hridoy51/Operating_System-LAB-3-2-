#include <cstdio>
#include <ctime>
#include <iostream>
#include <sys/types.h>
// #include <sys/wait.h>
#include <unistd.h>

using namespace std;

int main() {
  int fd[2];
  pid_t pid;

  // create the pipe
  if (pipe(fd) == -1) {
    perror("Pipe creation failed");
    return 1;
  }

  // create the first child process
  pid = fork();
  if (pid == -1) {
    perror("First fork failed");
    return 1;
  }

  // child process 1
  if (pid == 0) {
    // close the reading end of the pipe
    close(fd[0]);

    // write a message to the pipe
    char message[] = "What is the current time?";
    write(fd[1], message, sizeof(message));

    // close the writing end of the pipe
    close(fd[1]);
    return 0;
  }

  // create the second child process
  pid = fork();
  if (pid == -1) {
    perror("Second fork failed");
    return 1;
  }

  // child process 2
  if (pid == 0) {
    // close the writing end of the pipe
    close(fd[1]);

    // read the message from the pipe
    char message[100];
    read(fd[0], message, sizeof(message));
    cout << "Child 2: Received message: " << message << endl;

    // get the current time
    time_t now = time(0);
    char *time_str = ctime(&now);

    // write the time to the pipe
    write(fd[1], time_str, sizeof(time_str));

    // close the reading end of the pipe
    close(fd[0]);
    return 0;
  }

  // parent process
  // close both ends of the pipe
  close(fd[0]);
  close(fd[1]);

  // wait for the child processes to complete
  wait(NULL);
  wait(NULL);

  return 0;
}