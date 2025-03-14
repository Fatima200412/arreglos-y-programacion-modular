#ifndef FUNCION_ATM_H_INCLUDED
#define FUNCION_ATM_H_INCLUDED
#define PIN 1234
#define intentos 3
#define archivosaldo "saldo.txt"

// Funciones

// Función para consultar saldo
void consultar(float saldo) {
    printf("TU SALDO ES DE $ %.2f PESOS \n", saldo);
}

// Función para depositar o retirar saldo
int valida(float x) {
    if (x > 0) {
        printf("REALIZANDO OPERACION...\n");
        return 0;
    }
    else if (x == 0) {
        printf("NO ES POSIBLE REALIZAR ESTA OPERACION, INTENTA NUEVAMENTE:.\n");
        return 1;
    }
    else {
        printf("CANTIDAD NO VALIDA.\n");
        return 101;
    }
}

// Función para verificar el PIN
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

// Función para leer los saldos desde un archivo
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

// Función para guardar los saldos en un archivo
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

// Función para mostrar el menú de selección de cuenta
void menuSeleccionCuenta() {
    puts("SELECCIONE UNA CUENTA:");
    puts("1) Cuenta 1");
    puts("2) Cuenta 2");
    puts("3) Cuenta 3");
    puts("4) CERRAR EL PROGRAMA");
}

// Función para mostrar el menú de operaciones
void menuOperaciones() {
    puts(" SELECCIONE UNA OPERACION: ");
    puts("1) CONSULTAR SALDO");
    puts("2) DEPOSITAR DINERO");
    puts("3) RETIRAR DINERO");
    puts("4) SALIR DEL CAJERO");
}

// Función para verificar si los datos ingresados son correctos
int datosValidos(int opcion, int tipoValidacion) {
    if (opcion < 1 || opcion > 4) {
        printf("OPCION NO VALIDA, INTENTA DE NUEVO.\n");
        return 0;
    }
    if (tipoValidacion == 1 && (opcion < 1 || opcion > 3)) {
        printf("CUENTA NO VALIDA, INTENTA NUEVO.\n");
        return 0;
    }
    return 1;
}


#endif // FUNCION_ATM_H_INCLUDED
