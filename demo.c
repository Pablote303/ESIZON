#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "proveedores.h"
#include "demo.h"
#include "clientes.h"
#include "descuentosclientes.h"

void ListarDescuentos(Descuento *arrayDescuentos, int n_descuentos){

    int i;

    for(i = 0; i < n_descuentos; i++){
        printf("Id: %s\nDescripcion: %s\nTipo: %s\nAplicable: %s\nImporte: %d\nEstado: %s\n", arrayDescuentos[i].Id_cod, arrayDescuentos[i].Descrip, arrayDescuentos[i].Tipo, arrayDescuentos[i].Aplicable, arrayDescuentos[i].Importe, arrayDescuentos[i].Estado);

        if(i != n_descuentos - 1) printf("\nPulse cualquier tecla para ver el siguiente descuento...");
        else printf("\nPulse cualquier tecla para volver...");
        gets("");
        system("cls");
    }

}

Descuento* CargarDescuento(int *n_descuento){

    int n_lineas = 0, i;
    Descuento *arrayDescuento;
    FILE *f;

    f = fopen("Descuento.txt", "r");     //Abrimos archivo de arrayDescuento.txt

    if(f == NULL) printf("\nError al abrir Descuento.txt");  //Comprobamos que se abre y contenga los datos bien

    // Verificamos si el archivo está vacío
    if(feof(f)){
        fclose(f);
        *n_descuento = 0;
        return NULL; // Devolvemos NULL indicando que no hay arrayDescuento
    }

    n_lineas = ContarLineas(f);     //numeros de lineas igual al nuemro de arrayDescuento
    *n_descuento = n_lineas;

    arrayDescuento = (Descuento*)calloc(n_lineas, sizeof(Descuento));     //Memoria dinamica estrucutura

    if( arrayDescuento == NULL ) {
        fprintf (stderr, "Error de asignacion de memoria") ;
        exit (1);
    }

    rewind(f);

    for(i = 0; i < n_lineas; i++){                      //Bucle que almacena los datos de los arrayDescuento uno a uno
        fscanf(f, "%d-", &arrayDescuento[i].Id_cod);
        fscanf(f, "%[^-]-", arrayDescuento[i].Descrip);
        fscanf(f, "%[^-]-", arrayDescuento[i].Tipo);
        fscanf(f, "%[^-]-", arrayDescuento[i].Estado);
        fscanf(f, "%d[^-]-", &arrayDescuento[i].Importe);
        fscanf(f, "%d[^\n]\n", &arrayDescuento[i].Aplicable);
    }

    fclose(f);
    return arrayDescuento;

}


void GuardarEstructuraD(Descuento *arrayDescuento, int n_descuento){

    int i = 0;

    FILE *f;

    f = fopen("Descuento.txt","w");      //Abrimos el archivo el modo escritura
    if(f == NULL) printf("\nError al abrir Descuento.txt");

    while(i < n_descuento){      //Guardamos la estructura Cliente a Cliente en Cliente.txt

            fprintf(f, "%07i", arrayDescuento[i].Id_cod);
            fputc('-', f);
            fputs(arrayDescuento[i].Descrip, f);
            fputc('-', f);
            fputs(arrayDescuento[i].Tipo, f);
            fputc('-', f);
            fputs(arrayDescuento[i].Estado, f);
            fputc('-', f);
            fprintf(f, "%d", arrayDescuento[i].Importe);
            fputc('-', f);
            fputs(arrayDescuento[i].Aplicable, f);

            if(i != n_descuento-1) fputc('\n', f);
        i++;
    }

    fclose(f);      //Cerramos archivo

}
