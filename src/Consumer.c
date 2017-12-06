#include <stdio.h>
#include <stdlib.h>

#include "Consumer.h"

void consumer(void) {

	FILE *TURN;
	FILE *DATA;
	char fromFile;
	while(1) {
		//if turn is 1
		//read item in data, set turn to 0

		while ((TURN = fopen("../data/turn.txt", "r+")) == NULL);
			//can't open file until producer is done using it

		if( fgetc(TURN) ) {	//if turn is not 0
			//turn is 1, consumer's turn to read data
			DATA = fopen("../data/turn.txt", "r");
			fromFile = getc(DATA);
			putc(fromFile, stdout);	//append char to stdout stream
			fclose(DATA);
			rewind(TURN);
			putc("0", TURN);
		}
		fclose(TURN);
	}
}

const struct consumerP Consumer = {
    .consumer = consumer
};