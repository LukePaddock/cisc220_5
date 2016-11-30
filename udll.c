/* udll.c
   Luke Paddock (10157251)
   2016-11-29 */

#include<stdio.h>
#include"udll.h"

/* (from udll.h)

typedef struct { int *prev; int *next; union Data value; } Node;

*/

Node cn; /* First Node */
int size;
int crnt; /* current position (index of cn) */

void insert(int index, union Data data)
{
	if (size == 0) {
		/* We need to create the first node! */
		cn.prev = NULL;
		cn.next = NULL;
		cn.value = data;
		size = 1;
		crnt = 0;
	}
	else if (index < 0 || index >= size) { /* just add the node to the end */
		while (cn.next != NULL) { 
			cn = *cn.next;
			crnt++;
		}
		Node x = { &cn, NULL, data };
		cn.next = &x;
		size++;
	}
}

void lremove(int index) 
{
	/* Implement remove function */
}

union Data get(int index)
{
	if (index >= size) { /* use the last node  */
		index = ( size - 1 );
	}
	if (crnt > index) { 
		cn = *cn.prev;
		crnt = crnt - 1;
		return get(index); 
	}
	else if (crnt < index) { 
		cn = *cn.next;
		crnt = crnt + 1;
		return get(index);
	}
	else { /* crnt == index */ 
		return cn.value;
	}
	return cn.value; /* put this in to stop gcc warning */
}

int debug_size() { return size; }
int debug_crnt() { return crnt; }
