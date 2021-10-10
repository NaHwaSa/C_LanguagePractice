/**
* Priority Queue using array
* made by nahwasa
*/

#include<stdio.h>
#include<stdlib.h>
#include"priority_queue.h"

static void insert(priority_queue_t* q, int data);
static void del(priority_queue_t* q, int data);
static void print(priority_queue_t* q);
static void destroy(priority_queue_t* q);

static struct priority_queue_operations op = 
	{
		.insert = insert,
		.del = del,
		.print = print,
		.destroy = destroy
	};
 
priority_queue_t* create_priority_queue()
{
	priority_queue_t* q = (priority_queue_t*)malloc(sizeof(priority_queue_t));
	q->arr = (int*)malloc(sizeof(int) * MAX_SIZE);
    	q->rear = -1;
	q->op = &op;
	q->capacity = MAX_SIZE;
}

static void destroy(priority_queue_t* q)
{
	free(q->arr);
	q->arr = NULL;
	q->op = NULL;
	free(q);	
	q = NULL;
}

/*
* arrange array and insert 'data'
*/
static void re_arrange_and_insert(priority_queue_t* q, int data)
{
	int i, j;
 
	for (i = 0; i <= q->rear; i++)	{
		if (data >= q->arr[i]) {
			for (j = q->rear + 1; j > i; j--){
				q->arr[j] = q->arr[j - 1];
			}
			q->arr[i] = data;
			return;
		}
	}
	q->arr[i] = data;
}

/*
* when array size is over, must increase size
*/
static void increase_array_size(priority_queue_t* q)
{
	int i;
	int* new_arr = (int*)malloc(sizeof(int) * (q->capacity + MAX_SIZE));
	q->capacity += MAX_SIZE;
	
	for (i = 0; i <= q->rear; i++) {
		new_arr[i] = q->arr[i];
	}

	free(q->arr);
	q->arr = new_arr;
}

/*
* insert 'data' to 'q'
*/
static void insert(priority_queue_t* q, int data)
{
	if (q->rear >= MAX_SIZE - 1) {
		increase_array_size(q);
	}

	if (q->rear == -1) {
		q->rear++;
		q->arr[q->rear] = data;
		return;
	} else
		re_arrange_and_insert(q, data);

	q->rear++;
}

/*
* remove 'data' from 'q'
*/
static void del(priority_queue_t* q, int data)
{
	int i;
 
	if (q->rear==-1) {
		printf("No Data in Q\n");
		return;
	}
 
	for (i = 0; i <= q->rear; i++) {
		if (data == q->arr[i]) {
			for (; i < q->rear; i++){
				q->arr[i] = q->arr[i + 1];
			}
 
			q->arr[i] = -99;
			q->rear--;

			return;
		}
	}

	printf("Can't find %d\n", data);
}
 

static void print(priority_queue_t* q)
{
	int i;

	if (q->rear == -1){
		printf("No Data in Q\n");
		return;
	}
 
	for (i = 0; i <= q->rear; i++){
		printf("%d ", q->arr[i]);
	}
	printf("\n");
}



