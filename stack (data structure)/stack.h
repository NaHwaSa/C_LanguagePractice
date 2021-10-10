/**
* Stack Header
* OOP Style
* made by nahwasa
*/

#ifndef STACK_H_NAHWASA
#define STACK_H_NAHWASA

#include"node.h"
#include"list.h"

typedef struct struct_stack{
	list_t* list;
	struct stack_operations* op;
} stack_t;


struct stack_operations {
	void (*destroy)(stack_t* s);
	void (*push)(stack_t* s, void* data);
	void* (*pop)(stack_t* s);
	void* (*peek)(stack_t* s);
	int (*is_empty)(stack_t* s);
	int (*get_size)(stack_t* s);
};

extern stack_t* create_stack();


#endif
