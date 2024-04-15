#ifndef DESCUENTOSCLIENTES_H_INCLUDED
#define DESCUENTOSCLIENTES_H_INCLUDED

typedef struct{

    int Id_cliente;         // Maximo 7 digitos
    char Id_Cod[11];             // Maximo 10 digitos
    int Fechar_asig[3];     // dd, mm, aaaa
    int Fecha_cad[3];       // dd, mm, aaaa
    int Estado;              // 0(No aplicado) / 1(Aplicado)
    int Eliminado;

} DescuentoCliente;

typedef struct{       /* ESTRUCTA QUE FALTA, SOLO PARA QUE FUNCIONE EL PROGRAMA */

    char Id_cod[11];
    char Descrip[51];
    char Tipo[8];
    char Estado[8];
    int Importe;
    char Aplicable[6];

} Descuento;

//Funciones publicas
DescuentoCliente *CargarDescuentosClientes(int *n_descuentoscliente);
void GuardarEstrucuturaCD(DescuentoCliente *descuentosclientes, int n_descuentoscliente);


#endif // DESCUENTOSCLIENTES_H_INCLUDED
