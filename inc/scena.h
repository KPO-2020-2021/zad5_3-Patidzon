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
public:
//void wybierzdrona(int nrdrona);
    scena(/* args */);
    ~scena();
void dodajprzeszkode(PzG::LaczeDoGNUPlota &Lacze);    
void usunprzeszkode(PzG::LaczeDoGNUPlota &Lacze);    
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