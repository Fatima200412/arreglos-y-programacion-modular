#include <stdio.h>
#include <stdlib.h>

#define PIN 1234
#define intentos 3
#define archivosaldo "saldo.txt"

// Funciones

// Funcion para consultar saldo
void consultar(float saldo) {
    printf("TU SALDO ES DE $ %.2f PESOS \n", saldo);
}

// Funcion para depositar o retirar saldo
int valida(float x) {
    if (x > 0) {
        printf("REALIZANDO OPERACION...\n");
        return 0;
    } else if (x == 0) {
        printf("NO ES POSIBLE REALIZAR ESTA OPERACION, INTENTA NUEVAMENTE:.\n");
        return 1;
    } else {
        printf("CANTIDAD NO VALIDA.\n");
        return 101;
    }
}

// Funcion para verificar el PIN
int acceso() {
    int piningresado;
    for (int i = 0; i < intentos; i++) {
        printf("POR FAVOR INGRESA TU PIN: ");
        scanf("%d", &piningresado);
        if (piningresado == PIN) {
            printf("PIN CORRECTO! \n");
            return 1;
        } else {
            printf("PIN INCORRECTO\n");
        }
    }
    return 0;
}

// Funcion para leer los saldos desde un archivo
void leer(float saldo[3]) {
    FILE *archivo = fopen(archivosaldo, "r");
    if (archivo != NULL) {
        for (int i = 0; i < 3; i++) {
            fscanf(archivo, "%f", &saldo[i]);
        }
        fclose(archivo);
    } else {
        for (int i = 0; i < 3; i++) {
            saldo[i] = 1000;
        }
    }
}

// Funcion para guardar los saldos en un archivo
void guardarsaldo(float saldo[3]) {
    FILE *archivo = fopen(archivosaldo, "w");
    if (archivo != NULL) {
        for (int i = 0; i < 3; i++) {
            fprintf(archivo, "%f\n", saldo[i]);
        }
        fclose(archivo);
    } else {
        printf("ERROR AL GUARDAR SALDO.\n");
    }
}

// Funcion principal
int main() {
    // Variables del programa
    int opc, v, cuentasel;
    float saldo[3], depositar, retirar;

    // Leer los saldos iniciales
    leer(saldo);

    // Verificar el PIN
    if (!acceso()) {
        printf("SE HA ALCANZADO EL LIMITE DE INTENTOS\n");
        return 1;
    }

    // Seleccion de la cuenta
    do {
        puts("\t -------BIENVENIDO!------");
        puts("\t ---CAJERO AUTOMATICO --- \n");

        puts("SELECCIONE UNA CUENTA:");
        puts("1) Cuenta 1");
        puts("2) Cuenta 2");
        puts("3) Cuenta 3");
        puts("4) CERRAR EL PROGRAMA");
        scanf("%d", &cuentasel);

        if (cuentasel == 4) {
            puts("\n\t GRACIAS POR USAR EL CAJERO \n \t HASTA LUEGO! \n");
            break;
        }

        if (cuentasel < 1 || cuentasel > 3) {
            puts("OPCION NO VALIDA, INTENTA DE NUEVO");
            continue;
        }
        cuentasel--;

        // Menu de operaciones para la cuenta seleccionada
        do {
            puts(" SELECCIONE UNA OPERACION \n");
            puts("1) CONSULTAR SALDO \n");
            puts("2) DEPOSITAR DINERO \n");
            puts("3) RETIRAR DINERO \n");
            puts("4) SALIR DEL CAJERO\n");
            scanf("%d", &opc);

            // menu opcion seleccionada
            switch (opc) {
                case 1:
                    consultar(saldo[cuentasel]);
                    break;

                case 2:
                    printf("INGRESA LA CANTIDAD A DEPOSITAR: ");
                    scanf("%f", &depositar);
                    v = valida(depositar);
                    while (v != 0) {
                        scanf("%f", &depositar);
                        v = valida(depositar);
                    }
                    saldo[cuentasel] += depositar;
                    printf("\n\t HAS AGREGADO $ %f PESOS A TU CUENTA %d \n TU NUEVO SALDO ES DE $ %f PESOS \n", depositar, cuentasel + 1, saldo[cuentasel]);
                    guardarsaldo(saldo);
                    break;

                case 3:
                    printf("INGRESA LA CANTIDAD A RETIRAR: ");
                    scanf("%f", &retirar);
                    v = valida(retirar);
                    while (v != 0) {
                        scanf("%f", &retirar);
                        v = valida(retirar);
                    }
                    if (retirar > saldo[cuentasel]) {
                        printf("ERROR! TU SALDO ES INSUFICIENTE \n");
                    } else {
                        saldo[cuentasel] -= retirar;
                        printf("\n\t HAS RETIRADO $ %f PESOS DE TU CUENTA %d \n TU NUEVO SALDO ES DE $ %f PESOS \n", retirar, cuentasel + 1, saldo[cuentasel]);
                        guardarsaldo(saldo);
                    }
                    break;

                case 4:
                    puts("\n \t GRACIAS POR USAR EL CAJERO \n \t HASTA LUEGO! \n");
                    guardarsaldo(saldo);
                    break;

                default:
                    puts(" \n OPCION NO VALIDA \n INTENTA NUEVAMENTE  \n ");
                    break;
            }

        } while (opc != 4);

    } while (1);

    return 0;
}
