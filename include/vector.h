#pragma once
#include <stdlib.h>
#include <string.h>

#define VECTOR_INIT_CAPACITY 4

typedef struct {
	void *data;
	unsigned int size;
	unsigned int capacity;
	size_t elem_size;
}Vector;

Vector *Vector_init(size_t elem_size);
void Vector_pushback(Vector *vector, void *element);
void *Vector_getValue(Vector *vector, int index);
void Vector_newsize(Vector *vector, int newReserve);
void Vector_destroy(Vector *vector);

