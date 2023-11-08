#include "so_scheduler.h"

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

typedef enum {FALSE, TRUE} boolean;

// Here thread state should be implemented.

/*
 * My implementation of thread structure. Implementation
 * of semaphore to mark the state of the thread and remaining
 runtime should also be implemented in the code.
 */
typedef struct {
	tid_t tid;
	int priority;
	int runtime;
	so_handler *handler;
	// TO DO: Implement semaphore structure.
} thread;


/*
 * Scheduler structure in order to retain information about
 * ongoing state. My idea was to implement a priority queue
 * as a representation of what threads need to be accessed.
 */

typedef struct {
	int io;
	int quantum;

	thread **th;
	thread **prio_q;

} scheduler;

static scheduler thread_scheduler;
static boolean ok; // Checks if scheduler is initialized or not

/*
 * Thread routine where we should set state of thread,
 * plan thread and execute routine.
 */

static void start_thread(thread *t)
{
	t->handler(t->priority);
}

// Initialization of scheduler
int so_init(unsigned int quantum, unsigned int io)
{
	if (ok || quantum == 0 || io > 256)
		return -1;

	ok = TRUE;
	thread_scheduler.io = io;
	thread_scheduler.quantum = quantum;
	// calloc should be used later in execution
	thread_scheduler.th = (thread **)malloc(sizeof(thread *));
	thread_scheduler.prio_q = (thread **)malloc(sizeof(thread *));

	return 0;
}

// TO DO: Add thread to queue
tid_t so_fork(so_handler *handler, unsigned int priority)
{
	if (!handler || priority > 5)
		return 0;

	tid_t id;
	thread *t = (thread *)malloc(sizeof(thread));

	t->tid = 0;
	t->priority = priority;
	t->handler = handler;
	// Start & join thread
	pthread_create(&t->tid, NULL, (void *)start_thread, (void *)t);
	pthread_join(t->tid, NULL);
	id = t->tid;
	free(t);
	return id;
}

void so_exec(void)
{
	/*
	 * Here a sem_wait operation should be implemented for current thread
	 * in case of preemption.
	 */
}

int so_wait(unsigned int io)
{
	if (io >= thread_scheduler.io)
		return -1;

	return 0;
}
int so_signal(unsigned int io)
{
	if (io >= thread_scheduler.io)
		return -1;
	return 0;
}

// Free all memory
void so_end(void)
{
	if (ok == FALSE)
		return;
	free(thread_scheduler.th);
	free(thread_scheduler.prio_q);
	ok = FALSE;
}
