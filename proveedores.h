
#ifndef PROVEEDORES_H_INCLUDED
#define PROVEEDORES_H_INCLUDED

typedef struct{

    int Id_empresa;
    char Nombre[21];
    char email[31];
    char Contrasena[16];
    int Perfil_usuario;         // 0(administrador) / 1(provedor)
    //char Perfil_usuario[13];    // O int Perfil_usuario == 0(administrador) / 1(provedor)
    int Eliminado;

} Proveedor;

//Funciones publicas
Proveedor *CrearProveedor(Proveedor *arrayProveedores, int *n_proveedores, int op);
void ListarProveedores(Proveedor *arrayProveedores, int n_proveedores, int op, int posicion);
int BuscarProveedor(Proveedor *arrayProveedores, int n_proveedores, char nombre, char email, int id, int op);
void EliminarProv(Proveedor *arrayProveedores, int *n_proveedores, int posicion);
Proveedor* CargarProveedores(int *n_proveedores);
void GuardarEstructuraP(Proveedor *arrayProveedores, int n_proveedores);


#endif // PROVEEDORES_H_INCLUDED
