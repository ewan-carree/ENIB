#ifndef GENERIC_HPP
#define GENERIC_HPP

#include <vector>
#include <string>
#include <stdexcept> //runtime_error
#include <iostream>
#include <utility> // std::move()
#include <algorithm> //fonctions génériques
#include <array>


namespace exam
{

template<typename T>
class MinMax
{
	public:
		MinMax(T a, T b): sideA_{std::move(a)}, sideB_{std::move(b)} {}
		MinMax(): MinMax(0,0) {}



		template<typename T2>
		inline
		std::vector<T>
		generate(MinMax &a, T2 b)
		{
			std::vector<T> v;
			v.emplace_back(std::min(a.sideA_, a.sideB_));
			T max = std::max(a.sideA_, a.sideB_);
			T sum = v.back()+b;
			while (sum < max)
			{
				v.emplace_back(sum);
				sum = v.back()+b;
			}
			return v;
		}

		template<typename T3>
		inline
		auto
		extract_right(std::vector<T3> v, T3 a)
		{
			std::vector<T3> result;
			auto it = std::find_if (v.begin(), v.end(), [&](std::vector<T3> v2){
				for (const auto& elem : v2){
					if (elem > a){
						return elem;
					}
				}
			});
			std::for_each(it, v.end(), [&](std::vector<T3> &v3){
				for (const auto &elem: v3){
					result.emplace_back(elem);
				}
			});
			return result;

		}

	private:
		T sideA_, sideB_;
};



} //exam
#endif //GENERIC_HPP