#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "descuentosclientes.h"
#include "clientes.h"
#include "menu.h"
#include "proveedores.h"



DescuentoCliente *CargarDescuentosClientes(int *n_descuentoscliente){

    int n_lineas = 0, i;
    DescuentoCliente *descuentosclientes;
    FILE *f;

    f = fopen("DescuentosClientes.txt", "r");     //Abrimos archivo de DescuentoCliente.txt

    if(f == NULL) printf("\nError al abrir DescuentoCliente.txt");  //Comprobamos que se abre y contenga los datos bien

    n_lineas = ContarLineas(f);     //numeros de lineas igual al nuemro de DescuentoCliente
    *n_descuentoscliente = n_lineas;
    descuentosclientes = (DescuentoCliente*)calloc(n_lineas, sizeof(DescuentoCliente));     //Memoria dinamica estrucutura

    rewind(f);

    for(i = 0; i < n_lineas; i++){                      //Bucle que almacena los datos de los descuentosclientes uno a uno
        fscanf(f, "%d-", &descuentosclientes[i].Id_cliente);
        fscanf(f, "%[^-]-", descuentosclientes[i].Id_Cod);
        fscanf(f, "%d[^-]/", descuentosclientes[i].Fechar_asig[0]);
        fscanf(f, "%d[^/]/", descuentosclientes[i].Fechar_asig[1]);
        fscanf(f, "%d[^/]-", descuentosclientes[i].Fechar_asig[2]);
        fscanf(f, "%d[^-]/", descuentosclientes[i].Fecha_cad[0]);
        fscanf(f, "%d[^/]/", descuentosclientes[i].Fecha_cad[1]);
        fscanf(f, "%d[^/]-", &descuentosclientes[i].Fecha_cad[2]);
        fscanf(f, "%d[^\n]\n", &descuentosclientes[i].Estado);
        descuentosclientes[i].Eliminado = 0;
    }

    fclose(f);
    return descuentosclientes;

}

void GuardarEstrucutura(DescuentoCliente *descuentosclientes, int n_descuentoscliente){

    int i = 0;

    FILE *f;

    f = fopen("DescuentosClientes.txt","w");      //Abrimos el archivo el modo escritura
    if(f == NULL) printf("\nError al abrir DescuentosClientes.txt");

    while(i < n_descuentoscliente){
        if(descuentosclientes[i].Eliminado != 1){        //Solo si no esta borrado

            fprintf(f, "%07i", descuentosclientes[i].Id_cliente);
            fputc('-', f);
            fprintf(f, "%010i", descuentosclientes[i].Id_Cod);
            fputc('-', f);
            fprintf(f, "%i/%i/%i", descuentosclientes[i].Fechar_asig[0], descuentosclientes[i].Fechar_asig[1], descuentosclientes[i].Fechar_asig[2]);
            fputc('-', f);
            fprintf(f, "%i/%i/%i", descuentosclientes[i].Fecha_cad[0], descuentosclientes[i].Fecha_cad[1], descuentosclientes[i].Fecha_cad[2]);
            fputc('-', f);
            fprintf(f, "%010i", descuentosclientes[i].Estado);

            if(i != n_descuentoscliente-1) fputc('\n', f);
        }
        i++;
    }

    fclose(f);      //Cerramos archivo

}
