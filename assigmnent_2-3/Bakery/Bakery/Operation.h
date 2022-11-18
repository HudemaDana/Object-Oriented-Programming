#pragma once
#include "Material.h"

typedef struct
{
	Material* m;
	char* operationName;
}Operation;

Operation* createOperation(Material* m, char* operationName);
void destroyOperation(Operation* o);

Operation* copyOperation(Operation* o);

Material* getOperationMaterial(Operation* o);
char* getOperationName(Operation* o);