#include <iostream>
#include <utility> //pour std::move
#include <vector>
#include <string>
#include <tuple> //pour retourner plusieurs résultats
#include "sharing.hpp"

namespace exam {

Sensor make_sensor(std::string device, std::vector<double> values)
{
	Sensor result;
	result.device = std::move(device);
	result.values = std::move(values);

	return result;
}


/*Vec_str init_vector(int number)
{
	Vec_str values = {};
	for (int i = 0; i < number; ++i)
	{
		values.emplace_back(std::to_string(i%2));
	}
	return values;
}*/

Vec_int init_vector(int number)
{
	Vec_int values = {};
	for (int i = 0; i < number; ++i)
	{
		values.emplace_back(i);
	}
	return values;
}


std::string par_valeur_non_memo(std::string s)
{
	std::string result = s + " / Hello / Hola / Hallo\n";
	return result;
}

std::string par_valeur_memo(std::string s)
{
	std::string result = std::move(s) + " / How are you ? / Como esta ? / Wie gehen sie ?\n";
	return result;
}

void par_ref_non_const(Vec_int &v)
{
	for(auto &elem : v)
	{
		if (elem%2 == 0){
			elem = 0;
		}
	}
}

int par_ref_const(const Vec_int &v)
{
	int count = 0;
	for (const auto &elem : v)
	{
		if (elem%2==1)
		{
			++count;
		}
	}
	return count;
}

std::tuple<std::vector<int>, std::vector<int>, int> manyResults(const Vec_int &v)
{
	Vec_int pair = {},impair = {};
	int taille;
	for (const auto &elem : v)
	{
		if (elem%2==0)
		{
			pair.emplace_back(elem);
			++taille;
		}
		else
		{
			impair.emplace_back(elem);
			++taille;
		}
	}

	return {std::move(pair), std::move(impair), std::move(taille)};
}




}



