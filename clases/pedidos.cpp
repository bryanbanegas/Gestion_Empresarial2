#include "pedidos.h"

Pedidos::Pedidos(int num){
    numeroClaves=0;
    hoja=true;
    claves=new datosPedidos[(2*num)-1];
    hijos=new Pedidos*[(2*num)];
}

void Pedidos::imprimir(){
    for(int i=0;i<numeroClaves;i++){
        if(claves[i].estado){
            cout<<"ID: "<<claves[i].id<<" Cliente: "<<claves[i].cliente<<" Fecha: "<<claves[i].fecha<<" Cliente: "<<claves[i].cliente<<" Se a entregado el pedido."<<endl;
        }else{
            cout<<"ID: "<<claves[i].id<<" Cliente: "<<claves[i].cliente<<" Fecha: "<<claves[i].fecha<<" Cliente: "<<claves[i].cliente<<" No se a entregado el pedido."<<endl;
        }       
        cout<<"Pedidos: ";
        for(int i=0;i<claves[i].productosSolicitados.size();i++){
            cout<<claves[i].productosSolicitados.at(i)<<" ";
        } 
    }
}

datosPedidos Pedidos::buscar(int id){
    datosPedidos datos;
    for(int i=0;i<numeroClaves;i++){
        if(claves[i].id==id){
            datos=claves[i];
            return datos;
        }
    }
    return datos;
}

bool Pedidos::confirmar(int id){
    for(int i=0;i<numeroClaves;i++){
        if(claves[i].id==id){
            claves[i].estado=true;
            return claves[i].estado;
        }
    }
    return false;
}

