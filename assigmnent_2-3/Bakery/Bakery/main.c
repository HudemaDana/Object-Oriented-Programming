#define _CRTDBG_MAP_ALLOC

#include <stdio.h>
#include <crtdbg.h>
#include "Material.h"
#include "MaterialRepo.h"
#include "MaterialService.h"
#include "StackOperation.h"
#include "UI.h"
#include "Tests.h"



int main()
{
	testNonUi();

	{Repo* r = createRepo();
	StackOperation* u = createStackOperation();
	StackOperation* re = createStackOperation();
	Service* s = createService(r, u, re);
	controller(s);
	destroyService(s);
	}
	
	//sa vad daca e implementat bine copyMaterial....
	_CrtDumpMemoryLeaks();
	return 0;
}
