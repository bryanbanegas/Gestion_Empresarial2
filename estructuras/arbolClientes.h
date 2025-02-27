#ifndef ARBOLCLIENTES_H
#define ARBOLCLIENTES_H

#include "/home/bryan/Documents/VSCode/Gestion_Empresarial/clases/clientes.h"

struct datos{
    int id;
    string nombre;
    string correo;
    string telefono;
    vector<string> historialCompras;
    double saldo;
};

class ArbolClientes{
public:
    Clientes *root;
    int num;
    datos dato;

    ArbolClientes(int num);

    datosClientes buscar(int clave);
    void insertar(int clave, string nombre, string correo, string telefono, double saldo);
    void imprimir();
private:
    void split(Clientes *nodo1,int i, Clientes *nodo2);
    void nonfullInsert(Clientes *nodo,int clave);
    void print(Clientes nodoArbol);
    datosClientes search(int clave,Clientes nodoArbol);
};

#endif