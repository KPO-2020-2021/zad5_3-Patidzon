#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cassert>
#include <unistd.h>
#include "lacze_do_gnuplota.hh"
#include "size.h"
#include "dron.h"
#include "brylawzorcowa.h"
#include "vector.h"
#include "prostopadloscian.h"
#include "graniastoslup.h"
#include "matrix.h"
#include <cstdlib>
#include "przeszkoda.h"
#include <list>
#include <memory>
#include <algorithm>
//#include "przeszkoda.h"
/*!
 * \file scena.h
 * \brief  plik  zawiera  klase scena
 *
 */



/*!
 * \brief  
 *  
 *  klasa zawiera list shared pointerow oraz metody dodawania i usuwania z niej
 *  
 */
class scena
{
private:
    //dron drony[2];
 std::list<std::shared_ptr<przeszkoda>> Lst1;
  std::list<std::shared_ptr<dron>> Lst2;
public:
//void wybierzdrona(int nrdrona);
    scena(/* args */);
    ~scena();
void dodajprzeszkode(PzG::LaczeDoGNUPlota &Lacze);    
void usunprzeszkode(PzG::LaczeDoGNUPlota &Lacze);
void dodajdrona(int nr); 
void animujdrona(PzG::LaczeDoGNUPlota  &Lacze,int nr);
 void animacjalotu(PzG::LaczeDoGNUPlota  Lacze,int nr);
};

scena::scena(/* args */)
{
}

scena::~scena()
{
}


/*!
*****************************************************************************
 | \brief Metoda klasy scena.  |
   |         dodaje przeszkode  do listy shared pointerow                                 |
 |  Argumenty:                                                                |
 |   Lacze-lacze do gnuplota                                                      |
 */
void scena::dodajprzeszkode(PzG::LaczeDoGNUPlota &Lacze){
  //std::shared_ptr<przeszkoda> przeszkoda1=std::make_shared<przeszkoda>(nazwaplikuzapisu,Lacze);
  Lst1.push_back(std::make_shared<przeszkoda>(Nazwyplikowzapisuprzeszkod[nrprzeszkody],Lacze,nrprzeszkody));
  nrprzeszkody++;
}


/*!
*****************************************************************************
 | \brief Metoda klasy scena.  |
   |         usuwa przeszkode  do listy shared pointerow  wczesniej wyświetlajac liste obiektow                            |
 |  Argumenty:                                                                |
 |   Lacze-lacze do gnuplota                                                      |
 */
void scena::usunprzeszkode(PzG::LaczeDoGNUPlota &Lacze){
    int i=1,j,k=1;
    //std::list<std::shared_ptr<przeszkoda>>:: iterator it;
    for (auto it = Lst1.begin(); it !=Lst1.end(); it++ ){     
std::cout<<i<<" ";
(*it)->podajparametry();
i++;
    }

std::cout<<"Podaj nr przeszkody do usuniecia"<<std::endl;
 std::cin>>j;
 auto it=Lst1.begin();
 while (j>k)
 {
    it++;
    k++;
 }
 
 Lst1.erase(it); 
 j=(*it)->podajnr();
Lacze.UsunNazwePliku(Nazwyplikowzapisuprzeszkod[j]); 
i=1;
for (auto it = Lst1.begin(); it !=Lst1.end(); it++ ){       
std::cout<<i<<" ";
(*it)->podajparametry();
i++;
    }

}

void scena::dodajdrona(int nr){
 Lst2.push_back(std::make_shared<dron>(nr));

}

void scena::animujdrona(PzG::LaczeDoGNUPlota &Lacze,int nr){
auto it=Lst2.begin();
if (nr==1)
{
 it++;
}

(*it)->animacjalotu(Lacze);


}


/*!
*****************************************************************************
 | \brief Metoda klasy dron.                                                 |
 |     animuje przelot drona dla gnuplota                                |
 */
void scena::animacjalotu(PzG::LaczeDoGNUPlota  Lacze,int nr){

  auto it=Lst2.begin();
if (nr==1)
{
 it++;
}
  int kat=1,katbackup=(*it)->podajkat();
  int katorient=(*it)->podajkat();

  Vector<SIZE> polozeniepoczatkowe=(*it)->podajpolozeniepoczatkowe();
  double dlugosclotu;
  Vector<SIZE> V4=argumentsV10;
  Vector<SIZE> V12=V3;
  Vector<SIZE> V6;
   //Vector<SIZE> V11=V3;
   
  while ((kat%5)!=0)
  {
     std::cout<<"podaj kat obrotu drona(wielokrotnosc 5"<<std::endl;
  std::cin>>kat;
  }
  std::cout<<"podaj dlugosc lotu"<<std::endl;
  std::cin>>dlugosclotu;
  (*it)->DodajTrasePrzelotu(Lacze,kat,dlugosclotu);
 /*wznoszenie*/
  for (int i = 0; i < 100; i=i+2)
  { 
     V4=V4+V12;
    (*it)->ustawparametry(V4,katbackup);
  
    (*it)->obrocdron();
    usleep(100000); // 0.1 ms
    Lacze.Rysuj();

  }
  /*obracanie*/
  if (kat>=0)
  {
      for (int i=0; i <= kat; i+= 5) {
    (*it)->ustawparametry(V4,katbackup+i);
   (*it)->obrocdron();
    usleep(100000);
    Lacze.Rysuj();
  }
  }
  else
  {
         std::cout << "kat ujemny ... " << std::endl;
  for (int i=0; i >= kat; i-= 5) {
    (*it)->ustawparametry(V4,katbackup+i);
   (*it)->obrocdron();
    usleep(100000);
    Lacze.Rysuj();
  }
  }
  

/*przelot*/
katorient=(*it)->podajkat();
  Matrix<SIZE> macierz2=Matrix<SIZE>('z',katorient);
    V6=macierz2*V5;
  for (int i=0; i <= dlugosclotu; i+= 1) {
 
    V4=V4+V6;
    (*it)->ustawparametry(V4,katorient);
   (*it)->obrocdron();
    usleep(100000);
    Lacze.Rysuj();
  }
/*opadanie*/
    for (int i = 100; i > 0; i=i-2)
  {
     V4=V4-V12;
    (*it)->ustawparametry(V4,katorient);
    (*it)->obrocdron();
    usleep(100000); // 0.1 ms
    Lacze.Rysuj();
  }   
    Vector<SIZE> polozenie=(*it)->podajpolozenie();
  (*it)->ustawpolozeniepoczatkowe((polozenie+polozeniepoczatkowe));
    Lacze.UsunNazwePliku(PLIK_TRASY_PRZELOTU);
  Lacze.Rysuj();
}

