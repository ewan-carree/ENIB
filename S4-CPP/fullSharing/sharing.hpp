#ifndef SHARING_HPP
#define SHARING_HPP

#include <vector>
#include <string>
#include <tuple>

namespace exam{

struct Sensor{
	std::string device;
	std::vector<double> values;
};

Sensor make_sensor(std::string device, std::vector<double> values);


using Vec_str = std::vector<std::string>;
using Vec_int = std::vector<int>;

//Vec_str init_vector(int number);
Vec_int init_vector(int number);

std::string par_valeur_non_memo(std::string s);
std::string par_valeur_memo(std::string s);
void par_ref_non_const(Vec_int &v);
int par_ref_const(const Vec_int &v);

std::tuple<std::vector<int>, std::vector<int>, int> manyResults(const Vec_int &v);

}

#endif