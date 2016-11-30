/* main.c
   Luke Paddock (10157251)
   2016-11-29 */

#include<stdio.h>
#include"udll.h"
int main(void) {
	union Data d;
	d.a = 3;
	insert(3, d);
	insert(-1, d);
}
