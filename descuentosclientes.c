



DescuentoCliente* CargarDescuentosClietes(int *n_descuentoscliente){

    int n_lineas = 0, i;
    DescuentoCliente *descuentosclientes;
    FILE *f;

    f = fopen("DescuentosClientes.txt", "r");     //Abrimos archivo de DescuentoCliente.txt

    if(f == NULL) printf("\nError al abrir DescuentoCliente.txt");  //Comprobamos que se abre y contenga los datos bien

    n_lineas = ContarLineas(f);     //numeros de lineas igual al nuemro de DescuentoCliente
    *n_descuentoscliente = n_lineas;
    descuentosclientes = (DescuentoCliente*)calloc(n_lineas, sizeof(DescuentoCliente));     //Memoria dinamica estrucutura

    rewind(f);

    for(i = 0; i < n_lineas; i++){                      //Bucle que almacena los datos de los descuentosclientes uno a uno
        fscanf(f, "%d-", &descuentosclientes[i].Id_cliente);
        fscanf(f, "%[^-]-", descuentosclientes[i].Id_Cod);
        fscanf(f, "%d[^-]/", descuentosclientes[i].Fechar_asig[0]);
        fscanf(f, "%d[^/]/", descuentosclientes[i].Fechar_asig[1]);
        fscanf(f, "%d[^/]-", descuentosclientes[i].Fechar_asig[2]);
        fscanf(f, "%d[^-]/", descuentosclientes[i].Fecha_cad[0]);
        fscanf(f, "%d[^/]/", descuentosclientes[i].Fecha_cad[1]);
        fscanf(f, "%d[^/]-", &descuentosclientes[i].Fecha_cad[2]);
        fscanf(f, "%d[^\n]\n", &descuentosclientes[i].Estado);
        //descuentosclientes[i].Eliminado = 0;
    }

    fclose(f);
    return descuentosclientes;

}
