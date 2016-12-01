/* main.c
   Luke Paddock (10157251)
   2016-11-29 */

#include<stdio.h>
#include"udll.h"

/* ( Union Data from udll.h )
	int a;
	int *b;
	float c;
	float *d;
	char e;
	char *f;
*/

void print_data();

int main(void) {
	for (int x = 0; x < 6; x++) {
		union Data i;
		i.a = x;
		list_insert(-1, i);
	}

	print_data();
	printf("\nCreated list of 10 integers 0-9\n");
	union Data pizza;
	pizza.a = 13;
	list_insert(0, pizza);
	pizza.a = 40;
	list_insert(5, pizza);
	pizza.a = 1234;
	list_insert(2, pizza);
	pizza.a = 100000;
	list_insert(2, pizza);
	printf("added 13 to index 0\nadded 40 at index 5\nadded 1234 at index 2\nadded 100000 at index 2\n");
	print_data();
	
	
	list_remove(0);
	list_remove(3);
	list_remove(3);
	print_data();

}

void print_data() { /* prints the linked list */
	printf("\n----------------\n");
	int peter = list_length();
	union Data number;
	for ( int y = 0; y < peter; y++ ) {
		number = list_get(y);
		printf("%d\n", number.a);
	}
	printf("---------------\n");
	
	printf(" \nSize: %d\nCrnt: %d\n", list_length(), list_currentIndex());
}

