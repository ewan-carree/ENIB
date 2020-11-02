# include <stdio.h>
 # include <stdlib.h>
# include <string.h>
#include "prog.h"

void ing(Ingredient *a, int count, char * filename, char * filename_output)
{
	FILE *f=fopen(filename, "r");
  	if(!f)
  	{
    	fprintf(stderr, "cannot open \n");
  	}

  	FILE *f2=fopen(filename_output, "w");
  	if(!f2)
  	{
    	fprintf(stderr, "cannot open \n");
  	}

  	int caractereActuel=0;

  	fseek(f, 0, SEEK_SET);

	for (int i = 0; i < count; ++i)
	{

  		fscanf(f , "%d , %s , %s", &(a->id_ingredient), a->nom, a->pays);

  		fprintf(f2, "INSERT INTO ingredient(id_ingredient, nom, pays) VALUES (%d,%s,%s)\n", a->id_ingredient, a->nom, a->pays);

	}
	fclose(f);
	fclose(f2);	
}

void pl(Plat *a, int count, char * filename, char * filename_output)
{
	FILE *f=fopen(filename, "r");
  	if(!f)
  	{
    	fprintf(stderr, "cannot open \n");
  	}

  	FILE *f2=fopen(filename_output, "w");
  	if(!f2)
  	{
    	fprintf(stderr, "cannot open \n");
  	}

  	int caractereActuel=0;

  	fseek(f, 0, SEEK_SET);

	for (int i = 0; i < count; ++i)
	{

  		fscanf(f , "%d , %s , %lf", &(a->id_plat), a->nom, &(a->prix));

  		fprintf(f2, "INSERT INTO plat(id_plat, nom, prix) VALUES (%d,%s,%lf)\n", a->id_plat, a->nom, a->prix);

	}
	fclose(f);
	fclose(f2);	
}

void r(Recette *a, int count, char * filename, char * filename_output)
{
	FILE *f=fopen(filename, "r");
  	if(!f)
  	{
    	fprintf(stderr, "cannot open \n");
  	}

  	FILE *f2=fopen(filename_output, "w");
  	if(!f2)
  	{
    	fprintf(stderr, "cannot open \n");
  	}

  	int caractereActuel=0;

  	fseek(f, 0, SEEK_SET);

	for (int i = 0; i < count; ++i)
	{

  		fscanf(f , "%d , %d , %d", &(a->id_plat), &(a->id_ingredient), &(a->poids));

  		fprintf(f2, "INSERT INTO recette(id_plat, id_ingredient, poids) VALUES (%d,%d,%d)\n", a->id_plat, a->id_ingredient, a->poids);

	}
	fclose(f);
	fclose(f2);	
}

void m(Menu *a, int count, char * filename, char * filename_output)
{
	FILE *f=fopen(filename, "r");
  	if(!f)
  	{
    	fprintf(stderr, "cannot open \n");
  	}

  	FILE *f2=fopen(filename_output, "w");
  	if(!f2)
  	{
    	fprintf(stderr, "cannot open \n");
  	}

  	int caractereActuel=0;

  	fseek(f, 0, SEEK_SET);

	for (int i = 0; i < count; ++i)
	{

  		fscanf(f , "%d , %s , %lf", &(a->id_menu), a->nom, &(a->prix));

  		fprintf(f2, "INSERT INTO menu(id_menu, nom, prix) VALUES (%d,%s,%lf)\n", a->id_menu, a->nom, a->prix);

	}
	fclose(f);
	fclose(f2);	
}

void pm(Plat_Menu *a, int count, char * filename, char * filename_output)
{
	FILE *f=fopen(filename, "r");
  	if(!f)
  	{
    	fprintf(stderr, "cannot open \n");
  	}

  	FILE *f2=fopen(filename_output, "w");
  	if(!f2)
  	{
    	fprintf(stderr, "cannot open \n");
  	}

  	int caractereActuel=0;

  	fseek(f, 0, SEEK_SET);

	for (int i = 0; i < count; ++i)
	{

  		fscanf(f , "%d , %d", &(a->id_menu), &(a->id_plat));

  		fprintf(f2, "INSERT INTO plat_menu(id_menu, id_plat) VALUES (%d,%d)\n", a->id_menu, a->id_plat);

	}
	fclose(f);
	fclose(f2);	
}

void rm(Restaurant_Menu *a, int count, char * filename, char * filename_output)
{
	FILE *f=fopen(filename, "r");
  	if(!f)
  	{
    	fprintf(stderr, "cannot open \n");
  	}

  	FILE *f2=fopen(filename_output, "w");
  	if(!f2)
  	{
    	fprintf(stderr, "cannot open \n");
  	}

  	int caractereActuel=0;

  	fseek(f, 0, SEEK_SET);

	for (int i = 0; i < count; ++i)
	{

  		fscanf(f , "%d , %d", &(a->id_restaurant), &(a->id_menu));

  		fprintf(f2, "INSERT INTO restaurant_menu(id_restaurant, id_menu) VALUES (%d,%d)\n", a->id_restaurant, a->id_menu);

	}
	fclose(f);
	fclose(f2);	
}

int main(int argc, char const *argv[])
{
	int choice=0;
	printf("Bienvenue dans le convertisseur SQL, n'oubliez pas de coller le texte à traduire dans les fichiers prévus en format .csv de excel en remplacant tous les ',' par  ' , '\n\n");
	printf("Choix du convertissage (choisir nombre) ~~~ 1 : ingredient - 2 : plat - 3 : recette - 4 : menu - 5 : Plat_Menu - 6 : Restaurant_Menu \n");
	printf("Lequel voulez-vous convertir en SQL ?");
	scanf("%d", &choice);

	char filename_output[] = "bdd_output.txt";
	int count=0;

	switch(choice)
	{
		case 1:
			printf("Nombre d'éléments :");
			scanf("%d", &count);

			char filename[] = "ingredient.txt";
			Ingredient ingredient;

			ing(&ingredient,count,filename,filename_output);
			break;

		case 2:
			printf("Nombre d'éléments :");
			scanf("%d", &count);

			char filename2[] = "plat.txt";
			Plat plat;

			pl(&plat,count,filename2,filename_output);

			break;

		case 3:
			printf("Nombre d'éléments :");
			scanf("%d", &count);

			char filename3[] = "recette.txt";
			Recette recette;

			r(&recette,count,filename3,filename_output);

			break;

		case 4:
			printf("Nombre d'éléments :");
			scanf("%d", &count);

			char filename4[] = "menu.txt";
			Menu menu;

			m(&menu,count,filename4,filename_output);

			break;

		case 5:
			printf("Nombre d'éléments :");
			scanf("%d", &count);

			char filename5[] = "Plat_Menu.txt";
			Plat_Menu assoc;

			pm(&assoc,count,filename5,filename_output);

			break;

		case 6:
			printf("Nombre d'éléments :");
			scanf("%d", &count);

			char filename6[] = "Restaurant_Menu.txt";
			Restaurant_Menu assoc2;

			rm(&assoc2,count,filename6,filename_output);

			break;
	}

	return 0;
}
