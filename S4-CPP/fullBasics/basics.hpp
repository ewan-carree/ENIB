#ifndef BASICS_HPP
#define BASICS_HPP

#include <vector> // il faut toujours inclure les bibli qui sont utilent lors de la déclaration de fonctions
#include <string>

namespace exam{

	double collectOver(std::vector<double> values, double limit);

	struct Fraction //une structure peut directement se faire call par son nom, pas besoin de typedef comme en C
	{
			int numer, denom;
	};
	
	struct Interval
	{
		double low, high;
	};

	Fraction add(Fraction f, int i);
	Interval add(Interval i, double d);

	Fraction operator+(Fraction f, int a); //operator est reconnu comme une opération et s'utilise avec le symbole situé à gauche de operator, ici : +
	Interval operator+(Interval i, double b);



	std::string enumerateChars(std::string txt, char separator='|');
	bool parseInt(std::string txt, int *out_value);


	using vector = std::vector<int>;  // equivalent typedef, lors d'un appel de 'vector', on crée un tableau
	int compare(std::vector<int> const& t1, std::vector<int> const& t2); //tableau seulement consultable par référence

	void display(std::vector<std::string> tableau);
	void display(std::vector<int> tableau);
	void display(std::vector<unsigned long> tableau);

	void name_add(std::vector<std::string> args,std::vector<int> *values);
	int divide(int a, int b);

}

#endif