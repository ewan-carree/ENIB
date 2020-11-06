#ifndef COLOR_HPP
#define COLOR_HPP

#include <vector>
#include <string>
#include <stdexcept> //runtime_error
#include <iostream>
#include <utility> // std::move()

namespace tp2
{
	using uchar = unsigned char;

	struct Color
	{
		uchar red;
		uchar green;
		uchar blue;

		Color() : Color(0,0,0) {}
		Color(uchar red, uchar green, uchar blue) : red{red}, green{green}, blue{blue} {}

		uchar& operator[](int i);
		uchar operator[](int i) const;
		//std::ostream& operator<<(std::ostream& os, const Color& c1);

		Color(const Color &) = default; //constructeur par recopie
		Color(Color &&) = default; //constructeur par déplacement
		Color& operator=(const Color &) = default; //affectation par recopie
		Color& operator=(Color &&) = default; //affectation par déplacement
		~Color() = default; //destructeur



	};

	inline uchar& Color::operator[](int i) 
	{
		//std::cout << "with &" << std::endl;
		switch(i) {
			case 0:
				return red;
				break;
			case 1  :
		        	return green;
		       		break;
		   	case 2  :
		      		return blue;
		      		break;
		   	default :
		      		throw std::out_of_range("You didn't enter a correct index");
		}
	}

	inline uchar Color::operator[](int i) const 
	{
		//std::cout << "without &" << std::endl;
		switch(i) {
			case 0:
				return red;
				break;
			case 1  :
		        	return green;
		       		break;
		   	case 2  :
		      		return blue;
		      		break;
		   	default :
		      		throw std::out_of_range("You didn't enter a correct index");
		}	
	}

	inline std::ostream& operator<<(std::ostream& os, const Color& c1)
	{
		os << "red : " << int(c1[0]) << ", green : " << int(c1[1]) << ", blue : " << int(c1[2]) << std::endl;
		return os;
	}

	inline Color grey(const Color& c1)
	{	
		uchar gris = uchar((int(c1[0])+int(c1[1])+int(c1[2]))/3);
		return Color(gris, gris, gris);
	}

	


} //tp2
#endif //COLOR_HPP