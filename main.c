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

	for (char x = 'a'; x < 'g'; x++) {
		union Data i;
		i.e = x;
		list_insert(-1, i);
	}

	print_data();
	union Data pizza;
	pizza.e = 'x';
	list_insert(2, pizza);
	list_insert(0, pizza);
	list_insert(-1, pizza);
	printf("inserting 'x' at index 2, 0, then the end of the list\n");
	print_data();
	
	
	list_remove(0);
	list_remove(3);
	printf("removing nodes at index 0, then 3\n");
	print_data();

}

void print_data() { /* prints the linked list */
	printf("----------------\nList: ");
	int peter = list_length();
	union Data number;
	for ( int y = 0; y < peter; y++ ) {
		number = list_get(y);
		printf("%c ", number.e);
	}
	printf("\n");
	printf("---------------\n");
	
	printf("Size: %d\n", list_length());
}

