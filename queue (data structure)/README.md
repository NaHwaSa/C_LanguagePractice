## U can test it like this :

~~~
#include<stdio.h>
#include"queue.h"

int main(int argc, char* argv[])
{
	queue_t* q = create_queue();

	q->op->enqueue(q, "aa");
	q->op->enqueue(q, "bb");
	q->op->enqueue(q, "cc");
	q->op->enqueue(q, "dd");
	
	printf("%s\n", (char*) q->op->dequeue(q));
	printf("%s\n", (char*) q->op->dequeue(q));	
	printf("%s\n", (char*) q->op->peekqueue(q));	
	printf("%s\n", (char*) q->op->dequeue(q));	
	printf("%s\n", (char*) q->op->dequeue(q));

	q->op->destroy(q);
}
~~~
