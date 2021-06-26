#pragma once

#include <iostream>
#include <cmath>
#include <size.h>
#include "vector.h"

/*!
 * \file brylawzorcowa.h
 * \brief  plik  zawiera  definicje klasy brylawzorcowa
 *
 */



/*!
 * \brief  
 *
 *  klasa zawiera lokalizacje plikow z wspolrzednymi bryl wzorcowych
 *  oraz parametry wspolne dla klas z niej dziedziczacych
 */
class brylawzorcowa
{
protected:
   const char* nazwaplikuszescian="../bryly_wzorcowe/szescian.dat";
  const char* nazwaplikugraniastoslup="../bryly_wzorcowe/graniastoslup6.dat";
  Vector<SIZE> skala;
    double katorient=0;
   Vector<SIZE> polozenie=V1;
    Vector<SIZE> polozeniepoczatkowe;
public:
  
};

