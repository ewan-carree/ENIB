#include "nursery.hpp"


namespace exam{

Nursery::Nursery(tabstr name) : count_{(int)size(name)}, name_{std::move(name)}
{
	if (empty(name_)) //invariant
	{
		throw std::runtime_error{"At least one name is expected"};
	}
}

Nursery::Nursery (): Nursery({""}) {}

void Nursery::birth(std::string name)
{
	if (!empty(name))
	{
		name_.emplace_back(name);
		count_+=1;
	}
}

void Nursery::decease(int position)
{
	if (position>=0)
	{	
		name_.erase(name_.begin()+ position);	
		count_-=1;		
	}
	else
	{
		throw std::runtime_error{"name of baby cannot be under 0"};
	}
}

void Nursery::changeName(std::string name)
{
	name_.back() = name;
}



std::ostream& operator<<(std::ostream& os, const Nursery& n)
{
	os << "{ ";
	os << n.count();
	os << " babies with their names : ";
	os << n.getName();
	os << " }";

	return os;
}

std::ostream& operator<<(std::ostream& os, const tabstr& name)
{
	os << "< ";
	for (const auto &e: name)
	{
		os << e << " ";
	}
	os << '>';

	return os;
}

//nous modifions les constructeurs par recopie et recopie par affectation pour les autoriser 
Nursery::Nursery(const Nursery &n) : Nursery{n.name_}
{/*empty body*/}

Nursery & Nursery::operator=(const Nursery& n)
{
	count_=n.count_;
	name_=n.name_;
	return *this;
}


}