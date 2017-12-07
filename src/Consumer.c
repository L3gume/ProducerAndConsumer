#include <stdio.h>
#include <stdlib.h>

#include "Consumer.h"

void consumer(void) {

	FILE *TURN;
	FILE *DATA;
	char from_file;

    while ((TURN = fopen("../data/turn.txt", "r+")) == NULL);
        //can't open file until producer is done using it

    if('0' != fgetc(TURN)) {	//if turn is not 0
        //turn is 1, consumer's turn to read data
        DATA = fopen("../data/data.txt", "r");
        from_file = fgetc(DATA);
        putc(from_file, stdout);
        fclose(DATA);
        rewind(TURN);
        fputc('0', TURN);
    }

    fclose(TURN);
}

const struct consumer_t Consumer = {
    .consumer = consumer
};