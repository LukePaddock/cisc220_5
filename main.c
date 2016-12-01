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
	for (int x = 0; x < 10; x++) {
		union Data i;
		i.a = x;
		insert(-1, i);


	}
	printf("\nCreated list of 10 integers 0-9\n");
	union Data pizza;
	pizza.a = 13;
	insert(0, pizza);
	pizza.a = 40;
	insert(5, pizza);
	pizza.a = 1234;
	insert(2, pizza);
	pizza.a = 100000;
	insert(2, pizza);
	printf("added 13 to index 0\nadded 40 at index 5\nadded 1234 at index 2\nadded 100000 at index 2\n");
	print_data();
	
	
	lremove(0);
	lremove(3);
	lremove(3);
	print_data();

}

void print_data() {
	printf("\n--------------------------\n");
	int peter = length();
	union Data number;
	for ( int y = 0; y < peter; y++ ) {
		number = get(y);
		printf("%d\n", number.a);
	}
	printf("--------------------------\n");
	
	
	printf(" \nSize: %d\nCrnt: %d\n", length(), currentIndex());
}

