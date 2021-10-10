## U can test it like this :

~~~
#include<stdio.h>
#include"binary_search_tree.h"

int main(int argc, char* argv[])
{
	printf("--- nonrecurrent ---\n");
	bst_t* b = create_nonrecurrent_bst();
	
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


	printf("--- recursive ---\n");	
	b = create_recursive_bst();
	
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
