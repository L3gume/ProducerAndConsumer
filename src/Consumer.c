#include <stdio.h>
#include <stdlib.h>

#include "Consumer.h"

void consumer(void) {

	FILE *TURN;
	FILE *DATA;
	char from_file;

    while ((TURN = fopen("../data/turn.txt", "r+")) == NULL);
        //can't open file until producer is done using it

    if('0' != fgetc(TURN)) {	//if TURN is not 0
        //turn is 1, consumer's turn to read data
        DATA = fopen("../data/data.txt", "r");
        from_file = fgetc(DATA);    //read next char
        putc(from_file, stdout);    //print it to screen
        fclose(DATA);
        rewind(TURN);               //rewind TURN so it can be read again
        fputc('0', TURN);       //update TURN
    }

    fclose(TURN);
}

//this is used to make the function look like it's part of a library
const struct consumer_t Consumer = {
    .consumer = consumer
};