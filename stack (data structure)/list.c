/**
* Basic Linked List
* made by nahwasa
*/

#include<stdio.h>
#include<stdlib.h>
#include"list.h"

list_t* create_list();
static void destroy(list_t* l);
static int get_size(list_t* l);
static int is_empty(list_t* l);
static void insert_to_head(list_t* l, void* data); 
static void insert_to_tail(list_t* l, void* data); 
static void delete_head_node(list_t* l); 
static void delete_tail_node(list_t* l); 
static void print(list_t* l);
static node_t* get_head_node(list_t* l); 
static node_t* get_tail_node(list_t* l);
static void insert_to_before_node(list_t* l, node_t* pos, void* data);

/*
* Operations can be override
* Someone who want change operations, make own create_list function and change '&op' to another
*/
static struct list_operations op =
   {
      .get_size = get_size,
      .is_empty = is_empty,
      .insert_to_head = insert_to_head,
      .insert_to_tail = insert_to_tail,
      .delete_head_node = delete_head_node,
      .delete_tail_node = delete_tail_node,
      .print = print,
      .get_head_node = get_head_node,
      .get_tail_node = get_tail_node,
      .destroy = destroy,
      .insert_to_before_node = insert_to_before_node
   };


/*
* create list object and return
*/
list_t* create_list()
{   
   list_t* l = (list_t*)malloc(sizeof(list_t));
   
   l->op = &op;
   l->head = l->tail = NULL;
   l->size = 0;

   return l;
}

/*
* c language don't provide the way to release memory
* so programmer must provide destroy function
*/
static void destroy(list_t* l)
{
   node_t* p;
   node_t* t;

   if ( l->op->get_size(l) > 0 ) {
      p = l->op->get_head_node(l);
      while (p != NULL) {         
         t = p->next;
         p->next = p->prev = p->data = NULL;            
         free(p);
         p = t;
      }
      l->head = NULL;
      l->tail = NULL;
      l->size = 0;
      free(l);
      l = NULL;
   }
}

/*
* return the number of Nodes
*/
static int get_size(list_t* l) 
{   
   return l->size;
}

/*
* if list has no node, return true(1)
*/
static int is_empty(list_t* l)
{
   return !l->op->get_size(l);
}

/*
* insert Node to first of list
*/
static void insert_to_head(list_t* l, void* data) 
{   
   node_t* nd = (node_t*)malloc(sizeof(node_t)); 
   
   if ( l->op->is_empty(l) ) {   // when there's no node
      nd->prev = nd->next = NULL;
      nd->data = data;
      l->head = l->tail = nd;
   } else {
      nd->prev = NULL;
      nd->next = l->head;
      nd->data = data;
      l->head->prev = nd;
      l->head = nd;
   }

   l->size++;
}

/*
* insert Node to last of list
*/
static void insert_to_tail(list_t* l, void* data) 
{
   node_t* nd = (node_t*)malloc(sizeof(node_t));

   if ( l->op->is_empty(l) ) {
      nd->prev = nd->next = NULL;
      nd->data = data;
      l->head = l->tail = nd;
   } else {
      nd->next = NULL;
      nd->prev = l->tail;
      nd->data = data;
      (l->tail)->next = nd;
      l->tail = nd;
   }

   l->size++;
}

/*
* insert new Node before 'pos' Node
*/
static void insert_to_before_node(list_t* l, node_t* pos, void* data)
{
   node_t* nd = (node_t*)malloc(sizeof(node_t));

   if ( l->head == pos ) {
      l->op->insert_to_head(l, data);
      return;
   }

   if ( l->op->is_empty(l) ) {
      nd->prev = nd->next = NULL;
      nd->data = data;
      l->head = l->tail = nd;
   } else {
      nd->data = data;
      pos->prev->next = nd;
      nd->next = pos;
      nd->prev = pos->prev;
      pos->prev = nd;         
   }

   l->size++;
}

/*
* delete first Node
*/
static void delete_head_node(list_t* l) 
{
   if ( l->op->get_size(l) <= 1 ) {   // when there's No Node or only one Node
      l->head = l->tail = NULL;
      l->size = 0;
   } else {
      l->head = l->head->next;
      l->head->prev = NULL;
      l->size--;
   }
}

/*
* delete last Node
*/
static void delete_tail_node(list_t* l) 
{
   if (l->op->get_size(l) <= 1) {
      l->head = l->tail = NULL;
      l->size = 0;
   } else {
      l->tail = l->tail->prev;
      l->tail->next = NULL;
      l->size--;
   }
}

/*
* print the Nodes
*/
static void print(list_t* l)
{
   node_t* p = l->op->get_head_node(l);

   while (p != NULL) {
      printf("%s\n", (char*)p->data);
      p = p->next;      
   }
}


static node_t* get_head_node(list_t* l) 
{
   return l->head;
}

static node_t* get_tail_node(list_t* l) 
{
   return l->tail;
}
