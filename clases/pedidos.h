#ifndef PEDIDOS_H
#define PEDIDOS_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct datosPedidos{
    int id;
    string cliente;
    string fecha;
    vector<string> productosSolicitados;
    bool estado;
};

class Pedidos{
public:
    datosPedidos *claves;
    int numeroClaves;
    Pedidos **hijos;
    bool hoja;

    Pedidos(int num);
    void imprimir();
};

#endif