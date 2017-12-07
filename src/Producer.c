#include "Producer.h"

/*
 * Producer function
 *
 * Reads from the mydata.txt file and gives it to the consumer via the data.txt file
 */
void producer(void) {

    FILE *MY_DATA;
    FILE *TURN;
    FILE *DATA;

    static int pos = 0; // Keep track of the position in the mydata.txt file,
                        // making this static makes it persistent when leaving the scope of the function

    while ((TURN = fopen("../data/turn.txt", "r+")) == NULL); // Wait for access to the file

    if ('0' == fgetc(TURN)) {
        while ((DATA = fopen("../data/data.txt", "r+")) == NULL);

        /* Open the mydata.txt file, read a character and put in into data.txt  */
        MY_DATA = fopen("../data/mydata.txt", "r"); // Open in read mode
        fseek(MY_DATA, (long)pos++, SEEK_SET); // Go to the right position

        int c = fgetc(MY_DATA); // Get the next character from the file
        if (feof(MY_DATA)) {
            // We reached the end of the file, terminated the process
            exit(0);
        }
        fputc(c, DATA); // Write the character in the data.txt file

        /* Close the files so that the consumer will be able to access them */
        fclose(MY_DATA);
        fclose(DATA);

        /* Rewind for safety and then set turn */
        rewind(TURN);
        fputc('1', TURN);
    }
    /* Close the turn.txt file, signifying we are done with it */
    fclose(TURN);
}

// Use the designated initializer to make the function pointer point to the actual implementation of the producer function
const struct producer_t Producer = {
    .producer = producer
};
