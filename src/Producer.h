#ifndef PRODUCER_H
#define PRODUCER_H

struct producer {

    /* These two functions are needed for the producer/consumer structure  */
    void (*produce)(void);
    void (*wait)(void);
};

extern const struct producer Producer;

#endif
