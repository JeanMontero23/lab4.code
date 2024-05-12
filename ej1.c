#include <stdio.h>

/*
 * La siguiente funcion realiza un recorrido por todo el arreglo que posee un una dimension n para relizar la busqueda de un valor x
 * En caso de que sea encontrado, devuelve la posicion en la que se encontro el valor en la busqueda del arreglo
 * Por otra parte, en caso de que no lo encuentre devuelve -1
 */
int busquedaLineal(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

/*
 * En este bloque de codigo se hace una busqueda binaria en el arreglo entre las posiciones definidas como inicio y fin
 * Seguidamente, el valor del elemento medio se compara con x
 * Tambien se quiere ajustar los limites del intervalo a conveniencia hasta que se encuentre el elemento deseado o que se confirme que no se encuentra en el arreglo
 */
int busquedaBinaria(int arr[], int inicio, int fin, int x) {
    while (inicio <= fin) {
        int medio = inicio + (fin - inicio) / 2;
        if (arr[medio] == x) {
            return medio;
        }
        if (arr[medio] < x) {
            inicio = medio + 1;
        } else {
            fin = medio - 1;
        }
    }
    return -1;
}

/*
 * En la siguiente funcion se hace una busqueda de manera binaria, ademas es recursiva ya que se tenia que utilizar esto con lo que se pidio en la parte 4
 * Para cumplir con lo anterior se opto por dividir el arreglo en dos mitades y que la busqueda se haga en la mitad que corresponde al valor x
 *Al final de este bloque se usa busquedaBinariaRecursiva() para que se haga el llamado a busquedaBinariaRecursivaAux() para que se usen los parametros que sean mas apropiados para que se lleve a cabo la busqueda recursiva
 */
int busquedaBinariaRecursivaAux(int arr[], int inicio, int fin, int x) {
    if (inicio > fin) {
        return -1;
    }

    int medio = inicio + (fin - inicio) / 2;
    if (arr[medio] == x) {
        return medio;
    }
    if (arr[medio] < x) {
        return busquedaBinariaRecursivaAux(arr, medio + 1, fin, x);
    } else {
        return busquedaBinariaRecursivaAux(arr, inicio, medio - 1, x);
    }
}
int busquedaBinariaRecursiva(int arr[], int n, int x) {
    return busquedaBinariaRecursivaAux(arr, 0, n - 1, x);
}

/*
 * Primeramente se define un arreglo que tiene valores ordenados
 * Por medio de sizeof() se calcula las dimensiones del arreglo
 * Luego se le pide al usuario que ingrese un valor y ese se guarda en la variable con el mismo nombre
 * Despues se hacen los tres tipos de busquedas que se pueden identificar al inicio de cada una
 * Nota: En cada tipo de busqueda se imprimen mensajes para que al usuario se le proporcione de manera clara los resultados
 */
int main() {
    int arreglo[] = {2, 4, 6, 23, 56, 79};
    int tamano = sizeof(arreglo) / sizeof(arreglo[0]);

    int valor;
    printf("Ingrese un valor entero: ");
    scanf("%d", &valor);

    // Primeramente se hace una busqueda lineal
    int posicionLineal = busquedaLineal(arreglo, tamano, valor);
    if (posicionLineal != -1) {
        printf("El valor %d se encuentra en la posición %d (Uso de busqueda lineal).\n", valor, posicionLineal);
    } else {
        printf("El valor %d no fue encontrado (Uso de busqueda lineal).\n", valor);
    }

    // En segundo lugar se procede a hacer una busqueda binaria iterativa
    int posicionBinaria = busquedaBinaria(arreglo, 0, tamano - 1, valor);
    if (posicionBinaria != -1) {
        printf("El valor %d se encuentra en la posición %d (Uso de busqueda binaria iterativa).\n", valor, posicionBinaria);
    } else {
        printf("El valor %d no fue encontrado (Uso de busqueda binaria iterativa).\n", valor);
    }

    // Por ultimo se realiza la busqueda binaria recursiva
    int posicionRecursiva = busquedaBinariaRecursiva(arreglo, tamano, valor);
    if (posicionRecursiva != -1) {
        printf("El valor %d se encuentra en la posición %d (Uso de busqueda binaria recursiva).\n", valor, posicionRecursiva);
    } else {
        printf("El valor %d no fue encontrado (Uso de busqueda binaria recursiva).\n", valor);
    }

    return 0;
}

