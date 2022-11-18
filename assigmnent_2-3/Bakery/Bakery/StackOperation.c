#include "StackOperation.h"
#include <stdlib.h>

StackOperation* createStackOperation()
{
	StackOperation* so = (StackOperation*)malloc(sizeof(StackOperation));
	so->operations = createDynamicArray(100, &destroyOperation);
	return so;
}

void destroyStackOperation(StackOperation* stackOperation)
{
	if (stackOperation == NULL)
		return;
	destroyDynamicArray(stackOperation->operations);
	free(stackOperation);
}

void push(StackOperation* stackOperation, Operation* operation)
{
	add(stackOperation->operations, operation);
}

Operation* pop(StackOperation* stackOperation)
{
	DynamicArray* d = stackOperation->operations;
	if (d == NULL)
		return NULL;
	Operation* copy_o = copyOperation(get(d, d->size - 1));
	delete_d(d, d->size - 1);

	return copy_o;
}
