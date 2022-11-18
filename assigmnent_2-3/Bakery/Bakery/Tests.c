#include "DynamicArray.h"
#include "Material.h"
#include "MaterialRepo.h"
#include "MaterialService.h"
#include <crtdbg.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "Tests.h"


void testMaterial()
{
	Material* m = createMaterial("smantana", "alpalact", "12/03/2022", 120);
	assert(m != NULL);

	assert(strcmp(getName(m), "smantana") == 0);
	assert(strcmp(getSupplier(m), "alpalact") == 0);
	assert(strcmp(getExpiration_Date(m), "12/03/2022") == 0);
	assert(getQuantity(m) == 120);

	setName(m, "smantana_1");
	setSupplier(m, "alpalact_1");
	setExpiration_Date(m, "12/04/2022");
	setQuantity(m, 121);

	assert(strcmp(getName(m), "smantana_1") == 0);
	assert(strcmp(getSupplier(m), "alpalact_1") == 0);
	assert(strcmp(getExpiration_Date(m), "12/04/2022") == 0);
	assert(getQuantity(m) == 121);

	destroyMaterial(m);
}

void testMaterialRepo()
{
	Repo* r = createRepo(0);
	Material* m = createMaterial("smantana", "alpalact", "12/03/2022", 120);

	addToRepo(r, m);

	assert(strcmp(getName(get(r->elems,0)), "smantana") == 0);
	assert(strcmp(getSupplier(get(r->elems, 0)), "alpalact") == 0);
	assert(strcmp(getExpiration_Date(get(r->elems, 0)), "12/03/2022") == 0);
	assert(getQuantity(get(r->elems, 0)) == 120);

	Material* m1 = createMaterial("smantana_1", "None", "None", 121);
	r = updateMaterialFromRepo(r, m, m1);

	assert(getQuantity(get(r->elems, 0)) == 121);
	assert(strcmp(getName(get(r->elems, 0)), "smantana_1") == 0);

	removeFromRepo(r, m);

	assert(getSize(r->elems) == 0);
	destroyRepo(r);

}

void testMaterialService()
{
	Repo* r = createRepo(100);
	StackOperation* u = createStackOperation();
	StackOperation* re = createStackOperation();
	Service* s = createService(r, u, re);
	
	int value = 1;
	int* ok = &value;

	addMaterial(s, "lapte", "napolact", "12/12/2022", 120,ok);
	assert(*ok == 1);
	removeMaterial(s, "lapte", "napolact", "12/12/2022", 120, ok);
	assert(*ok == 1);
	addMaterial(s, "lapte_a", "napolact_a", "12/11/2022", 120, ok);
	updateMaterial(s, "lapte_a", "napolact_a", "12/11/2022", "lapte_lapte", "None", "None", -1, ok);
	assert(*ok == 1);

	char day[10],month[10],year[10];

	getDate("03/02/2002", day, month, year);
	assert(strcmp(day, "03") == 0);
	assert(strcmp(month, "02") == 0);
	assert(strcmp(year, "2002") == 0);

	//destroyStackOperation(u);
	destroyService(s);
}

void testNonUi()
{
	testMaterial();
	testMaterialRepo();
	testMaterialService();
}
