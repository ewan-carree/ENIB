#ifndef PROG_H
#define PROG_H
typedef struct Ingredient Ingredient;
struct Ingredient
{
	int id_ingredient;
	char *nom;
	char *pays;
};

typedef struct Plat_Menu Plat_Menu;
struct Plat_Menu
{
	int id_menu;
	int id_plat;
};

typedef struct Restaurant_Menu Restaurant_Menu;
struct Restaurant_Menu
{
	int id_restaurant;
	int id_menu;
};

typedef struct Menu Menu;
struct Menu
{
	int id_menu;
	char *nom;
	double prix;
};

typedef struct Recette Recette;
struct Recette
{
	int id_plat;
	int id_ingredient;
	int poids;
};

typedef struct Plat Plat;
struct Plat
{
	int id_plat;
	char *nom;
	double prix;
};

#endif