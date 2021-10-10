/**
* Queue Header
* OOP Style
* made by nahwasa
*/

#ifndef QUEUE_H_NAHWASA
#define QUEUE_H_NAHWASA

#include"node.h"
#include"list.h"

typedef struct queue_head {
	list_t* list;
	struct queue_operations* op;
} queue_t;


struct queue_operations {
	void (*enqueue)(struct queue_head* q, void* data);
	void* (*dequeue)(struct queue_head* q);
	void* (*peekqueue)(struct queue_head* q);
	void (*destroy)(queue_t* q);
	int (*get_size)(queue_t* q);
	int (*is_empty)(queue_t* q);
};

extern queue_t* create_queue();

#endif
