#pragma once


#include "vector.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <size.h>

/*!
 * \file matrix.h
 * \brief  plik  zawiera  definicje szablonu klasy Macierz<>
 *
 */



/*!
 * \brief  
 *
 *  Szablon modeluje klase macierz sluzaca do przechowywania macierzy obrotu
 *  
 */
template <int SIZE>
class Matrix {

private:
    double value[SIZE][SIZE];               // Wartosci macierzy

public:
    Matrix(double [SIZE][SIZE]);            // Konstruktor klasy

    Matrix();                               // Konstruktor klasy
    Matrix(char os,double kat);

    Vector<SIZE> operator * (Vector<SIZE>  tmp);           // Operator mnożenia przez wektor
    Matrix<SIZE>  operator * (Matrix<SIZE>  tmp);           // Operator mnożenia przez macierz

    Matrix<SIZE>  operator + (Matrix<SIZE>  tmp);
    void zaladujz(double kat);
    void zaladujx(double kat);
    void zaladujy(double kat);
    void zaladuj(char os,double kat);
    bool operator == (Matrix<SIZE>  tmp);
    double  &operator () (unsigned int row, unsigned int column);
    
    const double &operator () (unsigned int row, unsigned int column) const;
    double wyznacznik()const;
};
template <int SIZE>
std::istream &operator>>(std::istream &in, Matrix<SIZE>  &mat);
template <int SIZE>
std::ostream &operator<<(std::ostream &out, Matrix<SIZE>  const &mat);

/*!
*****************************************************************************
 | \brief Konstruktor klasy Matrix.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Macierz wypelnione wartoscia 0.                                       |
 */
template <int SIZE>
Matrix<SIZE> ::Matrix() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            value[i][j] = 0;
        }
    }
}


/*!
*****************************************************************************
 | \brief Konstruktor parametryczny klasy Matrix.                                              |
 |  Argumenty:                                                                |
 |      tmp - dwuwymiarowa tablica z elementami typu double.                               |
 |  Zwraca:                                                                   |
 |      Macierz wypelniona wartosciami podanymi w argumencie.                 |
 */
template <int SIZE>
Matrix<SIZE> ::Matrix(double tmp[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            value[i][j] = tmp[i][j];
        }
    }
}


/*!
*****************************************************************************
 | \brief Realizuje mnozenie macierzy przez wektor.                                 |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik mnozenia,                     |
 |      v - wektor, czyli drugi skladnik mnozenia.                            |
 |  Zwraca:                                                                   |
 |      Iloczyn dwoch skladnikow przekazanych jako wektor.                    |
 */
template <int SIZE>
Vector<SIZE>  Matrix<SIZE> ::operator * (Vector<SIZE>  tmp) {
    Vector<SIZE> result;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            result[i] += value[i][j] * tmp[j];
        }
    }
    return result;
}


/*!
*****************************************************************************
 |  \brief Funktor macierzy                                                          |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy.                             |
 */
template <int SIZE>
double &Matrix<SIZE> ::operator()(unsigned int row, unsigned int column) {

    if (row >= SIZE) {
        std::cout << "Error: Macierz jest poza zasiegiem"; 
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    if (column >= SIZE) {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    return value[row][column];
}


/*!
*****************************************************************************
 |  \brief Funktor macierzy                                                          |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy jako stala.                  |
 */
template <int SIZE>
const double &Matrix<SIZE> ::operator () (unsigned int row, unsigned int column) const {

    if (row >= SIZE) {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    if (column >= SIZE) {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    return value[row][column];
}

/*!
*****************************************************************************
 |  \brief Przeciążenie dodawania macierzy                                                          |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik dodawania,                     |
 |      v - wektor, czyli drugi skladnik dodawania.                                               |
 |  Zwraca:                                                                   |
 |      Macierz - iloczyn dwóch podanych macierzy.                  |
 */
template <int SIZE>
Matrix<SIZE>  Matrix<SIZE> ::operator + (Matrix<SIZE>  tmp) {
    Matrix result;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            result(i, j) = this->value[i][j] + tmp(i, j);
        }
    }
    return result;
}

/*!
*****************************************************************************
 | \brief Przeciazenie operatora >>                                                 |
 |  Argumenty:                                                                |
 |      in - strumien wyjsciowy,                                              |
 |      mat - macierz.                                                         |
 */
template <int SIZE>
std::istream &operator>>(std::istream &in, Matrix<SIZE>  &mat) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            in >> mat(i, j);
        }
    }
    return in;
}


/*!
*****************************************************************************
 | \brief Przeciazenie operatora <<                                                 |
 |  Argumenty:                                                                |
 |      out - strumien wejsciowy,                                             |
 |      mat - macierz.                                                        |
 */
template <int SIZE>
std::ostream &operator<<(std::ostream &out, const Matrix<SIZE>  &mat) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            out << "| " << mat(i, j) << " | "; //warto ustalic szerokosc wyswietlania dokladnosci liczb
        }
        std::cout << std::endl;
    }
    return out;
}
/*!
*****************************************************************************
 | \brief Metoda macierzy                                                |
 |  Argumenty:                                                                |
 |      kat - double,                                             |
 |      Wypelnia macierz wartosciami                                                      |
 */
template <int SIZE>
void Matrix<SIZE> ::zaladujz(double kat){
double radian;
radian=2*M_PI*(kat/360);
value[0][0]=cos(radian);
value[0][1]=-sin(radian);
value[0][2]=0;
value[1][0]=sin(radian);
value[1][1]=cos(radian);
value[1][2]=0;
value[2][0]=0;
value[2][1]=0;
value[2][2]=1;
}
/*!
*****************************************************************************
 | \brief Metoda macierzy                                                |
 |  Argumenty:                                                                |
 |      kat - double,                                             |
 |      Wypelnia macierz wartosciami                                                      |
 */
template <int SIZE>
void Matrix<SIZE> ::zaladujy(double kat){
double radian;
radian=2*M_PI*(kat/360);
value[0][0]=cos(radian);
value[0][1]=0;
value[0][2]=sin(radian);
value[1][0]=0;
value[1][1]=1;
value[1][2]=0;
value[2][0]=-sin(radian);
value[2][1]=0;
value[2][2]=cos(radian);
}
/*!
*****************************************************************************
 | \brief Metoda macierzy                                                |
 |  Argumenty:                                                                |
 |      kat - double,                                             |
 |      Wypelnia macierz wartosciami                                                      |
 */
template <int SIZE>
void Matrix<SIZE> ::zaladujx(double kat){
double radian;
radian=2*M_PI*(kat/360);
value[0][0]=1;
value[0][1]=0;
value[0][2]=0;
value[1][0]=0;
value[1][1]=cos(radian);
value[1][2]=-sin(radian);
value[2][0]=0;
value[2][1]=sin(radian);
value[2][2]=cos(radian);
}
/*!
*****************************************************************************
 |  \brief konstruktor parametryczny macierzy                                            |
 |  Argumenty:                                                                |
 |      kat - double, 
 |       os- char                                     |
 |     Wywoluje funkce zaladuj(x,y,z)  dla wartosci argumentu                                                    |
 */
template <int SIZE>
Matrix<SIZE> ::Matrix(char os,double kat){
switch (os)
{
case 'x':
    zaladujx(kat);
    break;
case 'y':
    zaladujy(kat);
    break;
case 'z':
    zaladujz(kat);
    break;
default:
    break;
}



}
/*!
*****************************************************************************
 | \brief metoda klasy macierz                                             |
 |  Argumenty:                                                                |
 |      kat - double,                                             |
 |     Wywoluje funkce zaladuj(x,y,z) dla wartosci argumentu                                                    |
 */
template <int SIZE>
void Matrix<SIZE> ::zaladuj(char os,double kat){
switch (os)
{
case 'x':
    zaladujx(kat);
    break;
case 'y':
    zaladujy(kat);
    break;
case 'z':
    zaladujz(kat);
    break;
default:
    break;
}



}
/*!
*****************************************************************************
 |  \brief Metoda macierzy                                                |
 |      Zwraca:                                          |
 |      suma-wyznacznik macierzy                                                        |
 */
template <int SIZE>
    double Matrix<SIZE> ::wyznacznik()const{
 double a[SIZE][SIZE], ratio,suma=1;
	 int i,j,k;
for(i=0;i<=SIZE-1;i++)
	 {
		  for(j=0;j<=SIZE-1;j++)
		  {
			  
			   a[i][j]=value[i][j];
               
		  }
	 }
for(i=0;i<=SIZE-1;i++)
	 {
		  if(a[i][i] == 0.0)
		  {
			   std::cout<<"Mathematical Error!";
			   exit(0);
		  }
		  for(j=i+1;j<=SIZE-1;j++)
		  {
			   ratio = a[j][i]/a[i][i];

			   for(k=0;k<=SIZE-1;k++)
			   {
			  		a[j][k] = a[j][k] - ratio*a[i][k];
                      
			   }
		  }
	 }
for(i=0;i<=SIZE-1;i++)
	 {
		 
			   
			  suma=a[i][i]*suma;
		  
	 }
return suma;
    }
    /*!
    *****************************************************************************
 |  \brief Realizuje mnozenie macierzy przez wektor.                                 |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik mnozenia,                     |
 |      v - wektor, czyli drugi skladnik mnozenia.                            |
 |  Zwraca:                                                                   |
 |      Iloczyn dwoch skladnikow przekazanych jako wektor.                    |
 */
template <int SIZE>
Matrix<SIZE>  Matrix<SIZE> ::operator * (Matrix<SIZE>  tmp) {
    Matrix result;
    double tmp1=0;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            tmp1=0;
            for (int k = 0; k < SIZE; ++k) {
            tmp1 += value[i][k] * tmp(k,j);
            
            result(i,j)=tmp1;}
          
        }
    }
    return result;
}


  /*!
  *****************************************************************************
 | \brief Przeciazenie operatora ==                                                 |
 |  Argumenty:                                                                |
 |      tmp - macierz.                                                         |
 */
template <int SIZE>
    bool Matrix<SIZE> ::operator == (Matrix<SIZE>  tmp){
 for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
        
        
        if(std::abs(value[i][j]- tmp.value[i][j]) >= MINDIF)
        
  
  {
    return false;
  }
                                        }
                               }



return true;
    }