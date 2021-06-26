#pragma once

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <size.h>
#include "brylawzorcowa.h"
#include "vector.h"
#include "matrix.h"
#include <fstream>


/*!
 * \file prostopadloscian.h
 * \brief  plik  zawiera  klase prostopadloscian
 *
 */



/*!
 * \brief  
 *  klasa dziedziczy po klasie brylawzorcowa
 *   klasa prostopadloscian sluzaca do modelowania korpusu drona
 *  
 */
 
class prostopadloscian: public brylawzorcowa

{
private:
     Vector<SIZE> wierzcholkiwzor[SIZE2];
  Vector<SIZE> wierzcholki[SIZE2];
public:
   /* prostopadloscian();
    ~prostopadloscian();*/
    void  zaladujwspwzor();
    void Przesunwierzcholki();
    void Obrocwierzcholki();
    void ustawpolozeniepoczatkowe(Vector<SIZE> polozeniepoczatkowe1);
    void zapiszwsp (const char* nazwaplikuzapisu);
    void przekazparametryprzesuniecia(Vector<SIZE> polozenie1, double kat );
    void przekazparametrykonstrukcji(  Vector<SIZE> skala1);
};

/*prostopadloscian::prostopadloscian()
{
}

prostopadloscian::~prostopadloscian()
{
}*/
/*!
*****************************************************************************
 | \brief Metoda klasy prostopadloscian.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      tabele wypelnione wartosciami z pliku .                                       |
 */
 void prostopadloscian::zaladujwspwzor (){
   int i;
std::fstream plik;
plik.open(nazwaplikuszescian,std::ios::in);
if (plik.good()==true)
{
for ( i = 0; i < SIZE2; i++)
     {
       
       plik>>wierzcholkiwzor[i];
       
       
     }
  
}
else {
  std::cout<<"nie mozna odczytac pliku"<<std::endl;
  exit(0);}
plik.close();
}
/*!
*****************************************************************************
 | \brief Metoda klasy prostopadloscian.                                                 |
 |  Argumenty:                                                                |
 |     nazwaplikuzapisu-nazwa pliku do ktorej zostana zapisane wspolrzedne prostopadlosciana                                                      |
 |      zapisuje do pliku wartosci z tabeli.                                       |
 */
void prostopadloscian::zapiszwsp (const char* nazwaplikuzapisu){

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
 | \brief Metoda klasy prostopadloscian.                                                 |
 |  Argumenty:    brak                                                            |                                                |
 |      oblicza wspolrzedne wierzcholkow prostopadlosciana                                     |
 */
void prostopadloscian::Przesunwierzcholki(){
  liczbawektorow++;
      calkowitaliczbawektorow++;
for ( int i = 0; i < SIZE2; i++)
     {
       
       wierzcholki[i]=wierzcholkiwzor[i]*skala+polozenie+polozeniepoczatkowe;
      
       
     }


}

/*!
*****************************************************************************
 | \brief Metoda klasy prostopadloscian.                                                 |
 |  Argumenty:    brak                                                            |                                                |
 |      oblicza wspolrzedne wierzcholkow prostopadlosciana z uwzglednieniem obroty                                    |
 */
void prostopadloscian::Obrocwierzcholki(){
calkowitaliczbawektorow++;
Matrix<SIZE> macierz=Matrix<SIZE>('z',katorient);

for ( int i = 0; i < SIZE2; i++)
     {
       
       wierzcholki[i]=macierz*(wierzcholkiwzor[i]*skala)+polozenie+polozeniepoczatkowe;
         
       
     }



}


/*!
*****************************************************************************
 | \brief Metoda klasy prostopadloscian.                                                 |
 |  Argumenty:    przesunieciewzgkorpusu-przesuniecie rotora wzg korpusu
|                                                |
 |     przekazuje parametry konstrukcji                                    |
 */
void prostopadloscian::przekazparametrykonstrukcji( Vector<SIZE> skala1){

skala=skala1;
}

/*!
*****************************************************************************
 | \brief Metoda klasy prostopadloscian.                                                 |
 |  Argumenty:    
  | polozenie1 aktualne przesuniecie od polozenia poczatkowego    
|   kat - aktualna wartosc kata
 |      przekazuje wspolrzedne polozenia i kata                                     |
 */
void prostopadloscian::przekazparametryprzesuniecia(Vector<SIZE> polozenie1, double kat ){
polozenie=polozenie1;
katorient=kat;
}

/*!
*****************************************************************************
 | \brief Metoda klasy prostopadloscian.                                                 |
 |  Argumenty:    
  | polozeniepoczatkowe aktualne  polozenie poczatkowe    |
 |      przekazuje wspolrzedne polozenia poczatkowego                                     |
 */
void prostopadloscian::ustawpolozeniepoczatkowe(Vector<SIZE> polozeniepoczatkowe1){

polozeniepoczatkowe=polozeniepoczatkowe1;


}