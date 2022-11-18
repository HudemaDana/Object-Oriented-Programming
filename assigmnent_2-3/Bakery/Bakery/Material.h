#pragma once

typedef struct
{
	char* name;
	char* supplier;
	char* expiration_date;
	int quantity;

}Material;

/// <summary>
/// It creates a material when it's given a name, a supplier, an expiration date and a quantity
/// </summary>
/// <param name="name"> a pointer to a char in which will be stored the name of the material
/// <param name="supplier"> a pointer to a char in which will be stored the name of the supplier
/// <param name="expiration_date"> a pointer to a char in which will be stored the expiration date of the material
/// <param name="quantity"> an integer in which will be stored the quantity of the material
/// <returns> The function returns a pointer of type Material in which are stored all the needed datas about the material
Material* createMaterial(char* name, char* supplier, char* expiration_date, int quantity);

/// <summary>
/// Clean up the space remaining on the heap when we want to erase a material
/// </summary>
/// <param name="m"> a pointer of type Material
void destroyMaterial(Material* m);

/// <summary>
/// Makes a copy of a material
/// </summary>
/// <param name="m"></param> the material we need to copy
/// <returns></returns> it will return a copy to the material
Material* copyMaterial(Material* m);

/// <summary>
/// Gives you the name of the Material or NULL if the Material is NULL
/// </summary>
/// <param name="m"> pointer of type Material
/// <returns> The name of the material
char* getName(Material* m);

/// <summary>
/// Gives you the supplier of the Material or NULL if the Material is NULL
/// </summary>
/// <param name="m"> pointer of type Material
/// <returns> The name of the supplier of the material
char* getSupplier(Material* m);

/// <summary>
/// Gives you the expiration date of the Material or NULL if the Material is NULL
/// </summary>
/// <param name="m"> pointer of type Material
/// <returns> The date in which the material expire
char* getExpiration_Date(Material* m);

/// <summary>
/// Gives you the quantity of the Material or 0 if the Material is NULL
/// </summary>
/// <param name="m"> pointer of type Material
/// <returns> The quantity of the material
int getQuantity(Material* m);

/// <summary>
/// Set the name of a material with a new one
/// </summary>
/// <param name="m"> pointer of type Material
/// <param name="name"> New name of the Material
void setName(Material* m, char* name);

/// <summary>
/// Set the name of the supplier of a material with a new one
/// </summary>
/// <param name="m"> pointer of type Material
/// <param name="supplier"> The new name of the supplier
void setSupplier(Material* m, char* supplier);

/// <summary>
/// Set the date in which a material expires with a new one
/// </summary>
/// <param name="m"> pointer of type Material
/// <param name="expiration_date"> The new date in which the material expires
void setExpiration_Date(Material* m, char* expiration_date);

/// <summary>
/// Set the quantity of a material with a new one
/// </summary>
/// <param name="m"> pointer of type Material
/// <param name="quantity"> The new value of the quantity of the material
void setQuantity(Material* m,int quantity);
