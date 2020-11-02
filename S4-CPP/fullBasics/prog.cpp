/*

Ewan Carrée

programme qui rassemble toutes les informations apprises dans le chapitre basics

à ajouter: point 6/fonctions tableau vector


*/


#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include "basics.hpp"


#define MAXTAB 9 //macro pour definir elements tableau


/////////////////evaluation 102

void test_collectOver(double limit){
	std::cout << "\n~~~" << __func__ << "~~~" << std::endl;
	std::vector<double> samples = {1.1,2.2,3.3,5.5,6.6,7.7,9.9,10.01};
	const double amount = exam::collectOver(samples,limit);
	std::cout << amount << " over the limit " << limit << std::endl;
}

void test_add(){
	std::cout << "\n\n\n~~~" << __func__ << "() ~~~" << std::endl;

	exam::Fraction f = {1,2};
	exam::Interval i = {1.1, 5.5};

	std::cout << "numer : " << f.numer << " , denom  " << f.denom << std::endl;
	std::cout << "low : " << i.low << " , high : " << i.high << std::endl;

	int a = 100;
	double b = 100.0;

	std::cout << "after first call of add() function : " << std::endl;
	exam::Fraction f1 = add(f, a);
	std::cout << "numer : " << f1.numer << " , denom  " << f1.denom << std::endl;
	exam::Interval i1 = add(i,b);
	std::cout << "low : " << i1.low << " , high : " << i1.high << std::endl;

	int c = 50;
	double d = 50.0;

	std::cout << "after second call of add() function using ADL : " << std::endl;
	exam::Fraction f2 = f+c;
	std::cout << "numer : " << f2.numer << " , denom  " << f2.denom << std::endl;
	exam::Interval i2 = i+d;
	std::cout << "low : " << i2.low << " , high : " << i2.high << std::endl;
}




////////////////////  string

void test_string(int argc, const char **argv){
  std::cout << "\n~~~~ " << __func__ << "() ~~~~\n";
  std::string msg{"Hi there!"};
  std::cout << "message is <" << msg << "> i.e. <"<< exam::enumerateChars(msg) << ">\n";

  //comparaison sur chaine
  if(msg!="Hello") {std::cout << '<' << msg << "> is not <Hello>\n";}
  if(msg>"Hello") {std::cout << '<' << msg << "> comes after <Hello>\n";}
  if(msg<"Hooray") {std::cout << '<' << msg << "> comes before <Hooray>\n";}


  // recherche dans chaine
  auto pos=msg.find(' '); // actual return-type is std::string::size_type 
  if(pos!=msg.npos) // si la position n'est pas "rien"
  {
    std::cout << "found <" << msg[pos] << "> at position " << pos << '\n';
    msg[pos]='\0'; // essaye de couper la chaine comme en C mais cela ne fait qu'ajouter \0 (carac invisible) dans la chaine mais ne la termine pas.
    std::cout << "message changed to <" << msg << "> i.e. <"<< exam::enumerateChars(msg) << ">\n";
   
    msg.resize(pos); //fonction pour couper la chaine. equivalent du msg[pos]='\0' en C
    std::cout << "... then to <" << msg << "> i.e. <"<< exam::enumerateChars(msg) << ">\n";
  }
  
  //taille chaine et contenu
  std::cout << "message size is " << size(msg)<< ", thus empty() returns "<< (empty(msg) ? "true\n" : "false\n");
  msg.clear(); // fonction pour faire une raz de la chaine, la chaine peut ensuite etre "reinitialisée"
  std::cout << "message size is now " << size(msg)<< ", thus empty() returns "<< (empty(msg) ? "true\n" : "false\n");
  


  //lit les parametres passés en arg lors du call de prog et analyse si entier ou pas 
  for(int i=0; i<argc; ++i)
  {
    std::string str{argv[i]};
    int value;
    if(exam::parseInt(str, &value))
    {
      std::cout << "integer " << value << " found in <" << str << ">\n";
    }
    else
    {
      std::cout << "cannot parse <" << str << "> as an integer!\n";
    }
  }
}



//////////////////////////////  vector

void test_vector(){
  std::cout << "\n~~~~ " << __func__ << "() ~~~~\n";

  //two types of init
  exam::vector tableau1= {1,2,3,4,5};
  std::vector<int> tableau2={1,3,5};

  std::cout << "la taille du tableau 1 est de : " << size(tableau1) << std::endl;
  std::cout << "mais la taille du tableau 2 est de : " << size(tableau2) << std::endl;
  std::cout << "that's why empty() return : " << empty(tableau2) << std::endl;

  std::cout << "\n";

  int incommon = exam::compare(tableau1, tableau2);
  if (incommon == 0){std::cout << "nothing in common" << std::endl;}
  else {std::cout << "\n";}// on ne peut pas mettre directement std::endl
  
  for (auto &elemtab : tableau1)  {elemtab = 10;} //modif chaque element : plus de const auto 
  std::cout << "tableau 1 après modif : ";
  for (const auto & elemtab : tableau1) {std::cout << elemtab << " ";} // affichage valeur de chaque elem du tableau 1
  // il est aussi possible deconsulter chaque élément d'un tableau en utilisant ce qu'on connaît en C, c'est à dire : std::cout<< tableau[0]  pour le premier élément du tableau
  std::cout << "\n\n";

  incommon = exam::compare(tableau1, tableau2);
  if (incommon == 0){std::cout << "Thats' why there's nothing in common" << std::endl;}
  else {std::cout << "\n";}

  //utilistion back()/pop_back()/emplace_back() sur un tableau
  // nous allons faire en sorte que nos deux tableaux correspondent l'un à l'autre et affiche des chiffres de 1 à 9
  //tableau 1 :

  //std::cout << tableau1.back() << size(tableau1) << std::endl;
  while (size(tableau1)!=0){
    tableau1.pop_back(); //retire le dernier element
  } 

  for (int i = 0; i < MAXTAB; ++i)
  {
    tableau1.emplace_back(i+1); //ajoute un élément à la fin
  }
  if (tableau1.back()==9){std::cout << "\nmodif tableau1 ok : ";}
  for (const auto & elemtab : tableau1) {std::cout << elemtab << " ";}
  std::cout << "\n";

  //tableau 2 : 
  while (size(tableau2)!=0){
    tableau2.pop_back();
  }
  for (int i = 0; i < MAXTAB; ++i)
  {
    tableau2.push_back(i+1); //same as emplace_back
  }
  if (tableau2.back()==9){std::cout << "\nmodif tableau2 ok : ";}
  for (const auto & elemtab : tableau2) {std::cout << elemtab << " ";}
  std::cout << "\n";

}


void test_anomalies(int argc, char const **argv){
	std::cout << "\n~~~~ " << __func__ << "() ~~~~\n";
	// static-assert ne fonctionne que si les éléments sont connus à la compilation, tel que des sizeof
	static_assert(sizeof(int)>=4, "problem in size of int");
	std::vector<int> values;
	static_assert(sizeof(values[0])>=4, "impossible to use int");


	std::vector<std::string> args{argv+1, argv+argc}; /*ci nous énumérons argc chaînes C à partir de argv. argv est de typechar **donc argv est équivalent à &argv[0] 
	et argv+argc est équivalent à &argv[argc], il ne s'agit que d'arithmétique des pointeurs*/
	exam::display(values);
	exam::name_add(args, &values);
	exam::display(values); //name changed !!

	/*std::vector<int> v = {1,2,3,4,5};
	std::vector<int> v1{v[0],v[size(v)-1]};
	exam::display(v1);
	exam::display(args);*/


  int a=0,b=10;
  int result = exam::divide(b,a);
  std::cout << result << "is the result of the function divide()" << std::endl;

}



int main(int argc, char const *argv[])
{
	test_collectOver(6.5);
	test_collectOver(8);
	test_add();
	test_string(argc, argv);
 	test_vector();
 	test_anomalies(argc, argv); //add name when call of ./prog
	return 0;
}


