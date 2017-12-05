#ifndef PRODUCER_H
#define PRODUCER_H

#include <stdlib.h>
#include <stdio.h>

struct producer {
    void (*produce)(void); // Will write to the file
};

extern const struct producer Producer;

#endif
