#ifndef ARBOLVENTAS_H
#define ARBOLVENTAS_H

#include "/home/bryan/Documents/VSCode/Gestion_Empresarial/clases/ventas.h"

struct datos{
    int idVenta;
    int idCliente;
    string fecha;
    vector<string> productosVendidos;
    int cantidad;
    double total;
};

class ArbolVentas{
public:
    Ventas *root;
    int num;
    datos dato;

    ArbolVentas(int num);

    void buscar(int clave);
    void insertar(int clave, int idcliente, string fecha, int cantidad, double total);
    void imprimir();
private:
    void split(Ventas *nodo1,int i, Ventas *nodo2);
    void nonfullInsert(Ventas *nodo,int clave);
    void print(Ventas nodoArbol);
};

#endif