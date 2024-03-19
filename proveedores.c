


Proveedor* CargarProveedores(int *n_proveedores){

    int n_lineas = 0, i;
    Proveedor *proveedores;
    FILE *f;

    f = fopen("AdminProv.txt", "r");     //Abrimos archivo de proveedores.txt

    if(f == NULL) printf("\nError al abrir proveedores.txt");  //Comprobamos que se abre y contenga los datos bien

    n_lineas = ContarLineas(f);     //numeros de lineas igual al nuemro de proveedores
    *n_proveedores = n_lineas;
    proveedores = (Proveedor*)calloc(n_lineas, sizeof(Proveedor));     //Memoria dinamica estrucutura

    rewind(f);

    for(i = 0; i < n_lineas; i++){                      //Bucle que almacena los datos de los proveedores uno a uno
        fscanf(f, "%d-", &proveedores[i].Id_empresa);
        fscanf(f, "%[^-]-", proveedores[i].Nombre);
        fscanf(f, "%[^-]-", proveedores[i].email);
        fscanf(f, "%[^-]-", proveedores[i].Contrasena);
        fscanf(f, "%[^\n]\n", &proveedores[i].Perfil_usuario);      //¿?¿?  Cambiar por sustitucion de enteros ¿?¿?
        //proveedores[i].Eliminado = 0;
    }

    fclose(f);
    return proveedores;

}
