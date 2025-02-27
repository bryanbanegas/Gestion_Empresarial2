#include "/home/bryan/Documents/VSCode/Gestion_Empresarial/estructuras/arbolEmpleados.h"

int main(){
    ArbolEmpleados *arbol=new ArbolEmpleados(3);

    arbol->insertar(1,"nombre","departamento","puesto",21,true);  
    arbol->insertar(2,"nombre","departamento","puesto",21,true);
    arbol->insertar(3,"nombre","departamento","puesto",21,true);  
    arbol->insertar(4,"nombre","departamento","puesto",21,true);  
    arbol->insertar(5,"nombre","departamento","puesto",21,true);
    
    cout<<"Arbol: ";
    arbol->imprimir();
}