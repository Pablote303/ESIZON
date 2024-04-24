#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "proveedores.h"
#include "demo.h"
#include "clientes.h"
#include "descuentosclientes.h"

#define MINIMO 5

//Cabecera:
//Precondicion: Cargada e inicializada la estructura de Clientes.txt, numero de clientes totales
//Postcondicion: Crea un nuevo registro de cliente y lo añade a la estructura
Cliente *CrearCliente(Cliente *arrayClientes, int *n_clientes){

    Cliente *nuevoarray;

    int control = 0, opcion, Clientes;
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

        while(BuscarCliente(arrayClientes, Clientes, 0, email, 0, 2) != -1){        //Comparar que no exista otro Cliente igual
            printf("\nEl Cliente introducido ya existe, vuelva a introducir otro (maximo 5 caracteres): ");
            scanf("%s", email);
            fflush(stdin);
        }

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
        printf("\nSon correctos los datos introducidos?");
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
                nuevoarray[*n_clientes - 1].Id_cliente = nuevoarray[*n_clientes - 2].Id_cliente + 1;
                nuevoarray[*n_clientes - 1].Eliminado = 0;

                strcpy(nuevoarray[*n_clientes - 1].email, email);
                strcpy(nuevoarray[*n_clientes - 1].Contrasena, contrasena);
                strcpy(nuevoarray[*n_clientes - 1].Nomb_cliente, nombre);
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

// Cabecera:
// Precondicion: estructura cargada e inicializada, debe existir al menos un administrador, numero de cientes sin ser necesario que exista uno
// Poscondicion: devuelve la posicion y permisos, del cliente, proveedor o administrador
int login(Cliente *arrayClientes, Proveedor *arrayProveedores, int *id, int *n_clientes, int *n_proveedores){

    int perm = -1, posicion, control = 0, n_clientes_aux, n_proveedores_aux, intento = 0;
    char email_aux[21], contrasena_aux[9];

    n_clientes_aux = *n_clientes;
    n_proveedores_aux = *n_proveedores;

    while(perm == -1){
        printf("Introduzca usuario (email): ");
        scanf("%s", email_aux);
        EliminarSaltoDeLinea(email_aux);
        fflush(stdin);

        if((posicion = BuscarCliente(arrayClientes, n_clientes_aux, 0, email_aux, 0, 2)) != -1){
            perm = 2;
        }
        else{
            if((posicion = BuscarProveedor(arrayProveedores, n_proveedores_aux, 0, email_aux, 0, 2)) != -1){
                perm = arrayProveedores[posicion].Perfil_usuario;
            }
            else{
                printf("\nError, usuario no encontrado, vuelva a intentarlo... (Intentos: %i)", 3 - intento);
                intento++;
            }
        }
        if(intento >= 3){
            perm = 3;
            printf("\nUsuario no encontrado, intentos maximos alcanzdaos, vuelva a intentarlo mas tarde...");
        }
    }

    if(perm != 3 && perm != -1){
        for(intento = 0; intento < 3 && control == 0; intento++){
            printf("Introduzca la contrasena: ");
            scanf("%s", contrasena_aux);
            fflush(stdin);
            EliminarSaltoDeLinea(contrasena_aux);

            if(perm == 2){
                //Comparar contrasena clientes
                if(strcmp(contrasena_aux, arrayClientes[posicion].Contrasena) == 0){
                    control = 1;
                    *id = posicion;
                }
                else{
                    printf("Contrasena incorrecta.\n");
                }
            }
            else{
                //comparar contrasena proveedores
                if(strcmp(contrasena_aux, arrayProveedores[posicion].Contrasena) == 0){
                    control = 1;
                    perm = arrayProveedores[posicion].Perfil_usuario;
                    *id = posicion;
                }
                else{
                    printf("Contrasena incorrecta.\n");
                }
            }
            if(intento == 3){
                printf("\nIntentos de iniciar sesion superados...\n");
                perm = -1;
            }
        }
    }

    return perm;  //0 ADMIN, 1 PROVEEDOR, 2 CLIENTE, 3 ERROR NO EXISTE, -1 CONTRASENA INCORRECTA

}

//Cabecera:
//Precondicion: estructura cargada e inicializada, numero de clientes
//Postcondicion: devuelve en pantalla el listado de clientes y sus datos (segun quien los visualice), en case de no haber ningun cliente no muestra nada y vuelve al menu.
void ListarCliente(Cliente *arrayClientes, int n_clientes, int posicion, int op){

    int i;

    if(posicion == -1){
        for(i = 0; i < n_clientes; i++){
            printf("ID:%i  Nombre: %s  Direccion: %s  Localidad: %s  Provincia: %s", arrayClientes[i].Id_cliente, arrayClientes[i].Nomb_cliente, arrayClientes[i].Dir_cliente, arrayClientes[i].Localidad, arrayClientes[i].Provincia);
            if(op == 1) printf("\nEmail: %s  Contrasena: %s  Cartera: %d", arrayClientes[i].email, arrayClientes[i].Contrasena, arrayClientes[i].Cartera);
            puts("");
        }
    }
    else{
        printf("ID:%i  Nombre: %s  Direccion: %s  Localidad: %s  Provincia: %s", arrayClientes[posicion].Id_cliente, arrayClientes[posicion].Nomb_cliente, arrayClientes[posicion].Dir_cliente, arrayClientes[posicion].Localidad, arrayClientes[posicion].Provincia);
        if(op == 1) printf("\nEmail: %s  Contrasena: %s  Cartera: %d", arrayClientes[posicion].email, arrayClientes[posicion].Contrasena, arrayClientes[posicion].Cartera);
        puts("");
    }

}

//Cabecera:
//Precondicion: estructura cargada e inicializada, numero de clientes y recibir al menos de uno de estos datos: email, nombre o id
//Postcondicion: devuelve la posicion del cliente o -1 si no existe
int BuscarCliente(Cliente *arrayClientes, int n_clientes, char *nombre, char *email, int id, int op){

    int i, control = 0, posicion = -1, opcion; printf("\n%s\n", email);

    switch(op){
        case 1:
            for(i = 0; i < n_clientes && control == 0; i++){
                if(strcmp(nombre, arrayClientes[i].Nomb_cliente) == 0){
                    printf("\nNombre: %s  Email: %s\nEs el cliente que busca? (1.-Si / 2.-NO):  ", arrayClientes[i].Nomb_cliente, arrayClientes[i].email);
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

    //printf("\nError, no se ha encontrado ningun cliente");

    return posicion;

}

//Cabecera:
//Precondicion: estrucutura cargada e inicializada y recibe la posicion del cliente
//Postcondicion: modifica los datos en estructura de datos del cliente deseado
void ModificarCliente(Cliente *arrayClientes, int posicion){

    int opcion;
    char aux, modificacion[51], nombre[21], direccion[51], localidad[21], provincia[21], email[31], contrasena[16];

    memset(modificacion, '\0', sizeof(modificacion));
    memset(nombre, '\0', sizeof(nombre));
    memset(direccion, '\0', sizeof(direccion));
    memset(localidad, '\0', sizeof(localidad));
    memset(provincia, '\0', sizeof(provincia));
    memset(email, '\0', sizeof(email));
    memset(contrasena, '\0', sizeof(contrasena));

    //ListarCliente(Cliente *arrayClientes, 0, 1, posicion);

    do{
        if(strlen(nombre) != 0) printf("\nNombre: %s\n", nombre);
        else printf("\nNombre: %s\n", arrayClientes[posicion].Nomb_cliente);
        if(strlen(email) != 0) printf("Email: %s\n", email);
        else printf("Email: %s\n", arrayClientes[posicion].email);
        if(strlen(contrasena) != 0) printf("Contrasena: %s\n", contrasena);
        else printf("Contrasena: %s\n", arrayClientes[posicion].Contrasena);
        if(strlen(direccion) != 0){
            printf("Direccion: %s\nLocalidad: %s\nProvicincia: %s\n", direccion, localidad, provincia);
        }
        else printf("Direccion: %s\nLocalidad: %s\nProvicincia: %s\n", arrayClientes[posicion].Dir_cliente, arrayClientes[posicion].Localidad, arrayClientes[posicion].Provincia);

        printf("\nQue desea modificar?\n1.- Nombre\n2.- Email\n3.- Contrasena\n4.- Direccion\n5.- Salir y Guardar\n6.- Salir sin Guardar\n");
        scanf("%i", &opcion);
        while(opcion < 1 || opcion >6){
            printf("Error, opcion no valida, vuelva a introducir: ");
            scanf("%i", &opcion);
        }
        fflush(stdin);

        switch(opcion){

        case 1:
            printf("\nIntroduzca el nuevo nombre (maximo 20 caracteres): ");
            fgets(modificacion, 21, stdin);
            EliminarSaltoDeLinea(modificacion);
            fflush(stdin);
            printf("%s\nEs correcto? (S/N): ", modificacion);
            scanf("%c", &aux);
            while((aux != 'S' && aux != 's') && (aux != 'N' && aux != 'n')){
                printf("\nError, valor incorrecto, vuelva a introducir: ");
                scanf("%c", &aux);
            }
            if(aux == 'S' || aux == 's'){
                strncpy(nombre, modificacion, sizeof(nombre)-1);
            }
            break;
        case 2:
            printf("\nIntroduzca el nuevo email (maximo 30 caracteres): ");
            scanf("%s", modificacion);
            fflush(stdin);
            printf("%s\nEs correcto? (S/N): ", modificacion);
            scanf("%c", &aux);
            while((aux != 'S' && aux != 's') && (aux != 'N' && aux != 'n')){
                printf("\nError, valor incorrecto, vuelva a introducir: ");
                scanf("%c", &aux);
            }
            if(aux == 'S' || aux == 's'){
                strncpy(email, modificacion, sizeof(email)-1);
            }
            break;
        case 3:
            printf("\nIntroduzca el nueva contrasena (maximo 15 caracteres y sin espacios): ");
            scanf("%s", modificacion);
            fflush(stdin);
            printf("%s\nEs correcto? (S/N): ", modificacion);
            scanf("%c", &aux);
            while((aux != 'S' && aux != 's') && (aux != 'N' && aux != 'n')){
                printf("\nError, valor incorrecto, vuelva a introducir: ");
                scanf("%c", &aux);
            }
            if(aux == 'S' || aux == 's'){
                strncpy(contrasena, modificacion, sizeof(contrasena)-1);
            }
            break;
        case 4:
            printf("\nIntroduzca el nueva direccion (maximo 50 caracteres): ");
            fgets(modificacion, 51, stdin);
            EliminarSaltoDeLinea(modificacion);
            fflush(stdin);
            printf("%s\nEs correcto? (S/N): ", modificacion);
            scanf("%c", &aux);
            while((aux != 'S' && aux != 's') && (aux != 'N' && aux != 'n')){
                printf("\nError, valor incorrecto, vuelva a introducir: ");
                scanf("%c", &aux);
            }
            fflush(stdin);
            if(aux == 'S' || aux == 's'){
                strncpy(direccion, modificacion, sizeof(direccion)-1);
                printf("\nIntroduzca el nueva localidad (maximo 20 caracteres): ");
                fgets(modificacion, 21, stdin);
                EliminarSaltoDeLinea(modificacion);
                fflush(stdin);
                printf("%s\nEs correcto? (S/N): ", modificacion);
                scanf("%c", &aux);
                while((aux != 'S' && aux != 's') && (aux != 'N' && aux != 'n')){
                    printf("\nError, valor incorrecto, vuelva a introducir: ");
                    scanf("%c", &aux);
                }
                fflush(stdin);
                if(aux == 'S' || aux == 's'){
                    strncpy(localidad, modificacion, sizeof(localidad)-1);
                    printf("\nIntroduzca el nueva provincia (maximo 20 caracteres): ");
                    fgets(modificacion, 21, stdin);
                    EliminarSaltoDeLinea(modificacion);
                    fflush(stdin);
                    printf("%s\nEs correcto? (S/N): ", modificacion);
                    scanf("%c", &aux);
                    while((aux != 'S' && aux != 's') && (aux != 'N' && aux != 'n')){
                        printf("\nError, valor incorrecto, vuelva a introducir: ");
                        scanf("%c", &aux);
                    }
                    if(aux == 'S' || aux == 's'){
                        strncpy(provincia, modificacion, sizeof(provincia)-1);
                    }
                    else{
                        memset(direccion, '\0', sizeof(direccion));
                        memset(localidad, '\0', sizeof(localidad));
                    }
                }
                else memset(direccion, '\0', sizeof(direccion));

            }
            break;
        case 5:
            printf("\nGURDANDO...\n");
            if(strlen(nombre) != 0) strncpy(arrayClientes[posicion].Nomb_cliente, nombre, sizeof(arrayClientes[posicion].Nomb_cliente)-1);
            if(strlen(email) != 0) strncpy(arrayClientes[posicion].email, email, sizeof(arrayClientes[posicion].email)-1);
            if(strlen(contrasena) != 0) strncpy(arrayClientes[posicion].Contrasena, contrasena, sizeof(arrayClientes[posicion].Contrasena)-1);
            if(strlen(direccion) != 0){
                strncpy(arrayClientes[posicion].Dir_cliente, direccion, sizeof(arrayClientes[posicion].Dir_cliente)-1);
                strncpy(arrayClientes[posicion].Localidad, localidad, sizeof(arrayClientes[posicion].Localidad)-1);
                strncpy(arrayClientes[posicion].Provincia, provincia, sizeof(arrayClientes[posicion].Provincia)-1);
            }
            printf("GUARDADO.\nSaliendo..");
            break;
        case 6:
            printf("Saliendo...");
            break;
        default:
            printf("\nError en la seleccion de modificar...\nSaliendo...\n");
            opcion = 5;
            break;
        }

    }while(opcion != 5 && opcion != 6);

}

//Cabecera:
//Precondicion: estructura cargada e inicializada, numero de clientes, y la posicion del cliente a eliminar.
//Postcondicion: elimina el cliente, hasta que no finalice el programa aparecera en la estructura pero sera inaccesible
void EliminarCliente(Cliente *arrayCliente, int *n_cliente, int posicion){

    int opcion;

    printf("Nombre: %s  Email: %s\nDesea eliminar el cliente? (1.- SI / 2.- NO): ", arrayCliente[posicion].Nomb_cliente, arrayCliente[posicion].email);
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
//Precondicion: estructura cargada e inicializada, la posicion del cliente, y recibe la operacion a relizar (op) con el dicho saldo
//Postcondicion: modifica el parametro de saldo del cliente deseado
void Cartera(Cliente *arrayClientes, int posicion, int operacion, int saldo){

    switch(operacion){
        case 0:
            printf("El Saldo es de: %i $", arrayClientes[posicion].Cartera);
            break;
        case 1:
            printf("El Saldo de %s es de: %i $", arrayClientes[posicion].Nomb_cliente, arrayClientes[posicion].Cartera);
            break;
        case 2:
            arrayClientes[posicion].Cartera =- saldo;
            break;
        case 3:
            printf("Introduce la cantidad a anadir: ");
            scanf("%i", &saldo);
            while(saldo < MINIMO){
                printf("Error, cantidad introducida erronea, el saldo minimo a introducir es de %i.\nIntroduzca de nuevo: ", MINIMO);
                scanf("%i", &saldo);
            }
            arrayClientes[posicion].Cartera =+ saldo;
            printf("\nEl nuevo saldo es de: %i", arrayClientes[posicion].Cartera);
            break;
    default: printf("\nError de operacion en cartera...\nVolviendo...");
    }

}

//Cabecera:
//Precondicion: Debe existir el fichero clientes.txt
//Postcondicion: Carga la estructura de clientes.txt y devuelve el numero de clientes registrados
Cliente* CargarClientes(int *n_clientes){

    int n_lineas = 0, i;
    Cliente *clientes;
    FILE *f;

    f = fopen("Clientes.txt", "r");     //Abrimos archivo de clientes.txt

    if(f == NULL) printf("\nError al abrir clientes.txt");  //Comprobamos que se abre y contenga los datos bien

    // Verificamos si el archivo está vacío
    if(feof(f)){
        fclose(f);
        *n_clientes = 0;
        return NULL; // Devolvemos NULL indicando que no hay clientes
    }

    n_lineas = ContarLineas(f);     //numeros de lineas igual al nuemro de clientes
    *n_clientes = n_lineas;

    clientes = (Cliente*)calloc(n_lineas, sizeof(Cliente));     //Memoria dinamica estrucutura

    if( clientes == NULL ) {
        fprintf (stderr, "Error de asignacion de memoria") ;
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
//Precondicion: debe existir el fichero cliente.txt
//Postcondicion: guarda la estructura de clientes en el fichero con el formato deseado
void GuardarEstructuraC(Cliente *arrayClientes, int n_Clientes){

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
//Precondicion: debe existir el nombre del fichero buscado
//Postcondicion: cuenta las lineas del fichero
int ContarLineas(FILE *f){

    int i = 0;
    char c;

    while((c = fgetc(f)) != EOF){
        if(c == '\n') i++; // Incrementa el contador solo si se encuentra un salto de línea
    }

    rewind(f);

    return i;
}

//Cabecera: funcion EliminarSaltoDeLinea(E/S cadena: cadena)
//Precondicion: recibe una cadena de caracteres valida y no vacia
//Postcondicion: devuelve la cadena sin el salto de linea del final
void EliminarSaltoDeLinea(char *cadena) {
    int i = strlen(cadena);

    if (i > 0 && cadena[i - 1] == '\n') {
        cadena[i - 1] = '\0'; // Eliminamos el salto de línea solo si está presente
    }
}

