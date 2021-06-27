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
//#include "prostopadloscian.h"
#include "graniastoslup.h"
//#include "scena.h"
#include "matrix.h"
#include <cstdlib>


/*!
 * \file scena.h
 * \brief  plik  zawiera  klase przeszkoda
 *
 */



/*!
 * \brief  
 *  
 *  klasa zawiera metody i atrybuty sluzace do stworzenia przeszkody
 *  
 */
class przeszkoda: public brylawzorcowa
{
private:
  Vector<SIZE> wierzcholkiwzor[SIZE2];
  Vector<SIZE> wierzcholki[SIZE2];
  const char* nazwa;
 int nrprzeszkody1;
public:
    przeszkoda(const char* nazwaplikuzapisu,PzG::LaczeDoGNUPlota &Lacze, int nr);
    ~przeszkoda();
   void tworzgorezostrymszczytem(const char* nazwaplikuzapisu,PzG::LaczeDoGNUPlota &Lacze);
   void tworzgorezdlugagrania(const char* nazwaplikuzapisu,PzG::LaczeDoGNUPlota &Lacze);
   void tworzplaskowyz(const char* nazwaplikuzapisu,PzG::LaczeDoGNUPlota &Lacze);
   void  zaladujwspwzor();
   void zapiszwsp (const char* nazwaplikuzapisu);
   void  podajparametry()const;
   int podajnr();

   //const const char* &WezNazwe()const{return nazwa;}
};

przeszkoda::przeszkoda(const char* nazwaplikuzapisu,PzG::LaczeDoGNUPlota &Lacze,int nr)
{int z;
std::cout<<"1-tworz plaskowyrz "<<std::endl
<<"2-tworz gore z dluga grania"<<std::endl
<<"3-tworz gore z ostrym szczytem"<<std::endl;
std::cin>>z;
nrprzeszkody1=nr;
  liczbawektorow++;
      calkowitaliczbawektorow++;
switch (z)
{
case 1:
  tworzplaskowyz(nazwaplikuzapisu,Lacze);
  break;
case 2:
  tworzgorezdlugagrania(nazwaplikuzapisu,Lacze);
  break;
  case 3:
  tworzgorezostrymszczytem(nazwaplikuzapisu,Lacze);
  break;
default:
std::cout<<" Nie poprawna opcja "<<std::endl;
  break;
}

}

przeszkoda::~przeszkoda()
{std::cout<<"destruktor przeszkody"<<std::endl;
  liczbawektorow--;
}
/*!
*****************************************************************************
 | \brief Metoda klasy przeszkoda.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      tablice wektorow wypelnione wartosciami z pliku .                                       |
 */
 void przeszkoda::zaladujwspwzor (){
   int i;
std::fstream plik;
plik.open(nazwaplikuszescian,std::ios::in);
if (plik.good()==true)
{
for ( i = 0; i < SIZE2; i++)
     {
       
       plik>>wierzcholkiwzor[i];
       //std::cout<<wierzcholkiwzor[i];
       
     }
  
}
else {
  std::cout<<"nie mozna odczytac pliku"<<std::endl;
  exit(0);}
plik.close();
}


/*!
*****************************************************************************
 | \brief Metoda klasy przeszkoda.                                                 |
 |  Argumenty:                                                                |
 |     nazwaplikuzapisu-nazwa pliku do ktorej zostana zapisane wspolrzedne przeszkodaa                                                      |
 |      zapisuje do pliku wartosci z tablicy.                                       |
 */
void przeszkoda::zapiszwsp (const char* nazwaplikuzapisu){

int i;
std::ofstream plik;
plik.open(nazwaplikuzapisu,std::ios::out);
if (plik.good()==true)
{
for ( i = 0; i <SIZE2; i++)
     {
       
       plik<<wierzcholki[i]<<std::endl;
      i++;
      plik<<wierzcholki[i]<<std::endl;
      i++;
      plik<<wierzcholki[i]<<std::endl;
      i++;
       plik<<wierzcholki[i]<<std::endl<<std::endl;
       
     }
  
}
else {
  std::cout<<"nie mozna odczytac pliku"<<std::endl;
  exit(0);}
plik.close();
  }



/*!
*****************************************************************************
 | \brief Metoda klasy przeszkoda.  |
   |         tworzy plaskowyrz                                    |
 |  Argumenty:                                                                |
 |     nazwaplikuzapisu-nazwa pliku do ktorej zostana zapisane wspolrzedne przeszkody|
 |   Lacze-lacze do gnuplota                                                      |
 |      zapisuje do pliku wartosci z tablicy.                                       |
 */
void przeszkoda::tworzplaskowyz(const char* nazwaplikuzapisu,PzG::LaczeDoGNUPlota &Lacze){
zaladujwspwzor();
double z,y,x;
//Vector<SIZE> skala1;
nazwa="plaskowyrz";
std::cout<<"Podaj skale przeszkody"<<std::endl;
std::cin>>skala;
std::cout<<"Podaj przesuniecie poczatkowe przeszkody"<<std::endl;
std::cin>>x>>y;
z=skala[2]*0.5;
double tmptabela[]={x,y,z};
 polozeniepoczatkowe=tmptabela;
for ( int i = 0; i < SIZE2; i++)
     {
       
       wierzcholki[i]=wierzcholkiwzor[i]*skala+polozeniepoczatkowe;
      
       
     }

zapiszwsp(nazwaplikuzapisu);
  Lacze.DodajNazwePliku(nazwaplikuzapisu);

} 

/*!
*****************************************************************************
 | \brief Metoda klasy przeszkoda.  |
   |         tworzy gore z dluga grania                                    |
 |  Argumenty:                                                                |
 |     nazwaplikuzapisu-nazwa pliku do ktorej zostana zapisane wspolrzedne przeszkody|
 |   Lacze-lacze do gnuplota                                                      |
 |      zapisuje do pliku wartosci z tablicy.                                       |
 */
void przeszkoda::tworzgorezdlugagrania(const char* nazwaplikuzapisu,PzG::LaczeDoGNUPlota &Lacze){
zaladujwspwzor();
double z,y,x;
nazwa="gora z dluga grania";
std::cout<<"Podaj skale przeszkody"<<std::endl;
std::cin>>skala;
std::cout<<"Podaj przesuniecie poczatkowe przeszkody"<<std::endl;
std::cin>>x>>y;
z=skala[2]*0.5;
double tmptabela[]={x,y,z};
 polozeniepoczatkowe=tmptabela;
for ( int i = 0; i < SIZE2; i++)
     { 
           if ( wierzcholkiwzor[i][2]>=0.5) { // Tutaj realizowana jest deformacja
	if ( wierzcholkiwzor[i][0] <= 0)  wierzcholkiwzor[i][0] = fabs( wierzcholkiwzor[i][0]);
      }
      /* std::cout<<wierzcholkiwzor[i]<<std::endl;
       wierzcholkiwzor[i][0]=wierzcholkiwzor[i][0]*10;
        std::cout<<wierzcholkiwzor[i]<<std::endl;*/
       wierzcholki[i]=wierzcholkiwzor[i]*skala+polozeniepoczatkowe;
       
     }

zapiszwsp(nazwaplikuzapisu);
  Lacze.DodajNazwePliku(nazwaplikuzapisu);
}


/*!
*****************************************************************************
 | \brief Metoda klasy przeszkoda.  |
   |         tworzy gore z ostrym szczytem                                    |
 |  Argumenty:                                                                |
 |     nazwaplikuzapisu-nazwa pliku do ktorej zostana zapisane wspolrzedne przeszkody|
 |   Lacze-lacze do gnuplota                                                      |
 |      zapisuje do pliku wartosci z tablicy.                                       |
 */
void przeszkoda::tworzgorezostrymszczytem(const char* nazwaplikuzapisu,PzG::LaczeDoGNUPlota &Lacze){
//double z;
zaladujwspwzor();
double z,y,x;
nazwa="gora z ostrym szczytem";
std::cout<<"Podaj skale przeszkody"<<std::endl;
std::cin>>skala;
std::cout<<"Podaj przesuniecie poczatkowe przeszkody"<<std::endl;
std::cin>>x>>y;
z=skala[2]*0.5;
double tmptabela[]={x,y,z};
 polozeniepoczatkowe=tmptabela;
for ( int i = 0; i < SIZE2; i++)
     {
       //z=wierzcholkiwzor[i][2];
         if (wierzcholkiwzor[i][2]>=0.5) { // Tutaj realizowana jest deformacja
	  wierzcholkiwzor[i][0]= wierzcholkiwzor[i][1] = 0;
      } else if (wierzcholkiwzor[i][2]== 0.5) {
          wierzcholkiwzor[i][0] /= 2;  wierzcholkiwzor[i][1] /= 2;
      }
       wierzcholki[i]=wierzcholkiwzor[i]*skala+polozeniepoczatkowe;
       
     }

zapiszwsp(nazwaplikuzapisu);
  Lacze.DodajNazwePliku(nazwaplikuzapisu);


}
/*!
*****************************************************************************
 | \brief Metoda klasy przeszkoda.  |
|       zwraca parametry nazwy i polozenia                                         |                                 
 */
void przeszkoda::podajparametry()const{
std::cout<<" "<<nazwa<<" "<<polozeniepoczatkowe<<std::endl;
//std::cout<<" test "<<std::endl;
}

/*!
*****************************************************************************
 | \brief Metoda klasy przeszkoda.  |
|       zwraca numer przeszkody                                       |                                 
 */
int przeszkoda::podajnr(){
  return nrprzeszkody1;
}