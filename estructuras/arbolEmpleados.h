#ifndef ARBOLEMPLEADOS_H
#define ARBOLEMPLEADOS_H

#include "/home/bryan/Documents/VSCode/Gestion_Empresarial/clases/empleados.h"

struct datos{
    int id;
    string nombre;
    string departamento;
    string puesto; 
    double salario;
    bool estado;
};

class ArbolEmpleados{
public:
    Empleados *root;
    int num;
    datos dato;

    ArbolEmpleados(int num);

    datosEmpleados buscar(int clave);
    void insertar(int clave, string nombre, string departamento, string puesto, double salario, bool estado);
    void imprimir();
private:
    void split(Empleados *nodo1,int i, Empleados *nodo2);
    void nonfullInsert(Empleados *nodo,int clave);
    void print(Empleados nodoArbol);
    datosEmpleados search(int clave,Empleados nodoArbol);
};

#endif