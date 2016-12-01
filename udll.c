/* udll.c
   Luke Paddock (10157251)
   2016-11-29 */

#include<stdlib.h>
#include<stdio.h>
#include"udll.h"

/* This program contains functions for controlling one linked list.
   A linked list contains of multiple Nodes ( struct Node defined in udll.h )
   Each Node contains a pointer to the previous node, a pointer to the next node,
   and a value ( union Data defined in udll.h )
*/

Node *cn; /* Current Node */
int size; /* Current Size */
int crnt; /* current position (index of cn) */

/* Create and insert a node with Data data at index index  
   use negative index to put node at the end of the list */
void list_insert(int index, union Data data)
{
	if (size == 0) { /* No nodes */
		/* We need to create the first node! */
		cn = malloc(sizeof(struct Node));
		cn->prev = NULL;
		cn->next = NULL;
		cn->value = data;
		size = 1; /* size is exactly equal to 1 because first ndoe */
		crnt = 0; /* current index is exactly equal to 0 because there is only one node */
	}
	else if (index < 0 || index >= (size-1)) { /* Index is negative or greater than last index */
		/* Just add the new node to the end */
		while (cn->next != NULL) { /* set cn to the last node */
			cn = cn->next;
			crnt++; /* current index counter keeps up with moving through the array */
		}
		/* Create new node */
		Node *x = malloc(sizeof(struct Node));
		x->prev = cn;
		x->next = NULL; /* (because this is the last node) */
		x->value = data;
		cn->next =  x;
		size++;
	}
	else if ( index == 0 ) { 
		/* Put node at the beginning of the list */
		while ( cn->prev != NULL ) { /* move to first node */
			cn = cn->prev;
			crnt--; /* current index counter keeps up with moving through array */
		}

		/* create new node */
		Node *x = malloc(sizeof(struct Node));
		x->prev = NULL;
		x->next = cn;
		x->value = data;
		cn->prev = x;
		size++; /* because the array is bigger now */
		crnt++; /* we added element before cn so we update index counter */
	}
	else { /* Put the node in the middle somewhere (at index) */
		if ( crnt > index ) { /* if cn is currently past the desired index */
			while ( crnt > index ) {
				cn = cn->prev;
				crnt--;
			}
		}
		else if ( crnt < index ) { /* if cn is currently before the desired index */
			while ( crnt < index ) { 
				cn = cn->next;
				crnt++;
			}
		}
		
		/* create new node directly before cn */
		Node *x = malloc(sizeof(struct Node));
		x->next = cn;
		x->prev = cn->prev;
		x->value = data;
		cn->prev->next = x;
		cn->prev = x;
		crnt++; /* we added element before cn so we update index counter */
		size++; /* array is exactly 1 element larger now */
	}
		
}

/* Remove element at index index */
void list_remove(int index) 
{
	if ( size == 1 ) { /* deleting the only node */
		free(cn);
		cn = NULL;
		size = 0;
		crnt = 0;
	}
	else if ( index == 0 ) { /* first node */
		while ( cn->prev != NULL ) { /* move to node 0 */
			cn = cn->prev;
			crnt--;
		}
		cn->next->prev = NULL;
		Node *x = cn;
		cn = cn->next;
		free(x); /* free space in memory */
		size--; /* list is one elemnt smaller now */
		/* crnt just stays at 0 */
	}
	else if ( index == (size-1) ) { /* last node */
		while ( cn->next != NULL ) { /* move to last node */
			cn = cn->next;
			crnt++;	
		}
		cn->prev->next = NULL;
		Node *x = cn; /* assign node to be removed to temp var so we can free(x) */
		cn = cn->prev;
		free(x); /* free deleted node from memory */
		size--; /* list is smaller by 1 */
		crnt--; /* (because we are deleting the last node) */ 
	}
	else { /* some node in between 0 and last */
		/* move cn to desired index */
		if ( crnt > index ) {
			while ( crnt > index ) {
				cn = cn->prev;
				crnt--;
			}
		}
		else if ( crnt < index ) {
			while ( crnt < index ) {
				cn = cn->next;
				crnt++;
			}
		}
	
		cn->prev->next = cn->next;
		cn->next->prev = cn->prev;
	
		Node *x = cn; /* assign cn to temp var to free(x) later */
		cn = cn->next; /* cn is now the node after deleted node */
		free(x);
		size--;
		/* crnt = crnt ( crnt doesn't have to change ) */
	}
}

union Data list_get(int index)
{
	if (index >= (size - 1)) { /* use the last node  */
		index = ( size - 1 );
	}
	if (crnt > index) { 
		cn = cn->prev;
		crnt = crnt - 1;
		return list_get(index); 
	}
	else if (crnt < index) { 
		cn = cn->next;
		crnt = crnt + 1;
		return list_get(index);
	}
	else { /* crnt == index */ 
		return cn->value;
	}
	return cn->value; /* put this in to stop gcc warning */
}

int list_length() { return size; } /* return size of the array (how many nodes)  */
int list_currentIndex() { return crnt; } /* return currentIndex (mostly for debugging) */
