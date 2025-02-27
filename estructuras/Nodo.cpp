#include "Nodo.h"

Nodo::Nodo(int num){
    numeroClaves=0;
    hoja=true;
    claves=new int[(2*num)-1];
    hijos=new Nodo*[(2*num)];
}

void Nodo::imprimir(){
    cout<<"[";
    for(int i=0;i<numeroClaves;i++){
        if(i<numeroClaves-1){
            cout<<claves[i]<<" | ";
        }else{
            cout<<claves[i];
        }
    }
    cout<<"]"<<endl;
}