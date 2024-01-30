// Función para fusionar dos subarreglos ordenados en uno solo 
void merge(int A[], int inicio, int medio, int fin) {
    int *aux = new int[fin - inicio + 1]; // Arreglo auxiliar para almacenar temporalmente los elementos fusionados
    int i = inicio;     // índice de la primera mitad
    int j = medio + 1;  // índice de la segunda mitad
    int h = 0;

    // Se recorren ambos subarreglos y se van combinando sus
    // elementos ordenadamente hasta que se haya recorrido
    // totalmente uno de ellos
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

    // Si se copiaron todos los elementos de la primera mitad,
    // se copia el resto de la segunda mitad
    if (i > medio) {
        while (j <= fin) {
            aux[h] = A[j];
            j += 1;
            h += 1;
        }
    } // Si no, se copia el resto de la primera mitad
    else {
        while (i <= medio) {
            aux[h] = A[i];
            i += 1;
            h += 1;
        }
    }
    
    h = 0;
    for (int k = inicio; k <= fin; k++) {
        A[k] = aux[h];
        h += 1;
    }
    delete [] aux; // Liberar la memoria del arreglo auxiliar
}

// Función recursiva para aplicar el algoritmo Merge Sort
void merge_sort(int A[], int inicio, int fin) {
    if (inicio < fin) {
        int medio = (inicio + fin) / 2;
        merge_sort(A, inicio, medio);       // Ordenar la primera mitad
        merge_sort(A, medio + 1, fin);      // Ordenar la segunda mitad
        merge(A, inicio, medio, fin);       // Fusionar las dos mitades ordenadas
    }
}

// Función para intercambiar dos elementos en un arreglo
void intercambiar(int A[], int x, int y) {
    int aux = A[x];
    A[x] = A[y];
    A[y] = aux;
}

// Función que particiona el arreglo para el algoritmo QuickSort
int partition(int A[], int p, int r) {
    int pivote = A[r]; // Registro elegido como pivote
    int ultimo = p - 1; // Índice del último registro menor al pivote

    // Agrupa los elementos menores al pivote al principio del arreglo
    for (int i = p; i < r; i++) {
        if (A[i] < pivote) {
            ultimo += 1;
            intercambiar(A, ultimo, i);
        }
    }

    // Mueve el pivote a su posición correcta
    intercambiar(A, ultimo + 1, r);
    return ultimo + 1;
}

// Función recursiva para aplicar el algoritmo QuickSort
void quicksort(int A[], int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quicksort(A, p, q - 1); // Ordenar la parte izquierda
        quicksort(A, q + 1, r); // Ordenar la parte derecha
    }
}

// Función para ordenar el arreglo usando el algoritmo Insertion Sort
void insertion_sort(int A[], int n) {
    for (int j = 1; j < n; j++) {
        int k = A[j];
        int i = j - 1;

        // Mueve los elementos mayores que k a una posición hacia la derecha
        while (i >= 0 && A[i] > k) {
            A[i + 1] = A[i];
            i = i - 1;
        }
        A[i + 1] = k;
    }
}

// Función para ordenar el arreglo usando el algoritmo Selection Sort
void selection_sort(int A[], int n) {
    for (int j = 0; j < n-1; j++) {
        int menor = j;

        // Encuentra el elemento mínimo del subarreglo no ordenado
        for (int i = j+1; i < n; i++) {
            if (A[i] < A[menor]) {
                menor = i;
            }
        }
        intercambiar (A, j, menor);
    }
}

// Función para ordenar el arreglo usando el algoritmo BubbleSort
void bubblesort(int A[], int n) {
    for (int i = 0; i < n-1; i++) {

        // Los primeros i elementos ya están ordenados
        for (int j = n-1; j > i; j--) {
            if (A[j] < A[j-1]) {
                intercambiar(A, j, j-1);
            }
        }
    }
}
