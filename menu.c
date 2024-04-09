#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "menu.h"
#include "clientes.h"
#include "proveedores.h"
#include "descuentosclientes.h"

crear_archivo(const char *nombre_archivo);

//Cabecera:
//Precondicion:
//Postcondicion:
void menu(){

    int n_clientes, n_proveedores, n_descuentosclientes, opcion, posicion, permisos;

    if(INI() == 1){
        crear_archivo("Clientes.txt");
        crear_archivo("Productos.txt");
        crear_archivo("Categorias.txt");
        crear_archivo("Descuentos.txt");
        crear_archivo("DescuentosClientes.txt");
        crear_archivo("Lockers.txt");
        crear_archivo("CompartimientosLockers.txt");
        crear_archivo("Pedidos.txt");
        crear_archivo("ProductosPedidos.txt");
        crear_archivo("Transportistas.txt");
        crear_archivo("Devoluciones.txt");
    }

    //Carga de estructuras
    Cliente *arrayClientes;
    arrayClientes = CargarClientes(&n_clientes);

    Proveedor *arrayProveedores;
    arrayProveedores = CargarProveedores(&n_proveedores);

    DescuentoCliente *arrayDescuentosClientes;
    arrayDescuentosClientes = CargarDescuentosClientes(&n_descuentosclientes);

    /*INICIAL*/
        // INICIAR SESION       º

        // CREAR CUENTA "SOLO CLIENTE"   �

    printf("Bienvenido a ESIZON\n\n");

    do{
        printf("1.- Iniciar sesion.\n2.- Registrarse.\n3.- Salir.\n");
        scanf("%i", &opcion);

        switch(opcion){
            case 1:
                permisos = login(*arrayClientes, *arrayProveedores, *posicion, *n_clientes, *n_proveedores);
                if(perm == -1 || perm == 3) printf("\nVolviendo al menu...\n");
                else{
                    if(perm == 2) void MenuCliente(*arrayClientes, *n_clientes, permisos);
                    else{
                        if(perm == 1) void MenuProveedor(*arrayClientes, *arrayProveedores, *arrayDescuentosClientes, *n_clientes, *n_proveedores, *n_descuentosclientes, posicion, permisos);
                        if(perm == 0) void MenuAdmin(*arrayClientes, *arrayProveedores, *arrayDescuentosClientes, *n_clientes, *n_proveedores, *n_descuentosclientes, posicion, permisos);
                    }
                }
                break;
            case 2:
                arrayClientes = CrearCliente(arrayClientes, *n_clientes);
                break;
            case 3:
                printf("\n\nCerrando el programa, adios...\n\n");
                break;
            default: printf("Error, opcion no valida, vuelva a introducir...\n\n");
        }

    } while(opcion != 3);

    /*MENU CLIENTES*/
        /*PERFIL*/
            // DATOS  �
            // MODIFICAR  �
            // CONSULTAR CARTERA    º
            // ANADIR FONDOS    º
        /*DESCUENTOS*/
            // CONSULTAR DESCUENTO CLIENTES

    /*MENU ADMIN*/
        /*PERFIL*/
            // DATOS    �
            // MODIFICAR    º
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
            // MODIFICAR    º
        /*DESCUENTO*/
            /*CLIENTE*/
                // ASIGNAR CHEQUE / PROMOCION A CLIENTE
                // QUITAR CHEQUE / PROMOCION A CLIENTE
                // CONSULTAR CHEQUE / PROMOCION CLIENTES


    /*MENU PROVEEDOR*/
        /*PERFIL*/
            // DATOS   �
            // MODIFICAR    º


    //Guardar estructuras en fichero
    GuardarEstructuraC(arrayClientes, n_clientes);
    GuardarEstructuraP(arrayProveedores, n_clientes);
    GuardarEstrucuturaCD(arrayDescuentosClientes, n_descuentosclientes);


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


    } while(opcion != 10);

}

//Cabecera: entero INI()
//Precondicion:
//Postcondicion:
int INI(){

    int control = 0;
    char contrasena[9];

    FILE *f;

    f = fopen("AdminProv.txt","r");
    if(f == NULL){
        control = 1;

        f = fopen("AdminProv.txt", "w");

        printf("Iniciando programa, creando archivos...\nIntroduce la contrasena para el usuario root: ");
        scanf("%s", contrasena);
        fflush(stdin);

        fputs("0000001", f);
        fputc('-', f);
        fputs("ROOT, f);
        fputc('-', f);
        fputs("root@esizon.com", f);
        fputc('-', f);
        fputs(crontrasena, f);
        fputc('-', f);
        puts("administrador", f);

        fclose(f);
    }
    else fclose(f);

    return control;

}

//Cabecera: funcion crear_archivo(E cadena: nombre_archivo)
//Precondicion: debe recibir una cadena de caracteres
//Postcondicion: si el archivo no existe lo crea sin contenido
void crear_archivo(const char *nombre_archivo){

    FILE* f;

    f = fopen(nombre_archivo, "r");
    if (f == NULL) {
        f = fopen(nombre_archivo, "w");
        fclose(f);
        printf("El archivo %s ha sido creado.\n", nombre_archivo);
    }
    else{
        fclose(f);
        printf("El archivo %s ya existe.\n", nombre_archivo);
    }
}
