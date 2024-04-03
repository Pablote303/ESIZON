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

    int n_clientes, n_proveedores, n_descuentosclientes, posicion, permisos;

    //Carga de estructuras
    Cliente *arrayClientes;
    arrayClientes = CargarClientes(&n_clientes);

    Proveedor *arrayProveedores;
    arrayProveedores = CargarProveedores(&n_proveedores);

    DescuentoCliente *arrayDescuentosClientes;
    arrayDescuentosClientes = CargarDescuentosClientes(&n_descuentosclientes);

    /*INICIAL*/
        // INICIAR SESION

        // CREAR CUENTA "SOLO CLIENTE"   �

    /*MENU CLIENTES*/
        /*PERFIL*/
            // DATOS  �
            // MODIFICAR  �
            // CONSULTAR CARTERA
            // ANADIR FONDOS
        /*DESCUENTOS*/
            // CONSULTAR DESCUENTO CLIENTES
    void MenuCliente(*arrayClientes, *n_clientes, permisos)

    /*MENU ADMIN*/
        /*PERFIL*/
            // DATOS    �
            // MODIFICAR
        /*CLIENTES*/
            // ALTA   �
            // BAJA   �
            // BUSQUEDA    �
            // LISTADO   �
            // MODIFICAR    �
        /*PROVEEDORES*/
            // ALTA   �
            // BAJA   �
            // BUSQUEDA    �
            // LISTADO     �
            // MODIFICAR
        /*DESCUENTO*/
            /*CLIENTE*/
                // ASIGNAR CHEQUE / PROMOCION A CLIENTE
                // QUITAR CHEQUE / PROMOCION A CLIENTE
                // CONSULTAR CHEQUE / PROMOCION CLIENTES
    void MenuAdmin(*arrayClientes, *arrayProveedores, *arrayDescuentosClientes, *n_clientes, *n_proveedores, *n_descuentosclientes, posicion, permisos);


    /*MENU PROVEEDOR*/
        /*PERFIL*/
            // DATOS   �
            // MODIFICAR
    void MenuProveedor(*arrayClientes, *arrayProveedores, *arrayDescuentosClientes, *n_clientes, *n_proveedores, *n_descuentosclientes, posicion, permisos);


    //Guardar estructuras en fichero


    return 0;

}

//Cabecera:
//Precondicion:
//Postcondicion:
void MenuCliente(Cliente *arrayClientes, int *n_clientes, int *posicion, int permisos){

    int opcion, opcion2, opcion3;

    printf("Bienvenido %s\n\nMenu:\n", arrayClientes[posicion].Nomb_cliente);

    do{

        printf("1.- Perfil\n2.- Productos\n3.- Descuentos\n4.- Pedidos\n5.- Devoluciones\n6.- Salir del sistema\n");
        scanf("%i", &opcion);

        switch(opcion){
            case 1:
                do{
                    printf("Perfil\n\n1.- Consultar Datos\n2.- Modificar Datos\n3.- Anadir fondos a la Cartera\n4.- Volver al menu principal\n");
                    scanf("%i", &opcion2);

                    switch(opcion2){
                        case 1:
                            //Funcion Consultar
                            break;
                        case 2:
                            //Funcion Modificar
                            break;
                        case 3:
                            //Funcion añadir fondos
                            break;
                        case 4:
                            printf("Volviendo...");
                            break;
                        default:
                            printf("\nError, opcion no valida, vuelva a introducir");
                    }
                } while(opcion2 < 1 || opcion2 > 4);
                break;
            case 2:
                break;
            case 3:
                //Menu descuentos
                //Funcion consultar descuentos clientes
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                printf("Saliendo...\n\nAdios %s", arrayClientes[posicion].Nomb_cliente);
                break;
            default:
                printf("\nError, opcion no valida, vuelva a introducir");
        }

    } while(opcion != 6);

}

//Cabecera:
//Precondicion:
//Postcondicion:
void MenuProveedor(Cliente *arrayClientes, Proveedor *arrayProveedores, DescuentoCliente *arrayDescuentosClientes, int n_clientes, int n_proveedores, int n_descuentosclientes, int posicion, int permisos){

    int opcion, opcion2, opcion3;

    printf("Bienvenido %s\n\nMenu:\n", arrayClientes[posicion].Nomb_cliente);

    do{
        printf("1.- Perfil\n2.- Productos\n3.- Pedidos\n4.- Salir");
        scanf("%i", &opcion);

        switch(opcion){
            case 1:
                do{
                    printf("Perfil\n\n1.- Consultar Datos\n2.- Modificar Datos\n3.- Volver al menu principal\n");
                    scanf("%i", &opcion2);

                    switch(opcion2){
                        case 1:
                            //Funcion Consultar
                            break;
                        case 2:
                            //Funcion Modificar
                            break;
                        case 3:
                            printf("Volviendo...");
                            break;
                        default:
                            printf("\nError, opcion no valida, vuelva a introducir");
                    }
                } while(opcion2 < 1 || opcion2 > 3);
                break;
            case 2:
                //Menu producto
                break;
            case 3:
                //Menu Pedidos
                break;
            case 4:
                printf("Saliendo...\nAdios %s", arrayProveedores[posicion].Nombre);
                break;
            default:
                printf("Error, la opcion no es valida, vuelva a introducir.\n\n");
        }

    } while(opcion != 4)

}

void MenuAdmin(Cliente *arrayClientes, Proveedor *arrayProveedores, DescuentoCliente *arrayDescuesntosClientes, *n_clientes, *n_proveedores, *n_descuentosclientes, posicion, permisos){

    int opcion, opcion2, opcion3;

    printf("Bienvenido %s (ADMINISTRADOR)\n\nMenu:\n", arrayClientes[posicion].Nomb_cliente);

    do{

        printf("1.- Perfil\n2.- Clientes\n3.- Proveedores\n4.- Productos\n5.- Categorias\6.- Pedidos\n7.- Transportistas\n8.- Descuentos\n9.- Devoluciones\n10.- Salir");
        scanf("%i", &opcion);

        switch(opcion){
            case 1:
                printf("Perfil\n\n1.- Consultar Datos\n2.- Modificar Datos\n3.- Volver al menu principal\n");
                scanf("%i", &opcion2);

                switch(opcion2){
                    case 1:
                        //Funcion Consultar
                        break;
                    case 2:
                        //Funcion Modificar
                        break;
                    case 3:
                        printf("Volviendo...");
                        break;
                    default:
                        printf("\nError, opcion no valida, vuelva a introducir");
                    }
                } while(opcion2 < 1 || opcion2 > 3);
                break;
            case 2:
                //Menu Clientes
                break;
            case 3:
                //Menu Proveedores
                break;
            case 4:
                //Menu Productos
                break;
            case 5:
                //Menu Categorias
                break;
            case 6:
                //Menu Pedidos
                break;
            case 7:
                //Menu Transportistas
                break;
            case 8:
                //Menu Descuentos
                break;
            case 9:
                //Menu Devoluciones
                break;
            case 10:
                printf("Saliendo...\nAdios %s", arrayProveedores[posicion].Nombre);
                break;
            default:
                printf("Error, la opcion no es valida, vuelva a introducir.\n\n");
        }

    } while(opcion != 10);

}
