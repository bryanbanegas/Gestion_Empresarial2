#include "inventario.h"

Inventario::Inventario(int num){
    numeroClaves=0;
    hoja=true;
    claves=new datosInventario[(2*num)-1];
    hijos=new Inventario*[(2*num)];
}

void Inventario::imprimir(){
    for(int i=0;i<numeroClaves;i++){
        cout<<"ID: "<<claves[i].id<<" Nombre: "<<claves[i].nombre<<endl;
    }
}