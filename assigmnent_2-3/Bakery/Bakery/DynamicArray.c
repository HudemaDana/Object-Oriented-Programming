#include "DynamicArray.h"
#include <stdlib.h>

DynamicArray* createDynamicArray(int capacity, DestroyElemFunctionType destroy)
{
	DynamicArray* d = (DynamicArray*)malloc(sizeof(DynamicArray));
	if (d == NULL)
		return NULL;

	d->size = 0;
	d->capacity = capacity;
	d->data = (TElem*)malloc(d->capacity * sizeof(TElem));

	if (d->data == NULL)
	{
		free(d);
		return NULL;
	}

	d->destroyElemFct = destroy;

	return d;
}

void destroyDynamicArray(DynamicArray* d)
{	if (d == NULL)
		return;
	
	if (d->data == NULL)
	{
		free(d);
		return;
	}

	for (int i = 0; i < d->size; i++)
	{
		if (d->data[i] != NULL)
			d->destroyElemFct(d->data[i]);
	}

	free(d->data);
	d->data = NULL;

	free(d);
	d = NULL;
}

void resize(DynamicArray* d)
{
	if (d == NULL)
		return;
	d->capacity += 100;

	TElem* new_data = (TElem*)malloc(sizeof(TElem) * d->capacity);
	if (new_data == NULL)
		return;

	for (int i = 0; i < d->size; i++)
		new_data[i] = d->data[i];
	free(d->data);
	d->data = new_data;
}

void add(DynamicArray* d, TElem m)
{
	if (d == NULL)
		return;
	if (d->data == NULL)
		return;
	if (d->size == d->capacity)
		resize(d);
	d->data[d->size++] = m;
}

void delete_d(DynamicArray* d, int pos)
{
	if (d == NULL)
		return;
	if (d->data == NULL)
		return;
	if (pos < 0 || pos >= d->size)
		return;

	d->destroyElemFct(d->data[pos]);
	for (int i = pos; i < d->size - 1; i++)
		d->data[i] = d->data[i + 1];

	d->size--;
}

int getSize(DynamicArray* d)
{
	if (d == NULL)
		return -1;
	return d->size;
}

TElem get(DynamicArray* d, int pos)
{
	return d->data[pos];
}
