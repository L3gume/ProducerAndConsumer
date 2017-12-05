#ifndef __CONSUMER
#define __CONSUMER

struct consumerP {
	void (*consumer)(void);
};

extern const struct consumerP Consumer;

#endif
