#ifndef DESCUENTOSCLIENTES_H_INCLUDED
#define DESCUENTOSCLIENTES_H_INCLUDED

typedef struct{

    int Id_cliente;         // Maximo 7 digitos
    int Id_Cod;             // Maximo 10 digitos
    int Fechar_asig[3];     // dd, mm, aaaa
    int Fecha_cad[3];       // dd, mm, aaaa
    int Estado;              // 0(No aplicado) / 1(Aplicado)
    int Eliminado;

} DescuentoCliente;

//Funciones publicas
DescuentoCliente *CargarDescuentosClientes(int *n_descuentoscliente);
void GuardarEstrucutura(DescuentoCliente *descuentosclientes, int n_descuentoscliente);


#endif // DESCUENTOSCLIENTES_H_INCLUDED
