#ifndef VENTAS_H
#define VENTAS_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct datosVentas{
    int idVenta;
    int idCliente;
    string fecha;
    vector<string> productosVendidos;
    int cantidad;
    double total;
};

class Ventas{
public:
    datosVentas *claves;
    int numeroClaves;
    Ventas **hijos;
    bool hoja;

    Ventas(int num);
    void imprimir();
    datosVentas buscar(int id);
};

#endif