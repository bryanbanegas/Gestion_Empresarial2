#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <string>
#include <iostream>
using namespace std;

struct datosInventario{
    int id;
    string nombre;
    string categoria;
    int cantidad; 
    double precio;
    bool estado;
};

class Inventario{
public:
    datosInventario *claves;
    int numeroClaves;
    Inventario **hijos;
    bool hoja;

    Inventario(int num);
    void imprimir();
};

#endif