#ifndef __CONSUMER
#define __CONSUMER

struct consumerP {
	pid_t pid;

	void (*consumer)(void);
};

extern const struct consumerP Consumer;

#endif
