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
    }

    return 0;
}
