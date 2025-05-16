#ifndef ATM
#define ATM

struct cliente
{
    int n_cuenta;
    char nombre[40];
    char apellido[40];
    int nip;
    float saldo;
    int bloqueada;
    int intentos;
    int movimientos[10];
};

int login(int n_cuenta, int nip, struct cliente *clientes);
void menu_cliente(struct cliente *clientes, int indice_cuenta);
void buscar_nombre(struct cliente *clientes, char nombre[40]);
int buscar_indice_cuenta(struct cliente *clientes, int n_cuenta);
int validar(float x);
void consultar_saldo(struct cliente *clientes, int i);
void realizar_deposito(struct cliente *clientes, int i_remitente, int n_cuenta_destino);
void realizar_deposito_sc(struct cliente *clientes, int n_cuenta);
void realizar_retiro(struct cliente *clientes, int indice_cuenta);
void agregar_usuario(struct cliente *clientes, int *n);
void imprimir_usuarios(struct cliente *clientes);
void menu_cliente(struct cliente *clientes, int indice_cuenta);
void guardar_clientes(struct cliente *clientes, int n_usuarios);

void guardar_clientes(struct cliente *clientes, int n_usuarios) {
    char usuario[40], pass[20];
    printf("Usuario administrador: ");
    scanf("%s", usuario);
    printf("Contraseña: ");
    scanf("%s", pass);

    if (strcmp(usuario, "admin") != 0 || strcmp(pass, "1234") != 0) {
        printf("Usuario o contraseña incorrectos. No se guardó el archivo.\n");
        return;
    }

    FILE *f = fopen("clientes.txt", "w");
    if (!f) {
        printf("No se pudo abrir el archivo para guardar.\n");
        return;
    }

    for (int i = 0; i < n_usuarios; i++) {
        fprintf(f, "%d,%s,%s,%d,%.2f,%d,%d,", 
            clientes[i].n_cuenta, clientes[i].nombre, clientes[i].apellido,
            clientes[i].nip, clientes[i].saldo, clientes[i].bloqueada, clientes[i].intentos);
        for (int j = 0; j < 10; j++) {
            fprintf(f, "%d", clientes[i].movimientos[j]);
            if (j < 9) fprintf(f, ";");
        }
        fprintf(f, "\n");
    }
    fclose(f);
    printf("Clientes guardados en clientes.txt\n");
}

int login(int n_cuenta, int nip, struct cliente *clientes) // 1 para login exitoso -1 para pin incorrecto -2 cuenta bloqueada 0 cuenta no existe
{
    for (int i = 0; i < 100; i++)
    {
        if (clientes[i].bloqueada == 1)
        {
            return -2;
        }
        if (n_cuenta == clientes[i].n_cuenta)
        {
            if (nip == clientes[i].nip)
            {
                return 1;
            }
            else
            {
                if (clientes[i].intentos < 2)
                {

                    clientes[i].intentos++;
                    return -1;
                }
                else
                {
                    clientes[i].bloqueada = 1;
                    return -2;
                }
            }
        }
    }
    printf("\nLa cuenta no existe");
    return 0;
}

void menu_cliente(struct cliente *clientes, int indice_cuenta)
{
    int opcion, n_cuenta_destino;
    do
    {
        printf("\n========= MENU CLIENTE ==========\n");
        printf("1. Consultar saldo\n");
        printf("2. Realizar deposito\n");
        printf("3. Realizar retiro\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            consultar_saldo(clientes, indice_cuenta);
            break;
        case 2:
            printf("Ingrese el numero de cuenta\n");
            scanf("%d", &n_cuenta_destino);
            realizar_deposito(clientes, indice_cuenta, n_cuenta_destino);
            break;
        case 3:
            realizar_retiro(clientes, indice_cuenta);
            break;
        case 4:
            break;
        default:
            printf("Opcion no valida. Intente de nuevo.\n");
            break;
        }
    } while (opcion != 4);
}
void buscar_nombre(struct cliente *clientes, char nombre[40])
{
    for (int i = 0; i < 100; i++)
    {
        if (strcmp(clientes[i].nombre, nombre) == 0)
        {
            printf("El cliente %s tiene el numero de cuenta %d\n", clientes[i].nombre, clientes[i].n_cuenta);
            return;
        }
    }
    printf("El cliente no existe\n");
}

int buscar_indice_cuenta(struct cliente *clientes, int n_cuenta)
{
    for (int i = 0; i < 100; i++)
    {
        if (clientes[i].n_cuenta == n_cuenta)
        {
            return i;
        }
    }
    return -1;
}

int validar(float x)
{
    if (x > 0)
    {
        printf("La cantidad ingresada es válida.\n");
        return 1;
    }
    else
    {
        printf("La cantidad ingresada es negativa, ingrese un número positivo\n");
        return 0;
    }
}

void consultar_saldo(struct cliente *clientes, int i)
{
    int opcion;
    printf("========= CONSULTA DE SALDO ==========\n");
    printf("1. Ver su saldo actual\n2. Ver historial de movimientos\n");
    scanf("%d", &opcion);
    if (opcion == 1)
    {
        printf("Su saldo actual es de: %.2f\n", clientes[i].saldo);
    }
    else if (opcion == 2)
    {
        printf("Historial de movimientos:\n");
        for (int j = 0; j < 10; j++)
        {
            if (clientes[i].movimientos[j] != 0)
            {
                printf("%d\n", clientes[i].movimientos[j]);
            }
        }
        printf("\n");
    }
    else
    {
        printf("Opcion no valida.\n");
    }
}

void realizar_deposito(struct cliente *clientes, int i_remitente, int n_cuenta_destino)
{
    int i_destinatario, v;
    float num;
    printf("========= DEPOSITOS ==========\n");

    i_destinatario = buscar_indice_cuenta(clientes, n_cuenta_destino);
    if (i_destinatario == -1)
    {
        printf("La cuenta no existe.\n");
        return;
    }

    printf("Ingrese la cantidad que desea depositar: \n");
    scanf("%f", &num);

    v = validar(num);
    while (v != 1)
    {
        scanf("%f", &num);
        v = validar(num);
    }

    if (clientes[i_remitente].saldo < num)
    {
        printf("No puedes depositar una cantidad menor a tu saldo actual.\n");
        return;
    }
    
    clientes[i_remitente].saldo -= num;
    clientes[i_destinatario].saldo += num;
    // Guardar el movimiento en el historial del remitente y destinatario
    for (int i = 0; i < 10; i++)
    {
        if (clientes[i_remitente].movimientos[i] == 0)
        {
            clientes[i_remitente].movimientos[i] = -num;
            break;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        if (clientes[i_destinatario].movimientos[i] == 0)
        {
            clientes[i_destinatario].movimientos[i] = num;
            break;
        }
    }
    printf("Su depósito se realizó con éxito. El saldo actual es: %.2f\n", clientes[i_remitente].saldo);
}

// Deposito sin cuenta de remitente

void realizar_deposito_sc(struct cliente *clientes, int n_cuenta)
{
    int i_destinatario, v;
    float num;
    printf("========= DEPOSITOS ==========\n");

    i_destinatario = buscar_indice_cuenta(clientes, n_cuenta);
    if (i_destinatario == -1)
    {
        printf("La cuenta no existe.\n");
        return;
    }

    printf("Ingrese la cantidad que desea depositar: \n");
    scanf("%f", &num);

    v = validar(num);
    while (v != 1)
    {
        scanf("%f", &num);
        v = validar(num);
    }
    clientes[i_destinatario].saldo += num;
    // Guardar el movimiento en el historial del destinatario
    for (int i = 0; i < 10; i++)
    {
        if (clientes[i_destinatario].movimientos[i] == 0)
        {
            clientes[i_destinatario].movimientos[i] = num;
            break;
        }
    }
    printf("Su depósito se realizó con éxito. El saldo actual es: %.2f\n", clientes[i_destinatario].saldo);
}

void realizar_retiro(struct cliente *clientes, int indice)
{
    float num;
    int v, continuar;

    printf("========= RETIROS ==========\n");
    printf("Ingrese la cantidad que desea retirar: \n");
    scanf("%f", &num);
    if (clientes[indice].saldo == 0)
    {
        printf("No tienes saldo disponible para retirar.\n");
        return;
    }
    v = validar(num);
    while (v != 1)
    {
        scanf("%f", &num);
        v = validar(num);
    }
    printf("Esta seguro que desea realizar el retiro?\n");
        printf("1.-Si\n");
        printf("2.-No\n");
        scanf("%d",&continuar);

        if(continuar !=1)
        {
            printf("Operacion cancelada\n");

        }
    if (num > clientes[indice].saldo)
    {
        printf("No tienes suficiente saldo, por favor ingresa una cantidad válida:\n");
    }
    else
    {
        clientes[indice].saldo -= num;
        printf("Su retiro se realizó con éxito. Saldo restante: %.2f\n", clientes[indice].saldo);
        // Guardar el movimiento en el historial
        for (int i = 0; i < 10; i++)
        {
            if (clientes[indice].movimientos[i] == 0)
            {
                clientes[indice].movimientos[i] = -num;
                break;
            }
        }
    }
}

void agregar_usuario(struct cliente *clientes, int *n)
{
    printf("Ingrese el numero de cliente");
    scanf("%d", &clientes[*n].n_cuenta);
    printf("Ingrese el nombre del cliente");
    scanf("%s", clientes[*n].nombre);
    printf("Ingrese el apellido del cliente");
    scanf("%s", clientes[*n].apellido);
    printf("Ingrese el nip del cliente");
    scanf("%d", &clientes[*n].nip);
    printf("Ingrese el saldo del cliente");
    scanf("%f", &clientes[*n].saldo);
    clientes[*n].bloqueada = 0;
    clientes[*n].intentos = 0;
    for (int i = 0; i < 10; i++)
    {
        clientes[*n].movimientos[i] = 0;
    }
    (*n)++;
}

void imprimir_usuarios(struct cliente *clientes)
{
    for (int i = 0; i < 100; i++)
    {
        printf("Numero de cuenta: %d\n", clientes[i].n_cuenta);
        printf("Nombre: %s\n", clientes[i].nombre);
        printf("Apellido: %s\n", clientes[i].apellido);
        printf("NIP: %d\n", clientes[i].nip);
        printf("Saldo: %.2f\n", clientes[i].saldo);
        printf("Bloqueada: %d\n", clientes[i].bloqueada);
        printf("Intentos: %d\n", clientes[i].intentos);
        printf("\n");
    }
}

#endif
