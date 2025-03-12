#include "arbolClientes.h"

ArbolClientes::ArbolClientes(int num){
    this->num=num;
    root=new Clientes(num);
}

datosClientes ArbolClientes::buscar(int clave){
    return search(clave,*root);
}

datosClientes ArbolClientes::search(int clave,Clientes nodo){
    datosClientes datos=nodo.buscar(clave);
    if(!datos.nombre.empty()){
        return datos;
    }

    if(!nodo.hoja){
        for(int i=0;i<=nodo.numeroClaves;i++){
            if(nodo.hijos[i]!=nullptr){
                search(clave,*nodo.hijos[i]);
            }
        }
    }
    return datos;
}

void ArbolClientes::insertar(int clave, string nombre, string correo, string telefono, double saldo){
    dato.id=clave;
    dato.nombre=nombre;
    dato.correo=correo;
    dato.telefono=telefono;
    dato.saldo=saldo;
    if(root->numeroClaves==((2*num)-1)){
        Clientes *nuevaRoot=new Clientes(num);
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

void ArbolClientes::split(Clientes *nodo1, int a, Clientes *nodo2){
    Clientes *temp=new Clientes(num);
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

void ArbolClientes::nonfullInsert(Clientes *nodo,int clave){
    if(nodo->hoja){
        int i=nodo->numeroClaves;
        while(i>=1&&clave<nodo->claves[i-1].id){
            nodo->claves[i]=nodo->claves[i-1];
            i--;
        }
        nodo->claves[i].id=dato.id;
        nodo->claves[i].nombre=dato.nombre;
        nodo->claves[i].correo=dato.correo;
        nodo->claves[i].telefono=dato.telefono;
        nodo->claves[i].saldo=dato.saldo;
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

void ArbolClientes::print(Clientes nodo){
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

void ArbolClientes::imprimir(){
    print(*root);
}