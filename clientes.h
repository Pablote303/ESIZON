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

typedef struct{

    int Id_empresa;
    char Nombre[21];
    char email[31];
    char Contrasena[16];
    char Perfil_usuario[13];    // O int Perfil_usuario == 0(administrador) / 1(provedor)
    //int Eliminado;

} Proveedor;

typedef struct{

    int Id_cliente;         // Maximo 7 digitos
    int Id_Cod;             // Maximo 10 digitos
    int Fechar_asig[3];     // dd, mm, aaaa
    int Fecha_cad[3];       // dd, mm, aaaa
    int Estado;              // 0(No aplicado) / 1(Aplicado)
    //int Eliminado;

} DescuentoCliente;

//Funciones publicas
Cliente* CargarClientes(int *n_clientes);
Proveedor* CargarProveedores(int *n_proveedores)

#endif // CLIENTES_H_INCLUDED
