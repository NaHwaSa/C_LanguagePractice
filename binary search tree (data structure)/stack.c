/**
* Stack (using linked list)
* OOP Style
* made by nahwasa
*/

#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

static void destroy(stack_t* s);
static void push(stack_t* s, void* data);
static void* pop(stack_t* s);
static void* peek(stack_t* s);
static int is_empty(stack_t* s);
static int get_size(stack_t* s);

static struct stack_operations op =
	{
		.push = push,
		.destroy = destroy,
		.pop = pop,
		.peek = peek,
		.is_empty = is_empty,
		.get_size = get_size
	};

/*
* create stack object and return
*/
stack_t* create_stack()
{
	stack_t* s = (stack_t*)malloc(sizeof(stack_t*));

	s->list = create_list();
	s->op = &op;
	
	return s;
}

/*
* release memory
*/
static void destroy(stack_t* s)
{
	s->list->op->destroy(s->list);
	s->op = NULL;
	free(s);
	s = NULL;
}

/*
* put one data to stack
*/
static void push(stack_t* s, void* data)
{
	s->list->op->insert_to_head(s->list, data);
}

/*
* get one data from stack and delete it
*/
static void* pop(stack_t* s)
{
	if ( s->list->op->is_empty(s->list) )
		return NULL;
	
	node_t* node = s->list->op->get_head_node(s->list);
	s->list->op->delete_head_node(s->list);
	
	return node->data;
}

/*
* get one data from stack
*/
static void* peek(stack_t* s)
{
	if ( s->list->op->is_empty(s->list) )
		return NULL;
	
	node_t* node = s->list->op->get_head_node(s->list);
	
	return node->data;
}

static int is_empty(stack_t* s)
{
	if (!s->list->op->get_size(s->list))
		return 1;
	else
		return 0;
}

static int get_size(stack_t* s)
{
	return s->list->op->get_size(s->list);
}
