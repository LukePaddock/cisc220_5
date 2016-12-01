/* udll.h
   Luke Paddock (10157251)
   2016-11-29 */
#ifndef UDLL_H
#define CALC_H

union Data {
	int a;
	int *b;
	float c;
	float *d;
	char e;
	char *f;
};

typedef struct Node {

	struct Node *prev;
	struct Node *next;
	union Data value;

} Node;

void list_insert(int index, union Data data);
void list_remove(int index);
union Data list_get(int index);
int list_length();
int list_currentIndex();

#endif	
