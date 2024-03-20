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
Proveedor *CrearProveedor(Proveedor *arrayProveedores, int *n_proveedores, int op){  // op == 0(Normal) / 1(ADMIN)

    Proveedor *nuevoarray;

    int control = 0, opcion, elminado = 0, permiso;
    char nombre[21], email[31], contrasena[16];

    *n_proveedores += 1;
    Proveedor = *n_proveedores;
    nuevoarray = (Proveedor*)realloc(arrayProveedores, (*n_proveedores) * sizeof(Proveedor));

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
        printf("\n¿Son correctos los datos introducidos?");
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
                *n_proveedores  -= 1;                //Si no se registra quitamos el Proveedor anadido al principio
                memcpy(nuevoarray, arrayProveedores, *n_proveedores ;              //Si no se registras, remplazamos el array temporal por el original para que no se pierda ningun dato sin el nuevo Cliente registrado
                control = 1;
            }
            else{
                // Guardar en estructura
                nuevoarray[*n_proveedores - 1].Id = nuevoarray[*n_proveedores  - 2].Id_empresa + 1;
                nuevoarray[*n_proveedores  - 1].Eliminado = 0;

                strcpy(nuevoarray[*n_proveedores  - 1].email, email);
                strcpy(nuevoarray[*n_proveedores  - 1].Contrasena, contrasena);
                strcpy(nuevoarray[*n_proveedores  - 1].Nomb_Cliente, nombre);

                nuevoarray[*n_proveedores  - 1].Perfil_usuario = permiso;  //Dinero inicial
                /*if(permiso == 1) strcpy(nuevoarray[*n_clientes - 1].Perfil_usuario, "Proveedor");
                else strcpy(nuevoarray[*n_clientes - 1].Perfil_usuario, "administrador");*/

                control = 1;
            }
        }
    }
    // Cierre
    return nuevoarray;         //Devolvemos el array al original con los datos del nuevo Proveedor o como estaba al principio si no se registra

}

//Cabecera:
//Precondicion:
//Postcondicion:
Proveedor *CargarProveedores(int *n_proveedores){

    int n_lineas = 0, i;
    char perfil[13];
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
        fscanf(f, "%[^\n]\n", perfil);
        EliminarSaltoDeLinea(perfil);
        if(strcmp(perfil, "administrador") == 0) proveedores[i].Perfil_usuario = 0;
        else proveedores[i].Perfil_usuario = 1;
        //fscanf(f, "%[^\n]\n", &proveedores[i].Perfil_usuario);      //¿?¿?  Cambiar por sustitucion de enteros ¿?¿?
        proveedores[i].Eliminado = 0;
    }

    fclose(f);
    return proveedores;

}

//Cabecera:
//Precondicion:
//Postcondicion:
void GuardarEstrucutura(Proveedor *arrayProveedores, int n_proveedores){

    int i = 0;

    FILE *f;

    f = fopen("Proveedores.txt","w");      //Abrimos el archivo el modo escritura
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
            if(arrayProveedores[i].Perfil_usuario == 0) fputs("administrador", f);
            else fputs("proveedor", f);
            //fputs(arrayProveedores[i].Perfil_usuario, f);

            if(i != n_proveedores-1) fputc('\n', f);
        }
        i++;
    }

    fclose(f);      //Cerramos archivo

}
