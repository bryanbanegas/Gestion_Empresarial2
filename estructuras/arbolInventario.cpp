#include "arbolInventario.h"

ArbolInventario::ArbolInventario(int num){
    this->num=num;
    root=new Inventario(num);
}

void ArbolInventario::buscar(int clave){

}

void ArbolInventario::insertar(int clave, string nombre, string categoria,int cantidad, double precio, bool estado){
    dato.id=clave;
    dato.nombre=nombre;
    dato.categoria=categoria;
    dato.cantidad=cantidad;
    dato.precio=precio;
    dato.estado=estado;
    if(root->numeroClaves==((2*num)-1)){
        Inventario *nuevaRoot=new Inventario(num);
        root=nuevaRoot;
        nuevaRoot->hoja=false;
        nuevaRoot->numeroClaves=0;
        nuevaRoot->hijos[0]=root;
        split(nuevaRoot,0,root);
        nonfullInsert(nuevaRoot,clave);
    }else{
        nonfullInsert(root,clave);
    }
}

void ArbolInventario::split(Inventario *nodo1, int a, Inventario *nodo2){
    Inventario *temp=new Inventario(num);
    temp->hoja=nodo2->hoja;
    temp->numeroClaves=num-1;
    for(int i=0;i<(num-1);i++){
        temp->claves[i]=nodo2->claves[i+num];
    }
    if(!nodo2->hoja){
        for(int i=0;i<num;i++){
            temp->hijos[i]=nodo2->hijos[i+num];
        }
    }
    nodo2->numeroClaves=num-1;
    for(int i=nodo1->numeroClaves;i>a;i--){
        nodo1->hijos[i+1]=nodo1->hijos[i];
    }
    nodo1->hijos[a+1]=temp;
    for(int i=nodo1->numeroClaves;i>a;i--){
        nodo1->claves[i+1]=nodo1->claves[i];
    }
    nodo1->claves[a]=nodo2->claves[num-1];
    nodo1->numeroClaves++;
}

void ArbolInventario::nonfullInsert(Inventario *nodo,int clave){
    if(nodo->hoja){
        int i=nodo->numeroClaves;
        while(i>=1&&clave<nodo->claves[i-1].id){
            nodo->claves[i]=nodo->claves[i-1];
            i--;
        }
        nodo->claves[i].id=dato.id;
        nodo->claves[i].nombre=dato.nombre;
        nodo->claves[i].categoria=dato.categoria;
        nodo->claves[i].cantidad=dato.cantidad;
        nodo->claves[i].precio=dato.precio;
        nodo->claves[i].estado=dato.estado;
        nodo->numeroClaves++;
    }else{
        int i=0;
        while(i<nodo->numeroClaves&&clave>nodo->claves[i].id){
            i++;
        }
        if(nodo->hijos[i]->numeroClaves==((2*num)-1)){
            
            if(clave>nodo->claves[i].id){
                i++;
            }
        }
        nonfullInsert(nodo->hijos[i],clave);
    }
}

void ArbolInventario::print(Inventario nodo){
    nodo.imprimir();

    if(!nodo.hoja){
        for(int i=0;i<=nodo.numeroClaves;i++){
            if(nodo.hijos[i]!=nullptr){
                cout<<endl;
                print(*nodo.hijos[i]);
            }
        }
    }
}

void ArbolInventario::imprimir(){
    print(*root);
}