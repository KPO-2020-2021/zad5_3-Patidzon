/*!
 * \file
 * \brief Przykład animacji przelotu drona
 *
 * Przykład ten ma tylko i wyłącznie za zadanie pokazanie efektów animacji lotu
 * drona. Kod w nim zawarty nie jest pisany w sposób obiektowo zorientowany.
 * Dlatego też nie należy wzorować się na nim.
 * Niemniej można się wzorować na ciągu operacji, które należy wykonać,
 * aby otrzymać właściwą animację.
 */
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "../tests/doctest/doctest.h"
#endif

#include "exampleConfig.h"
#include "example.h"

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
#include "scena.h"
#include "matrix.h"
#include <cstdlib>
#include "przeszkoda.h"
#include <list>
#include <memory>
using namespace std;





/*

#define ILOSC_WIERZCHOLKOW_GRANIATOSLUPA  6
#define PROMIEN_PODSTAWY                  10
#define GRUBOSC_ROTORA                    5.0
*/


#define ILOSC_WIERZ_LINII_TWORZACEJ            4

#define PLIK_WZORCOWEGO_SZESCIANU       "../bryly_wzorcowe/szescian.dat"
#define PLIK_WZORCOWEGO_GRANIASTOSLUPA6 "../bryly_wzorcowe/graniastoslup6.dat"
#define PLIK_KORPUSU_DRONA1             "../dat/korpus_drana1.dat"









int main()
{  char z='a';
   int nr=0;

  PzG::LaczeDoGNUPlota  Lacze;
  

  Lacze.DodajNazwePliku("../bryly_wzorcowe/plaszczyzna.dat");
  Lacze.DodajNazwePliku(PLIK_WLASCIWY__DRON1_KORPUS);
  Lacze.DodajNazwePliku(PLIK_WLASCIWY__DRON1_ROTOR1);
  Lacze.DodajNazwePliku(PLIK_WLASCIWY__DRON1_ROTOR2);
  Lacze.DodajNazwePliku(PLIK_WLASCIWY__DRON1_ROTOR3);
  Lacze.DodajNazwePliku(PLIK_WLASCIWY__DRON1_ROTOR4);
    Lacze.DodajNazwePliku(PLIK_WLASCIWY__DRON2_KORPUS);
  Lacze.DodajNazwePliku(PLIK_WLASCIWY__DRON2_ROTOR1);
  Lacze.DodajNazwePliku(PLIK_WLASCIWY__DRON2_ROTOR2);
  Lacze.DodajNazwePliku(PLIK_WLASCIWY__DRON2_ROTOR3);
  Lacze.DodajNazwePliku(PLIK_WLASCIWY__DRON2_ROTOR4);

  Lacze.ZmienTrybRys(PzG::TR_3D);
  Lacze.Inicjalizuj();  // Tutaj startuje gnuplot.

  Lacze.UstawZakresX(0, 200);
  Lacze.UstawZakresY(0, 200);
  Lacze.UstawZakresZ(0, 120);


  scena scena1;
  dron dron[3];
  dron[0].tworzdrona(0);
  dron[1].tworzdrona(1);
   Lacze.Rysuj();
  scena1.dodajprzeszkode(Lacze);
   Lacze.Rysuj();
    scena1.dodajprzeszkode(Lacze);
     Lacze.Rysuj();
    scena1.dodajprzeszkode(Lacze);
     Lacze.Rysuj();

  Lacze.Rysuj();


   std::cout<<"dron 1 to ten blizej poczatku ukladu wspolrzednych"<<std::endl;
while (z!='k')
{std::cout<<""<<std::endl
<<"l lec dronem na wskazana odleglosc"<<std::endl
<<"d zmien drona"<<std::endl
//<<"z lot zwiadowczy"<<std::endl
<<"p dodaj przeszkode"<<std::endl
<<"u usun przeszkode"<<std::endl
<<"k koniec"<<std::endl
<<"aktywny dron to "<<nr+1<<std::endl
<<"aktualna liczba wektorow "<<liczbawektorow<<std::endl
<<"calkowita liczba wektorow "<<calkowitaliczbawektorow<<std::endl;

  std::cin>>z;
  switch (z)
  { case 'l':
  dron[nr].animacjalotu(Lacze);
  break;
  /*case 'z':
  dron[nr].lotzwiadowczy(Lacze);
  break;*/
   case 'd':
  if (nr==0)
  {
    nr=1;
  }
  else
  {
    nr=0;
  }
  
  break;
  case 'p':
  scena1.dodajprzeszkode(Lacze);
  Lacze.Rysuj();
  break;
   case 'u':
  scena1.usunprzeszkode(Lacze);
   Lacze.Rysuj();
  break;
  default:
  if (z!='k')
  {
    std::cout<<"nie poprawna opcja"<<std::endl;
  }
  

    break;
  }
}

  
}
