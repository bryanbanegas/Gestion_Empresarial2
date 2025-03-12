#include "ventas.h"

Ventas::Ventas(int num){
    numeroClaves=0;
    hoja=true;
    claves=new datosVentas[(2*num)-1];
    hijos=new Ventas*[(2*num)];
}

void Ventas::imprimir(){
    for(int i=0;i<numeroClaves;i++){
        cout<<"ID de Venta: "<<claves[i].idVenta<<" ID de cliente: "<<claves[i].idCliente<<endl;
    }
}

datosVentas Ventas::buscar(int id){
    for(int i=0;i<numeroClaves;i++){
        if(claves[i].idVenta==id){
            return claves[i];
        }
    }
}