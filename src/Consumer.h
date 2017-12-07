#ifndef CONSUMER_H
#define CONSUMER_H

struct consumer_t {
	void (*consumer)(void);
};

//the struct is used to simulate a library
extern const struct consumer_t Consumer;

#endif
