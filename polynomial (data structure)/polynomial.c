/**
* Polynomial
* made by nahwasa
*/

#include <stdio.h>
#include <stdlib.h>
#include"polynomial.h"

static void destroy(polynomial_t* p);
static void insert_term(polynomial_t* p, double coef, int exp);
static polynomial_t* add_polynomials(polynomial_t* p1, polynomial_t* p2);
static void print(polynomial_t* p);

static struct polynomial_operations op =
	{
		.destroy = destroy,
		.insert_term = insert_term,
		.add_polynomials = add_polynomials,
		.print = print
	};

polynomial_t* create_polynomial()
{
	polynomial_t* p = (polynomial_t*)malloc(sizeof(polynomial_t));

	p->list = create_list();
	p->op = &op;

	return p;
}

static void destroy(polynomial_t* p)
{
	p->list->op->destroy(p->list);
	p->op = NULL;
	free(p);
	p = NULL;
}

/*
* polynomial_t list terms ascend. so find position
*/
static node_t* find_add_position_node(polynomial_t* p, int exp)
{
	int i;
	polynomial_term_t* t;
	node_t* pos = p->list->op->get_head_node(p->list);
		
	for (i = 0; i < p->list->op->get_size(p->list); i++) {
		t = (polynomial_term_t*)pos->data;		

		if (t->exp < exp)
			return pos;
		pos = pos->next;			
	}

	return NULL;
}

/*
* insert term(coef^exp) to p
*/
static void insert_term(polynomial_t* p, double coef, int exp)
{
	node_t* pos; 
	polynomial_term_t* t = (polynomial_term_t*)malloc(sizeof(polynomial_term_t));
	t->coef = coef;
	t->exp = exp;
	
	if (!p->list->op->get_size(p->list)) {
		p->list->op->insert_to_head(p->list, t);
		return;	
	}

	pos = find_add_position_node(p, exp);
	
	if (pos == NULL)
		p->list->op->insert_to_tail(p->list, t);
	else
		p->list->op->insert_to_before_node(p->list, pos, t);
}

/*
* add p1 and p2. finally new polynomial_t return
*/
static polynomial_t* add_polynomials(polynomial_t* p1, polynomial_t* p2)
{
	polynomial_t* p = create_polynomial();
	node_t* n1 = p1->list->op->get_head_node(p1->list);
	node_t* n2 = p2->list->op->get_head_node(p2->list);
	polynomial_term_t* t1 = (polynomial_term_t*)n1->data;
	polynomial_term_t* t2 = (polynomial_term_t*)n2->data;

	while (n1 != NULL && n2 != NULL) {
		printf("deb!\n");
		p->op->print(p);
		if (n1 == NULL) {
			p->op->insert_term(p, t2->coef, t2->exp);
			
			n2 = n2->next;
			if (n2 != NULL)
				t2 = (polynomial_term_t*)n2->data;
		} else if (n2 == NULL) {
			p->op->insert_term(p, t1->coef, t1->exp);
			
			n1 = n1->next;
			if (n1 != NULL)			
				t1 = (polynomial_term_t*)n1->data;
		} else if (t1->exp > t2->exp) {
			p->op->insert_term(p, t1->coef, t1->exp);
			
			n1 = n1->next;
			if (n1 != NULL)			
				t1 = (polynomial_term_t*)n1->data;
		} else if (t2->exp > t1->exp) {
			p->op->insert_term(p, t2->coef, t2->exp);
			
			n2 = n2->next;
			if (n2 != NULL)
				t2 = (polynomial_term_t*)n2->data;
		} else {
			if (t1->coef + t2->coef != 0)
				p->op->insert_term(p, t1->coef + t2->coef, t1->exp);

			n1 = n1->next;
			if (n1 != NULL)
				t1 = (polynomial_term_t*)n1->data;
			n2 = n2->next;

			if (n2 != NULL)
				t2 = (polynomial_term_t*)n2->data;
		}		
	}	
	return p;
}


static void print(polynomial_t* p)
{
	node_t* nd;
	polynomial_term_t* t;	

	if (!p->list->op->get_size(p->list)) {
		printf("No data!");
		return;
	}

	nd = p->list->op->get_head_node(p->list);

	while (nd != NULL) {
		t = (polynomial_term_t*)nd->data;

		if (!(nd == p->list->tail))
			printf("%.1fx^%d + ", t->coef, t->exp);
		else
			printf("%.1fx^%d", t->coef, t->exp);

		nd = nd->next;		
	}
	printf("\n");
}



