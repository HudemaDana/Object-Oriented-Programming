#include "Operation.h"
#include <stdlib.h>
#include <string.h>

Operation* createOperation(Material* m, char* operationName)
{
	if (m == NULL || operationName == NULL)
		return NULL;

	Operation* o = (Operation*)malloc(sizeof(Operation));
	if (o == NULL)
		return NULL;
	
	o->m = copyMaterial(m);
	o->operationName = malloc(sizeof(char) * (strlen(operationName) + 1));
	strcpy(o->operationName, operationName);
	return o;

}

void destroyOperation(Operation* o)
{
	if (o == NULL)
		return;
	destroyMaterial(o->m);
	free(o->operationName);
	free(o);
}

Operation* copyOperation(Operation* o)
{
	if (o == NULL)
		return NULL;
	Operation* copyOperation;
	copyOperation = createOperation(o->m, o->operationName);

	return copyOperation;
}

Material* getOperationMaterial(Operation* o)
{
	if (o == NULL)
		return NULL;
	return o->m;
}

char* getOperationName(Operation* o)
{
	if (o == NULL)
		return NULL;
	return o->operationName;
}
