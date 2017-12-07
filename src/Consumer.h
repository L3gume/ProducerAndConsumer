#ifndef CONSUMER_H
#define CONSUMER_H

struct consumer_t {
	void (*consumer)(void);
};

extern const struct consumer_t Consumer;

#endif
