#ifndef PROVEEDORES_H_INCLUDED
#define PROVEEDORES_H_INCLUDED

typedef struct{

    int Id_empresa;
    char Nombre[21];
    char email[31];
    char Contrasena[16];
    char Perfil_usuario[13];    // O int Perfil_usuario == 0(administrador) / 1(provedor)
    int Eliminado;

} Proveedor;

//Funciones publicas
Proveedor* CargarProveedores(int *n_proveedores);
void GuardarEstrucutura(Proveedor *arrayProveedores, int n_proveedores);


#endif // PROVEEDORES_H_INCLUDED
