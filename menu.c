#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "menu.h"
#include "proveedores.h"
#include "demo.h"
#include "clientes.h"
#include "descuentosclientes.h"

void MenuCliente(Cliente *arrayClientes, DescuentoCliente *arrayDescuentosClientes, Descuento *arraDescuento, int *n_clientes, int *n_descuentosclientes, int *n_descuentos, int posicion, int permisos);
void MenuProveedor(Cliente *arrayClientes, Proveedor *arrayProveedores, DescuentoCliente *arrayDescuentosClientes, int n_clientes, int n_proveedores, int n_descuentosclientes, int posicion, int permisos);
void MenuAdmin(Cliente *arrayClientes, Proveedor *arrayProveedores, DescuentoCliente *arrayDescuesntosClientes, int *n_clientes, int *n_proveedores, int *n_descuentosclientes, int posicion, int permisos);
int INI();
void crear_archivo(const char *nombre_archivo);

//Cabecera:
//Precondicion:
//Postcondicion:
void menu(){

    int n_clientes, n_proveedores, n_descuentosclientes, n_descuentos, opcion, permisos, posicion;

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
    arrayClientes = CargarClientes(&n_clientes); printf("\n *-*- clientes: %i -*-* \n", n_clientes);

    Proveedor *arrayProveedores;
    arrayProveedores = CargarProveedores(&n_proveedores); printf("\n *-*- proveedores: %i -*-* \n", n_proveedores);

    DescuentoCliente *arrayDescuentosClientes;
    arrayDescuentosClientes = CargarDescuentosClientes(&n_descuentosclientes);

    Descuento *arrayDescuentos;
    arrayDescuentos = CargarDescuento(&n_descuentos);

    printf("Bienvenido a ESIZON\n\n");

    do{
        printf("1.- Iniciar sesion.\n2.- Registrarse.\n3.- Salir.\n");
        scanf("%i", &opcion);

        switch(opcion){
            case 1:
                permisos = login(arrayClientes, arrayProveedores, &posicion, &n_clientes, &n_proveedores);printf("pos: %i", posicion);
                if(permisos == -1 || permisos == 3) printf("\nVolviendo al menu...\n");
                else{
                    if(permisos == 2) MenuCliente(arrayClientes, arrayDescuentosClientes, arrayDescuentos, &n_clientes, &n_descuentosclientes, &n_descuentos, posicion, permisos);
                    else{
                        if(permisos == 1) MenuProveedor(arrayClientes, arrayProveedores, arrayDescuentosClientes, &n_clientes, &n_proveedores, &n_descuentosclientes, posicion, permisos);
                        if(permisos == 0) MenuAdmin(arrayClientes, arrayProveedores, arrayDescuentosClientes, &n_clientes, &n_proveedores, &n_descuentosclientes, posicion, permisos);
                    }
                }
                break;
            case 2:
                arrayClientes = CrearCliente(arrayClientes, &n_clientes);
                break;
            case 3:
                printf("\n\nCerrando el programa, adios...\n\n");
                break;
            default: printf("Error, opcion no valida, vuelva a introducir...\n\n");
        }

    } while(opcion != 3);


    //Guardar estructuras en fichero
    if(n_clientes != 0 ) GuardarEstructuraC(arrayClientes, n_clientes);
    free(arrayClientes);
    if(n_proveedores != 0 ) GuardarEstructuraP(arrayProveedores, n_proveedores);
    free(arrayProveedores);
    if(n_descuentosclientes != 0 ) GuardarEstrucuturaCD(arrayDescuentosClientes, n_descuentosclientes);
    free(arrayDescuentosClientes);
    //Guardar Estructura Productos
    //Guardar Estructura Categoria
    //Guardar Estructura Descuentos
    GuardarEstructuraD(arrayDescuentos, n_descuentos);
    free(arrayDescuentos);
    //Guardar Estructura Lockers
    //Guardar Estructura Compartimientos Lockers
    //Guardar Estructura Pedidos
    //Guardar Estructura Productos Pedidos
    //Guardar Estructura Transportistas
    //Guardar Estructura Devoluciones


    return 0;

}

//Cabecera:
//Precondicion:
//Postcondicion:
void MenuCliente(Cliente *arrayClientes, DescuentoCliente *arrayDescuentosClientes, Descuento *arrayDescuento, int *n_clientes, int *n_descuentosclientes, int *n_descuentos, int posicion, int permisos){
printf("ControlCLientes0 %i", posicion);
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
                            ListarCliente(arrayClientes, n_clientes, posicion, 1);
                            break;
                        case 2:
                            ModificarCliente(arrayClientes, posicion);
                            break;
                        case 3:
                            Cartera(arrayClientes, posicion, 3, 0);
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
                printf("Descuentos del clientes:\n");
                ListarDescuentosCliente(arrayDescuentosClientes, arrayClientes, arrayDescuento, n_descuentosclientes, n_descuentos, posicion);
                //Funcion consultar descuentos clientes
                break;
            case 4:
                //Pedidos
                break;
            case 5:
                //Devoluciones
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

    int opcion, opcion2;

    printf("Bienvenido %s\n\nMenu:\n", arrayProveedores[posicion].Nombre);

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
                            ListarProveedores(arrayProveedores, n_proveedores, 0, posicion);
                            break;
                        case 2:
                            ModificarProveedor(arrayProveedores, n_proveedores, posicion, 1);
                            break;
                        case 3:
                            printf("Volviendo...");
                            break;
                        default:
                            printf("\nError, opcion no valida, vuelva a introducir");
                            break;
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

    } while(opcion != 4);

}

void MenuAdmin(Cliente *arrayClientes, Proveedor *arrayProveedores, DescuentoCliente *arrayDescuesntosClientes, int *n_clientes, int *n_proveedores, int *n_descuentosclientes, int posicion, int permisos){

    int opcion, opcion2;

    printf("Bienvenido %s (ADMINISTRADOR)\n\nMenu:\n", arrayProveedores[posicion].Nombre);

    do{

        printf("1.- Perfil\n2.- Clientes\n3.- Proveedores\n4.- Productos\n5.- Categorias\6.- Pedidos\n7.- Transportistas\n8.- Descuentos\n9.- Devoluciones\n10.- Salir");
        scanf("%i", &opcion);

        switch(opcion){
            case 1:
                printf("Perfil\n\n1.- Consultar Datos\n2.- Modificar Datos\n3.- Volver al menu principal\n");
                scanf("%i", &opcion2);

                do{
                switch(opcion2){
                    case 1:
                        ListarProveedores(arrayProveedores, n_proveedores, 1, posicion);
                        break;
                    case 2:
                        ModificarProveedor(arrayProveedores, n_proveedores, posicion, 3);
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
                puts("");//Menu Proveedores
                break;
            case 4:
                puts("");//Menu Productos
                break;
            case 5:
                puts("");//Menu Categorias
                break;
            case 6:
                puts("");//Menu Pedidos
                break;
            case 7:
                puts("");//Menu Transportistas
                break;
            case 8:
                //Menu Descuentos
                break;
            case 9:
                puts("");//Menu Devoluciones
                break;
            case 10:
                printf("Saliendo...\nAdios %s", arrayProveedores[posicion].Nombre);
                break;
            default:
                printf("Error, la opcion no es valida, vuelva a introducir.\n\n");
                break;
        }

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
        fputs("ROOT", f);
        fputc('-', f);
        fputs("root@esizon.com", f);
        fputc('-', f);
        fputs(contrasena, f);
        fputc('-', f);
        fputs("admin", f);

        fclose(f);
    }
    else fclose(f);
/*
    f = fopen("AdminProv.txt","r");
    if(f == NULL){
        control = 1;

        f = fopen("AdminProv.txt", "w");

        fputs("0000001", f);
        fputc('-', f);
        fputs("ROOT", f);
        fputc('-', f);
        fputs("ESIZON", f);
        fputc('-', f);
        fputs("ESIZON", f);
        fputc('-', f);
        fputs("ESIZON", f);
        fputc('-', f);
        fputs("root@cliente.com", f);
        fputc('-', f);
        fputs(contrasena, f);
        fputc('-', f);
        fputs("administrador", f);

        fclose(f);
    }
    else fclose(f);

    printf("\nSe ha generado los perfiles:\nAdmin: root@esizon.com\nCliente: root@cliente.com\nAmbas con misma contrasena.\n");
*/
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
