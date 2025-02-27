#include "pedidos.h"

Pedidos::Pedidos(int num){
    numeroClaves=0;
    hoja=true;
    claves=new datosPedidos[(2*num)-1];
    hijos=new Pedidos*[(2*num)];
}

void Pedidos::imprimir(){
    for(int i=0;i<numeroClaves;i++){
        cout<<"ID: "<<claves[i].id<<" Nombre: "<<claves[i].cliente<<endl;
    }
}

