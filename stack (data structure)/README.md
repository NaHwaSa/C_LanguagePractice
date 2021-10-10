## U can test it like this :

~~~
#include<stdio.h>
#include"stack.h"

int main(int argc, char* argv[]) {
	stack_t* s = create_stack();

	s->op->push(s, "aa");
	s->op->push(s, "bb");
	s->op->push(s, "cc");
	s->op->push(s, "dd");
	printf("size : %d\n", s->op->get_size(s));

	printf("%s\n", (char*)(s->op->peek(s)));
	printf("%s\n", (char*)(s->op->peek(s)));
	printf("size : %d\n", s->op->get_size(s));
	
	printf("%s\n", (char*)(s->op->pop(s)));
	printf("%s\n", (char*)(s->op->pop(s)));
	printf("%s\n", (char*)(s->op->pop(s)));
	printf("%s\n", (char*)(s->op->pop(s)));
	printf("size : %d\n", s->op->get_size(s));
	//printf("%s\n", (char*)(s->op->pop(s)));
	
	s->op->destroy(s);
}
~~~
