#include "arbolVentas.h"

ArbolVentas::ArbolVentas(int num){
    this->num=num;
    root=new Ventas(num);
}

datosVentas ArbolVentas::buscar(int clave){
    return search(clave,*root);
}

datosVentas ArbolVentas::search(int clave,Ventas nodo){
    return nodo.buscar(clave);

    if(!nodo.hoja){
        for(int i=0;i<=nodo.numeroClaves;i++){
            if(nodo.hijos[i]!=nullptr){
                search(clave,*nodo.hijos[i]);
            }
        }
    }
}

void ArbolVentas::insertar(int clave, int idcliente, string fecha, int cantidad, double total){
    dato.idVenta=clave;
    dato.idCliente=idcliente;
    dato.fecha=fecha;
    dato.cantidad=cantidad;
    dato.total=total;
    if(root->numeroClaves==((2*num)-1)){
        Ventas *nuevaRoot=new Ventas(num);
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

void ArbolVentas::split(Ventas *nodo1, int a, Ventas *nodo2){
    Ventas *temp=new Ventas(num);
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

void ArbolVentas::nonfullInsert(Ventas *nodo,int clave){
    if(nodo->hoja){
        int i=nodo->numeroClaves;
        while(i>=1&&clave<nodo->claves[i-1].idVenta){
            nodo->claves[i]=nodo->claves[i-1];
            i--;
        }
        nodo->claves[i].idVenta=dato.idVenta;
        nodo->claves[i].idCliente=dato.idCliente;
        nodo->claves[i].fecha=dato.fecha;
        nodo->claves[i].cantidad=dato.cantidad;
        nodo->claves[i].total=dato.total;
        nodo->numeroClaves++;
    }else{
        int i=0;
        while(i<nodo->numeroClaves&&clave>nodo->claves[i].idVenta){
            i++;
        }
        if(nodo->hijos[i]->numeroClaves==((2*num)-1)){
            
            if(clave>nodo->claves[i].idVenta){
                i++;
            }
        }
        nonfullInsert(nodo->hijos[i],clave);
    }
}

void ArbolVentas::print(Ventas nodo){
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

void ArbolVentas::imprimir(){
    print(*root);
}