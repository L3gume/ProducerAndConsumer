#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "Producer.h"
#include "Consumer.h"

int main(void) {

    pid_t pid = fork();
    int status;

    // Infinite loop, its ok since we break from it when the child process (the producer) terminates
    while (1) {
        if(waitpid(pid, &status, WNOHANG) == pid) {
            // The producer is done and has exited
            break; // Break out of the loop, terminating the program
        } else {
            // child process still running
            switch (pid) {
                default: Consumer.consumer(); break;
                case 0: Producer.producer(); break;
                case -1: printf("Error: invalid PID\n"); exit(1);
            }
        }
    }

    return 0;
}
