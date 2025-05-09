 #include <stdio.h>
#include "practicaja.h"

int main() {
    int cuentaSeleccionada;
    int operaciones;
    int bucle = 1;

    struct cliente banco[3] = {
        {1, 15000, "Carlos Ramirez", 1234},
        {2, 10000, "Karla Gutierrez", 1701},
        {3, 20200, "Pepe Pollo", 7766}
    };

    printf("\n========== BIENVENIDO A LA PRACTICAJA CUCEI ==========\n");

    printf("\nPor favor seleccione la cuenta en la que quiere realizar una operación:\n");
    printf("1.- Cuenta 1\n");
    printf("2.- Cuenta 2\n");
    printf("3.- Cuenta 3\n");
    scanf("%d", &cuentaSeleccionada);

    if (cuentaSeleccionada < 1 || cuentaSeleccionada > 3) {
        printf("La opcion ingresada no es válida.\n");
        return 0;
    }

    cuentaSeleccionada -= 1;

    if (!autenticarNip(banco, cuentaSeleccionada)) {
        return 0;
    }

    do {
        printf("\nPor favor ingrese la opcion deseada:\n\n");
        printf("1.- Consulta de saldo\n");
        printf("2.- Depositos\n");
        printf("3.- Retiros\n");
        printf("4.- Salir de la practicaja\n");
        scanf("%d", &operaciones);

        switch (operaciones) {
            case 1:
                consultarSaldo(banco, cuentaSeleccionada);
                break;
            case 2:
                realizarDeposito(banco, cuentaSeleccionada);
                break;
            case 3:
                realizarRetiro(banco, cuentaSeleccionada);
                break;
            case 4:
                printf("\nGracias por usar la Practicaja CUCEI. Que tenga un buen dia\n");
                return 0;
            default:
                printf("La opcion ingresada no es correcta.\n");
        }

        printf("\nDesea realizar alguna otra operacion?\n");
        printf("1.- Sí\n");
        printf("2.- No\n");
        scanf("%d", &bucle);
    } while (bucle != 2);

    printf("\nGracias por usar la Practicaja CUCEI. Que tenga un buen dia\n");
    return 0;
}
