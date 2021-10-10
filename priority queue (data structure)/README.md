## U can test it like this :

~~~
#include<stdio.h>
#include"priority_queue.h"

int main(int argc, char* argv[])
{
	priority_queue_t* q = create_priority_queue();

	q->op->insert(q, 132);
	q->op->insert(q, 6929);
	q->op->insert(q, 232);
	q->op->insert(q, 5933);
	q->op->insert(q, 3254);
	q->op->insert(q, 12);
	q->op->print(q);
	
	q->op->del(q, 3254);
	q->op->print(q);

	q->op->destroy(q);
}
~~~
