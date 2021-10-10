## U can test it like this :

~~~
#include<stdio.h>
#include"binary_search_tree.h"

int main(int argc, char* argv[])
{
	bst_t* b = create_nonrecurrent_bst();
	printf("--- nonrecurrent ---\n");	

	b->op->insert_node(b, 5);
	b->op->insert_node(b, 3);
	b->op->insert_node(b, 8);
	b->op->insert_node(b, 1);
	b->op->insert_node(b, 10);

	b->op->print_inorder(b);
	b->op->print_preorder(b);
	b->op->print_postorder(b);
	b->op->print_bfs(b);
	b->op->print_dfs(b);

	b = create_nonrecurrent_bst();
	printf("--- recursive ---\n");	

	b->op->insert_node(b, 5);
	b->op->insert_node(b, 3);
	b->op->insert_node(b, 8);
	b->op->insert_node(b, 1);
	b->op->insert_node(b, 10);

	b->op->print_inorder(b);
	b->op->print_preorder(b);
	b->op->print_postorder(b);
	b->op->print_bfs(b);
	b->op->print_dfs(b);
}
~~~
