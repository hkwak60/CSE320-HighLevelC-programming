#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pipes[2];

    // Create a pipe
    if (pipe(pipes) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Fork the first child process
    pid_t left, right;
    left = fork();
    if (left == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (left == 0) {
        // Child process 1
        close(pipes[0]);  // Close read end of the pipe

        // Redirect stdout to the write end of the pipe
        dup2(pipes[1], STDOUT_FILENO);

        // Close unused file descriptor
        close(pipes[1]);

        // Execute command 1
        execlp("ls", "ls", "-l", NULL);

        // If execlp fails
        perror("execlp");
        exit(EXIT_FAILURE);
    } else {
        // Fork the second child process
        right = fork();
        if (right == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (right == 0) {
            // Child process 2
            close(pipes[1]);  // Close write end of the pipe

            // Redirect stdin to the read end of the pipe
            dup2(pipes[0], STDIN_FILENO);

            // Close unused file descriptor
            close(pipes[0]);

            // Execute command 2
            execlp("wc", "wc", "-l", NULL);

            // If execlp fails
            perror("execlp");
            exit(EXIT_FAILURE);
        } else {
            // Parent process
            // Close unused file descriptors
            close(pipes[0]);
            close(pipes[1]);

            // Wait for child processes to finish
            waitpid(left, NULL, 0);
            waitpid(right, NULL, 0);
        }
    }

    return 0;
}
