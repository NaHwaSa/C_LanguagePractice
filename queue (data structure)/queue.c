/**
* Queue (using basic_list)
* OOP Style
* made by nahwasa
*/

#include<stdio.h>
#include<stdlib.h>
#include"queue.h"

static void destroy(queue_t* q);
static void enqueue(queue_t* q, void* data);
static void* dequeue(queue_t* q);
static void* peekqueue(queue_t* q);
static int get_size(queue_t* q);
static int is_empty(queue_t* q);


static struct queue_operations op =
	{
		.destroy = destroy,
		.enqueue = enqueue,
		.dequeue = dequeue,
		.peekqueue = peekqueue,
		.get_size = get_size,
		.is_empty = is_empty
	};

/*
* create queue object and return
*/
queue_t* create_queue()
{
	queue_t* q = (queue_t*)malloc(sizeof(queue_t));

	q->list = create_list();
	q->op = &op;

	return q;
}

/*
* release memory
*/
static void destroy(queue_t* q)
{
	q->list->op->destroy(q->list);
	q->list = NULL;
	q->op = NULL;
	free(q);
	q = NULL;
}

/*
* put one data to queue
*/
static void enqueue(queue_t* q, void* data)
{
	q->list->op->insert_to_tail(q->list, data);
}

/*
* get one data from queue and delete
*/
static void* dequeue(queue_t* q)
{
	if ( q->list->op->is_empty(q->list) )
		return NULL;

	node_t* node = q->list->op->get_head_node(q->list);
	q->list->op->delete_head_node(q->list);
	return node->data;
}

/*
* get one data from queue
*/
static void* peekqueue(queue_t* q)
{
	if ( q->list->op->is_empty(q->list) )
		return NULL;

	node_t* node = q->list->op->get_head_node(q->list);
	return node->data;
}

static int get_size(queue_t* q)
{
	return q->list->op->get_size(q->list);
}

static int is_empty(queue_t* q)
{
	return q->list->op->is_empty(q->list);
}
