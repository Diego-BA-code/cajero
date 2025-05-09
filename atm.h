#ifndef ATM_H_INCLUDED
#define ATM_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>

#define MAX_INTENTOS 3

struct clientes{
    int noCliente;
    float saldo;
    char nombre[40];
    int pin;
};


int validarPIN(int pinIngresado, int pin) {
        return(pinIngresado == pin);
    }

void consultarSaldo(float saldo)
{
        printf("Tu saldo es: $%.2f\n", saldo);
}

float depositar(float saldo, float cantidad)
{
        if (cantidad > 0)
        {
                saldo += cantidad;
                printf("Deposito exitoso. Nuevo saldo: $%.2f\n", saldo);
        }
        else
        {
                printf("Cantidad invalida.\n");
        }
        return saldo;
}

float retirar(float saldo, float cantidad)
{
        if (cantidad > 0 && cantidad <= saldo)
        {
                saldo -= cantidad;
                printf("Retiro exitoso. Nuevo saldo: $%.2f\n", saldo);
        }
        else
        {
                printf("Cantidad invalida o saldo insuficiente.\n");
        }
        return saldo;
}

void menu(int cuenta, struct clientes cliente[])
{
        int pinIngresado;
        int intentos = 0;
        float cantidadDeposito,cantidadRetiro;
        int opcion;

        while (intentos < MAX_INTENTOS)
        {
                printf("Introduce tu PIN: ");
                scanf("%d", &pinIngresado);

                if (validarPIN(pinIngresado, cliente[cuenta].pin))
                {
                    printf("Bienvenido %s\n",cliente[cuenta].nombre);
                        do
                        {
                                printf("\n--- Cajero Automatico ---\n");
                                printf("1. Consultar saldo\n");
                                printf("2. Depositar\n");
                                printf("3. Retirar\n");
                                printf("4. Salir\n");
                                printf("Elige una opcion: ");
                                scanf("%d", &opcion);

                                switch (opcion)
                                {
                                case 1:
                                        consultarSaldo(cliente[cuenta].saldo);
                                        break;
                                case 2:
                                        printf("Introduce la cantidad a depositar: ");
                                        scanf("%f", &cantidadDeposito);
                                        cliente[cuenta].saldo = depositar(cliente[cuenta].saldo, cantidadDeposito);
                                        break;
                                case 3:
                                        printf("Introduce la cantidad a retirar: ");
                                        scanf("%f", &cantidadRetiro);
                                        cliente[cuenta].saldo = retirar(cliente[cuenta].saldo, cantidadRetiro);
                                        break;
                                case 4:
                                        printf("Gracias por usar el cajero automatico.\n");
                                        break;
                                default:
                                        printf("Opcion invalida.\n");
                                }
                        } while (opcion != 4);
                        exit(0); // Salir del programa después de un acceso exitoso
                }
                else
                {
                        printf("PIN incorrecto\n");
                        intentos++;
                }
        }

        // Si se exceden los intentos, bloquear el acceso y cerrar el programa
        printf("Acceso bloqueado");
        exit(0);
}

#endif // ATM_H_INCLUDED

