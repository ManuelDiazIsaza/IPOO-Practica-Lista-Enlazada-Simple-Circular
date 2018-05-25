/*
  Archivo: Main.cpp
  Autor: Luis Yovany Romo Portilla
  Email: luis.romo@correounivalle.edu.co
  Fecha creaciC3n: 2017-08-31
  Fecha C:ltima modificaciC3n: 2017-08-31
  VersiC3n: 0.1
  Licencia: GPL
*/
#include <stdio.h>
#include <iostream>
#include "ListaCircular.h"
using namespace std;

int main()
{
    Lista *listacircular = new Lista();


    listacircular->insertarUltimo(45);
    listacircular->insertarUltimo(12);

    listacircular->insertarUltimo(4);
    listacircular->insertarUltimo(30);

    listacircular->insertarUltimo(100);

    listacircular->imprimir();

    listacircular->borrarMayor();

 //   cout << listacircular->cantidad() << endl;
    listacircular->imprimir();
 //   listacircular->imprimir();
    return 0;
}