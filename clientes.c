#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "clientes.h"
#include "menu.h"
#include "proveedores.h"
#include "descuentosclientes.h"

//Cabecera:
//Precondicion:
//Postcondicion:
Cliente *CrearCliente(Cliente *arrayClientes, int *n_clientes/*, int op*/){

    Cliente *nuevoarray;

    int control = 0, opcion, permiso = 1, Clientes, cartera, elminado = 0;
    char nombre[21], Direccion[51], localidad[21], Provincia[21], email[31], contrasena[16];

    *n_clientes += 1;
    Clientes = *n_clientes;
    nuevoarray = (Cliente*)realloc(arrayClientes, (*n_clientes) * sizeof(Cliente));

    // Formulario registro
    while(control == 0){
        printf("Introduce email (maximo 30 caracteres): "); /*Colocar*/fflush(stdin);
        fgets(email, 31, stdin);
        EliminarSaltoDeLinea(email);
        fflush(stdin);

        /*while(BuscarCliente(email, arrayClientes, Clientes-1) != -1){        //Comparar que no exista otro Cliente igual
            printf("\nEl Cliente introducido ya existe, vuelva a introducir otro (maximo 5 caracteres): ");
            scanf("%s", email);
            EliminarSaltoDeLinea(email);
            fflush(stdin);
        }
*/
        //Formulario datos de Cliente
        printf("Introduce contrasena (maximo 15 caracteres): ");
        fgets(contrasena, 16, stdin);
        EliminarSaltoDeLinea(contrasena);
        fflush(stdin);
        printf("\nIntroduce nombre y apellido (maximo 20 caracteres): ");
        fgets(nombre, 21, stdin);
        EliminarSaltoDeLinea(nombre);
        fflush(stdin);
        printf("Introduce direccion (maximo 50 caracteres): ");
        fgets(Direccion, 51, stdin);
        EliminarSaltoDeLinea(Direccion);
        fflush(stdin);
        printf("Introduce localidad (maximo 20 caracteres): ");
        fgets(localidad, 21, stdin);
        EliminarSaltoDeLinea(localidad);
        fflush(stdin);
        printf("Introduce Provincia (maximo 20 caracteres): ");
        fgets(Provincia, 21, stdin);
        EliminarSaltoDeLinea(Provincia);
        fflush(stdin);

        // Validacion datos
        printf("\n¿Son correctos los datos introducidos?");
        printf("email: %s\ncontrasena: %s\nNombre: %s\nDireccion: %s\nLocalidad: %s\nProvincia: %s\n1.- Si || 2.- No || 3.- Cancelar registro\n", email, contrasena, nombre, Direccion, localidad, Provincia);
        scanf("%i", &opcion);
        while(opcion < 1 && opcion > 3){
            printf("Error, vuelva a introducir: ");
            scanf("%i", &opcion);
        }                                               //El Cliente valida los datos, si son correctos continua y almacena los datos, si no comienza de nuevo el registro

        // Verificacion y guardado de Cliente con su nueva id;
        if(opcion == 2) printf("Repita el formulario con los datos correctos.\n");
        else{
            if(opcion == 3){
                *n_clientes -= 1;                //Si no se registra quitamos el Cliente anadido al principio
                memcpy(nuevoarray, arrayClientes, *n_clientes);              //Si no se registras, remplazamos el array temporal por el original para que no se pierda ningun dato sin el nuevo Cliente registrado
                control = 1;
            }
            else{
                // Guardar en estructura
                nuevoarray[*n_clientes - 1].Id_Cliente = nuevoarray[*n_clientes - 2].Id_Cliente + 1;
                nuevoarray[*n_clientes - 1].Eliminado = 0;

                strcpy(nuevoarray[*n_clientes - 1].email, email);
                strcpy(nuevoarray[*n_clientes - 1].Contrasena, contrasena);
                strcpy(nuevoarray[*n_clientes - 1].Nomb_Cliente, nombre);
                strcpy(nuevoarray[*n_clientes - 1].Dir_cliente, Direccion);
                strcpy(nuevoarray[*n_clientes - 1].Localidad, localidad);
                strcpy(nuevoarray[*n_clientes - 1].Provincia, Provincia);

                nuevoarray[*n_clientes - 1].Cartera = 0;  //Dinero inicial

                control = 1;
            }
        }
    }
    // Cierre
    return nuevoarray;         //Devolvemos el array al original con los datos del nuevo Cliente o como estaba al principio si no se registra

}

int login(Cliente *arrayClientes int *id, int *n_clientes){

    int perm = -1, cont = 0, posicion, control = 0, aux, n_clientes_aux, i = 0, intento = 0;
    char email_aux[21], contrasena_aux[9];

    n_clientes_aux = *n_clientes;
    n_proveedores_aux = *n_proveedores;

    while(perm < 0){
        printf("");
        scanf("%s", email_aux);

        if(BuscarCliente(Cliente *arrayClientes, n_clientes_aux, 0, email_aux, 0, 2) != 1){
            perm = 2;
        }
        else{
            if(BuscarProveedor() != -1){
                perm = arrayProveedores[posicion].Perfil_usuario;
            }
            else{
                printf("\nError, usuario no encontrado, vuelva a intentarlo...");
                intento++;
                if(intentos > 3){

                }
            }
        }
    }

    return perm;  //0 ADMIN, 1 PROVEEDOR, 2 CLIENTE, 3 ERROR NO EXISTE

}

//Cabecera:
//Precondicion:
//Postcondicion:
void ListarCliente(Cliente *arrayClientes, int n_clientes, int op, int posicion){

    int i;

    if(posicion == -1){
        for(i = 0; i < n_clientes, i++){
            printf("ID:%i  Nombre: %s  Direccion: %s  Localidad: %s  Provincia: %s", arrayClientes[i].Id_cliente, arrayClientes[i].Nomb_cliente, arrayClientes[i].Dir_cliente, arrayClientes[i].Localidad, arrayClientes[i].Provincia);
            if(op == 1) printf("\nEmail: %s  Contrasena: %s  Cartera: %s", arrayClientes[i].email, arrayClientes[i].Contrasena, arrayClientes[i].Cartera);
            puts("");
        }
    }
    else{
        printf("ID:%i  Nombre: %s  Direccion: %s  Localidad: %s  Provincia: %s", arrayClientes[posicion].Id_cliente, arrayClientes[posicion].Nomb_cliente, arrayClientes[posicion].Dir_cliente, arrayClientes[posicion].Localidad, arrayClientes[posicion].Provincia);
        if(op == 1) printf("\nEmail: %s  Contrasena: %s  Cartera: %s", arrayClientes[i].email, arrayClientes[i].Contrasena, arrayClientes[i].Cartera);
        punts("");
    }

}

//Cabecera:
//Precondicion:
//Postcondicion:
int BuscarCliente(Cliente *arrayClientes, int n_clientes, char nombre, char email, int id, int op){

    int i, control = 0, posicion = -1, opcion;

    switch(op){
        case 1:
            for(i = 0; i < n_clientes && control == 0; i++){
                if(strcmp(nombre, arrayClientes[i].nombre) == 0){
                    printf("\nNombre: %s  Email: %s\n¿Es el cliente que busca? (1.-Si / 2.-NO):  ", arrayClientes[i].Nomb_cliente, arrayClientes[i].email);
                    scanf("%i", &opcion);
                    while(opcion != 1 && opcion != 2){
                        printf("\nError, valor no valido, vuelva a introducir (1.-Si / 2.-NO):  ");
                        scanf("%i", &opcion);
                    }
                    if(opcion == 1){
                        posicion = i;
                        control = 1;
                    }
                }
            }
            break;
        case 2:
            for(i = 0; i < n_clientes && control == 0; i++){
                if(strcmp(email, arrayClientes[i].email) == 0){
                    posicion = i;
                    control = 1;
                }
            }
            break;
        case 3:
            for(i = 0; i < n_clientes && control == 0; i++){
                if(id == arrayClientes[i].Id_cliente){
                    posicion = i;
                    control = 1;
                }
            }
            break;
    default: printf("\nError en la seleccion de modo de busqueda.");
    }

    printf("\nError, no se ha encontrado ningun cliente");

    return posicion;

}

//Cabecera:
//Precondicion:
//Postcondicion:
void EliminarCliente(Cliente *arrayCliente, int *n_cliente, int posicion){

    int opcion;

    printf("Nombre: %s  Email: %s\n¿Desea eliminar el cliente? (1.- SI / 2.- NO): ", arrayCliente[posicion].Nomb_cliente, arrayCliente[posicion].email);
    scanf("%i", &opcion);
    while(opcion != 1 && opcion != 2){
        printf("\nError, valor introducido no valido, vuelva a introducirlo: ");
        scanf("%i", &opcion);
    }

    if(opcion == 1){
        arrayCliente[posicion].Eliminado = 1;
        printf("\nEl cliente se ha borrado...");
    }
    else printf("\nCancelado.\nVolviendo...");

}

//Cabecera:
//Precondicion:
//Postcondicion:
Cliente* CargarClientes(int *n_clientes){

    int n_lineas = 0, i;
    Cliente *clientes;
    FILE *f;

    f = fopen("clientes.txt", "r");     //Abrimos archivo de clientes.txt

    if(f == NULL) printf("\nError al abrir clientes.txt");  //Comprobamos que se abre y contenga los datos bien

    n_lineas = ContarLineas(f);     //numeros de lineas igual al nuemro de clientes
    *n_clientes = n_lineas;
    clientes = (Cliente*)calloc(n_lineas, sizeof(Cliente));     //Memoria dinamica estrucutura
    if( clientes == NULL ) {
        fprintf (stderr, "Error de asignación de memoria") ;
        exit (1);
    }

    rewind(f);

    for(i = 0; i < n_lineas; i++){                      //Bucle que almacena los datos de los clientes uno a uno
        fscanf(f, "%d-", &clientes[i].Id_cliente);
        fscanf(f, "%[^-]-", clientes[i].Nomb_cliente);
        fscanf(f, "%[^-]-", clientes[i].Dir_cliente);
        fscanf(f, "%[^-]-", clientes[i].Localidad);
        fscanf(f, "%[^-]-", clientes[i].Provincia);
        fscanf(f, "%[^-]-", clientes[i].email);
        fscanf(f, "%[^-]-", clientes[i].Contrasena);
        fscanf(f, "%d[^\n]\n", &clientes[i].Cartera);
        clientes[i].Eliminado = 0;
    }

    fclose(f);
    return clientes;

}

//Cabecera:
//Precondicion:
//Postcondicion:
void GuardarEstrucutura(Cliente *arrayClientes, int n_Clientes){

    int i = 0;

    FILE *f;

    f = fopen("Clientes.txt","w");      //Abrimos el archivo el modo escritura
    if(f == NULL) printf("\nError al abrir Clientes.txt");

    while(i < n_Clientes){      //Guardamos la estructura Cliente a Cliente en Cliente.txt
        if(arrayClientes[i].Eliminado != 1){        //Solo si no esta borrado

            fprintf(f, "%07i", arrayClientes[i].Id_cliente);
            fputc('-', f);
            fputs(arrayClientes[i].Nomb_cliente, f);
            fputc('-', f);
            fputs(arrayClientes[i].Dir_cliente, f);
            fputc('-', f);
            fputs(arrayClientes[i].Localidad, f);
            fputc('-', f);
            fputs(arrayClientes[i].Provincia, f);
            fputc('-', f);
            fputs(arrayClientes[i].email, f);
            fputc('-', f);
            fputs(arrayClientes[i].Contrasena, f);
            fputc('-', f);
            fprintf(f, "%d", arrayClientes[i].Cartera);

            if(i != n_Clientes-1) fputc('\n', f);
        }
        i++;
    }

    fclose(f);      //Cerramos archivo

}

//Cabecera:
//Precondicion:
//Postcondicion:
int ContarLineas(FILE *f){

    int i = 1;
    char c;

    while((c = fgetc(f)) != EOF){
        if(c == '\n') i++;              //Cuenta las lineas si hay un salto de linea y no esta vacio
    }

    rewind(f);

    return i;

}

//Cabecera: funcion EliminarSaltoDeLinea(E/S cadena: cadena)
//Precondicion: recibe una cadena de caracteres valida y no vacia
//Postcondicion: devuelve la cadena sin el salto de linea del final
void EliminarSaltoDeLinea(char *cadena){

	int i = strlen(cadena);

	if(cadena[i-1] == '\n') cadena[i-1] = '\0';     //Eliminamos el salto de linea de las cadenas de caracteres
}
