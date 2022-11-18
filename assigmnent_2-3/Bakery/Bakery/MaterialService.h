#pragma once

#include "StackOperation.h"
#include "MaterialRepo.h"
#include "Material.h"

typedef struct
{
	Repo* r;
	StackOperation* undo_stack;
	StackOperation* redo_stack;
}Service;

/// <summary>
/// It creates a new service
/// </summary>
/// <param name="r"> a pointer of type Repo
/// <returns> The new service created
Service* createService(Repo* r, StackOperation* UstackOperation, StackOperation* RstackOperation);

/// <summary>
/// Free the space of the Service
/// </summary>
/// <param name="s">the service
void destroyService(Service* s);


/// <summary>
/// it makes a copy of the service
/// </summary>
/// <param name="s"></param> the service we want to copy
/// <returns></returns> a copy of the service
Service* copyService(Service* s);

/// <summary>
/// A getter to the repository
/// </summary>
/// <param name="s">the service
/// <returns> The starting address of the repository
Repo* getRepo(Service* s);

/// <summary>
/// /// it will look for the given material and if it's found, it will add to the current quantity the new one. Otherwise it will add the new material to the list.
/// </summary>
/// <param name="s"> the service
/// <param name="name">a name after a material is identified
/// <param name="supplier"> a supplier after a material is identified
/// <param name="expiration_date"> expiration date after a material if identified
/// <param name="ok"> in integer in which we save the a number corresponding to a message that will be shown on the screen
void addMaterial(Service* s, char* name, char* supplier, char* expiration_date, int quantity, int* ok);

/// <summary>
/// /// it will look for the given material and if it's found, it will remove it. Otherwise it will raise an error with the help of OK
/// </summary>
/// <param name="s"> the service
/// <param name="name">a name after a material is identified
/// <param name="supplier"> a supplier after a material is identified
/// <param name="expiration_date"> expiration date after a material if identified
/// <param name="ok"> in integer in which we save the a number corresponding to a message that will be shown on the screen
void removeMaterial(Service* s, char* name, char* supplier, char* expiration_date, int quantity, int* ok);

/// <summary>
/// it will look for the given material and if it's found, it will update it
/// </summary>
/// <param name="s"> the service
/// <param name="name1">a name after a material is identified
/// <param name="supplier1"> a supplier after a material is identified
/// <param name="expiration_date1"> expiration date after a material if identified
/// <param name="name2">new name of the material
/// <param name="supplier2">new name of the supplier
/// <param name="expiration_date2">new value of the expiration date
/// <param name="quantity2">new value of the quantity
/// <param name="ok"> in integer in which we save the a number corresponding to a message that will be shown on the screen
void updateMaterial(Service* s, char* name1, char* supplier1, char* expiration_date1, char* name2, char* supplier2, char* expiration_date2, int quantity2, int* ok);

/// <summary>
/// It will split the expiration date into its day,month and year
/// </summary>
/// <param name="expiration_date"> a pointer to a char which contain the expiration date of a material
/// <param name="day">a vector in which we will save the current day
/// <param name="month">a vector in which we will save the current month
/// <param name="year"> a vector in which we will save the current year
void getDate(char* expiration_date, char day[], char month[], char year[]);

/// <summary>
/// if the string is "null" the function will search all the expired material, otherwise it will search for those who have in them the given string
/// </summary>
/// <param name="s">poiter of type Service
/// <param name="a"> The current day
/// <param name="b"> The current month
/// <param name="c"> The current year
/// <param name="str"> A string after we search the expired materials
/// <returns> a repo with all the expired materials
Repo* filterByString(Service* s,char day_a[],char month_a[], char year_a[], char str[]);
Repo* filterByName(Service* s, char* name);
/// <summary>
/// sort repo by name without changing it
/// </summary>
/// <param name="s"></param>
/// <returns></returns> the sorted list
Service* sortByName(Service* s);

/// <summary>
/// sort repo by a given quantity without changing it
/// </summary>
/// <param name="s"></param>
/// <returns></returns> the sorted list
Service* sortByQuantity(Service* s, int nr);

void undo(Service* s);
void redo(Service* s);