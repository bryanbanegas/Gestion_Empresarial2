#ifndef NODO_H
#define NODO_H

#include <iostream>
using namespace std;

class Nodo{
public:
    int *claves, numeroClaves;
    Nodo **hijos;
    bool hoja;

    Nodo(int num);

    void imprimir();
};

#endif