#ifndef ARBOL_H
#define ARBOL_H

#include "Nodo.h"

class Arbol{
public:
    Nodo *root;
    int num;

    Arbol(int num);

    void buscar(int clave);
    void insertar(int clave);
    void imprimir();
private:
    void split(Nodo *nodo1,int i, Nodo *nodo2);
    void nonfullInsert(Nodo *nodo,int clave);
    void print(Nodo nodoArbol);
};

#endif