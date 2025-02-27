#ifndef ARBOLINVENTARIO_H
#define ARBOLINVENTARIO_H

#include "/home/bryan/Documents/VSCode/Gestion_Empresarial/clases/inventario.h"

struct datos{
    int id;
    string nombre;
    string categoria;
    int cantidad; 
    double precio;
    bool estado;
};

class ArbolInventario{
public:
    Inventario *root;
    int num;
    datos dato;

    ArbolInventario(int num);

    void buscar(int clave);
    void insertar(int clave, string nombre, string categoria,int cantidad, double precio, bool estado);
    void imprimir();
private:
    void split(Inventario *nodo1,int i, Inventario *nodo2);
    void nonfullInsert(Inventario *nodo,int clave);
    void print(Inventario nodoArbol);
};

#endif