#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "clientes.h"
#include "menu.h"
#include "proveedores.h"
#include "descuentosclientes.h"


Proveedor* CargarProveedores(int *n_proveedores){

    int n_lineas = 0, i;
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
        fscanf(f, "%[^\n]\n", &proveedores[i].Perfil_usuario);      //¿?¿?  Cambiar por sustitucion de enteros ¿?¿?
        proveedores[i].Eliminado = 0;
    }

    fclose(f);
    return proveedores;

}

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
            fputs(arrayProveedores[i].Perfil_usuario, f);

            if(i != n_proveedores-1) fputc('\n', f);
        }
        i++;
    }

    fclose(f);      //Cerramos archivo

}
