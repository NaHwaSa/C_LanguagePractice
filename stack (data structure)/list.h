/**
* Basic Linked List Header
* This list using node(node.h)
* made by nahwasa
*/

#ifndef BASIC_LIST_H_NAHWASA
#define BASIC_LIST_H_NAHWASA

#include"node.h"

typedef struct list_head {
   node_t* head;   // first Node
   node_t* tail;   // last Node
   int size;   // number of Nodes
   struct list_operations* op;   // list operations
} list_t;

struct list_operations {
   int (*get_size)(list_t* l);
   int (*is_empty)(list_t* l);
   void (*insert_to_head)(list_t* l, void* data); 
   void (*insert_to_tail)(list_t* l, void* data); 
   void (*delete_head_node)(list_t* l); 
   void (*delete_tail_node)(list_t* l); 
   node_t* (*get_head_node)(list_t* l); 
   node_t* (*get_tail_node)(list_t* l);
   void (*print)(list_t* l);
   void (*destroy)(list_t* l);
   void (*insert_to_before_node)(list_t* l, node_t* pos, void* data);
};

extern list_t* create_list();

#endif
