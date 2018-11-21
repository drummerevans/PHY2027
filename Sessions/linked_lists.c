/*
 *
 * Not so simple example of a linked list
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct elements
{
  int data;
  struct elements *next; // pointer to next structure in the list
}Elem;

Elem *set_node(Elem *node);

int main(){

   /* Initialize nodes */
   Elem *head;
   Elem *node = NULL;

   int nlist;
   printf("How many elements do you want in your list?\n");
   scanf("%d",&nlist);
   printf("\n\n");

   /* Allocate nodes */
   for (int i=0; i < nlist ; ++i){
      node = set_node(node);

      if (node == NULL){
        printf("Node was not correctly allocated\n");
	return -1;
      }

      node->data=i;  //Allocate the data inside each node
   }

   /* Set head of list */
   head = node;

   /* Traverse the list */
   for (Elem *p=head ; p != NULL ; p = p->next){
       printf("%d\n",p->data);
   }

   return 0;
}

Elem *set_node(Elem *node){
   Elem *p;

   /* Allocate the node */
   p = (Elem *) malloc(sizeof(Elem));

   /* Point to the next element of the list */
   p->next = node;

   return p;
}

