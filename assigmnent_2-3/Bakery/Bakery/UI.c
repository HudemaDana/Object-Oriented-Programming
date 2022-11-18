#include<stdio.h>
#include<stdlib.h>
#include "UI.h"
#include "MaterialService.h"


void printMenu()
{
	printf("\n\n-------------------- BAKERY ------------------------\n\n");
	printf("a. Modify the materials\n");
	printf("b. See all available materials past their expiration date\n");
	printf("c. Display all materials from a given supplier, which are in short supply\n");
	printf("d. Undo/Redo\n");
	printf("e. Exit\n");
	printf("f. Display the materials sorted by their name.\n\n");
	printf("----------------------------------------------------\n\n");
}

void printMenuA()
{
	printf("----------------------------------------------------\n\n");
	printf("1. Add a material\n");
	printf("2. Remove a material\n");
	printf("3. Update a material\n");
	printf("4. Write materials\n");
	printf("0. Exit\n\n");
	printf("----------------------------------------------------\n\n");
}
void printMenuB1()
{
	printf("----------------------------------------------------\n\n");
	printf("1. Filter by their expiration date\n");
	printf("2. Filter by their name\n");
	printf("3. Exit\n\n");
	printf("----------------------------------------------------\n\n");
}
void printMenuC()
{
	printf("----------------------------------------------------\n\n");
	printf("1. Ascending order by their quantity\n");
	printf("2. Descending order by their quantity\n");
	printf("0. Exit\n\n");
	printf("----------------------------------------------------\n\n");
}

void printMenuD()
{
	printf("----------------------------------------------------\n\n");
	printf("1. Undo\n");
	printf("2. Redo\n");
	printf("3. Print Materials\n");
	printf("0. Exit\n\n");
	printf("----------------------------------------------------\n\n");
}

void print_materials(Service* s)
{
	printf("NAME_MATERIAL\t\tSUPPLIER\t\tEXPIRATION DATA\t\tQUANTITY\n");
	for (int i = 0; i < getSize(getRepo(s)->elems); i++)
		printf("%s\t\t\t%s\t\t\t%s\t\t\t%d\n", getName(get(getRepo(s)->elems,i)), getSupplier(get(getRepo(s)->elems, i)), getExpiration_Date(get(getRepo(s)->elems, i)), getQuantity(get(getRepo(s)->elems, i)));
}

void printByValue(Service* s, int value)
{
	printf("NAME_MATERIAL\t\tSUPPLIER\t\tEXPIRATION DATA\t\tQUANTITY\n");
	for (int i = 0; i < getSize(getRepo(s)->elems); i++)
		if(getQuantity(get(getRepo(s)->elems, i)) >= value)
			printf("%s\t\t\t%s\t\t\t%s\t\t\t%d\n", getName(get(getRepo(s)->elems, i)), getSupplier(get(getRepo(s)->elems, i)), getExpiration_Date(get(getRepo(s)->elems, i)), getQuantity(get(getRepo(s)->elems, i)));
}

void create_materials(Service* s)
{
	addToRepo(s->r, createMaterial("lapte", "napolact", "12/04/2022", 120));
	addToRepo(s->r, createMaterial("unt", "farmBio", "11/02/2022", 100));
	addToRepo(s->r, createMaterial("faina", "angola", "22/03/2022", 250));
	addToRepo(s->r, createMaterial("drojdie", "bigAir", "12/03/2022", 50));
	addToRepo(s->r, createMaterial("ulei", "solaris", "04/03/2022", 300));
	addToRepo(s->r, createMaterial("lapte", "alpalact", "13/04/2022", 45));
	addToRepo(s->r, createMaterial("iaurt", "napolact", "12/02/2022", 32));
	addToRepo(s->r, createMaterial("sare", "salsa", "01/03/2025", 58));
	addToRepo(s->r, createMaterial("iaurt", "alpalact", "07/03/2022", 96));
	addToRepo(s->r, createMaterial("branza", "napolact", "13/04/2022", 112));

}

void controllerA(Service* s)
{
	int ok_while = 1;
	while (ok_while)
	{
		printMenuA();
		char number;
		printf("What do you want to do = ");
		scanf(" %c", &number);
		switch (number)
		{
		case '1':
		{
			int quantity,value = 1;
			int* ok = &value;
			char *name,*supplier,*expiration_date;

			name = (char*)malloc(sizeof(char) * 1000);
			supplier = (char*)malloc(sizeof(char) * 1000);
			expiration_date = (char*)malloc(sizeof(char) * 1000);

			printf("Type the name of the material: ");
			scanf("%s", name);

			printf("Type the supplier of the material: ");
			scanf("%s", supplier);

			printf("Type the expiration date of the material: ");
			scanf("%s", expiration_date);

			printf("Type the quantity of the material: ");
			scanf("%d", &quantity);

			addMaterial(s, name, supplier, expiration_date, quantity, ok);

			if (*ok == 0)
				printf("Invalid input to be added\n");
			else if (*ok == 1)
				printf("Material added succesfully\n");

			free(name);
			free(supplier);
			free(expiration_date);

			break;
		}
		case '2':
		{
			int max= 1000,value = 1;
			int* ok = &value;
			char* name, * supplier, * expiration_date;

			name = malloc(sizeof(char) * max);
			supplier = malloc(sizeof(char) * max);
			expiration_date = malloc(sizeof(char) * max);
			
			printf("Type the name of the material: ");
			scanf("%s", name);

			printf("Type the supplier of the material: ");
			scanf("%s", supplier);

			printf("Type the expiration date of the material: ");
			scanf("%s", expiration_date);

			removeMaterial(s, name, supplier, expiration_date, 0, ok);
			if (*ok == 0)
				printf("Invalid input for the remove proccess\n");
			else if (*ok == 1)
				printf("Material removed succesfully\n");
			else if (*ok == 2)
				printf("The material doesn't exit. Try another input.\n");

			free(name);
			free(supplier);
			free(expiration_date);
			break;
		}
		case '3':
		{
			int max = 1000,value = 1, quantity2;
			int* ok = &value;
			char *name1, *supplier1, *expiration_date1,*name2, *supplier2, *expiration_date2;

			name1 = malloc(sizeof(char) * max);
			supplier1 = malloc(sizeof(char) * max);
			expiration_date1 = malloc(sizeof(char) * max);
			name2 = malloc(sizeof(char) * max);
			supplier2 = malloc(sizeof(char) * max);
			expiration_date2 = malloc(sizeof(char) * max);

			printf("Type the name of the material: ");
			scanf("%s", name1);

			printf("Type the supplier of the material: ");
			scanf("%s", supplier1);

			printf("Type the expiration date of the material: ");
			scanf("%s", expiration_date1);



			printf("Type the name of the material: ");
			scanf("%s", name2);

			printf("Type the supplier of the material: ");
			scanf("%s", supplier2);

			printf("Type the expiration date of the material: ");
			scanf("%s", expiration_date2);

			printf("Type the quantity of the material: ");
			scanf("%d", &quantity2);

			updateMaterial(s, name1, supplier1, expiration_date1, name2, supplier2, expiration_date2, quantity2,ok);
			
			if (*ok == 0)
				printf("Material to be updated doesn't exist. Try another input data\n");
			else if (*ok == 1)
				printf("Material succesfully updated\n");
			else if (*ok == 2)
				printf("Wrong input data. Please try again\n");
			else if (*ok == 3)
				printf("Data good, but it was updated with the same data\n");

			free(name1);
			free(supplier1);
			free(expiration_date1);
			free(name2);
			free(supplier2);
			free(expiration_date2);
			break;
		}
		case '4':
			print_materials(s);
			break;
		case '0':
			ok_while = 0;
			break;
		default:
			printf("Invalid number for requirement A. Please try again");
		}	
	}
}

void controllerB(Service* s)
{
	char* date;
	char str[100], day_a[4], month_a[4], year_a[6];

	date = malloc(sizeof(char) * 1000);

	printf("Current date: ");
	scanf("%s", date);

	printf("Type a string:");
	scanf("%s", &str);

	getDate(date, day_a, month_a, year_a);
	Repo* res = filterByString(s, day_a, month_a, year_a, str);
	
	if (getSize(res->elems) == 0)
	{
		printf("No material with the given string is expired");
		return;
	}

	printf("\n\nNAME_MATERIAL\t\tSUPPLIER\t\tEXPIRATION DATA\t\tQUANTITY\n");
	for (int i = 0; i < getSize(res->elems); i++)
		printf("%s\t\t\t%s\t\t\t%s\t\t\t%d\n", getName(get(res->elems,i)), getSupplier(get(res->elems, i)), getExpiration_Date(get(res->elems, i)), getQuantity(get(res->elems, i)));
	

	free(date);
	destroyRepo(res);
}

void controllerB1(Service* s)
{

	char str[100];
	printf("Type a name:");
	scanf("%s", &str);

	Repo* res = filterByName(s, str);

	if (getSize(res->elems) == 0)
	{
		printf("No material with the given string is expired");
		return;
	}

	printf("\n\nNAME_MATERIAL\t\tSUPPLIER\t\tEXPIRATION DATA\t\tQUANTITY\n");
	for (int i = 0; i < getSize(res->elems); i++)
		printf("%s\t\t\t%s\t\t\t%s\t\t\t%d\n", getName(get(res->elems, i)), getSupplier(get(res->elems, i)), getExpiration_Date(get(res->elems, i)), getQuantity(get(res->elems, i)));


	destroyRepo(res);
}

void controllerC(Service* s)
{
	int ok = 1;
	while (ok)
	{
		printMenuC();
		char number;

		printf("What do you want to do = ");
		scanf(" %c", &number);
		switch (number)
		{
		case '1':
		{
			int value;
			printf("Type the value = ");
			scanf("%d", &value);

			Service* copy_s = sortByQuantity(s, 1);
			printByValue(copy_s, value);
			destroyService(copy_s);
			break;
		}
		case '2':
		{
			int value;
			printf("Type the value = ");
			scanf("%d", &value);

			Service* copy_s = sortByQuantity(s, 2);
			printByValue(copy_s, value);
			destroyService(copy_s);
;			break;
		}
		case '0':
			ok = 0;
			break;
		default:
			printf("Invalid number for requirement C. Please try again");
		}			
	}
}

void controllerD(Service* s)
{
	int ok = 1;
	while (ok)
	{
		printMenuD();
		char number;
		printf("What do you want to do = ");
		scanf(" %c", &number);
		switch (number)
		{
		case '1':
			if (s->undo_stack->operations->size > 0)
				undo(s);
			else
				printf("Nothing more to undo");
			break;
		case '2':
			if (s->redo_stack->operations->size > 0)
				redo(s);
			else
				printf("Nothing more to undo");
			break;
		case '3':
			print_materials(s);
			break;
		case '0':
			ok = 0;
			break;
		default:
			printf("Invalid number for requirement D. Please try again");
		}
	}
}

void controllerF(Service* s)
{
	Service* copy_s = sortByName(s);
	print_materials(copy_s);

	destroyService(copy_s);
}

void controller(Service* s)
{
	create_materials(s);
	while(1)
	{
		printMenu();
		char menuCommand;
		printf("What do you want to do = ");
		scanf(" %c", &menuCommand);
		switch (menuCommand)
		{
		case 'a':
			controllerA(s);
			break;
		case 'b':
		{	int ok = 1;
		while (ok)
		{
			printMenuB1();
			char nr;
			printf("What do you want to do = ");
			scanf(" %c", &nr);
			switch (nr)
			{
			case '1':
				controllerB(s);
				break;
			case '2':
				controllerB1(s);
				break;
			case '3':
				ok = 0;
				break;
			default:
				printf("Command invalid");
			}
		}
			break;
		}
		case 'c':
			controllerC(s);
			break;
		case 'd':
			controllerD(s);
			break;
		case 'e':
			return;
			break;
		case 'f':
			controllerF(s);
			break;
		default:
			printf("Invalid input. Please try again.");
		}
	}
}
