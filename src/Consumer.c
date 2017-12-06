#include <stdio.h>
#include <stdlib.h>

#include Consumer.h

void consumer(void) {

	FILE *turn;
	FILE *data;
	char fromFile;
	while(1) {
		//if turn is 1
		//read item in data, set turn to 0

		turn = fopen("../data/turn.txt", "r+");

		if(atoi (getc(turn)) ) {	//if turn is not 0
			//turn is 1, consumer's turn to read data
			data = fopen("../data/turn.txt", "r");
			fromFile = getc(data);
			putc(fromFile, stdout);	//append char to stdout stream
			fclose(data);
			rewind(turn);
			putc("0", turn);
		}
		fclose(turn);
	}
}

const struct consumerP Consumer = {
    .consumer = consumer
};