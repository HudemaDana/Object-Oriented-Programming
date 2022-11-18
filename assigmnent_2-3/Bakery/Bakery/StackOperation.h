#pragma once
#include "DynamicArray.h"
#include "Operation.h"


typedef struct
{
	DynamicArray* operations;
}StackOperation;

StackOperation* createStackOperation();
void destroyStackOperation(StackOperation* stackOperation);
void push(StackOperation* stackOperation, Operation* operation);
Operation* pop(StackOperation* stackOperation);
