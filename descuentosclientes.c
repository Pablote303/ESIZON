#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "proveedores.h"
#include "clientes.h"
#include "descuentosclientes.h"

//Cabecera:
//Precondicion:
//Postcondicion:
DescuentoCliente *AsignarDescuentoCliente(DescuentoCliente *arrayDescuentosClientes, Cliente *arrayClientes, Descuento *arraDescuentos, int *n_descuentosclientes, int n_clientes, int pos_des, int posicion, int op, int asigVec[3], int cadVec[3]){

    DescuentoCliente *nuevoarray;

    int control = 0, opcion, elminado = 0, permiso, descuentocliente, asignacion[3], caducidad[3];

    *n_descuentosclientes += 1;
    descuentocliente = *n_descuentosclientes;
    nuevoarray = (DescuentoCliente*)realloc(arrayDescuentosClientes, (*n_descuentosclientes) * sizeof(DescuentoCliente));

    // Formulario registro
    while(control == 0){
        if(op == 1){        //Modo automatico, se envian datos, generalizado para aplicar descuentos a varios clientes
            control = 1;
        }
        else{               //Modo manual, se aplica descuento cliente a cliente
            printf("Introduce fecha de asignacion: ");  //Seria automatica pero no esta implementado sistema de hora y dia      /*Colocar*/fflush(stdin);
            printf("\nDia(dd): "); scanf("%i", &asignacion[0]);
            printf("Mes (mm): "); scanf("%i", &asignacion[1]);
            printf("Ano (aaaa): "); scanf("%i", &asignacion[2]);

            printf("Introduce fecha de caducidad: ");
            printf("\nDia(dd): "); scanf("%i", &caducidad[0]);
            printf("Mes (mm): "); scanf("%i", &caducidad[1]);
            printf("Ano (aaaa): "); scanf("%i", &caducidad[2]);

            // Validacion datos
            system("cls");
            printf("\n Son correctos los datos introducidos?\nAsignacio: ( %i / %i / %i )\nCaducidad: ( %i / %i / %i )\n\n1.- Si\n2.- No", asignacion[0], asignacion[1], asignacion[2], caducidad[0], caducidad[1], caducidad[2]);
            scanf("%i", &control);
            while(control < 1 && control > 2){
                printf("Error, vuelva a introducir");
                scanf("%i", &control);
            }

        }

        if(control = 1){
            strcpy(nuevoarray[*n_descuentosclientes - 1].Id_Cod, arraDescuentos[pos_des].Id_cod);
            nuevoarray[*n_descuentosclientes - 1].Id_cliente = arrayClientes[posicion].Id_cliente;
            nuevoarray[*n_descuentosclientes - 1].Estado = 0;
            if(op == 1){
                nuevoarray[*n_descuentosclientes - 1].Fechar_asig[0] = asigVec[0]; nuevoarray[*n_descuentosclientes - 1].Fechar_asig[1] = asigVec[1]; nuevoarray[*n_descuentosclientes - 1].Fechar_asig[2] = asigVec[1];
                nuevoarray[*n_descuentosclientes - 1].Fecha_cad[0] = cadVec[0]; nuevoarray[*n_descuentosclientes - 1].Fecha_cad[1] = cadVec[1]; nuevoarray[*n_descuentosclientes - 1].Fecha_cad[2] = cadVec[2];
            }
            else{
                nuevoarray[*n_descuentosclientes - 1].Fechar_asig[0] = asignacion[0]; nuevoarray[*n_descuentosclientes - 1].Fechar_asig[1] = asignacion[1]; nuevoarray[*n_descuentosclientes - 1].Fechar_asig[2] = asignacion[1];
                nuevoarray[*n_descuentosclientes - 1].Fecha_cad[0] = caducidad[0]; nuevoarray[*n_descuentosclientes - 1].Fecha_cad[1] = caducidad[1]; nuevoarray[*n_descuentosclientes - 1].Fecha_cad[2] = caducidad[2];
            }

            nuevoarray[*n_descuentosclientes  - 1].Eliminado = 0;

        }
        else{
            *n_descuentosclientes =- 1;                //Si no se registra eliminamos el registro del descuento al cliente
            memcpy(nuevoarray, arrayDescuentosClientes, *n_descuentosclientes) ;              //Si no se registras, remplazamos el array temporal por el original para que no se pierda ningun dato sin el nuevo descuento del Cliente registrado
            printf("Cancelada la aplicacion de descuento a la cuenta del cliente...\n");
        }
    }

    return nuevoarray;

}

//Cabecera:
//Precondicion:
//Postcondicion:
int BuscarDescuentoCliente(DescuentoCliente *arrayDescuentoCliente, Cliente *arrayClientes, int pos_cliente, int n_descuentosclientes, char descuento){

    int i, posicion = -1;

    for(i = 0; i < n_descuentosclientes; i++){
        if((strcmp(descuento, arrayDescuentoCliente[i].Id_Cod) == 1)&& arrayClientes[pos_cliente].Id_cliente == arrayDescuentoCliente[i].Id_cliente){
            posicion = i;
            i = n_descuentosclientes;
        }
    }

    return posicion;

}

//Cabecera:
//Precondicion:
//Postcondicion:
int AplicarDescuentoCliente(DescuentoCliente *arrayDescuentosClientes, Cliente *arrayClientes, Descuento *arrayDescuento, Proveedor *arraProveedores, int n_descuentosclientes, int n_clientes, char descuento, int posicion, int id_desc, int pos_prov){

    int Comprobar = 0, pos_descuento;

    pos_descuento = BuscarDescuentoCliente(arrayDescuentosClientes, arrayClientes, posicion, n_descuentosclientes, descuento);

    if(strcmp("todos", arrayDescuento[pos_descuento].Aplicable) == 1){
        arrayDescuentosClientes[posicion].Estado = 1;
        Comprobar = 1;

        printf("El descuento %s se ha aplicado\n", arrayDescuentosClientes[posicion].Id_Cod);
    }
    else{
        if(strcmp("ESIZON", arrayDescuento[id_desc].Aplicable) == 1){
            if(strcmp("ESIZON", arraProveedores[pos_prov].Nombre) == 1){
                arrayDescuentosClientes[posicion].Estado = 1;
                Comprobar = 1;

                printf("El descuento %s se ha aplicado.\n", arrayDescuentosClientes[posicion].Id_Cod);
            }
            else{
                printf("Este descuento no es valido para este proveedor.\n");
                Comprobar = 0;
            }
        }
        else printf("El descuento %s no es posible aplicarlo.\n");
    }

    return Comprobar;

}

//Cabecera:
//Precondicion:
//Postcondicion:
void ListarDescuentosCliente(DescuentoCliente *arrayDescuentosClientes, Cliente *arrayClientes, int n_descuentosclientes, int posicion){

    int i, filas, x = 0, pag = 0, pagina;

    printf("Introduce el numero de descuentos a mostrar por pagina (5 a 50): ");
    scanf("%i", &pagina);
    while(filas < 5 || filas > 50){
        printf("Valor introducido no valido, vuelva a introducir la cantidad: ");
        scanf("%i", &filas);
    }

    for(i = 0; i < n_descuentosclientes; i++){
        if(arrayDescuentosClientes[i].Id_cliente == arrayClientes[posicion].Id_cliente){
            printf("%s - %i - Asignado: %i/%i/%i - Caduca: %i/%i/%i - Estado:", arrayClientes[posicion].email, arrayDescuentosClientes[i].Id_Cod, arrayDescuentosClientes[i].Fechar_asig[0], arrayDescuentosClientes[i].Fechar_asig[1], arrayDescuentosClientes[i].Fechar_asig[2], arrayDescuentosClientes[i].Fecha_cad[0], arrayDescuentosClientes[i].Fecha_cad[1], arrayDescuentosClientes[i].Fecha_cad[2]);
            if(arrayDescuentosClientes[i].Estado == 0) printf(" No aplicado\n");
            else printf(" Aplicado\n");

            x++;
            if(x == filas-1){
                printf("\nPagina %i de %i", x+1, n_descuentosclientes/filas);
                printf("\nPulse cualquier tecla para pasar pagina...\n");
                pag++;
                getchar();
                x = 0;
                system("cls");
            }
        }
    }

}

//Cabecera:
//Precondicion:
//Postcondicion:
void ListarDescuentosTotalClientes(DescuentoCliente *arrayDescuentosClientes, Cliente *arrayClientes, int n_descuestosclientes, int n_clientes){

    int i, posicion, filas, x = 0, pag = 0;

    printf("Introduce el numero de descuentos a mostrar por pagina (5 a 50): ");
    scanf("%i", &filas);
    while(filas < 5 || filas > 50){
        printf("Valor introducido no valido, vuelva a introducir la cantidad: ");
        scanf("%i", &filas);
    }

    for(i = 0; i < n_descuestosclientes; i++){
        posicion = BuscarCliente(arrayClientes, n_clientes, 0, 0, arrayDescuentosClientes[i].Id_cliente, 3);
        printf("%s - %i - Asignado: %i/%i/%i - Caduca: %i/%i/%i - Estado:", arrayClientes[posicion].email, arrayDescuentosClientes[i].Id_Cod, arrayDescuentosClientes[i].Fechar_asig[0], arrayDescuentosClientes[i].Fechar_asig[1], arrayDescuentosClientes[i].Fechar_asig[2], arrayDescuentosClientes[i].Fecha_cad[0], arrayDescuentosClientes[i].Fecha_cad[1], arrayDescuentosClientes[i].Fecha_cad[2]);
        if(arrayDescuentosClientes[i].Estado == 0) printf(" No aplicado\n");
        else printf(" Aplicado\n");

        x++;
        if(x == filas-1){
            printf("\nPagina %i de %i", x+1, n_descuestosclientes/filas);
            printf("\nPulse cualquier tecla para pasar pagina...\n");
            pag++;
            getchar();
            x = 0;
            system("cls");
        }
    }

}

//Cabecera:
//Precondicion: Debe existir el fichero descuentosclientes.txt
//Postcondicion: Carga la estructura de descuentosclientes.txt y devuelve el numero de descuentos de clientes registrados
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

//Cabecera:
//Precondicion: debe existir el fichero descuentosclientes.txt
//Postcondicion: guarda la estructura de descuento clientes en el fichero con el formato deseado
void GuardarEstrucuturaCD(DescuentoCliente *descuentosclientes, int n_descuentoscliente){

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
