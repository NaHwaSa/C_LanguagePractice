/**
* binary search tree (with and without recursion call)
* made by nahwasa
*
* list OOP, there's root Node.
*
*     bst  -- start tree structure and using like OOP's class name
*      |
*     root    
*     /   \
* nodes..  nodes..
*
* SO, you can make many tree structures you wants.
*/

#include<stdio.h>
#include<stdlib.h>
#include"binary_search_tree.h"

static void destroy(bst_t* b);
static bst_node_t* search_node_recursive(bst_t* b, int find_num);
static void insert_node_recursive(bst_t* b, int num);
static void remove_node_recursive(bst_t* b, int num);
static void print_inorder_recursive(bst_t* b);
static void print_preorder_recursive(bst_t* b);
static void print_postorder_recursive(bst_t* b);
static bst_node_t* search_node_nonrecurrent(bst_t* b, int find_num);
static void insert_node_nonrecurrent(bst_t* b, int num);
static void remove_node_nonrecurrent(bst_t* b, int num);
static void print_inorder_nonrecurrent(bst_t* b);
static void print_preorder_nonrecurrent(bst_t* b);
static void print_postorder_nonrecurrent(bst_t* b);
static void print_bfs(bst_t* b);
static void print_dfs(bst_t* b);
static int get_size(bst_t* b);

/*
* functions using recursive call
*/
static struct bst_operations recursive_op =
	{
		.destroy = destroy,
		.search_node = search_node_recursive,
		.insert_node = insert_node_recursive,
		.remove_node = remove_node_recursive,
		.print_inorder = print_inorder_recursive,
		.print_preorder = print_preorder_recursive,
		.print_postorder = print_postorder_recursive,
		.print_bfs = print_bfs,
		.print_dfs = print_dfs,
		.get_size = get_size
	};

/*
* functions without recursive call
*/
static struct bst_operations nonrecurrent_op =
	{
		.destroy = destroy,
		.search_node = search_node_nonrecurrent,
		.insert_node = insert_node_nonrecurrent,
		.remove_node = remove_node_nonrecurrent,
		.print_inorder = print_inorder_nonrecurrent,
		.print_preorder = print_preorder_nonrecurrent,
		.print_postorder = print_postorder_nonrecurrent,
		.print_bfs = print_bfs,
		.print_dfs = print_dfs,
		.get_size = get_size
	};


bst_t* create_recursive_bst()
{
	bst_t* b = (bst_t*)malloc(sizeof(bst_t));
	b->op = &recursive_op;
	b->root = NULL;
	b->size = 0;
	return b;
}


bst_t* create_nonrecurrent_bst()
{
	bst_t* b = (bst_t*)malloc(sizeof(bst_t));
	b->op = &nonrecurrent_op;
	b->root = NULL;
	b->size = 0;
	return b;
}


static void destroy(bst_t* b)
{
	b->op = NULL;
	free(b);
	b = NULL;
}

/*
* create one node
*/
static bst_node_t* create_node(int num)
{
	bst_node_t* n = (bst_node_t*)malloc(sizeof(bst_node_t));
	n->left = NULL;
	n->right = NULL;
	n->num = num;
	n->checked = 0;
 
	return n;
}

static bst_node_t* search_node_nonrecurrent(bst_t* b, int find_num)
{
	stack_t* st = create_stack();
	
	if (b->root == NULL) {	// if there's no root node
		st->op->destroy(st);		
		return NULL;
	}
	
	st->op->push(st, b->root);

	while (!st->op->is_empty(st)) {
		bst_node_t* n = (bst_node_t*)st->op->pop(st);

		if (n->num == find_num)
			return n;
		else if (n->num > find_num)
			st->op->push(st, n->left);
		else
			st->op->push(st, n->right);
	}

	st->op->destroy(st);
	return NULL;
}

static bst_node_t* search_node_recursive_sub(bst_node_t* n, int find_num)
{
	if (n == NULL)
		return NULL;

	if (n->num == find_num)
		return n;
	else if (n->num > find_num)
		search_node_recursive_sub(n->left, find_num);
	else
		search_node_recursive_sub(n->right, find_num);
}

static bst_node_t* search_node_recursive(bst_t* b, int find_num)
{
	if (b->root == NULL)	// if there's no root node
		return NULL;
		
	return search_node_recursive_sub(b->root, find_num);
}

 
static void insert_node_nonrecurrent(bst_t* b, int num)
{
	bst_node_t* nn = create_node(num);
	stack_t* st = create_stack();
		
	
	if (b->root == NULL) {
		b->root = nn;
		b->size++;
		st->op->destroy(st);
		return;	
	}
	
	st->op->push(st, b->root);
	while (!st->op->is_empty(st)) {
		bst_node_t* n = (bst_node_t*)st->op->pop(st);
		
		if (nn->num > n->num) {
			if (n->right != NULL)
				st->op->push(st, n->right);
			else 
				n->right = nn;
		} else if (nn->num <= n->num) {
			if (n->left != NULL)
				st->op->push(st, n->left);
			else 
				n->left = nn;
		}
	}
		
	b->size++;
	st->op->destroy(st);	
}

static void insert_node_recursive_sub(bst_node_t* n, bst_node_t* nn)
{
	if (nn->num > n->num) {
		if (n->right != NULL)
			insert_node_recursive_sub(n->right, nn);
		else 
			n->right = nn;
	} else if (nn->num <= n->num) {
		if (n->left != NULL)
			insert_node_recursive_sub(n->left, nn);
		else 
			n->left = nn;
	}
}


static void insert_node_recursive(bst_t* b, int num)
{
	bst_node_t* nn = create_node(num);
	
	if (b->root == NULL) {
		b->root = nn;
		b->size++;
		return;	
	}

	insert_node_recursive_sub(b->root, nn);
	b->size++;
}


static bst_node_t* find_min_bst_node(bst_t* b, bst_node_t* bn)
{
	stack_t* st = create_stack();

	if (bn == NULL) {
		st->op->destroy(st);
		return NULL;	
	}

	st->op->push(st, bn);
	while (!st->op->is_empty(st)) {
		bst_node_t* n = (bst_node_t*)st->op->pop(st);

		if (n->left != NULL)
			st->op->push(st, n->left);
		else {
			st->op->destroy(st);
			return n;
		}
	}
}

static bst_node_t* find_max_bst_node(bst_t* b, bst_node_t* bn)
{
	stack_t* st = create_stack();	
	
	if (bn == NULL) {
		st->op->destroy(st);
		return NULL;
	}

	st->op->push(st, bn);
	while (!st->op->is_empty(st)) {
		bst_node_t* n = (bst_node_t*)st->op->pop(st);

		if (n->right != NULL)
			st->op->push(st, n->right);
		else {
			st->op->destroy(st);
			return n;
		}
	}	
}
 
static void remove_node_recursive(bst_t* b, int num)
{
	stack_t* st = create_stack();	

	if (b->root == NULL) {
		st->op->destroy(st);
		return;
	}

	st->op->push(st, b->root);
	while (!st->op->is_empty(st)) {
		bst_node_t* n = (bst_node_t*)st->op->pop(st);

		if (n->num > num)
			st->op->push(st, n->left);
		else if (n->num < num)
			st->op->push(st, n->right);
		else {
			if (n->left != NULL && n->right != NULL) {
				bst_node_t* tn = find_min_bst_node(b, n->right);
				num = n->num = tn->num;          
				st->op->push(st, n->right);
			} else if (n->left == NULL) {
				n = n->right;
				b->size--;
			} else if (n->right == NULL) {
				n = n->left;
				b->size--;	
			}			
		} 
	}
	st->op->destroy(st);
}

static void remove_node_nonrecurrent(bst_t* b, int num)
{
	stack_t* st = create_stack();	

	if (b->root == NULL) {
		st->op->destroy(st);
		return;
	}

	st->op->push(st, b->root);
	while (!st->op->is_empty(st)) {
		bst_node_t* n = (bst_node_t*)st->op->pop(st);

		if (n->num > num)
			st->op->push(st, n->left);
		else if (n->num < num)
			st->op->push(st, n->right);
		else {
			if (n->left != NULL && n->right != NULL) {
				bst_node_t* tn = find_min_bst_node(b, n->right);
				num = n->num = tn->num;          
				st->op->push(st, n->right);
			} else if (n->left == NULL) {
				n = n->right;
				b->size--;
			} else if (n->right == NULL) {
				n = n->left;
				b->size--;	
			}			
		} 
	}
	st->op->destroy(st);
}
 

static void print_inorder_nonrecurrent(bst_t* b)
{	
	node_t* n;
	int* i;
	list_t* l = create_list();

	if (b->root == NULL) {
		l->op->destroy(l);
		return;
	}

	l->op->insert_to_head(l, b->root);
	while (1) {
		if (b->op->get_size(b) == l->op->get_size(l)) {
			break;
		}

		n = l->op->get_head_node(l);
		
		while (n->next != NULL) {
			if (! ((bst_node_t*) n->data)->checked ) {
				if (n->prev != NULL)
					l->op->insert_to_before_node(l, n, ((bst_node_t*) n->data)->left);
				if (n->next != NULL)
					l->op->insert_to_before_node(l, n->next, ((bst_node_t*) n->data)->right);
			}
			((bst_node_t*) n->data)->checked = 1;
			n = n->next;
		}		
	}
	
	while (l->op->get_size(l) != 0) {
		n = l->op->get_head_node(l);
		((bst_node_t*) n->data)->checked = 0;
		printf("%d ", ((bst_node_t*) n->data)->num);
	}

	l->op->destroy(l);
	printf("\n");
}

static void print_inorder_recursive_sub(bst_node_t* n)
{
	if(n == NULL)
		return;

	print_inorder_recursive_sub(n->left);
	printf("%d ", n->num);
	print_inorder_recursive_sub(n->right);
}

static void print_inorder_recursive(bst_t* b)
{	
	if (b->root == NULL)
		return;
	
	print_inorder_recursive_sub(b->root);
	printf("\n");
}
	

static void print_preorder_nonrecurrent(bst_t* b)
{	
	node_t* n;
	int* i;
	list_t* l = create_list();

	if (b->root == NULL) {
		l->op->destroy(l);
		return;
	}

	l->op->insert_to_head(l, b->root);
	while (1) {
		if (b->op->get_size(b) == l->op->get_size(l)) {
			break;
		}

		n = l->op->get_head_node(l);
		
		while (n->next != NULL) {
			if (! ((bst_node_t*) n->data)->checked ) {
				if (n->prev != NULL)
					l->op->insert_to_before_node(l, n->next, ((bst_node_t*) n->data)->left);
				if (n->next != NULL)
					l->op->insert_to_before_node(l, n->next, ((bst_node_t*) n->data)->right);
			}
			((bst_node_t*) n->data)->checked = 1;
			n = n->next;
		}		
	}
	
	while (l->op->get_size(l) != 0) {
		n = l->op->get_head_node(l);
		((bst_node_t*) n->data)->checked = 0;
		printf("%d ", ((bst_node_t*) n->data)->num);
	}

	l->op->destroy(l);
	printf("\n");
}

static void print_preorder_recursive_sub(bst_node_t* n)
{
	if(n == NULL)
		return;

	printf("%d ", n->num);
	print_preorder_recursive_sub(n->left);	
	print_preorder_recursive_sub(n->right);
}

static void print_preorder_recursive(bst_t* b)
{	
	if (b->root == NULL)
		return;
	
	print_preorder_recursive_sub(b->root);
	printf("\n");
}

static void print_postorder_nonrecurrent(bst_t* b)
{
	node_t* n;
	int* i;
	list_t* l = create_list();

	if (b->root == NULL) {
		l->op->destroy(l);
		return;
	}

	l->op->insert_to_head(l, b->root);
	while (1) {
		if (b->op->get_size(b) == l->op->get_size(l)) {
			break;
		}

		n = l->op->get_head_node(l);
		
		while (n->next != NULL) {
			if (! ((bst_node_t*) n->data)->checked ) {
				if (n->prev != NULL)
					l->op->insert_to_before_node(l, n, ((bst_node_t*) n->data)->left);
				if (n->next != NULL)
					l->op->insert_to_before_node(l, n, ((bst_node_t*) n->data)->right);
			}
			((bst_node_t*) n->data)->checked = 1;
			n = n->next;
		}		
	}
	
	while (l->op->get_size(l) != 0) {
		n = l->op->get_head_node(l);
		((bst_node_t*) n->data)->checked = 0;
		printf("%d ", ((bst_node_t*) n->data)->num);
	}

	l->op->destroy(l);
	printf("\n");
}

static void print_postorder_recursive_sub(bst_node_t* n)
{
	if(n == NULL)
		return;

	print_postorder_recursive_sub(n->left);	
	print_postorder_recursive_sub(n->right);
	printf("%d ", n->num);
}

static void print_postorder_recursive(bst_t* b)
{	
	if (b->root == NULL)
		return;
	
	print_postorder_recursive_sub(b->root);
	printf("\n");
}



static void print_bfs(bst_t* b)
{
	bst_node_t* n;
	int* i;
	queue_t* q = create_queue();

	if (b->root == NULL)
		return;

	q->op->enqueue(q, b->root);
	while (q->op->get_size(q) != 0) {	
		n = (bst_node_t*)q->op->dequeue(q);
		
		printf("%d ", n->num);
		
		if (n->left != NULL) {
			q->op->enqueue(q, n->left);
		}		

		if (n->right != NULL) {
			q->op->enqueue(q, n->right);
		}
	}
	
	
	printf("\n");
}

static void print_dfs(bst_t* b)
{
	bst_node_t* n;
	int* i;
	stack_t* s = create_stack();

	if (b->root == NULL)
		return;	

	s->op->push(s, b->root);
	while (s->op->get_size(s) != 0) {	
		n = (bst_node_t*)s->op->pop(s);
		
		printf("%d ", n->num);
		
		if (n->left != NULL) {
			s->op->push(s, n->left);
		}	
		
		if (n->right != NULL) {
			s->op->push(s, n->right);
		}
			

	}
	printf("\n");
}


static int get_size(bst_t* b)
{
	return b->size;
}

