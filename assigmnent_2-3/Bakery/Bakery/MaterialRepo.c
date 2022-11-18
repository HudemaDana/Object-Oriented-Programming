#include "MaterialRepo.h"
#include "Material.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>


Repo* createRepo()
{
	Repo* r = (Repo*)malloc(sizeof(Repo));
	r->elems = createDynamicArray(100, &destroyMaterial);

	return r;
}

void destroyRepo(Repo* r)
{
	if (r == NULL)
		return;
	if (r->elems != NULL)
		destroyDynamicArray(r->elems);
	free(r);
	r = NULL;
}

Repo* copyRepo(Repo* r)
{
	Repo* copy = createRepo();
	for (int i = 0; i < getSize(r->elems); i++)
	{
		Material* mat = get(r->elems, i);
		addToRepo(copy, createMaterial(getName(mat), getSupplier(mat), getExpiration_Date(mat), getQuantity(mat)));
	}
	return copy;
}



int addToRepo(Repo* r, Material* m)
{
	if (r == NULL || m == NULL)
		return 0;

	for (int i = 0; i < getSize(r->elems); i++)
	{
		Material* mat = get(r->elems, i);
		if (strcmp(getName(mat), getName(m)) == 0 && strcmp(getSupplier(mat), getSupplier(m)) == 0 && strcmp(getExpiration_Date(mat), getExpiration_Date(m)) == 0)
		{
			mat->quantity += m->quantity;
			return 1;
		}
	}
	
	add(r->elems, m);
	return 1;
}

int removeFromRepo(Repo* r, Material* m)
{
	if (r == NULL || m == NULL)
		return 0;

	for (int i = 0; i <getSize(r->elems); i++)
	{
		Material* mat = get(r->elems, i);
		if (strcmp(getName(mat), getName(m)) == 0 && strcmp(getSupplier(mat), getSupplier(m)) == 0 && strcmp(getExpiration_Date(mat), getExpiration_Date(m)) == 0)
		{
			delete_d(r->elems, i);
			return 1;
		}
	}
	return 2;
}

Repo* updateMaterialFromRepo(Repo* r, Material* m_old, Material* m_new)
{
	if (r == NULL || m_old == NULL || m_new ==NULL)
		return NULL;
	for (int i = 0; i < getSize(r->elems); i++)
	{
		Material* mat = get(r->elems, i);
		if (strcmp(getName(mat), getName(m_old)) == 0 && strcmp(getSupplier(mat), getSupplier(m_old)) == 0 && strcmp(getExpiration_Date(mat), getExpiration_Date(m_old)) == 0)
		{
			if (strcmp(getName(m_new), "None") != 0)
				setName(mat, getName(m_new));
			if (strcmp(getSupplier(m_new), "None") != 0)
				setSupplier(mat, getSupplier(m_new));
			if (strcmp(getExpiration_Date(m_new), "None") != 0)
				setExpiration_Date(mat, getExpiration_Date(m_new));
			if (getQuantity(m_new) != -1)
				setQuantity(mat, getQuantity(m_new));
			break;
		}
	}
	return r;
}


