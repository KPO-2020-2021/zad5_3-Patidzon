#pragma once

#include <iostream>
#include <cmath>
#include <size.h>
#include "brylawzorcowa.h"
#include "vector.h"
#include "prostopadloscian.h"
#include "graniastoslup.h"
#include <cstdlib>
#include "matrix.h"
#include <fstream>
#include <cassert>
#include <unistd.h>
#include <iomanip>
#include "lacze_do_gnuplota.hh"


/*!
 * \file dron.h
 * \brief  plik  zawiera  klase dron
 *
 */



/*!
 * \brief  
 * klasa niezbedne metody i pola wartosci aby modelowac drona
 *  
 *  
 */
class dron
{
private:
    prostopadloscian korpus;
    graniastoslup rotory[4];
    double katorient=0;
    Vector<SIZE> polozenie=V1;
     Vector<SIZE> polozeniepoczatkowe;
    Vector<SIZE> skalarotor=skalarotor1;
    Vector<SIZE> skalakorpus=skalakorpus1;
    Vector<SIZE> polozenierotorow[4]={wek1,wek2,wek3,wek4};
    int nrdrona;
public:
  dron(int nr);
  void  tworzdrona(int nr);
  void  przemiescdron(/*Vector<SIZE> przesuniecie*/);
 
  void  lotzwiadowczy(PzG::LaczeDoGNUPlota  Lacze);//nie dziala poprawnie
  void  ustawparametry(Vector<SIZE> polozenie2, double kat);//ustawia parametry obrotu
  void ustawpolozeniepoczatkowe(Vector<SIZE> polozeniepoczatkowe1);//ustawia polozenie poczatkowe
  void przesundron();//przesuwa drona bez rotacji
  void obrocdron();// obraca drona z uwzglednieniem rotacji 
  void animacjalotu(PzG::LaczeDoGNUPlota  Lacze);//tworzy animacje lotu dla gnuplota
  void DodajTrasePrzelotu(PzG::LaczeDoGNUPlota &Lacze,int kat,double dlugosclotu);//dodaje trase przelotu
};


dron::dron(int nr){
tworzdrona(nr);

}
/*!
*****************************************************************************
 | \brief Metoda klasy dron.                                                 |
 |  Argumenty:    |
|   nr-numer drona |
 |     tworzy drona w oparciu o jego numer nr i wbudowane przesuniecie                                     |
 */
void dron::tworzdrona(int nr){
  Vector<SIZE> V11=V3;
  nrdrona=nr;
  int j=0;
  polozeniepoczatkowe=V2*(nr+1); 
  ustawparametry(V1,0);
for (unsigned int Idx = 0; NazwyPlikowWlasciwychrotory[nrdrona][Idx] != nullptr; ++Idx) 
{
 rotory[Idx].przekazparametrykonstrukcji(polozenierotorow[j],skalarotor);
 rotory[Idx].ustawpolozeniepoczatkowe(V2);
 rotory[Idx].zaladujwspwzor();
 rotory[Idx].Przesunwierzcholki();
 rotory[Idx].zapiszwsp(NazwyPlikowWlasciwychrotory[nrdrona][Idx]);

 j++;

}
for (unsigned int Idx = 0; NazwyPlikowWlasciwychkorpusy[nrdrona][Idx] != nullptr; ++Idx) {
 korpus.przekazparametrykonstrukcji(skalakorpus);
 korpus.ustawpolozeniepoczatkowe(V2+V11);
 V2-V11;
 std::cout<<V2<<V11<<std::endl;
 korpus.zaladujwspwzor();
 korpus.Przesunwierzcholki();
 korpus.zapiszwsp(NazwyPlikowWlasciwychkorpusy[nrdrona][Idx]);
}
}


/*!
*****************************************************************************
 | \brief Metoda klasy dron.                                                 |
 |  Argumenty:    |
|   polozenie2-aktualne przesuniecie |
|   kat aktualny kat |
 |     przekazuje parametry dronowi                                    |
 */
void dron::ustawparametry(Vector<SIZE> polozenie2, double kat){
polozenie=polozenie2;
katorient=kat;
}  


/*!
*****************************************************************************
 | \brief Metoda klasy dron.                                                 |
 |  Argumenty:    |
|   polozeniepoczatkowe1-ustawaia polozenie poczatkowe |
 |     przekazuje parametry dronowi                                    |
 */
void dron::ustawpolozeniepoczatkowe(Vector<SIZE> polozeniepoczatkowe1){
polozeniepoczatkowe=polozeniepoczatkowe1;
 Vector<SIZE> V14=V3;

  for (unsigned int Idx = 0; NazwyPlikowWlasciwychkorpusy[nrdrona][Idx] != nullptr; ++Idx)
{
korpus.ustawpolozeniepoczatkowe(polozeniepoczatkowe);
}
polozeniepoczatkowe1-V14;
  for (unsigned int Idx = 0; NazwyPlikowWlasciwychrotory[nrdrona][Idx] != nullptr; ++Idx) 
{
  rotory[Idx].ustawpolozeniepoczatkowe(polozeniepoczatkowe1);
}


}
/*!
*****************************************************************************
 | \brief Metoda klasy dron.                                                 |
 |     przesuwa drona do nowych wspolrzednych drona                                 |
 */
void dron::przesundron(){
for (unsigned int Idx = 0; NazwyPlikowWlasciwychrotory[nrdrona][Idx] != nullptr; ++Idx) 
{
 rotory[Idx].przekazparametryprzesuniecia(polozenie,katorient);
 rotory[Idx].zaladujwspwzor();
 rotory[Idx].Przesunwierzcholki();
 rotory[Idx].zapiszwsp(NazwyPlikowWlasciwychrotory[nrdrona][Idx]);
}
for (unsigned int Idx = 0; NazwyPlikowWlasciwychkorpusy[nrdrona][Idx] != nullptr; ++Idx) {

 korpus.przekazparametryprzesuniecia(polozenie,katorient);
 korpus.zaladujwspwzor();
 korpus.Przesunwierzcholki();
korpus.zapiszwsp(NazwyPlikowWlasciwychkorpusy[nrdrona][Idx]);
  
}
}


/*!
*****************************************************************************
 | \brief Metoda klasy dron.                                                 |
 |     przesuwa i obraca drona do nowych wspolrzednych drona                                 |
 */
void dron::obrocdron(){
    
for (unsigned int Idx = 0; NazwyPlikowWlasciwychrotory[nrdrona][Idx] != nullptr; ++Idx) 
{
 rotory[Idx].przekazparametryprzesuniecia(polozenie,katorient);
 rotory[Idx].zaladujwspwzor();
 rotory[Idx].Obrocwierzcholki();
 rotory[Idx].zapiszwsp(NazwyPlikowWlasciwychrotory[nrdrona][Idx]);
}
for (unsigned int Idx = 0; NazwyPlikowWlasciwychkorpusy[nrdrona][Idx] != nullptr; ++Idx) {

 korpus.przekazparametryprzesuniecia(polozenie,katorient);
 korpus.zaladujwspwzor();
 korpus.Obrocwierzcholki();
 korpus.zapiszwsp(NazwyPlikowWlasciwychkorpusy[nrdrona][Idx]);
}



}
/*!
*****************************************************************************
 | \brief Metoda klasy dron.                                                 |
 |     animuje przelot drona dla gnuplota                                |
 */
void dron::animacjalotu(PzG::LaczeDoGNUPlota  Lacze){
  int kat=1,katbackup=katorient;
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
  DodajTrasePrzelotu(Lacze,kat,dlugosclotu);
 /*wznoszenie*/
  for (int i = 0; i < 100; i=i+2)
  { 
     V4=V4+V12;
    ustawparametry(V4,katbackup);
  
    obrocdron();
    usleep(100000); // 0.1 ms
    Lacze.Rysuj();

  }
  /*obracanie*/
  if (kat>=0)
  {
      for (int i=0; i <= kat; i+= 5) {
    ustawparametry(V4,katbackup+i);
   obrocdron();
    usleep(100000);
    Lacze.Rysuj();
  }
  }
  else
  {
         std::cout << "kat ujemny ... " << std::endl;
  for (int i=0; i >= kat; i-= 5) {
    ustawparametry(V4,katbackup+i);
   obrocdron();
    usleep(100000);
    Lacze.Rysuj();
  }
  }
  

/*przelot*/
  Matrix<SIZE> macierz2=Matrix<SIZE>('z',katorient);
    V6=macierz2*V5;
  for (int i=0; i <= dlugosclotu; i+= 1) {
 
    V4=V4+V6;
    ustawparametry(V4,katorient);
   obrocdron();
    usleep(100000);
    Lacze.Rysuj();
  }
/*opadanie*/
    for (int i = 100; i > 0; i=i-2)
  {
     V4=V4-V12;
    ustawparametry(V4,katorient);
    obrocdron();
    usleep(100000); // 0.1 ms
    Lacze.Rysuj();
  }   
  ustawpolozeniepoczatkowe((polozenie+polozeniepoczatkowe));
    Lacze.UsunNazwePliku(PLIK_TRASY_PRZELOTU);
  Lacze.Rysuj();
}




/*!
*****************************************************************************
 | \brief Metoda klasy dron.    Nie dziala                                             |
 |    animuje lot zwiadowczy drona                                |
 */
void dron::lotzwiadowczy(PzG::LaczeDoGNUPlota  Lacze){
  Vector<SIZE> V6;
    int kat=60,katbackup=katorient;
  double dlugosclotu=50;
  Vector<SIZE> V4=argumentsV10;
  for (int i = 0; i < 100; i=i+2)
  { 
     V4=V4+V3;
    ustawparametry(V4,katbackup);
  
    obrocdron();
    usleep(100000); // 0.1 ms
    Lacze.Rysuj();
  }
      Matrix<SIZE> macierz2=Matrix<SIZE>('z',katorient);
    V6=macierz2*V5;
  for (int i=0; i <= dlugosclotu; i+= 1) {
 
    V4=V4+V6;
    ustawparametry(V4,katorient);
   obrocdron();
    usleep(100000);
    Lacze.Rysuj();
  }
  katbackup=katorient;

  
    for (int i=0; i <= kat; i+= 5) {
    ustawparametry(V4,katbackup+i);
   obrocdron();
    usleep(100000);
    Lacze.Rysuj();
  }
   katbackup=katorient;
   Matrix<SIZE> macierz3=Matrix<SIZE>('z',katorient);
    V6=macierz3*V5;
  
  for (int j = 0; j < 5; j++)
  {
      for (int i=0; i <= kat; i+= 5) {
    ustawparametry(V4,katbackup+i);
   obrocdron();
    usleep(100000);
    Lacze.Rysuj();
  }
  V6=macierz3*V6;
   katbackup=katorient;
  for (int i=0; i <= dlugosclotu; i+= 1) {
 
    V4=V4+V6;
    ustawparametry(V4,katorient);
   obrocdron();
    usleep(100000);
    Lacze.Rysuj();}
  


  }
  



}

/*!
*****************************************************************************
 | \brief Metoda klasy dron.                                                 |
  |   atgumenty:                             |
   |    kat -kat obrotu podawany przez uzytkownika                            |
   |   dlugosclotu -dlugosc lotu podawana przez uzytkownika                            |
 |    rysuje trase przelotu drona dla gnuplota                         |
 */
void dron::DodajTrasePrzelotu(PzG::LaczeDoGNUPlota &Lacze, int kat,double dlugosclotu)
{ Vector<SIZE> tmp=polozeniepoczatkowe;
  Vector<SIZE> V6,V7=V3;
  std::ofstream  StrmWy(PLIK_TRASY_PRZELOTU);

  if (!StrmWy.is_open()) {
    std::cerr << std::endl
	 << " Nie mozna otworzyc do zapisu pliku: " << PLIK_TRASY_PRZELOTU << std::endl
	 << std::endl;
    exit(0);
  }

  StrmWy <<tmp<< std::endl;
  tmp=tmp+(V7*50);
  
	 StrmWy <<tmp<< std::endl;
	 Matrix<SIZE> macierz3=Matrix<SIZE>('z',katorient+kat);
    V6=macierz3*V5;
  tmp=tmp+(V6*dlugosclotu);
   StrmWy <<tmp<< std::endl;
   V7=V3;
   std::cout<<V7;
   tmp=tmp-(V7*50);
   StrmWy <<tmp<< std::endl;
  Lacze.DodajNazwePliku(PLIK_TRASY_PRZELOTU);
 
}