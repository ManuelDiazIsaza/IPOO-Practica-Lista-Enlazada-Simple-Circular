/*
  Archivo: ListaCircular.h
  Autor: Luis Yovany Romo
  Email: luis.romo@correounivalle.edu.co
  Fecha creaciC3n: 2018-02-09
  Fecha Cltima modificaciC3n: 2018-02-09
  VersiC3n: 0.1
  Licencia: GPL
*/

// Clase: Lista
// Responsabilidad: elemento (nodo) de una lista
// ColaboraciCB3n: ninguna


#ifndef LISTA_H
#define LISTA_H
#include "Nodo.h"


using namespace std;


class Lista
{
private:
    Nodo *cab;
    Nodo *ultimo;
public:
    Lista();
    ~Lista();
    void insertarPrimero(int x);
    void insertarUltimo(int x);
    void borrarSegundo();
    bool vacia();
    void imprimir();
    int cantidad();
    void borrar(int pos);
    void borrarUltimo();
    void borrarMayor();
};

#endif