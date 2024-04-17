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
Cliente *CrearCliente(Cliente *arrayClientes, int *n_clientes);
int login(Cliente *, Proveedor *, int *id, int *n_clientes, int *n_proveedores);
void ListarCliente(Cliente *arrayClientes, int n_clientes, int posicion, int op);
int BuscarCliente(Cliente *arrayClientes, int n_clientes, char nombre, char *email, int id, int op);
void ModificarCliente(Cliente *arrayClientes, int posicion);
void EliminarCliente(Cliente *arrayCliente, int *n_cliente, int posicion);
void Cartera(Cliente *arrayClientes, int posicion, int operacion, int saldo);
Cliente* CargarClientes(int *n_clientes);
void GuardarEstructuraC(Cliente *arrayClientes, int n_Clientes);
int ContarLineas(FILE *f);
void EliminarSaltoDeLinea(char *cadena);

#endif // CLIENTES_H_INCLUDED
