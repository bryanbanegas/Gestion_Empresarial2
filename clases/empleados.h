#ifndef EMPLEADOS_H
#define EMPLEADOS_H

#include <string>
#include <iostream>
using namespace std;

struct datosEmpleados{
    int id;
    string nombre;
    string departamento;
    string puesto; 
    double salario;
    bool estado;
};

class Empleados{
public:
    datosEmpleados *claves;
    int numeroClaves;
    Empleados **hijos;
    bool hoja;

    Empleados(int num);
    void imprimir();
    datosEmpleados buscar(int id);
};

#endif