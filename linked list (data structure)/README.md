## U can test it like this :

~~~
#include<stdio.h>
#include<stdlib.h>
#include"list.h"

int main(int argc, char* argv[]) {
	list_t* l = create_list();
	
	printf("--- insert test ---\n");
	l->op->insert_to_head(l, "aaa");
	l->op->insert_to_tail(l, "bbbb");
	l->op->insert_to_head(l, "cc");
	l->op->insert_to_head(l, "dddddd");
	l->op->insert_to_head(l, "eeeeeeee");
	printf("::: %d :::\n", l->op->get_size(l));
	l->op->print(l);

	printf("--- insert before node test ---\n");
	node_t* pos = l->op->get_head_node(l);
	pos = pos->next->next;
	l->op->insert_to_before_node(l, pos, "here");
	printf("::: %d :::\n", l->op->get_size(l));
	l->op->print(l);	
	
	printf("--- delete test ---\n");
	l->op->delete_tail_node(l);
	l->op->delete_head_node(l);
	printf("::: %d :::\n", l->op->get_size(l));
	l->op->print(l);	
	
	l->op->destroy(l);
}
~~~

