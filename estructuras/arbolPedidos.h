#ifndef ARBOLPEDIDOS_H
#define ARBOLPEDIDOS_H

#include "/home/bryan/Documents/VSCode/Gestion_Empresarial/clases/pedidos.h"

struct datosArbolPedidos{
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
    datosArbolPedidos dato;

    ArbolPedidos(int num);

    datosPedidos buscar(int clave);
    bool confirmar(int clave);
    void insertar(int clave, string cliente, string fecha, bool estado);
    void imprimir();
private:
    bool confirmarPedido(int clave,Pedidos nodo);
    datosPedidos search(int clave,Pedidos nodo);
    void split(Pedidos *nodo1,int i, Pedidos *nodo2);
    void nonfullInsert(Pedidos *nodo,int clave);
    void print(Pedidos nodoArbol);
};

#endif