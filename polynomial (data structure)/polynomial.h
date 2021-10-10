/**
* Polynomial Header
* made by nahwasa
*/

#ifndef NODE_POLYNOMIAL_H_NAHWASA
#define NODE_POLYNOMIAL_H_NAHWASA

#define MAX(a,b) ((a>b)?a:b)
#define MAX_DEGREE 10

#include"node.h"
#include"list.h"

typedef struct polynomial_term {
	double coef;
	int exp;
} polynomial_term_t;

typedef struct {
	list_t* list;
	struct polynomial_operations* op;	
} polynomial_t;

struct polynomial_operations {
	void (*destroy)(polynomial_t* p);
	void (*insert_term)(polynomial_t* p, double coef, int exp);
	polynomial_t* (*add_polynomials)(polynomial_t* p1, polynomial_t* p2);
	void (*print)(polynomial_t* p);
};

extern polynomial_t* create_polynomial();

#endif
