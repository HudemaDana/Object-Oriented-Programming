#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "MaterialService.h"
#include "Operation.h"
#include "Valid.h"

Service* createService(Repo* r, StackOperation* UstackOperation,StackOperation* RstackOperation)
{
	Service* s = malloc(sizeof(Service));
	if (s == NULL)
		return NULL;
	s->r = r;
	s->undo_stack = UstackOperation;
	s->redo_stack = RstackOperation;
	return s;
}

void destroyService(Service* s)
{
	if (s == NULL)
		return;
	
	destroyStackOperation(s->undo_stack);
	destroyStackOperation(s->redo_stack);
	destroyRepo(s->r);
	free(s);
}


Service* copyService(Service* s)
{
	Service* copy = createService(copyRepo(s->r),s->undo_stack,s->redo_stack);
	return copy;
}

Repo* getRepo(Service* s)
{
	return s->r;
}

void addMaterial(Service* s, char* name, char* supplier, char* expiration_date, int quantity, int* ok)
{
	Material* m = createMaterial(name, supplier, expiration_date, quantity);
	if (m == NULL || ValidMaterial(name,supplier,expiration_date) == 0) 
	{
		*ok = 0;
		destroyMaterial(m);
		return;
	}
	*ok = addToRepo(s->r, m);
	
	if (*ok == 1)
	{
		Operation* o = createOperation(m, "add");
		push(s->undo_stack, o);
		if (s->redo_stack->operations->size > 0)
		{
			destroyStackOperation(s->redo_stack);
			s->redo_stack = createStackOperation();
		}
	}
}

void removeMaterial(Service* s, char* name, char* supplier, char* expiration_date, int quantity, int* ok)
{
	Material* m = createMaterial(name, supplier, expiration_date, quantity);
	if (m == NULL || ValidMaterial(name, supplier, expiration_date) == 0)
	{
		*ok = 0;
		destroyMaterial(m);
		return;
	}
	*ok = removeFromRepo(s->r, m);

	if (*ok == 1)
	{
		Operation* o = createOperation(m, "remove");
		push(s->undo_stack, o);
		if (s->redo_stack->operations->size >0)
		{
			destroyStackOperation(s->redo_stack);
			s->redo_stack = createStackOperation();
		}
	}

}

void updateMaterial(Service* s, char* name1, char* supplier1, char* expiration_date1, char* name2, char* supplier2, char* expiration_date2, int quantity2, int* ok)
{
	if (ValidMaterial(name1, supplier1, expiration_date1) == 0 || ValidMaterial(name1, supplier1, expiration_date1) == 0)
	{
		*ok = 2;
		return;
	}


	int quantity1 = -1;
	for (int i = 0; i < getSize(getRepo(s)->elems); i++)
	{
		Material* mat = get(getRepo(s)->elems, i);
		if (strcmp(getName(mat), name1) == 0 && strcmp(getSupplier(mat), supplier1) == 0 && strcmp(getExpiration_Date(mat), expiration_date1) == 0)
			quantity1 = getQuantity(mat);
	}
	
	if (quantity1 == -1)
	{
		*ok = 0;
		return;
	}

	Material* m_old = createMaterial(name1, supplier1, expiration_date1, quantity1);
	Material* m_new = createMaterial(name2, supplier2, expiration_date2, quantity2);

	s->r = updateMaterialFromRepo(s->r, m_old, m_new);

	if (s->r == NULL)
	{
		*ok = 2;
		destroyMaterial(m_old);
		destroyMaterial(m_new);
		return;
	}
	*ok = 1;

	//m_new = createMaterial(name2, supplier2, expiration_date2, quantity2);
	if (*ok == 1)
	{
		Operation* o1 = createOperation(m_old, "update1");
		Operation* o2 = createOperation(m_new, "update2");
		push(s->undo_stack, o1);
		push(s->undo_stack, o2);
		if (s->redo_stack->operations->size > 0)
		{
			destroyStackOperation(s->redo_stack);
			s->redo_stack = createStackOperation();
		}
	}

}

void getDate(char* expiration_date, char day[], char month[], char year[])
{
	int nr = 1;
	char* copy = calloc(strlen(expiration_date) + 1, sizeof(char));
	strcpy(copy, expiration_date);
	char* p = strtok(copy, "/");
	while (p)
	{
		if (nr == 1)
			strcpy(day, p);
		else if (nr == 2)
			strcpy(month, p);
		else if (nr == 3)
			strcpy(year, p);
		nr++;
		p = strtok(NULL, "/");
	}
	free(copy);
}

Repo* filterByName(Service* s, char* name)
{
	Repo* res = createRepo();
	if (strcmp(name, "null") == 0)
		return s->r;
	else
	{
		for (int i = 0; i < getSize(getRepo(s)->elems); i++)
		{
			if (strcmp(getName(get(getRepo(s)->elems,i)), name) == 0)
			{
				Material* mat = copyMaterial(s->r->elems->data[i]);
				addToRepo(res, mat);
			}
		}
	}

	return res;
}

Repo* filterByString(Service* s,char day_a[],char month_a[], char year_a[], char str[])
{
	Repo* res = createRepo();
	char day[4], month[4], year[6];
	if (strcmp(str, "null") == 0)
	{
		for (int i = 0; i < getSize(getRepo(s)->elems); i++)
		{
			char* expiration = getExpiration_Date(get(getRepo(s)->elems,i));
			getDate(expiration, day, month, year);
			if (strcmp(year, year_a) == 0)
			{
				if (strcmp(month, month_a) == 0)
				{
					if (strcmp(day, day_a) <= 0)
					{
						Material* mat = copyMaterial(s->r->elems->data[i]);
						addToRepo(res, mat);
					}
				}
				else if (strcmp(month, month_a) < 0)
				{
					Material* mat = copyMaterial(s->r->elems->data[i]);
					addToRepo(res, mat);
				}
			}
			else if (strcmp(year, year_a) < 0)
			{
				Material* mat = copyMaterial(s->r->elems->data[i]);
				addToRepo(res, mat);
			}
		}
	}
	else
	{
		for (int i = 0; i < getSize(getRepo(s)->elems); i++)
		{
			if (strstr(getName(get(getRepo(s)->elems,i)), str) != NULL || strstr(getSupplier(get(getRepo(s)->elems, i)), str) != NULL || strstr(getExpiration_Date(get(getRepo(s)->elems, i)), str) != NULL)
			{
				char* expiration = getExpiration_Date(get(getRepo(s)->elems,i));
				getDate(expiration, day, month, year);
				if (strcmp(year, year_a) == 0)
				{
					if (strcmp(month, month_a) == 0)
					{
						if (strcmp(day, day_a) <= 0)
						{
							Material* mat = copyMaterial(s->r->elems->data[i]);
							addToRepo(res, mat);
						}
					}
					else if (strcmp(month, month_a) < 0)
					{
						Material* mat = copyMaterial(s->r->elems->data[i]);
						addToRepo(res, mat);
					}
				}
				else if (strcmp(year, year_a) < 0)
				{
					Material* mat = copyMaterial(s->r->elems->data[i]);
					addToRepo(res, mat);
				}
			}
		}
	}

	return res;
}


Service* bubbleSortAsc(Service* s)
{
	int found;
	do
	{
		found = 1;
		for (int i = 0; i < getSize(getRepo(s)->elems)-1; i++)
		{
			if (getQuantity(get(getRepo(s)->elems,i)) > getQuantity(get(getRepo(s)->elems, i+1)))
			{
				Material* m = get(getRepo(s)->elems, i);
				getRepo(s)->elems->data[i] = get(getRepo(s)->elems, i + 1);
				getRepo(s)->elems->data[i+1] = m;
				found = 0;
			}

		}
	}while(found == 0);
	return s;
}

Service* bubbleSortDesc(Service* s)
{
	int found;
	do
	{
		found = 1;
		for (int i = 0; i < getSize(getRepo(s)->elems) - 1; i++)
		{
			if (getQuantity(get(getRepo(s)->elems, i)) < getQuantity(get(getRepo(s)->elems, i + 1)))
			{
				Material* m = get(getRepo(s)->elems, i);
				getRepo(s)->elems->data[i] = get(getRepo(s)->elems, i + 1);
				getRepo(s)->elems->data[i + 1] = m;
				found = 0;
			}

		}
	} while (found == 0);
	return s;
}

Service* sortByName(Service* s)
{
	if (s == NULL)
		return NULL;
	Service* copy_s = copyService(s);
	int found;
	do
	{
		found = 1;
		for (int i = 0; i < getSize(getRepo(s)->elems) - 1; i++)
		{
			if (strcmp(getName(get(getRepo(s)->elems, i)), getName(get(getRepo(s)->elems, i + 1))) > 0)
			{
				Material* m = get(getRepo(s)->elems, i);
				getRepo(s)->elems->data[i] = get(getRepo(s)->elems, i + 1);
				getRepo(s)->elems->data[i + 1] = m;
				found = 0;
			}

		}
	} while (found == 0);
	return copy_s;
}

Service* sortByQuantity(Service* s, int nr)
{
	if (s == NULL)
		return NULL;
	Service* copy_s = copyService(s);
	if (nr == 1)
		return bubbleSortAsc(copy_s);
	else
		return bubbleSortDesc(copy_s);
}

void undo(Service* s)
{
	Operation* o = pop(s->undo_stack);
	if (o != NULL)
	{
		if (strcmp(getOperationName(o), "add") == 0)
		{
			Material* mat = copyMaterial(getOperationMaterial(o));
			removeFromRepo(s->r,getOperationMaterial(o));
			push(s->redo_stack, createOperation(mat, "remove"));
		}

		if (strcmp(getOperationName(o), "remove") == 0)
		{
			Material* mat = copyMaterial(o->m);
			addToRepo(s->r, getOperationMaterial(o));
			push(s->redo_stack, createOperation(mat, "add"));
		}

		if (strcmp(getOperationName(o), "update2") == 0)
		{
			Operation* o1 = pop(s->undo_stack);
			Material* mat = copyMaterial(o->m);
			Material* mat1 = copyMaterial(o1->m);
			//sa fac copie la materialul din operatie ca sa pot sa dau destroy la operatie
			updateMaterialFromRepo(s->r, mat, mat1);  
			push(s->redo_stack, createOperation(mat, "update2"));
			push(s->redo_stack, createOperation(mat1, "update1"));

			//destroyOperation(o1);
		}
	}

	//destroyOperation(o);
}

void redo(Service* s)
{
	Operation* o = pop(s->redo_stack);
	if (o != NULL)
	{
		if (strcmp(getOperationName(o), "add") == 0)
		{
			Material* mat = copyMaterial(getOperationMaterial(o));
			removeFromRepo(s->r, getOperationMaterial(o));
			push(s->undo_stack, createOperation(mat, "remove"));
		}

		if (strcmp(getOperationName(o), "remove") == 0)
		{
			Material* mat = copyMaterial(getOperationMaterial(o));
			addToRepo(s->r, getOperationMaterial(o));
			push(s->undo_stack, createOperation(mat, "add"));
		}

		if (strcmp(getOperationName(o), "update1") == 0)
		{
			Operation* o1 = pop(s->redo_stack);
			Material* mat = copyMaterial(getOperationMaterial(o));
			Material* mat1 = copyMaterial(getOperationMaterial(o1));
			updateMaterialFromRepo(s->r, mat, mat1);
			push(s->undo_stack, createOperation(mat, "update1"));
			push(s->undo_stack, createOperation(mat1, "update2"));

			//destroyOperation(o1);
		}
	}

	//destroyOperation(o);
}




