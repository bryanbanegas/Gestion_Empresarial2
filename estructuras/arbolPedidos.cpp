#include "arbolPedidos.h"

ArbolPedidos::ArbolPedidos(int num){
    this->num=num;
    root=new Pedidos(num);
}

bool ArbolPedidos::confirmar(int clave){
    return confirmarPedido(clave,*root);
}

bool ArbolPedidos::confirmarPedido(int clave,Pedidos nodo){
    if(nodo.confirmar(clave)){
        return true;
    }

    if(!nodo.hoja){
        for(int i=0;i<=nodo.numeroClaves;i++){
            if(nodo.hijos[i]!=nullptr){
                confirmarPedido(clave,*nodo.hijos[i]);
            }
        }
    }

    return false;
}

datosPedidos ArbolPedidos::buscar(int clave){
    return search(clave,*root);
}

datosPedidos ArbolPedidos::search(int clave,Pedidos nodo){
    datosPedidos datos=nodo.buscar(clave);
    if(!datos.cliente.empty()){
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

void ArbolPedidos::insertar(int clave, string cliente, string fecha, bool estado){
    dato.id=clave;
    dato.cliente=cliente;
    dato.fecha=fecha;
    dato.estado=estado;
    if(root->numeroClaves==((2*num)-1)){
        Pedidos *nuevaRoot=new Pedidos(num);
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

void ArbolPedidos::split(Pedidos *nodo1, int a, Pedidos *nodo2){
    Pedidos *temp=new Pedidos(num);
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

void ArbolPedidos::nonfullInsert(Pedidos *nodo,int clave){
    if(nodo->hoja){
        int i=nodo->numeroClaves;
        while(i>=1&&clave<nodo->claves[i-1].id){
            nodo->claves[i]=nodo->claves[i-1];
            i--;
        }
        nodo->claves[i].id=dato.id;
        nodo->claves[i].cliente=dato.cliente;
        nodo->claves[i].fecha=dato.fecha;
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

void ArbolPedidos::print(Pedidos nodo){
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

void ArbolPedidos::imprimir(){
    print(*root);
}