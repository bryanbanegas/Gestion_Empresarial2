#include <iostream>
#include <string>
#include "/home/bryan/Documents/VSCode/Gestion_Empresarial/estructuras/arbolEmpleados.h"
#include "/home/bryan/Documents/VSCode/Gestion_Empresarial/estructuras/arbolClientes.h"
#include "/home/bryan/Documents/VSCode/Gestion_Empresarial/estructuras/arbolVentas.h"
#include "/home/bryan/Documents/VSCode/Gestion_Empresarial/estructuras/arbolInventario.h"
#include "/home/bryan/Documents/VSCode/Gestion_Empresarial/estructuras/arbolPedidos.h"
using namespace std;

ArbolEmpleados *arbolEmpleados=new ArbolEmpleados(3);
ArbolClientes *arbolClientes=new ArbolClientes(3);
ArbolVentas *arbolVentas=new ArbolVentas(3);
ArbolInventario *arbolInvetario=new ArbolInventario(3);
ArbolPedidos *arbolPedidos=new ArbolPedidos(3);

void agregarEmpleados(int id){
    string nombre, departamento, puesto, opcion="d"; 
    double salario;
    bool estado;
    
    cout << "---------------------------------" << endl;
    //hay que ver que tipo de restriccion pondremos para el id o si la funcion ya tendra las validaciones
    cout << "Ingresar nombre: ";
    cin >> nombre;
    cout << "---------------------------------" << endl; 
    while(opcion != "1" && opcion != "2"){
        cout << "Seleccionar Departamento:" << endl
             << "1. Administracion" << endl
             << "2. Personal Laboral" << endl
             << "Ingresar departamento: ";
        cin >> opcion;
        
        if(opcion == "1"){
            departamento = "Administracion";
        } else {
            departamento = "Personal Laboral";
        }  
        cout << "---------------------------------" << endl;    
    }

    cout << "Ingresar puesto: ";
    cin >> puesto;
    //habran puestos determinados?
    cout << "---------------------------------" << endl;
    cout << "Ingresar salario: ";
    //validar qeu sean numeros
    //habran salarios preestablecidos?
    cin >> salario;
    arbolEmpleados->insertar(id,nombre,departamento,puesto,salario,true);
    cout << "--------------------------------" << endl;
    cout << "¡Empleado agregado con éxito!" << endl;
    cout << "---------------------------------" << endl;
}

void agregarCliente(int id){
    string nombre, correo, telefono, opcion="d"; 
    double saldo;
    int dat;
    cout << "---------------------------------" << endl;
    cout << "Ingresar nombre del cliente: ";
    cin >> nombre;
    cout << "Ingresar correo del cliente: ";
    cin >> correo;
    cout << "Ingresar telefono del cliente: ";
    cin >> telefono;
    arbolClientes->insertar(id,nombre,correo,telefono,saldo);
    cout << "---------------------------------" << endl;
    cout << "¡Cliente agregado con éxito!" << endl;
    cout << "---------------------------------" << endl;
}

void administracion(){
    string opcion;
    cout << "---------------------------------" << endl;
    cout << "---- MENÚ ADMINISTRACION ----" << endl;
    cout << "1. Gestion de Ventas" << endl
         << "2. Gestion de Pedidos" << endl
         << "Ingresar una opcion: ";
    cin >> opcion;
    cout << "---------------------------------" << endl;
    if(opcion == "1"){
        //funcion para gestioanr la venta
        //
        cout << "Gestionando ventas..." << endl;
    } else if(opcion == "2"){
        //fucnion para gestionar pedidos
        cout << "Gestionando pedidos..." << endl;
    } else {
        cout << "Opción Incorrecta" << endl;
    }
}

void inventario(){
    string opcion;
    cout << "---------------------------------" << endl;
    cout << "---- MENÚ INVENTARIO ----" << endl;
    cout << "1. Agregar Producto" << endl
         << "2. Ver Productos" << endl
         << "Ingresar una opcion: ";
    cin >> opcion;
    cout << "---------------------------------" << endl;
    if(opcion == "1"){
        //funcion para agregar el producto
        cout << "Agregando producto..." << endl;
    } else if(opcion == "2"){
        //funcion para mostrar los productos
        cout << "Mostrando productos..." << endl;
    } else {
        cout << "Opción Incorrecta." << endl;
    }
}

int main(){
    int id,idEmpleados=0, idCLientes=0, idVentas=0, idPedidos=0;
    string opcion="g", opcionEmpleados="g", opcionClientes="g";

    while(opcion != "3"){
        cout << "---------------------------------" << endl;
        cout << "---- MENÚ PRINCIPAL ----" << endl;
        cout << "1. Gestion de Empleados" << endl
             << "2. Gestion de Clientes" << endl
             << "3. Salir" << endl;
        cout << "Ingresar una opcion: ";
        cin >> opcion;
        cout << "---------------------------------" << endl;

        if(opcion == "1"){
            cout << "---- MENÚ EMPLEADOS ----" << endl;
            cout << "1. Agregar empleado" << endl
                 << "2. Ingresar ID de empleado" << endl;
            cout << "Ingresar una opcion: ";
            cin >> opcionEmpleados;
            if(opcionEmpleados == "1"){
                idEmpleados++;
                agregarEmpleados(idEmpleados);
            } else if(opcionEmpleados == "2"){
                cout << "---------------------------------" << endl;
                cout << "Ingresar ID: ";
                cin >> id;
                //el id sera generado o asignado
                //sera un numero o sera el tipo
                if(arbolEmpleados->buscar(id).departamento=="administrativo"){
                    administracion();
                } else if (arbolEmpleados->buscar(id).departamento=="inventario") {
                    inventario();
                }else{
                    cout << "Ingreso un ID incorrecto";
                }
            } else {
                cout << "Opción Incorrecta" << endl;
            }

        } else if(opcion == "2"){
            cout << "---- MENÚ CLIENTES ----" << endl;
            cout << "1. Agregar cliente" << endl
                 << "2. Hacer un pedido como cliente" << endl;
            cout << "Ingresar una opcion: ";
            cin >> opcionClientes;
            cout << "---------------------------------" << endl;
            if(opcionClientes == "1"){
                idCLientes++;
                agregarCliente(idCLientes);
            } else if(opcionClientes == "2"){
                cout << "Ingresar ID: ";
                cin >> id;
                datosClientes datos=arbolClientes->buscar(id);
            } else {
                cout << "Opción Incorrecta" << endl;
            }

        } else if(opcion == "3"){
            cout << "Saliendo del sistema..." << endl;
        } else {
            cout << "Opción Incorrecta." << endl;
        }

        cout << endl;
    }

    return 0;
}