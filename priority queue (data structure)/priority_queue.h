/**
* Priority Queue Header
* made by nahwasa
*/

#ifndef PRIORITY_QUEUE_H_NAHWASA
#define PRIORITY_QUEUE_H_NAHWASA
 
#define MAX_SIZE 100

typedef struct {
	int* arr;
	int rear;
	int capacity;
	struct priority_queue_operations* op;
} priority_queue_t;

struct priority_queue_operations {
	void (*insert)(priority_queue_t* q, int data);
	void (*del)(priority_queue_t* q, int data);
	void (*print)(priority_queue_t* q);
	void (*destroy)(priority_queue_t* q);
};	

extern priority_queue_t* create_priority_queue();

#endif
