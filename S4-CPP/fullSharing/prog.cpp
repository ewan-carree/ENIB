#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <tuple>
#include "sharing.hpp"

/*
    les paramètres d'entrée (in) des fonctions,
        pour des données simples et peu volumineuses (types de base, structures dont la taille n'excède pas trois ou quatre fois celle d'un pointeur, chaînes std::string dont nous savons qu'elles sont probablement très courtes,...), doivent être passés par valeur,
        pour des données volumineuses, notamment celles qui utilisent en interne une allocation dynamique de mémoire (tableaux dynamiques std::vector<T>, chaînes std::string dont nous savons qu'elles peuvent être longues,...),
            doivent être passés par référence constante s'ils ne sont que consultés,
            doivent être passés par valeur puis déplacés vers leur destination lorsqu'ils doivent être mémorisés,
    les paramètres de sortie (out) des fonctions sont systématiquement renvoyés par l'instruction return,
        ce résultat est transmis par valeur sans que cela n'implique de surcoût en temps d'exécution,
        s'il y a plusieurs résultats à transmettre, il faut renvoyer un std::tuple<...> en prenant soin de provoquer le déplacement des données locales qui en initialisent les membres,
    les paramètres d'entrée-sortie (in-out) des fonctions,
        pour des données simples et peu volumineuses (voir un peu plus haut), doivent être passés par valeur en entrée, et renvoyées comme un résultat en sortie, sans prendre de précaution particulière,
        pour des données volumineuses (voir un peu plus haut), doivent être passés par référence (non constante afin de permettre la modification),
    les références désignent avec un nouveau nom des données déjà existantes et permettent de les manipuler sans impliquer leur recopie,
    il faut éviter, autant que faire se peut, d'avoir recours aux pointeurs.
*/
/*
il faut donc chercher à utiliser, par ordre de préférence :

    un passage par valeur si le paramètre est peu coûteux à recopier ou s'il doit être mémorisé (std::move() sera alors utilisé lors de la mémorisation),
    un passage par référence (qualifiées de const ou non, selon le besoin) si le paramètre est potentiellement coûteux à recopier,
    un passage par pointeur si une référence conviendrait mais que la donnée pourrait ne pas exister (nullptr),
*/


// 201
void test_make_sensor()
{
	std::string s = "four";
	std::vector<double> v = {1.1,2.2,3.3,4.4,5.5};

	exam::Sensor result = exam::make_sensor(std::move(s),std::move(v));

	std::cout << "on affiche les éléments de result : ";
	std::cout << result.device << std::endl;
	for (const auto &e : result.values){
		std::cout << e << " ";
	}

	std::cout<<"\n";

}



void test_valeur_sans_memorisation()
{
	std::cout << "~~~~~~~~" << __func__ << "~~~~~~~~" << std::endl;
	std::string s = "Salut";
	std::string result =exam::par_valeur_non_memo(s);
	std::cout << result << std::endl;
}

void test_valeur_avec_memorisation()
{
	std::cout << "~~~~~~~~" << __func__ << "~~~~~~~~" << std::endl;
	std::string s = "Comment ça va ?";
	std::string result =exam::par_valeur_memo(std::move(s));
	std::cout << result << std::endl;
}

void test_reference_non_const()
{
	std::cout << "~~~~~~~~" << __func__ << "~~~~~~~~" << std::endl;
	exam::Vec_int values = exam::init_vector(100);
	exam::par_ref_non_const(values);
	for (const auto &elem : values)
	{
		std::cout << elem << " ";
	}
	std::cout << "\n";
}

void test_reference_const()
{
	std::cout << "~~~~~~~~" << __func__ << "~~~~~~~~" << std::endl;
	exam::Vec_int values = exam::init_vector(100);
	int result =  exam::par_ref_const(values);
	for (const auto &elem : values)
	{
		std::cout << elem << " ";
	}
	std::cout << "\nIl y a " << result << " nombres impairs\n" << std::endl;
}

void test_return_tuple()
{
	std::cout << "~~~~~~~~" << __func__ << "~~~~~~~~" << std::endl;
	exam::Vec_int values = exam::init_vector(100);
	auto [pair, impair, taille] = exam::manyResults(values);
	std::cout << "La taille totale est : " << taille << " élements"<< std::endl;
	std::cout << "Tableau pair : "<< std::endl;
	for (const auto &elem :pair)
	{
		std::cout << elem << " ";
	}
	std::cout << "\nTableau impair : " << std::endl;
	for (const auto &elem : impair)
	{
		std::cout << elem << " ";
	}


}

/*void test()
{
	exam::Vec_str values = exam::init_vector(1'000);
	for (const auto &e : values){
		std::cout << e << " ";
	}
}*/

int main(int argc, char const *argv[])
{
	test_make_sensor();
	//test();
	test_valeur_sans_memorisation();
	test_valeur_avec_memorisation();
	test_reference_non_const();
	test_reference_const();
	test_return_tuple();
	return 0;
}