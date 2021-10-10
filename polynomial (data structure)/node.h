/**
* Node structure
* made by nahwasa
*/

#ifndef NODE_H_NAHWASA
#define NODE_H_NAHWASA

typedef struct node {
   struct node* prev;   // previous Node
   struct node* next;   // next Node
   void* data;      // node's data. it can be any data type
} node_t;

#endif
