#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "proveedores.h"
#include "clientes.h"
#include "descuentosclientes.h"
#include "demo.h"

//Cabecera:
//Precondicion: Cargada e inicializada la estructura de proveedores, numero de proveedores/administradores, y el tipo de registro
//Postcondicion: Devuelve a estrutura el nuevo proveedor/administrador registrado
Proveedor *CrearProveedor(Proveedor *arrayProveedores, int *n_proveedores, int op){

    Proveedor *nuevoarray;

    int control = 0, opcion, elminado = 0, permiso, proveedores;
    char nombre[21], email[31], contrasena[16];

    *n_proveedores += 1;
    proveedores = *n_proveedores;
    nuevoarray = (Proveedor*)realloc(arrayProveedores, (*n_proveedores) * sizeof(Proveedor));

    // Formulario registro
    while(control == 0){
        printf("Introduce email (maximo 30 caracteres): "); /*Colocar*/fflush(stdin);
        fgets(email, 31, stdin);
        EliminarSaltoDeLinea(email);
        fflush(stdin);

        //Revisar ERROR
        /*while(BuscarCliente() != -1){        //Comparar que no exista otro Cliente igual
            printf("\nEl Cliente introducido ya existe, vuelva a introducir otro (maximo 5 caracteres): ");
            scanf("%s", email);
            EliminarSaltoDeLinea(email);
            fflush(stdin);
        }
        */
        //Formulario datos de Proveedor
        printf("Introduce contrasena (maximo 15 caracteres): ");
        fgets(contrasena, 16, stdin);
        EliminarSaltoDeLinea(contrasena);
        fflush(stdin);
        printf("\nIntroduce nombre (maximo 20 caracteres): ");
        fgets(nombre, 21, stdin);
        EliminarSaltoDeLinea(nombre);
        fflush(stdin);

        if(op == 1){                                                                        //Menu solo accesible si eres administrador, para seleccionar los permisos
            printf("Permisios del proveedor:\n1.- Administrador\n2.- Proveedor\n");
            scanf("%i", &permiso);
            while(permiso != 1 && permiso != 2){
                printf("Error, vuelva a introducir: ");
                scanf("%i", &permiso);
            }
            permiso--;
        }

        // Validacion datos
        printf("\n Son correctos los datos introducidos?");
        if(op == 1){
            if(permiso == 1) printf("Permisos: Cliente\n");
            else printf("Permisos: administrador\n");
        }
        printf("email: %s\ncontrasena: %s\nNombre: \n1.- Si || 2.- No || 3.- Cancelar registro\n", email, contrasena, nombre);
        scanf("%i", &opcion);
        while(opcion < 1 && opcion > 3){
            printf("Error, vuelva a introducir: ");
            scanf("%i", &opcion);
        }

        // Verificacion y guardado de Proveedor con su nueva id;
        if(opcion == 2) printf("Repita el formulario con los datos correctos.\n");
        else{
            if(opcion == 3){
                *n_proveedores =- 1;                //Si no se registra quitamos el Proveedor anadido al principio
                memcpy(nuevoarray, arrayProveedores, *n_proveedores) ;              //Si no se registras, remplazamos el array temporal por el original para que no se pierda ningun dato sin el nuevo Cliente registrado
                control = 1;
            }
            else{
                // Guardar en estructura
                nuevoarray[*n_proveedores - 1].Id_empresa = nuevoarray[*n_proveedores  - 2].Id_empresa + 1;
                nuevoarray[*n_proveedores  - 1].Eliminado = 0;

                strcpy(nuevoarray[*n_proveedores  - 1].email, email);
                strcpy(nuevoarray[*n_proveedores  - 1].Contrasena, contrasena);
                strcpy(nuevoarray[*n_proveedores  - 1].Nombre, nombre);

                nuevoarray[*n_proveedores  - 1].Perfil_usuario = permiso;  //Dinero inicial
                /*if(permiso == 1) strcpy(nuevoarray[*n_clientes - 1].Perfil_usuario, "Proveedor");
                else strcpy(nuevoarray[*n_clientes - 1].Perfil_usuario, "administrador");*/

                control = 1;
            }
        }
    }

    return nuevoarray;
}

//Cabecera:
//Precondicion: estructura cargada e inicializada, numero de proveedores/administradores, al menos un administrador registrado
//Postcondicion: devuelve en pantalla el listado de clientes y sus datos (segun quien los visualice)
void ListarProveedores(Proveedor *arrayProveedores, int n_proveedores, int op, int posicion){

    int i;

    if(posicion == -1){
        for(i = 0; i < n_proveedores; i++){
            printf("ID: %07i  Nombre: %s  Email: %s", arrayProveedores[i].Id_empresa, arrayProveedores[i].Nombre, arrayProveedores[i].email);
            if(op == 1){
                if(arrayProveedores[i].Perfil_usuario == 0) printf("  Perfil: Administrador");
                else printf("  Perfil: Proveedor");
            }
            puts("");
        }
    }
    else{
        printf("Nombre: %s  Email: %s  C");
        if(op == 1) printf("");
    }

}

//Cabecera:
//Precondicion: estructura cargada e inicializada, numero de proveedores/clientes y recibir al menos de uno de estos datos: email, nombre o id
//Postcondicion: devuelve la posicion del proveedor/administrador o -1 si no existe
int BuscarProveedor(Proveedor *arrayProveedores, int n_proveedores, char nombre, char *email, int id, int op){

    int i, control = 0, posicion = -1, opcion;

    switch(op){
        case 1:
            for(i = 0; i < n_proveedores && control == 0; i++){
                if(strcmp(nombre, arrayProveedores[i].Nombre) == 0){
                    printf("\nNombre: %s  Email: %s\n Es el proveedor que busca? (1.-Si / 2.-NO):  ", arrayProveedores[i].Nombre, arrayProveedores[i].email);
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
            for(i = 0; i < n_proveedores && control == 0; i++){
                if(strcmp(email, arrayProveedores[i].email) == 0){
                    posicion = i;
                    control = 1;
                }
            }
            break;
        case 3:
            for(i = 0; i < n_proveedores && control == 0; i++){
                if(id == arrayProveedores[i].Id_empresa){
                    posicion = i;
                    control = 1;
                }
            }
            break;
    default: printf("\nError en la seleccion de modo de busqueda.");
    }

    return posicion;

}

//Cabecera:
//Precondicion: estrucutura cargada e inicializada y recibe la posicion del proveedor/administrador
//Postcondicion: modifica los datos en estructura de datos del proveedor/administrador deseado
void ModificarProveedor(Proveedor *arrayProveedores, int n_proveedores, int posicion, int op){

    int opcion;
    char aux, modificacion[51], nombre[21], email[31], contrasena[16];

    memset(modificacion, '\0', sizeof(modificacion));
    memset(nombre, '\0', sizeof(nombre));
    memset(email, '\0', sizeof(email));
    memset(contrasena, '\0', sizeof(contrasena));

    switch(op){
        case 1 && 2:
            do{
                if(nombre != 'NULL') printf("\nNombre: %s\n", nombre);
                else printf("\nNombre: %s\n", arrayProveedores[posicion].Nombre);
                if(email != 'NULL') printf("Email: %s\n", email);
                else printf("Email: %s\n", arrayProveedores[posicion].Eliminado);
                if(contrasena != 'NULL') printf("Contrasena: %s\n", contrasena);
                else if(op == 2) printf("Contrasena: %s\n", arrayProveedores[posicion].Contrasena);

                printf("\n�Que desea modificar?\n1.- Nombre\n2.- Email\n3.- Contrasena\n4.- Salir y Guardar\n5.- Salir sin Guardar\n");
                scanf("%i", &opcion);
                while(opcion < 1 || opcion >5){
                    printf("");
                    scanf("%i", &opcion);
                }
                switch(opcion){

                case 1:
                    printf("\nIntroduzca el nuevo nombre (maximo 20 caracteres): ");
                    scanf("%s", modificacion);
                    EliminarSaltoDeLinea(modificacion);
                    printf("%s\n�Es correcto? (S/N): ");
                    scanf("%c", aux);
                    while(aux != 'S' && aux != 'N'){
                        printf("\nError, valor incorrecto, vuelva a introducir: ");
                        scanf("%c", aux);
                    }
                    if(aux == 'S'){
                        strncpy(nombre, modificacion, sizeof(nombre)-1);
                    }
                    break;
                case 2:
                    printf("\nIntroduzca el nuevo email (maximo 30 caracteres): ");
                    scanf("%s", modificacion);
                    EliminarSaltoDeLinea(modificacion);
                    printf("%s\n�Es correcto? (S/N): ");
                    scanf("%c", aux);
                    while(aux != 'S' && aux != 'N'){
                        printf("\nError, valor incorrecto, vuelva a introducir: ");
                        scanf("%c", aux);
                    }
                    if(aux == 'S'){
                        strncpy(email, modificacion, sizeof(email)-1);
                    }
                    break;
                case 3:
                    printf("\nIntroduzca el nueva contrasena (maximo 15 caracteres): ");
                    scanf("%s", modificacion);
                    EliminarSaltoDeLinea(modificacion);
                    printf("%s\n�Es correcto? (S/N): ");
                    scanf("%c", aux);
                    while(aux != 'S' && aux != 'N'){
                        printf("\nError, valor incorrecto, vuelva a introducir: ");
                        scanf("%c", aux);
                    }
                    if(aux == 'S'){
                        strncpy(contrasena, modificacion, sizeof(contrasena)-1);
                    }
                    break;
                case 4:
                    printf("\nGURDANDO...\n");
                    if(nombre != 'NULL') strncpy(arrayProveedores[posicion].Nombre, nombre, sizeof(arrayProveedores[posicion].Nombre)-1);
                    if(email != 'NULL') strncpy(arrayProveedores[posicion].email, email, sizeof(arrayProveedores[posicion].email)-1);
                    if(contrasena != 'NUll') strncpy(arrayProveedores[posicion].Contrasena, contrasena, sizeof(arrayProveedores[posicion].Contrasena)-1);
                    printf("GUARDADO.\NSaleindo..");
                    break;
                case 5:
                    printf("Saliendo...");
                    break;
                default:
                    printf("\nError en la seleccion de modificar...\nSaliendo...\n");
                    opcion = 5;
                    break;
                }

            }while(opcion != 5 && opcion != 6);
            break;
        case 3:
                printf("\nPor normativa de la empresa todo administrador tendra como nombre ESIZON\ny no podra modificar su email administrativo.\n\nID: %04i\nNombre: %s\n", arrayProveedores[posicion].Id_empresa, arrayProveedores[posicion].Nombre);
                printf("Email: %s\n", arrayProveedores[posicion].email);
                if(contrasena != 'NULL') printf("Contrasena: %s\n", contrasena);
                else printf("Contrasena: %s\n", arrayProveedores[posicion].Contrasena);

                printf("\n¿Desea modificar su contrasena?\n1.- Si\n2.- No");
                scanf("%i", &opcion);
                while(opcion < 1 || opcion > 2){
                    printf("Error, opcion no valida...\nVuelva a introducir: ");;
                    scanf("%i", &opcion);
                }

                if(opcion == 1){
                    printf("Introduzca la nueva contrasena (15 carecteres maximos): ");
                    scanf("%s", modificacion);
                    EliminarSaltoDeLinea(modificacion);

                    printf("\n¿Es correcto?  Contrasena: %s\n1.- Si\n2.- No", modificacion);
                    while(opcion < 1 || opcion > 2){
                        printf("Error, opcion no valida...\nVuelva a introducir: ");;
                        scanf("%i", &opcion);
                    }

                    if(opcion == 1){
                        if(modificacion != 'NUll') strncpy(arrayProveedores[posicion].Contrasena, modificacion, sizeof(arrayProveedores[posicion].Contrasena)-1);
                    }
                }
                else{
                    printf("Saliendo....");
                }
            break;
        default:
            printf("Error, en la seleccion.");
            break;
        }
}

//Cabecera:
//Precondicion: estructura cargada e inicializada, numero de proveedores, y la posicion del proveedor/administrador a eliminar.
//Postcondicion: elimina el proveedor/administrador, hasta que no finalice el programa aparecera en la estructura pero sera inaccesible
void EliminarProv(Proveedor *arrayProveedores, int *n_proveedores, int posicion){

    int opcion;

    printf("Nombre: %s  Email: %s\n Desea eliminar el proveedor? (1.- SI / 2.- NO): ", arrayProveedores[posicion].Nombre, arrayProveedores[posicion].email);
    scanf("%i", &opcion);
    while(opcion != 1 && opcion != 2){
        printf("\nError, valor introducido no valido, vuelva a introducirlo: ");
        scanf("%i", &opcion);
    }

    if(opcion == 1){
        arrayProveedores[posicion].Eliminado = 1;
        printf("\nEl proveedor se ha borrado...");
    }
    else printf("\nCancelado.\nVolviendo...");

}

//Cabecera:
//Precondicion: Debe existir el fichero proveedores.txt
//Postcondicion: Carga la estructura de proveedores.txt y devuelve el numero de preveedores y administradores registrados
Proveedor *CargarProveedores(int *n_proveedores){

    int n_lineas = 0, i;
    char perfil[13], *ad = "admin";
    Proveedor *proveedores;
    FILE *f;

    f = fopen("AdminProv.txt", "r");     //Abrimos archivo de proveedores.txt

    if(f == NULL) printf("\nError al abrir proveedores.txt");  //Comprobamos que se abre y contenga los datos bien

    n_lineas = ContarLineas(f);     //numeros de lineas igual al nuemro de proveedores
    *n_proveedores = n_lineas;
    proveedores = (Proveedor*)calloc(n_lineas, sizeof(Proveedor));     //Memoria dinamica estrucutura

    rewind(f);

    for(i = 0; i < n_lineas; i++){                      //Bucle que almacena los datos de los proveedores uno a uno
        fscanf(f, "%d-", &proveedores[i].Id_empresa);
        fscanf(f, "%[^-]-", proveedores[i].Nombre);
        fscanf(f, "%[^-]-", proveedores[i].email);
        fscanf(f, "%[^-]-", proveedores[i].Contrasena);
        fscanf(f, "%[^\n]\n", perfil); printf("/*/*/ %s /*/*/*", perfil);
        //EliminarSaltoDeLinea(perfil);
        fflush(stdin);
        if(strcmp(perfil, ad) == 0){
            proveedores[i].Perfil_usuario = 0;
        }
        else {
            proveedores[i].Perfil_usuario = 1;
        }
        proveedores[i].Eliminado = 0;
fflush(stdin);
        printf("\n.. %07i - %s - %s - %s - %i|| Eliminado: %i  ..\n", proveedores[i].Id_empresa, proveedores[i].Nombre, proveedores[i].email, proveedores[i].Contrasena, proveedores[i].Perfil_usuario, proveedores[i].Eliminado);
    }

    fclose(f);
    return proveedores;

}

//Cabecera:
//Precondicion: debe existir el fichero proveedores.txt
//Postcondicion: guarda la estructura de clientes en el fichero con el formato deseado
void GuardarEstructuraP(Proveedor *arrayProveedores, int n_proveedores){

    int i = 0;

    FILE *f;

    f = fopen("AdminProv.txt","w");      //Abrimos el archivo el modo escritura
    if(f == NULL) printf("\nError al abrir Proveedores.txt");

    while(i < n_proveedores){
        if(arrayProveedores[i].Eliminado != 1){        //Solo si no esta borrado

            fprintf(f, "%07i", arrayProveedores[i].Id_empresa);
            fputc('-', f);
            fputs(arrayProveedores[i].Nombre, f);
            fputc('-', f);
            fputs(arrayProveedores[i].email, f);
            fputc('-', f);
            fputs(arrayProveedores[i].Contrasena, f);
            fputc('-', f);
            if(arrayProveedores[i].Perfil_usuario == 0) fputs("admin", f);
            else fputs("proveedor", f);
            //fputs(arrayProveedores[i].Perfil_usuario, f);

            if(i != n_proveedores-1) fputc('\n', f);
        }
        i++;
    }

    fclose(f);      //Cerramos archivo

}
