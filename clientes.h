#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

typedef struct{

    int Id_cliente;
    char Nomb_cliente[21];
    char Dir_cliente[51];
    char Localidad[21];
    char Provincia[21];
    char email[31];
    char Contrasena[16];
    int Cartera;
    int Eliminado;          // 0(Cliente no eliminado) / 1(Cliente eliminado, no se guarda en fichero ni se usara mientras funciona la app)

} Cliente;

//Funciones publicas
Cliente *CrearCliente(Cliente *arrayClientes, int *n_clientes/*, int op*/);
Cliente* CargarClientes(int *n_clientes);
GuardarEstrucutura(Cliente *arrayClientes, int n_Clientes);

#endif // CLIENTES_H_INCLUDED
