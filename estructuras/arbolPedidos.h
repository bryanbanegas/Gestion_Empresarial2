#ifndef ARBOLPEDIDOS_H
#define ARBOLPEDIDOS_H

#include "/home/bryan/Documents/VSCode/Gestion_Empresarial/clases/pedidos.h"

struct datos{
    int id;
    string cliente;
    string fecha;
    vector<string> productosSolicitados;
    bool estado;
};

class ArbolPedidos{
public:
    Pedidos *root;
    int num;
    datos dato;

    ArbolPedidos(int num);

    void buscar(int clave);
    void insertar(int clave, string cliente, string fecha, bool estado);
    void imprimir();
private:
    void split(Pedidos *nodo1,int i, Pedidos *nodo2);
    void nonfullInsert(Pedidos *nodo,int clave);
    void print(Pedidos nodoArbol);
};

#endif