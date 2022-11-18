#pragma once

#include "DynamicArray.h"
#include "Material.h"



typedef struct
{
	DynamicArray* elems;
}Repo;

/// <summary>
/// It creates an Repo with a given capacity, in which, for the beginnig we can store the a given number of elements
/// </summary>
/// <param name="capacity"> an integer in which is stored the max amount of elements that can be stored in repository
/// <returns> It returns a repository of type Repo, in which are stored all the needed data about the repo
Repo* createRepo(); 

/// <summary>
/// Clean up the space remaining on the heap when we want to erase a repo
/// </summary>
/// <param name="r"> a pointer of type Repo
void destroyRepo(Repo* r);

/// <summary>
/// Creates a copy of the repo
/// </summary>
/// <param name="r">the original repo
/// <returns>the copy of the repo
Repo* copyRepo(Repo* r);

/// <summary>
/// It adds a new material in the repo or just adds the new quantity over the old one, if the material already exists
/// </summary>
/// <param name="r">pointer of type Repo, in which we have the repository
/// <param name="m"> a pointer of type Material, in which we have the material we want to add 
int addToRepo(Repo* r, Material* m);

/// <summary>
/// It removes the given material from the repository, if it exists
/// </summary>
/// <param name="r">pointer of type Repo, in which we have the repository
/// <param name="m"> a pointer of type Material, in which we have the material we want to remove
int removeFromRepo(Repo* r, Material* m);

/// <summary>
/// Because a material is unique identified by its name, supplier and expiration date, the only thing that can be updated is the quantity
/// </summary>
/// <param name="r">pointer of type Repo, in which we have the repository
/// <param name="m"> a pointer of type Material, in which we have the material we want to update
/// <returns> It returns the repository updated
Repo* updateMaterialFromRepo(Repo* r, Material* m_old,Material* m_new);




