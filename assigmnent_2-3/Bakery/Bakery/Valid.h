#pragma once

/// <summary>
/// Check if the name is valid
/// </summary>
/// <param name="name"> the name of the material
/// <returns>it return 0 if it's wrong, 1 othewise
int ValidName(char* name);

/// <summary>
/// Check if the supplier is valid
/// </summary>
/// <param name="supplier"> the supplier of the material
/// <returns>it return 0 if it's wrong, 1 othewise
int ValidSupplier(char* supplier);

/// <summary>
/// Check if the expiration date is valid
/// </summary>
/// <param name="expiration_date"> the name of the material
/// <returns>it return 0 if it's wrong, 1 othewise
int ValidExpiration_Date(char* expiration_date);

/// <summary>
/// Check if the material is valid
/// </summary>
/// <param name="name"> the name of the material
/// <param name="supplier"> the supplier of the material
/// <param name="expiration_date"> the name of the material
/// <param name="quantity"> the quantity of the material
/// <returns>it return 0 if it's wrong, 1 othewise
int ValidMaterial(char* name,char* supplier,char* expiration_date);