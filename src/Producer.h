#ifndef PRODUCER_H
#define PRODUCER_H

#include <stdlib.h>
#include <stdio.h>

struct producer_t {
    void (*producer)(void); // Will write to the file
};

extern const struct producer_t Producer;

#endif
