#ifndef CLIENTES_H
#define CLIENTES_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct datosClientes{
    int id;
    string nombre;
    string correo;
    string telefono;
    vector<string> historialCompras;
    double saldo;
};

class Clientes{
public:
    datosClientes *claves;
    int numeroClaves;
    Clientes **hijos;
    bool hoja;
    
    Clientes(int num);
    void imprimir();
    datosClientes buscar(int id);
};

#endif