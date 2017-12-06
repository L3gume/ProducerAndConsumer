#include "Producer.h"

void producer(void) {
    // TODO

    FILE *TURN;
    FILE *DATA;

    while ((TURN = fopen("../data/turn.txt", "r+")) == NULL); // Wait for access to the file

    int _turn = fgetc(TURN); // get the first character of the turn.txt file.

    /* We only want to do stuff if _turn IS 0  */
    if (!_turn) {
        char c = getchar();
        if (c != 0x00) {
            while ((DATA = fopen("../data/data.txt", "w")) == NULL); // Opened with w since we don't care about overwriting it
            fputc((int)c, DATA);
            fputc(0x00, TURN);
            fclose(DATA);
        } else {
            exit(0); // we're done here
        }
    }
    fclose(TURN);
}

const struct producer_t Producer = {
    .producer = producer
};
