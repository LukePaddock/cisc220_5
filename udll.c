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

void insert(int index, union Data data)
{
	if (size == 0) {
		//we need to create the first node!
		cn.prev = NULL;
		cn.next = NULL;
		cn.value = data;
		size = 1;
	}
	else if (index < 0 || index >= size) { /* just add the node to the end */
		while (cn.next != NULL) { 
			cn = *cn.next;
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
	/* Implement 'get'  function */
	union Data x;
	x.a = 3;
	return x;
}
