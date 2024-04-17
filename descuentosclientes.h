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

typedef struct{       // ESTRUCTA QUE FALTA, SOLO PARA QUE FUNCIONE EL PROGRAMA

    char Id_cod[11];
    char Descrip[51];
    char Tipo[8];
    char Estado[8];
    int Importe;
    char Aplicable[6];

} Descuento;

//Funciones publicas
DescuentoCliente *AsignarDescuentoCliente(DescuentoCliente *arrayDescuentosClientes, Cliente *arrayClientes, Descuento *arraDescuentos, int *n_descuentosclientes, int n_clientes, int pos_des, int posicion, int op, int asigVec[3], int cadVec[3]);
int BuscarDescuentoCliente(DescuentoCliente *arrayDescuentoCliente, Cliente *arrayClientes, int pos_cliente, int n_descuentosclientes, char descuento);
int AplicarDescuentoCliente(DescuentoCliente *arrayDescuentosClientes, Cliente *arrayClientes, Descuento *arrayDescuento, Proveedor *arraProveedores, int n_descuentosclientes, int n_clientes, char descuento, int posicion, int id_desc, int pos_prov);
void ListarDescuentosCliente(DescuentoCliente *arrayDescuentosClientes, Cliente *arrayClientes, Descuento *arrayDescuento, int n_descuentosclientes, int n_descuentos, int posicion);
void ListarDescuentosTotalClientes(DescuentoCliente *arrayDescuentosClientes, Cliente *arrayClientes, int n_descuestosclientes, int n_clientes);
DescuentoCliente *CargarDescuentosClientes(int *n_descuentoscliente);
void GuardarEstrucuturaCD(DescuentoCliente *descuentosclientes, int n_descuentoscliente);


#endif // DESCUENTOSCLIENTES_H_INCLUDED
