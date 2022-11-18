#include "Material.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>


Material* createMaterial(char* name, char* supplier, char* expiration_date, int quantity)
{
	if (name == NULL || supplier == NULL || expiration_date == NULL)
		return NULL;

	Material* m = (Material*)malloc(sizeof(Material)); //allocate space for the entire entity

	if (m == NULL)
		return NULL;

	m->name = malloc((strlen(name) + 1) * sizeof(char)); //I allocate space for each pointer in which i'm going to save smth
	if (m->name == NULL) //I the space can't be alloc than we return NULL and free up the space allocated until then
	{
		free(m);
		return NULL;
	}

	strcpy(m->name, name);

	m->supplier = malloc((strlen(supplier) + 1) * sizeof(char));
	if (m->supplier == NULL)
	{
		free(m->name);
		free(m);
		return NULL;
	}
	strcpy(m->supplier, supplier);

	m->expiration_date = malloc((strlen(expiration_date) + 1) * sizeof(char));
	if (m->expiration_date == NULL)
	{
		free(m->supplier);
		free(m->name);
		free(m);
		return NULL;
	}
	strcpy(m->expiration_date, expiration_date);

	m->quantity = quantity;

	return m;

}

void destroyMaterial(Material* m)
{
	if (m == NULL)
		return;
	free(m->name);
	free(m->supplier);
	free(m->expiration_date);
	free(m);
}

Material* copyMaterial(Material* m)
{
	if (m == NULL)
		return NULL;

	Material* copy_m = createMaterial(getName(m),getSupplier(m),getExpiration_Date(m),getQuantity(m));

	return copy_m;
}

char* getName(Material* m)
{
	if (m == NULL)
		return NULL;
	return m->name;
}

char* getSupplier(Material* m)
{
	if (m == NULL)
		return NULL;
	return m->supplier;
}

char* getExpiration_Date(Material* m)
{
	if (m == NULL)
		return NULL;
	return m->expiration_date;
}

int getQuantity(Material* m)
{
	if (m == NULL)
		return 0;
	return m->quantity;
}

void setName(Material* m, char* name)
{
	if (m == NULL || name == NULL)
		return;
	free(m->name);
	m->name = malloc((strlen(name) + 1) * sizeof(char));
	strcpy(m->name, name);
}

void setSupplier(Material* m, char* supplier)
{
	if (m == NULL || supplier == NULL)
		return;
	free(m->supplier);
	m->supplier = malloc((strlen(supplier) + 1) * sizeof(char));
	strcpy(m->supplier, supplier);
}

void setExpiration_Date(Material* m, char* expiration_date)
{
	if (m == NULL || expiration_date == NULL)
		return;
	free(m->expiration_date);
	m->expiration_date = malloc((strlen(expiration_date) + 1) * sizeof(char));
	strcpy(m->expiration_date, expiration_date);
}

void setQuantity(Material* m, int quantity)
{
	if (m == NULL)
		return;
	m->quantity = quantity;
}

