#include <iostream>

// Función que realiza la fusión de dos subarreglos ordenados.
void merge(int A[], int inicio, int medio, int fin);

// Implementación del algoritmo de ordenamiento Merge Sort.
void merge_sort(int A[], int inicio, int fin);

// Implementación del algoritmo de ordenamiento Merge Sort con Insertion Sort para subarreglos pequeños.
void merge_sort_is(int A[], int inicio, int fin, int k);

// Implementación del algoritmo de ordenamiento Insertion Sort.
void insertion_sort(int A[], int n);

// Función auxiliar para intercambiar dos elementos en un arreglo.
void intercambiar_rec(int A[], int x, int y);

// Función auxiliar para el paso de partición en el algoritmo QuickSort.
int partition(int A[], int p, int r);

// Implementación del algoritmo de ordenamiento QuickSort.
void quicksort(int A[], int p, int r);

int main() {
    // Aquí puedes probar tus funciones de ordenamiento con un arreglo de prueba
    return 0;
}

// Implementación de la función merge
void merge(int A[], int inicio, int medio, int fin) {
    // Crear un arreglo auxiliar para almacenar temporalmente los elementos fusionados.
    int *aux = new int[fin - inicio + 1];
    int i = inicio;
    int j = medio + 1;
    int h = 0;

    // Fusionar los dos subarreglos ordenados en el arreglo auxiliar.
    while ((i <= medio) && (j <= fin)) {
        if (A[i] <= A[j]) {
            aux[h] = A[i];
            i += 1;
        } else {
            aux[h] = A[j];
            j += 1;
        }
        h += 1;
    }

    // Copiar los elementos restantes del subarreglo izquierdo, si los hay.
    if (i > medio) {
        while (j <= fin) {
            aux[h] = A[j];
            j += 1;
            h += 1;
        }
    } else {
        // Copiar los elementos restantes del subarreglo derecho, si los hay.
        while (i <= medio) {
            aux[h] = A[i];
            i += 1;
            h += 1;
        }
    }

    // Copiar los elementos ordenados de vuelta al arreglo original.
    h = 0;
    for (int k = inicio; k <= fin; k++) {
        A[k] = aux[h];
        h += 1;
    }

    // Liberar la memoria del arreglo auxiliar.
    delete[] aux;
}

// Implementación del algoritmo Merge Sort
void merge_sort(int A[], int inicio, int fin) {
    if (inicio < fin) {
        int medio = (inicio + fin) / 2;
        // Ordenar recursivamente las dos mitades del arreglo.
        merge_sort(A, inicio, medio);
        merge_sort(A, medio + 1, fin);
        // Fusionar las dos mitades ordenadas.
        merge(A, inicio, medio, fin);
    }
}

// Implementación del algoritmo Merge Sort con Insertion Sort para subarreglos pequeños.
void merge_sort_is(int A[], int inicio, int fin, int k) {
    if (inicio < fin) {
        int medio = (inicio + fin) / 2;

        // Utilizar Insertion Sort si el tamaño del subarreglo es menor o igual a k.
        if (medio - inicio + 1 <= k) {
            insertion_sort(A + inicio, medio - inicio + 1);
        } else {
            // Continuar con Merge Sort recursivamente.
            merge_sort_is(A, inicio, medio, k);
        }

        if (fin - medio <= k) {
            insertion_sort(A + medio + 1, fin - medio);
        } else {
            merge_sort_is(A, medio + 1, fin, k);
        }

        // Fusionar las dos mitades ordenadas.
        merge(A, inicio, medio, fin);
    }
}

// Implementación del algoritmo Insertion Sort.
void insertion_sort(int A[], int n) {
    for (int i = 1; i < n; i++) {
        int key = A[i];
        int j = i - 1;

        // Mover los elementos mayores que key a una posición adelante.
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j = j - 1;
        }

        // Colocar key en su posición correcta.
        A[j + 1] = key;
    }
}

// Función auxiliar para intercambiar dos elementos en un arreglo.
void intercambiar_rec(int A[], int x, int y) {
    int aux = A[x];
    A[x] = A[y];
    A[y] = aux;
}

// Función auxiliar para el paso de partición en el algoritmo QuickSort.
int partition(int A[], int p, int r) {
    int pivote = A[r];
    int ultimo = p - 1;

    // Agrupar los elementos menores que el pivote al principio del arreglo.
    for (int i = p; i < r; i++) {
        if (A[i] < pivote) {
            ultimo += 1;
            intercambiar_rec(A, ultimo, i);
        }
    }

    // Mover el pivote a su posición correcta.
    intercambiar_rec(A, ultimo + 1, r);
    return ultimo + 1;
}

// Implementación del algoritmo QuickSort.
void quicksort(int A[], int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        // Ordenar recursivamente las dos mitades del arreglo.
        quicksort(A, p, q - 1);
        quicksort(A, q + 1, r);
    }
}
