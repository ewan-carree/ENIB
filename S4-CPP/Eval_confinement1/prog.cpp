/*
Ewan Carrée - S4P
prog.cpp - Projet Nursery
11/04/2020
*/

#include "nursery.hpp"

#if 0
#define DECEASE_POSITION -1 //impossible!
#else
#define DECEASE_POSITION 1
#endif

void test_nursery()
{
	std::cout << "~~~~" << __func__ << "~~~~" << std::endl;
	exam::tabstr name = {"Lilian", "Ismaël", "Erlé"};
	exam::Nursery n{std::move(name)};
	std::cout << n << std::endl;
	
	//on fait naître un bébé
	std::cout << "\n~~~~ trying to give birth ~~~~"<< std::endl;
	n.birth("Ewan");
	std::cout << n << std::endl;

	//on fait mourir un bébé
	std::cout << "\n~~~~ trying to kill baby ~~~~"<< std::endl;
	std::string dead = exam::name(DECEASE_POSITION, n);
	n.decease(DECEASE_POSITION);
	std::cout << n << " " << dead << " died unfortunately..." << std::endl;

	//on change le nom du dernier bébé
	std::cout << "\n~~~~ trying to change name ~~~~"<< std::endl;
	std::string newName = "Léo";
	n.changeName(std::move(newName));
	std::cout << n << std::endl;

	//on essaye de faire une recopie et une recopie par affectation
	std::cout << "\n~~~~ trying copies ~~~~"<< std::endl;
	exam::Nursery n1{n};
	std::cout << n1 << std::endl;
	exam::Nursery n2;
	n2=n1;
	std::cout << n2 << std::endl;

	//on vérifie que le déplacement fonctionne aussi
	std::cout << "\n~~~~ trying moves ~~~~"<< std::endl;
	exam::Nursery n3{std::move(n2)};
	std::cout << n3 << std::endl;
	exam::Nursery n4;
	n4=std::move(n3);
	std::cout << n4 << std::endl;
	std::cout << "~~~~ we make sure that previous Nursery are now empty ~~~~"<< std::endl;
	if (empty(n2.getName())&&empty(n3.getName()))
	{
		std::cout << "everything's fine !\n" << std::endl;
	}

}

int main(int argc, char const *argv[])
{
	test_nursery();
	return 0;
}
