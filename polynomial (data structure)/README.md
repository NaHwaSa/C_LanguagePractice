## U can test it like this :

~~~
#include<stdio.h>
#include"polynomial.h"

int main(int argc, char* argv[])
{
	polynomial_t* p;
	polynomial_t* p1;
	polynomial_t* p2;

	p1 = create_polynomial();
	p1->op->insert_term(p1, 3.3, 2);
	p1->op->insert_term(p1, 7.4, 6);
	p1->op->insert_term(p1, 2.5, 1);
	p1->op->insert_term(p1, 9.2, 8);	
	p1->op->print(p1);
	
	p2 = create_polynomial();
	p2->op->insert_term(p2, 6.2, 2);
	p2->op->insert_term(p2, 4.3, 6);
	p2->op->insert_term(p2, 2.6, 1);
	p2->op->insert_term(p2, 10.3, 10);
	p2->op->insert_term(p2, 22.1, 12);	
	p2->op->insert_term(p2, 2.0, 8);		
	p2->op->print(p2);
	
	p = p->op->add_polynomials(p1, p2);
	p->op->print(p);

	p->op->destroy(p);
	p1->op->destroy(p1);
	p2->op->destroy(p2);
}
~~~
