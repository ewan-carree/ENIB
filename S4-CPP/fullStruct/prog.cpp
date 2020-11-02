#include <iostream>
#include <array>
#include <vector>
#include <string>
#include "struct.hpp"


void
test_init()
{
  std::cout << "~~~~" << __func__ << "()~~~~"<<std::endl;
  exam::Init0 struct0;
  //std::cout << "<"<<struct0.a<<"> <"<<struct0.b << ">" << std::endl;
  
  exam::Init1 struct1;
  std::cout << "<"<<struct1.a<<"> <"<<struct1.b << ">" << std::endl;

  exam::Init2 struct2;
  std::cout << "<"<<struct2.a<<"> <"<<struct2.b << ">" << std::endl;

  exam::Init3 struct3{1'000,1'000.0};
  std::cout << "<"<<struct3.a<<"> <"<<struct3.b << ">" << std::endl;

  exam::Init3 struct3_b;
  std::cout << "<"<<struct3_b.a<<"> <"<<struct3_b.b << ">" << std::endl;

}

#if 0
void test_gravity()
{
  std::cout << "~~~~" << __func__ << "()~~~~"<<std::endl;
  exam::Gravity g1,g2{0,0,-MAGNITUDE};
  std::cout <<"g1 : "<< g1.xyz[0] << "|" << g1.xyz[1] << "|" << g1.xyz[2] << std::endl;
  std::cout <<"g2 : "<< g2.xyz[0] << "|" << g2.xyz[1] << "|" << g2.xyz[2] << std::endl;

  double normeg1{exam::magnitude(g1)};
  double normeg2{exam::magnitude(g2)};
  std::cout << "||g1|| = "<<normeg1<< "\n||g2|| = "<<normeg2<< std::endl;
}

#else
void test_gravity()
{
  std::cout << "~~~~" << __func__ << "()~~~~"<<std::endl;
  exam::Gravity g1;
  exam::Gravity g2{0,0,-MAGNITUDE};
  std::cout <<"g1 : "<<g1.x()<<"|" << g1.y()<< "|" <<g1.z() << std::endl; // une fonction membre ne nécessite pas de exam:: ou Gravity:: c'est implicite
  std::cout <<"g2 : "<<g2.x()<<"|" << g2.y()<< "|" <<g2.z() << std::endl;

  double normeg1{exam::magnitude(g1)};
  double normeg2{exam::magnitude(g2)};
  std::cout << "||g1|| = "<<normeg1<< "\n||g2|| = "<<normeg2<< std::endl;

  g2.reverse(); // g2 ne doit pas être const car nous le modifions
  std::cout <<"g2 : "<<g2.x()<<"|" << g2.y()<< "|" <<g2.z() << std::endl;

  exam::Gravity g3{exam::opposite(g1)};
  std::cout <<"g3 : "<<g3.x()<<"|" << g3.y()<< "|" <<g3.z() << "(-g1)" << std::endl; // une fonction membre ne nécessite pas de exam:: ou Gravity:: c'est implicite
  
  exam::Gravity g4;
  std::cout <<"g4 : "<<g4.x()<<"|" << g4.y()<< "|" <<g4.z() << std::endl;
  g4.setX(10.0);
  g4.setY(7.0);
  g4.setZ(3.0);
  std::cout <<"g4 : "<<g4<< std::endl; //surchage de l'opérateur
  

}

#endif


void
read(std::string title,
     const exam::Book &book) // ouch! a huge copy may occur here
{
  std::cout << title << ": " << book.word_count() << " words, "
                             << book.letter_count() << " letters\n";
  if(book.word_count())
  {
    std::cout << "    " << book.words().front() << " ... "
                        << book.words().back() << '\n';
  }
}


void test_book(){
  std::cout << "~~~~" << __func__ << "()~~~~"<<std::endl;
  exam::Book book1{1'000'000,20};
  read("after init, book1", book1);

  exam::Book book2= std::move(book1);
  read("after init, book2", book2);

  read("after init, book1", book1);

  book1= std::move(book2);
  read("after assign, book1", book1);
  read("after assign, book2", book2);

  
}

void test_schoolbag(){
  exam::Book english{{"one", "two",   "three",  "four",    "five",
                       "six", "seven", "height", "nine",    "ten"}};
  exam::Book italian{{"uno", "due",   "tre",    "quattro", "cinque",
                       "sei", "sette", "otto",   "nove",    "dieci"}};
  exam::SchoolBag bag1{std::move(english), std::move(italian)};
  #if 0
  exam::SchoolBag bag2{std::move(bag1)};
  exam::SchoolBag bag3;
  bag3=std::move(bag2);
  #else
  exam::SchoolBag bag2{bag1};
  exam::SchoolBag bag3;
  bag3=bag2;
  #endif
  read("english from bag1", bag1.english());
  read("italian from bag1", bag1.italian());
  read("english from bag2", bag2.english());
  read("italian from bag2", bag2.italian());
  read("english from bag3", bag3.english());
  read("italian from bag3", bag3.italian());
}


int main(int argc, char const *argv[])
{
	test_init();
  test_gravity();
  test_book();
  test_schoolbag();
	return 0;
}