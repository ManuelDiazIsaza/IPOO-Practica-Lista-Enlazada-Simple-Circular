/*
  Archivo: Lista.cpp
  Autor: Luis Yovany Romo Portilla
  Email: luis.romo@correounivalle.edu.co
  Fecha creaciC3n: 2017-08-31
  Fecha C:ltima modificaciC3n: 2017-08-31
  VersiC3n: 0.1
  Licencia: GPL
*/

#include "ListaCircular.h"
#include "Nodo.h"
#include <time.h>
#include <stdio.h>
#include <iostream>

Lista::Lista()
{
    cab = NULL;
    ultimo = NULL;
}

//inserta un nuevo elemento al principio
//de la lista

void Lista::insertarPrimero(int info)
{
    Nodo *nuevo = new Nodo();
    nuevo->setInfo(info);
    if (cab == NULL)
    {
        nuevo->setSig(nuevo);
        cab  = nuevo;
        ultimo = nuevo;
    }
    else
    {
        nuevo->setSig(cab);
        cab = nuevo;
        ultimo->setSig(nuevo);
    }
}

void Lista::insertarUltimo(int info)
{
    Nodo *nuevo = new Nodo();
    nuevo->setInfo(info);
    if (cab == NULL)
    {
        nuevo->setSig(nuevo);
        cab  = nuevo;
        ultimo = nuevo;
    }
    else
    {
        nuevo->setSig(cab);
        ultimo->setSig(nuevo);
        ultimo = nuevo;
    }
}

void Lista::borrarSegundo()
{
    if(cantidad()<2)
    {
        cout << "No hay suficientes elementos." << endl;
    }
    else if(cantidad()==2)
    {
        Nodo *borrar = cab->getSig();
        cab->setSig(cab);
        ultimo = cab;
        delete borrar;
    }
    else
    {
        Nodo *borrar = cab->getSig();
        cab->setSig(borrar->getSig());
        delete borrar;
    }
}

void Lista::borrarUltimo()
{
    if(cab== nullptr)
    {
        cout << "No hay suficientes elementos." << endl;
    }
    else if(cantidad()==1)
    {
        delete cab;
        cab = nullptr;
        ultimo = nullptr;
    }
    else
    {
        Nodo *pos1 = cab;
        while(pos1->getSig()!=ultimo)
        {
            pos1 = pos1->getSig();
        }
        pos1->setSig(cab);
        delete ultimo;
        ultimo = pos1;
    }
}

void Lista::borrarMayor()
{
    if(cab== nullptr)
    {
        cout << "No hay suficientes elementos." << endl;
    }
    else if(cantidad()==1)
    {
        delete cab;
        cab = nullptr;
        ultimo = nullptr;
    }
    else
    {
        Nodo *pos1 = cab;
        int mayorTemp = 0;
        int pos = 0;
        for(int i=0;i<cantidad();i++)
        {
            if(mayorTemp<pos1->getInfo())
            {
                mayorTemp = pos1->getInfo();
                pos=i;
                pos1 = pos1->getSig();
            }
            else
            {
                pos1 = pos1->getSig();
            }
        }
        pos1 = cab;
        for(int i=0;i<pos-1;i++)
        {
            pos1 = pos1->getSig();
        }

        if(pos==0)
        {
            ultimo->setSig(cab->getSig());
            delete cab;
            cab = ultimo->getSig();
        }
        else if(pos == cantidad()-1)
        {
            pos1->setSig(cab);
            delete ultimo;
            ultimo = pos1;
        }
        else
        {
           Nodo *pos2 = pos1->getSig();
           pos1->setSig(pos1->getSig()->getSig());
           delete pos2;
        }
    }
}



bool Lista::vacia()
{
    if (cab == NULL)
        return true;
    else
        return false;
}

void Lista::imprimir()
{
    if (!vacia()) {
        Nodo *desplaza = cab;
        do {
            cout<<desplaza->getInfo()  <<"-";
            desplaza = desplaza->getSig();
        } while (desplaza != cab);
        cout << endl;
    }
}

Lista::~Lista()
{
    if (cab != NULL) {
        Nodo *desplaza = cab->getSig();
        Nodo *borrar;
        while (desplaza != cab)
        {
            borrar = desplaza;
            desplaza = desplaza->getSig();
            delete borrar;
            borrar = NULL;
        }
        delete cab;
        cab = NULL;
    }
}

int Lista::cantidad()
{
    if(cab==nullptr)
    {
        return 0;
    }
    else
    {
        int contador=1;
        Nodo *desplaza = cab->getSig();
        while(desplaza!=cab)
        {
            contador++;
            desplaza=desplaza->getSig();
        }
        return contador;
    }
}