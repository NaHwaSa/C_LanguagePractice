/**
* binary search tree Header
* made by nahwasa
*/

#ifndef BST_H_NAHWASA
#define BST_H_NAHWASA

#include"list.h"
#include"stack.h"
#include"queue.h"

typedef struct bst_node {
	struct bst_node* left;
	struct bst_node* right;
	int num;
	int checked;
} bst_node_t;

typedef struct {
	bst_node_t* root;
	int size;
	struct bst_operations* op;
} bst_t;

struct bst_operations {
	void (*destroy)(bst_t* b);
	bst_node_t* (*search_node)(bst_t* b, int find_num);
	void (*insert_node)(bst_t* b, int num);
	void (*remove_node)(bst_t* b, int num);
	void (*print_inorder)(bst_t* b);
	void (*print_preorder)(bst_t* b);
	void (*print_postorder)(bst_t* b);
	void (*print_bfs)(bst_t* b);
	void (*print_dfs)(bst_t* b);
	int (*get_size)(bst_t* b);
};

extern bst_t* create_recursive_bst();
extern bst_t* create_nonrecurrent_bst();

#endif
