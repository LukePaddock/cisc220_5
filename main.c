/* main.c
   Luke Paddock (10157251)
   2016-11-29 */

#include<stdio.h>
#include"udll.h"
int main(void) {
	for (int x = 0; x < 5; x++) {
		union Data i;
		i.a = x;
		insert(-1, i);


	}
	

	printf(" \nSize: %d\nCrnt: %d\n", debug_size(), debug_crnt());
	union Data number = get(2);
	printf("%d\n", number.a);
	number = get(4);
	printf("%d\n", number.a);
	
	printf(" \nSize: %d\nCrnt: %d\n", debug_size(), debug_crnt());
}

