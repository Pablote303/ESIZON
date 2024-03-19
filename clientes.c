#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "clientes.h"
#include "menu.h"

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


int ContarLineas(FILE *f){

    int i = 1;
    char c;

    while((c = fgetc(f)) != EOF){
        if(c == '\n') i++;              //Cuenta las lineas si hay un salto de linea y no esta vacio
    }

    rewind(f);

    return i;

}
