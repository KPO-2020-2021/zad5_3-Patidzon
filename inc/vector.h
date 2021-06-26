#pragma once

#include <iostream>
#include <cmath>
#include <size.h>

/*!
 * \file vector.h
 * \brief Ten plik zawiera definicje szablonu Wektor<>
 *
 */

/*!
 * \brief szablon klasy wektor
 * 
 *  Modeluje tablice wartosci sluzaca do przechowywania wspolrzednych wektora
 *  wykorzystywany rowniez do zapisu poszczegolnych punktow w prostopadloscianie 
 */
template <int SIZE>
class Vector {

private:

    double size[SIZE];     //Tablica wektora

public:

    Vector();

    Vector(double [SIZE]);

    Vector<SIZE> operator + (const Vector<SIZE> &v);

    Vector< SIZE> operator - (const Vector< SIZE> &v);

    Vector< SIZE> operator * (const double &tmp);
     Vector< SIZE> operator * (const Vector<SIZE> &v);

    Vector< SIZE> operator / (const double &tmp);
    bool operator == (Vector< SIZE> tmp)const;

    const double &operator [] (int index) const;

    double &operator [] (int index);
    double dlugosc()const; 
};
template <int SIZE>
std::ostream &operator << (std::ostream &out, Vector<SIZE> const &tmp);
template <int SIZE>
std::istream &operator >> (std::istream &in, Vector<SIZE> &tmp);

/*!
*****************************************************************************
 | \brief Konstruktor klasy Vector.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Tablice wypelniona wartoscia 0.                                       |
 */
template <int SIZE>
Vector< SIZE>::Vector() {
    for (int i = 0; i < SIZE; ++i) {
        size[i] = 0;
    }
}


/*!
*****************************************************************************
 | \brief Konstruktor klasy Vector.                                                 |
 |  Argumenty:                                                                |
 |      tmp - Jednowymiarowa tablica typu double.                             |
 |  Zwraca:                                                                   |
 |      Tablice wypelniona wartosciami podanymi w argumencie.                 |
 */
template <int SIZE>
Vector< SIZE>::Vector(double tmp[SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        size[i] = tmp[i];
    }
}


/*!
*****************************************************************************
 | \brief Realizuje dodawanie dwoch wektorow.                                       |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik dodawania,                                   |
 |      v - drugi skladnik dodawania.                                         |
 |  Zwraca:                                                                   |
 |      Sume dwoch skladnikow przekazanych jako wskaznik                      |
 |      na parametr.                                                          |
 */
template <int SIZE>
Vector< SIZE> Vector< SIZE>::operator + (const Vector< SIZE> &v) {
    Vector result;
    for (int i = 0; i < SIZE; ++i) {
        result[i] = size[i] += v[i];
    }
    return result;
}


/*!
*****************************************************************************
 | \brief Realizuje odejmowanie dwoch wektorow.                                     |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik odejmowania,                                 |
 |      v - drugi skladnik odejmowania.                                       |
 |  Zwraca:                                                                   |
 |      Roznice dwoch skladnikow przekazanych jako wskaznik                   |
 |      na parametr.                                                          |
 */
template <int SIZE>
Vector< SIZE> Vector< SIZE>::operator - (const Vector< SIZE> &v) {
    Vector result;
    for (int i = 0; i < SIZE; ++i) {
        result[i] = size[i] -= v[i];
    }
    return result;
}


/*!
*****************************************************************************
 | \brief Realizuje mnozenie wektora przez liczbe zmiennoprzecinkowa.               |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik mnozenia (wektor),                           |
 |      v - drugi skladnik mnozenia (liczba typu double).                     |
 |  Zwraca:                                                                   |
 |      Iloczyn dwoch skladnikow przekazanych jako wskaznik                   |
 |      na parametr.                                                          |
 */
template <int SIZE>
Vector< SIZE> Vector< SIZE>::operator * (const double &tmp) {
    Vector result;
    for (int i = 0; i < SIZE; ++i) {
        result[i] = size[i] *= tmp;
    }
    return result;
}


/*!
*****************************************************************************
 | \brief Realizuje dzielenie dwoch wektorow.                                       |
 |  Argumenty:                                                                |
 |      this - licznik dzielenia,                                             |
 |      v - mianownik dzielenia.                                              |
 |  Zwraca:                                                                   |
 |      Iloraz dwoch skladnikow przekazanych jako wskaznik                    |
 |      na parametr.                                                          |
 */
template <int SIZE>
Vector< SIZE> Vector< SIZE>::operator / (const double &tmp) {
    Vector result;

    for (int i = 0; i < SIZE; ++i) {
        result[i] = size[i] / tmp;
    }

    return result;
}


/*!
*****************************************************************************
 | \brief Funktor wektora.                                                          |
 |  Argumenty:                                                                |
 |      index - index wektora.                                                |
 |  Zwraca:                                                                   |
 |      Wartosc wektora w danym miejscu tablicy jako stala.                   |
 */
template <int SIZE>
const double &Vector< SIZE>::operator [] (int index) const {
    if (index < 0 || index >= SIZE) {
        std::cerr << "Error: Wektor jest poza zasiegiem!" << std::endl;
    } // lepiej byłoby rzucić wyjątkiem stdexcept
    return size[index];
}


/*!
*****************************************************************************
 | \brief Funktor wektora.                                                          |
 |  Argumenty:                                                                |
 |      index - index wektora.                                                |
 |  Zwraca:                                                                   |
 |      Wartosc wektora w danym miejscu tablicy.                              |
 */
template <int SIZE>
double &Vector< SIZE>::operator[](int index) {
    return const_cast<double &>(const_cast<const Vector< SIZE> *>(this)->operator[](index));
} 


/*!
*****************************************************************************
 | \brief Przeciazenie operatora <<                                                 |
 |  Argumenty:                                                                |
 |      out - strumien wejsciowy,                                             |
 |      tmp - wektor.                                                         |
 */
template <int SIZE>
std::ostream &operator << (std::ostream &out, Vector< SIZE> const &tmp) {
    for (int i = 0; i < SIZE; ++i) {
       // out << "[ " << tmp[i] << " ]\n";
       out<< std::setprecision(10)<<tmp[i]<< std::fixed<<" ";

    }
    return out;
}


/*!
*****************************************************************************
 | \brief Przeciazenie operatora >>                                                 |
 |  Argumenty:                                                                |
 |      in - strumien wyjsciowy,                                              |
 |      tmp - wektor.                                                         |
 */
template <int SIZE>
std::istream &operator >> (std::istream &in, Vector< SIZE> &tmp) {
    for (int i = 0; i < SIZE; ++i) {
        in >>std::setprecision(10)>>tmp[i]>>std::fixed;
    }
    std::cout << std::endl;
    return in;
}

/*!
*****************************************************************************
 | \brief Metoda Wektora                                                |
 |  Argumenty:                                                                |
 |      this- wektor. 
 | Zwraca:
 |      wynik-długosc wektora                                                  |
 */
template <int SIZE>
  double Vector< SIZE>::dlugosc()const{
double tmp,wynik; 
for (int i = 0; i < SIZE; ++i) {
        tmp=pow(size[i],2)+tmp;
    }


wynik=sqrt(tmp);
return wynik;

  }




  /*!
  *****************************************************************************
 | \brief Przeciazenie operatora ==                                                 |
 |  Argumenty:                                                                |
 |      tmp - wektor.                                                         |
 */
/*template <int SIZE>
  bool Vector< SIZE>::operator == (Vector< SIZE> tmp)const{
if ((std::abs(size[0]- tmp.size[0]) <= MINDIF) && (std::abs(size[1]- tmp.size[1]) <= MINDIF)){
    return true;
  }
  else {
    return false;
  }
  }
*/

  /*!
*****************************************************************************
 | \brief Realizuje dodawanie dwoch wektorow.                                       |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik dodawania,                                   |
 |      v - drugi skladnik dodawania.                                         |
 |  Zwraca:                                                                   |
 |      Sume dwoch skladnikow przekazanych jako wskaznik                      |
 |      na parametr.                                                          |
 */
template <int SIZE>
Vector< SIZE> Vector< SIZE>::operator * (const Vector< SIZE> &v) {
    Vector result;
    for (int i = 0; i < SIZE; ++i) {
        result[i] = size[i] *= v[i];
    }
    return result;
}
