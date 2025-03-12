#include <stdio.h>
#include <stdlib.h>
    // Función para calcular el área de un rectángulo
    float calcularArea(float base, float altura) {
         return base * altura;
          }

float calcularpromedio (int arreglo[],int tamano){
int suma=0;
for (int i=0; i<tamano; i++){
    suma+=arreglo[i];
}
return (float)suma/tamano;
}

int calcularSuma(int arreglo[], int tamano) {
    int suma = 0;
    for (int i = 0; i < tamano; i++) {
        suma += arreglo[i];
    }
    return suma;
}
int main()
{
   /*
   int numeros [5] = {10,20,30,40,50};
   for(int i=0 ; i<5; i++){
    printf("elemento %d: %d\n",i,numeros[i]);
   }
   int matriz [2][3] = {{1,2,3},{4,5,6}}
   for(int i=0; i<2;i++){
    for(int j=0;j<3;j++){
        printf("elemento [%d][%d]: %d \n",i,j,matriz [i][j]);
    }
   }

    int arreglo[5];
    printf("Ingrese 5 numeros: \n");


    for (int i = 0; i < 5; i++) {
        scanf("%d", &arreglo[i]);
    }


    printf("\n Los numeros ingresados en orden inverso son:\n");
    for (int i = 4; i >= 0; i--) {
        printf("%d\n", arreglo[i]);
    }*/

    // Función para calcular el área de un rectángulo
   /* float base = 5.0, altura = 3.0;
    float area = calcularArea(base, altura);
    printf("El área del rectángulo es: %.2f\n", area);

    // Función para calcular el promedio
        int numeros[] = {10, 20, 30, 40, 50};
         int tamano = sizeof(numeros) / sizeof(numeros[0]);
          float promedio = calcularpromedio(numeros, tamano);
           printf("El promedio es: %.2f\n", promedio);*/
///clas
int numeros[5];
 printf("Introduce 5 numeros: \n");
    for (int i = 0; i < 5; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    // Calcular la suma y el promedio
    int suma = calcularSuma(numeros, 5);
    float prom = calcularpromedio(numeros, 5);

    // Mostrar los resultados
    printf("\nLa suma de los 5 numeros es: %d\n", suma);
    printf("El promedio de los 5 numeros es: %.2f\n", prom);




    return 0;
}
