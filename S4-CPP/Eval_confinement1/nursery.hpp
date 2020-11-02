#ifndef NURSERY_HPP
#define NURSERY_HPP

#include <vector>
#include <string>
#include <stdexcept> //runtime_error{}
#include <iostream>
#include <utility> // std::move()


namespace exam{

using tabstr = std::vector<std::string>; //plus simple d'utilisation

/*
Je réalise un type structuré de type Nursery qui est constitué du nombre de bébés au sein d'une maternité, ainsi qu'un tableau de leurs noms.
L'invariant est simple, un bébé non déclaré à la mairie ne peut pas exister, il y a donc toujours un nom qui lui est attribué.
*/

class Nursery 
{
	public:
	////////////règle de 5///////////////
	// on autorise la recopie qu'en cas d'exrême nécéssité
	Nursery(const Nursery &n); //recopie
	Nursery & operator=(const Nursery& n);//recopie par affectation

	Nursery(Nursery &&n) = default;//déplacement
	Nursery & operator=(Nursery && n)=default;//déplacement par affectation
	~Nursery()=default;//destructeur

	Nursery (tabstr name); //constructeur
	Nursery ();//delegation

	int count() const
	{
		return count_;
	}

	tabstr getName() const
	{
		return name_;
	}

	void birth(std::string name);
	void decease(int position);
	void changeName(std::string name);


	private:
		int count_;
		tabstr name_;
};


////////overload////////////
std::ostream& operator<<(std::ostream& os, const Nursery& n); 
std::ostream& operator<<(std::ostream& os, const tabstr& name); 

inline std::string name(int position, const Nursery &n)
{
	tabstr name = n.getName();
	return name[position];
}

}

#endif
