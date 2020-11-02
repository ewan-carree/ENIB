#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include "basics.hpp"

namespace exam {

double collectOver(std::vector<double> values, double limit){
	double sum=0.0;
	for(const auto &elem : values){
		const double delta = elem-limit;
		if (delta>0.0){
			sum += delta;
		}
	}
	return sum;
}

Fraction add(Fraction f, int i){
	Fraction result = {f.numer+i*f.denom, f.denom};
	return result;
}

Interval add(Interval i, double d){
	Interval result = {i.low+d, i.high+d};
	return result;
}

Fraction operator+(Fraction f, int a){
	Fraction result = add(f,a);
	return result;
}

Interval operator+(Interval i, double b){
	Interval result = add(i,b);
	return result;
}


std::string enumerateChars(std::string txt, char separator){
  std::string result; // default initialisation yields an empty string
  for(const auto &c: txt) // for each character in a string by looking value at the adress os the variable
  {
    if(!empty(result)) // test whether a string is empty or not
    {
      result+=separator; // append a character to a string // += surcharge de l'opérateur
    }
    result+=c; // append a character to a string
  }
  return result; // a string is safely transmitted as a return value
}

bool parseInt(std::string txt, int *out_value){
  const char *cstr=data(txt); // access C-style string inside C++ string
  return std::sscanf(cstr, " %d ", out_value)==1; // C-style string analysis
}

int compare(std::vector<int> const& tableau1, std::vector<int> const& tableau2){
	int count = 0;
	std::cout << "element en commun entre tab1 et tab2 : ";
  	for (const auto &elemtab : tableau1){
    	for (const auto &elem2 : tableau2){
     		if (elemtab == elem2){
      	  		std::cout << elem2 << " ";
      	  		count ++;
      		}
    	}
 	}
 	std::cout << "\n";
 	return count;
}

void name_add(std::vector<std::string> args,std::vector<int> *values){
  /*for (int i = 1; i < argc; ++i){
    try{
      std::stoi(argv[i]);
      name->emplace_back(argv[i]);
    }
    catch(const std::invalid_argument &e){
      std::cerr << "<" << argv[i] << "> does not look like a string!\n";
    }
  }*/


  /*for (const auto &elem : args){
    try{
        values->emplace_back(std::strtoul(elem.c_str(),0,10));
    }
    catch(const std::out_of_range &e){
      std::cerr << "<" << elem << "> does not look like an unsigned long int!\n";
    }
  }*/

  std::vector<int> result;
  for(const auto &elem: args)
  {
    try
    {
      values->emplace_back(std::stoi(elem));
      result.emplace_back(std::stoi(elem));
      
    }
    catch(const std::invalid_argument &e)
    {
      std::cerr << "<" << elem << "> does not look like an integer!\n";
    }
    catch(const std::exception &e)
    {
      std::cerr << "integer conversion failure on <" << elem
                << ">: " << e.what() << '\n';
    }
    if(empty(result))
    {
      throw std::runtime_error{"integer arguments were expected"};
    }
  }
}

void display(std::vector<int> tableau){
  for (const auto &elem : tableau){
    std::cout << elem << " ";
  }
  std::cout << "\n";
}

void display(std::vector<std::string> tableau){
  for (const auto &elem : tableau){
    std::cout << elem << " ";
  }
  std::cout << "\n";
}

void display(std::vector<unsigned long> tableau){
  for (const auto &elem : tableau){
    std::cout << elem << " ";
  }
  std::cout << "\n";
}

int divide(int a, int b){
  int result = 0;
  try{
    result = a/b;
  }
  catch(std::exception &e){
    std::cerr << "an error was found, here is an exponation" << e.what() << std::endl;
  }
  if (result == 0){
    throw std::runtime_error {"result cannot equals 0, there is a problem somewhere"};
  }
  return result;
}


}



