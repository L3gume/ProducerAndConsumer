#include <unistd.h>
#include "Producer.h"
#include "Consumer.h"

int main(void) {

    pid_t pid = fork();

    while (1) {
        if (pid == 0) {
            Producer.producer();
        }
        if (pid != 0) {
            Consumer.consumer();
        }
        if (pid == -1) {
            // That's a problem, notify the user and exit
            printf("Error: invalid PID\n");
            exit(1);
        }
    }

    // TODO: guarantee that exiting from the producer process actually exits the whole program

    return 0;
}
