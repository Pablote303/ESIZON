#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "menu.h"
#include "clientes.h"
#include "proveedores.h"
#include "descuentosclientes.h"

//Cabecera:
//Precondicion:
//Postcondicion:
void menu(){

    int n_clientes, n_proveedores, n_descuentosclientes;

    //Carga de estructuras
    Cliente *arrayClientes;
    arrayClientes = CargarClientes(&n_clientes);

    Proveedor *arrayProveedores;
    arrayProveedores = CargarProveedores(&n_proveedores);

    DescuentoCliente *arrayDescuentosClientes;
    arrayDescuentosClientes = CargarDescuentosClientes(&n_descuentosclientes);

    /*INICIAL*/
        // INICIAR SESION
        // CREAR CUENTA "SOLO CLIENTE"   º

    /*MENU CLIENTES*/
        /*PERFIL*/
            // DATOS  º
            // MODIFICAR  º
            // CONSULTAR CARTERA
            // ANADIR FONDOS
        /*DESCUENTOS*/
            // CONSULTAR DESCUENTO CLIENTES


    /*MENU ADMIN*/
        /*PERFIL*/
            // DATOS    º
            // MODIFICAR
        /*CLIENTES*/
            // ALTA   º
            // BAJA   º
            // BUSQUEDA    º
            // LISTADO   º
            // MODIFICAR    º
        /*PROVEEDORES*/
            // ALTA   º
            // BAJA   º
            // BUSQUEDA    º
            // LISTADO     º
            // MODIFICAR
        /*DESCUENTO*/
            /*CLIENTE*/
                // ASIGNAR CHEQUE / PROMOCION A CLIENTE
                // QUITAR CHEQUE / PROMOCION A CLIENTE
                // CONSULTAR CHEQUE / PROMOCION CLIENTES


    /*MENU PROVEEDOR*/
        /*PERFIL*/
            // DATOS   º
            // MODIFICAR


    //Guardar estructuras en fichero


    return 0;

}
