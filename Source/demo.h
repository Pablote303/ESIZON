#ifndef DEMO_H_INCLUDED
#define DEMO_H_INCLUDED

typedef struct{       // ESTRUCTA QUE FALTA, SOLO PARA QUE FUNCIONE EL PROGRAMA

    char Id_cod[11];
    char Descrip[51];
    char Tipo[8];
    char Estado[8];
    int Importe;
    char Aplicable[6];

} Descuento;
/*
typedef struct{



} Productos;

typedef struct{



} Categorias;

typedef struct{



} Lockers;

typedef struct{



} ComportamientoLockers;

typedef struct{



} Pedidos;

typedef struct{



} ProductosPedidos;

typedef struct{



} Transportistas;

typedef struct{



} Devoluciones;
*/

//Funciones Publicas
void ListarDescuentos(Descuento *arrayDescuentos, int n_descuentos);
Descuento* CargarDescuento(int *n_descuento);
void GuardarEstructuraD(Descuento *arrayDescuento, int n_descuento);

#endif // DEMO_H_INCLUDED
