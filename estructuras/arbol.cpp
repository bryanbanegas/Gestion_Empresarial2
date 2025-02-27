#include "arbol.h"

Arbol::Arbol(int num){
    this->num=num;
    root=new Nodo(num);
}

void Arbol::buscar(int clave){

}

void Arbol::insertar(int clave){
    if(root->numeroClaves==((2*num)-1)){
        Nodo *nuevaRoot=new Nodo(num);
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

void Arbol::split(Nodo *nodo1, int a, Nodo *nodo2){
    Nodo *temp=new Nodo(num);
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

void Arbol::nonfullInsert(Nodo *nodo,int clave){
    if(nodo->hoja){
        int i=nodo->numeroClaves;
        while(i>=1&&clave<nodo->claves[i-1]){
            nodo->claves[i]=nodo->claves[i-1];
            i--;
        }
        nodo->claves[i]=clave;
        nodo->numeroClaves++;
    }else{
        int i=0;
        while(i<nodo->numeroClaves&&clave>nodo->claves[i]){
            i++;
        }
        if(nodo->hijos[i]->numeroClaves==((2*num)-1)){
            
            if(clave>nodo->claves[i]){
                i++;
            }
        }
        nonfullInsert(nodo->hijos[i],clave);
    }
}

void Arbol::print(Nodo nodoArbol){
    nodoArbol.imprimir();

    if(!nodoArbol.hoja){
        for(int i=0;i<=nodoArbol.numeroClaves;i++){
            if(nodoArbol.hijos[i]!=nullptr){
                cout<<endl;
                print(*nodoArbol.hijos[i]);
            }
        }
    }
}

void Arbol::imprimir(){
    print(*root);
}