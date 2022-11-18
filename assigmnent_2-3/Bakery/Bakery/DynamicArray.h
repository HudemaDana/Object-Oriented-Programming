#pragma once

typedef void* TElem;
typedef void (*DestroyElemFunctionType)(void*);

typedef struct
{
	int size, capacity;
	TElem* data;
	DestroyElemFunctionType destroyElemFct;
}DynamicArray;

/// <summary>
/// creates a new dynamicArray
/// </summary>
/// <param name="capacity"></param> the max number of elements 
/// <param name="destroy"></param> the destroyer inside it
/// <returns></returns> the new dynamicArray
DynamicArray* createDynamicArray(int capacity, DestroyElemFunctionType destroy);

/// <summary>
/// destroys a dynamicArray
/// </summary>
/// <param name="d"></param> dynamicArray we want to destroy
void destroyDynamicArray(DynamicArray* d);

/// <summary>
/// add in the array a new element of type TElem
/// </summary>
/// <param name="d"></param> the array of element
/// <param name="m"></param> element we want to add
void add(DynamicArray* d, TElem m);

/// <summary>
/// remove from the array a new element of type TElem
/// </summary>
/// <param name="d"></param> the array of element
/// <param name="m"></param> element we want to remove
void delete_d(DynamicArray* d, int pos);

/// <summary>
/// get the currentSize of the array
/// </summary>
/// <param name="d"></param> the dynamicArray we work with
/// <returns></returns> the currentSize of the array
int getSize(DynamicArray* d);

/// <summary>
/// get an element(entity -> exemple: Material) from the array
/// </summary>
/// <param name="d"></param> dynamicArray we work with
/// <param name="pos"></param> the element from which position we want to extract the element
/// <returns></returns> the entity
TElem get(DynamicArray* d, int pos);
