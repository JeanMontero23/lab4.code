#include <stdio.h>

/*
 * La siguiente funcion lo que hace es que recibe el arreglo de enteros desordenados asi como su longitud de parametros
 * Seguidamente se va a iterar en el arreglo pero comenzando desde el segundo elemento
 * En la iteracion de va a comparar cada elemento con el valor minimo actual, de igual manera "minimo" se va a comparar si se encuentra un valor menor
 * Por ultimo va a devolver el valor minimo que se encontro al final
 */
int encontrarMinimo(int arreglo[], int longitud) {
    int minimo = arreglo[0];
    for (int i = 1; i < longitud; i++) {
        if (arreglo[i] < minimo) {
            minimo = arreglo[i];
        }
    }
    return minimo;
}

/*
 * Este bloque funciona similar al anterior
 * A diferencia de encontrarMinimo, en este se tiene el primer elemento del arreglo como el maximo
 * De igual modo se compara dicho valor con todos los demas y se actualiza si se encuentra uno mayor
 */
int encontrarMaximo(int arreglo[], int longitud) {
    int maximo = arreglo[0];
    for (int i = 1; i < longitud; i++) {
        if (arreglo[i] > maximo) {
            maximo = arreglo[i];
        }
    }
    return maximo;
}

/*
 * Aqui se utiliza como apoyo el prototipo que se dio para encontrar maximo y minimo en el arreglo
 * Se usa el primer elemento del arreglo para fijar los valores maximo y minimo del inicio
 * Se hace una iteracion en el arreglo
 * En la iteracion se van actualizando los valores maximo y minimo
 */
void encontrarMinMax(int *arreglo, int *minimo, int *maximo, int longitud) {
    *minimo = *maximo = arreglo[0];
    for (int i = 1; i < longitud; i++) {
        if (arreglo[i] < *minimo) {
            *minimo = arreglo[i];
        }
        if (arreglo[i] > *maximo) {
            *maximo = arreglo[i];
        }
    }
}


/*
 *En este bloque se declara el arreglo en primera instancia, el cual fue solicitado en el enunciado de este ejercicio
 *Una vez declarado lo anterior se calcula su longitud con el uso de sizeof
 *Se llaman las funciones que se mencionaron anteriormente y se imprime lo que se obtuvo
 */
int main() {
    int arreglo[] = {21, 24, 65, 3, 56, 12, 35, 15};
    int longitud = sizeof(arreglo) / sizeof(arreglo[0]);
    
    printf("Valor minimo usando funcion aparte: %d\n", encontrarMinimo(arreglo, longitud));
    printf("Valor maximo usando funcion aparte: %d\n", encontrarMaximo(arreglo, longitud));
    
    int min, max;
    encontrarMinMax(arreglo, &min, &max, longitud);
    printf("Valor minimo usando punteros: %d\n", min);
    printf("Valor maximo usando punteros: %d\n", max);
    
    return 0;
}

