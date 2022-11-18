#include "Valid.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int ValidName(char* name)
{
	if (name == NULL)
		return 0;
	for (int i = 0; i < strlen(name); i++)
		if (isdigit(name[i]))
			return 0;
	return 1;
}

int ValidSupplier(char* supplier)
{
	if (supplier == NULL)
		return 0;

	int ok = 0;
	for (int i = 0; i < strlen(supplier); i++)
		if (isalpha(supplier[i]))
		{
			ok = 1;
			break;
		}
	if (ok == 1)
		return 1;
	return 0;
}

int ValidExpiration_Date(char* expiration_date)
{
	if (expiration_date == NULL)
		return 0;
	if (strlen(expiration_date) != 10)
		return 0;
	for (int i = 0; i < strlen(expiration_date); i++)
		if (isalpha(expiration_date[i]))
			return 0;
	return 1;
}


int ValidMaterial(char* name, char* supplier, char* expiration_date)
{

	if (ValidName(name) && ValidSupplier(supplier) && ValidExpiration_Date(expiration_date))
		return 1;
	return 0;
}
